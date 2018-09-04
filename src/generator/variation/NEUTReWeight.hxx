// Copyright 2018 L. Pickering, P Stowell, R. Terri, C. Wilkinson, C. Wret

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

#ifndef GENERATOR_VARIATION_NEUTREWEIGHT_HXX_SEEN
#define GENERATOR_VARIATION_NEUTREWEIGHT_HXX_SEEN

#include "variation/IWeightProvider.hxx"

class NEUTReWeight : public IWeightProvider {
public:
  double GetEventWeight(nuis::event::MinimalEvent const &);
  void Initialize(fhicl::ParameterSet const &);
  paramId_t GetParameterId(std::string const &);
  void SetParameterValue(paramId_t, double);
  bool ParametersVaried();
  void Reconfigure();
};

#endif
