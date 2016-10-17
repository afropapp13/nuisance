#include "MINERvA_CC1pi0_XSec_1DEnu_antinu.h"

// The constructor
MINERvA_CC1pi0_XSec_1DEnu_antinu::MINERvA_CC1pi0_XSec_1DEnu_antinu(std::string inputfile, FitWeight *rw, std::string  type, std::string fakeDataFile) {

  fName = "MINERvA_CC1pi0_XSec_1DEnu_nubar_2016";
  fPlotTitles = "; E_{#nu} (GeV); d#sigma(E_{#nu}) (cm^{2}/nucleon)";
  EnuMin = 1.5;
  EnuMax = 10;
  fIsDiag = false;
  fAllowedTypes += "NEW";

  Measurement1D::SetupMeasurement(inputfile, type, rw, fakeDataFile);

  this->SetDataValues(std::string(std::getenv("EXT_FIT"))+"/data/MINERvA/CC1pi0/2016/anu-cc1pi0-xsec-enu.csv");

  // Error is given as percentage of cross-section
  // Need to scale the bin error properly before we do correlation -> covariance conversion
  for (int i = 0; i < dataHist->GetNbinsX()+1; i++) {
    dataHist->SetBinError(i+1, dataHist->GetBinContent(i+1)*dataHist->GetBinError(i+1)/100.);
  }

  // This is a correlation matrix, changed to covariance in SetCovarMatrixFromText
  //this->SetCovarMatrixFromText(std::string(std::getenv("EXT_FIT"))+"/data/MINERvA/CC1pi0/2016/cc1pi0_enu_corr.txt", dataHist->GetNbinsX());
  this->SetCovarMatrixFromCorrText(std::string(std::getenv("EXT_FIT"))+"/data/MINERvA/CC1pi0/2016/anu-cc1pi0-correlation-enu.csv", dataHist->GetNbinsX());
  this->SetupDefaultHist();

  fScaleFactor = this->fEventHist->Integral("width")*double(1E-38)/double(fNEvents);
};

void MINERvA_CC1pi0_XSec_1DEnu_antinu::FillEventVariables(FitEvent *event) {

    TLorentzVector Pnu = (event->PartInfo(0))->fP;
    TLorentzVector Ppi0;
    TLorentzVector Pmu;

    // Loop over the particle stack
    for (unsigned int j = 2; j < event->Npart(); ++j) {
      if (!(event->PartInfo(j))->fIsAlive && (event->PartInfo(j))->fStatus != 0) continue;
      int PID = (event->PartInfo(j))->fPID;
      if (PID == 111) {
        Ppi0 = event->PartInfo(j)->fP;
      } else if (PID == -13) {
        Pmu = (event->PartInfo(j))->fP;
      }
    }

    double hadMass = FitUtils::Wrec(Pnu, Pmu);
    double Enu;

    if (hadMass > 100 && hadMass < 1800) {
      //Enu = FitUtils::EnuCC1pi0rec(Pnu, Pmu, Ppi0);
      Enu = Pnu.E()/1000.;
    } else {
      Enu = -999;
  }

  fXVar = Enu;

  return;
};

//******************************************************************** 
bool MINERvA_CC1pi0_XSec_1DEnu_antinu::isSignal(FitEvent *event) {
//******************************************************************** 
  return SignalDef::isCC1pi0Bar_MINERvA(event, EnuMin, EnuMax);
}
