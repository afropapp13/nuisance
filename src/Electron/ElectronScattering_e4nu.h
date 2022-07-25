// Copyright 2016-2021 L. Pickering, P Stowell, R. Terri, C. Wilkinson, C. Wret

/*******************************************************************************
*    This file is part of NUISANCE.
*
*    NUISANCE is free software: you can redistribute it and/or modify
*    it under the terms of the GNU General Public License as published by
*    the Free Software Foundation, either version 3 of the License, or
*    (at your option) any later version.
*
*    NUISANCE is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU General Public License for more details.
*
*    You should have received a copy of the GNU General Public License
*    along with NUISANCE.  If not, see <http://www.gnu.org/licenses/>.
*******************************************************************************/

#ifndef ElectronScattering_e4nu_H_SEEN
#define ElectronScattering_e4nu_H_SEEN

#include "Measurement1D.h"

class ElectronScattering_e4nu : public Measurement1D {

public:

  ElectronScattering_e4nu(nuiskey samplekey);
  virtual ~ElectronScattering_e4nu() {};

  void FillEventVariables(FitEvent* event);
  bool isSignal(FitEvent* event);
  void SetDataFromName( const std::string& name );
  int GetNDOF();
  double GetLikelihood();
  void SetFitOptions(std::string opt);

  TH1D* GetMCHistogram(void);
  TH1D* GetDataHistogram(void);
};

#endif
