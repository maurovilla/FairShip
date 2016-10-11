#include "ecalClusterTuning.h"

ecalClusterTuning::ecalClusterTuning() {

  setDefaultTuning();

  // Currently these numbers refer to 4x4 cm2 cells!!
  /*
  energyCorrection[0] = 0.175; // GeV
  energyCorrection[1] = 1./.995;

  zCorrection[0] = 15.0; // cm
  zCorrection[1] = 0.64;

  sShapeParameter[0]=1.6;   // cm
  sShapeParameter[1]=0.125;
  sShapeParameter[2]=6.5;  // 1/cm
  sShapeParameter[3]=0.065;
  */
}


// all corrections as default: true for 6 cm cell
// Tested on FairShip as of 10 Oct 2016
void ecalClusterTuning::setDefaultTuning(){

  energyCorrection[0] = 0.0744; // GeV  -- unchanged!
  energyCorrection[1] = 1.;

  zCorrection[0] = 12.22; // cm         -- uncert: +-0.63
  zCorrection[1] = 1.789; // cm/lnGeV   -- uncert: +-0.316

  sShapeParameter[0]= 1.164;   // cm        -- uncert: 0.011
  sShapeParameter[1]= -0.0774; //cm/ln(GeV) -- uncert: 0.0061
  sShapeParameter[2]= 2.069;  // 1/cm       -- uncert: 0.051
  sShapeParameter[3]=0.968;   //1/(cm*ln(GeV);      -- uncert: 0.036

}

// all corrections to 0
void  ecalClusterTuning::setNullTuning(){

  energyCorrection[0] = 0.; // Energy shift 0 GeV
  energyCorrection[1] = 1.;  // scale factor to 1

  zCorrection[0] = 0.0; // fix whatever reco provides (cm)
  zCorrection[1] = 0.0; // no energy dependence  (cm/log(1GeV))

  sShapeParameter[0]=0.0; // cell width cm  (if 0 no correction)
  sShapeParameter[1]=0.0; // no energy dependence  (cm/log(1GeV))
  sShapeParameter[2]=0.0;  // 1/cm
  sShapeParameter[3]=0.0; // no energy dependence  (1/cm/log(1GeV))
}



Double32_t ecalClusterTuning::getBestCoord(Double32_t cogCoord, 
			   Double32_t centerCellCoord,
			   Double32_t lnEnergy) const {
  Double32_t width  = getSScale(lnEnergy);
  Double32_t lambda = getLambda(lnEnergy);
  Double32_t delta = cogCoord-centerCellCoord;

  return centerCellCoord + width*TMath::ASinH(lambda*delta);
}

ecalClusterTuning::~ecalClusterTuning(){};

ClassImp(ecalClusterTuning)
