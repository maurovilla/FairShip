#ifndef ECALCLUSTERTUNING_H
#define ECALCLUSTERTUNING_H

#include "TMath.h"
//#include "TObject.h"

/*
  This class contains the parameters for S-Shape correction
  and shower maximum evaluation.
  
  It is meant to be used in association to a given cell shape/type.
  By design it is NOT single static object since in a calo, 
  more types of cells/modules can be present.

  The default values of all the coefficients are related to the 6x6 cm2 cells.

  M. Villa
 */


class ecalClusterTuning {
 public:
   ecalClusterTuning(); 
   /** Destructor **/
   virtual ~ecalClusterTuning();

   void setDefaultTuning(); // all corrections as default
   void setNullTuning();   // all corrections to 0

   void setEnergyCorrections(Double32_t aShift, Double32_t bScale){
     energyCorrection[0] = aShift;  energyCorrection[1] = bScale;
   };
   Double32_t getEnergyShift() const { return energyCorrection[0];};
   Double32_t getEnergyScale() const { return energyCorrection[1];};

   Double32_t getBestEnergy(Double32_t anEnergy) const { 
     return (anEnergy+energyCorrection[0])*energyCorrection[1];
   }

   void setZCorrections(Double32_t aShift, Double32_t bSlope){
     zCorrection[0] = aShift;     zCorrection[1] = bSlope;
   };
   Double32_t getZShift() const { return zCorrection[0];};
   Double32_t getZSlope() const { return zCorrection[1];};
   Double32_t getBestZ(Double32_t startZ, Double32_t lnEnergy) const { 
     return (startZ + zCorrection[0]+zCorrection[1]*lnEnergy) ;
   };

   void setSShapeParWidth(Double32_t aConst, Double32_t bSlope){
     sShapeParameter[0] = aConst;     sShapeParameter[1] = bSlope;
   };
   void setSShapeParLambda(Double32_t aConst, Double32_t bSlope){
     sShapeParameter[2] = aConst;     sShapeParameter[3] = bSlope;
   };
   Double32_t getSScale(Double32_t lnEnergy) const { 
     return sShapeParameter[0]+sShapeParameter[1]*(TMath::Max(lnEnergy,-0.2));
   };
   Double32_t getLambda(Double32_t lnEnergy) const { 
     return sShapeParameter[2]+sShapeParameter[3]*(TMath::Max(lnEnergy,-0.2));
   };
   Double32_t getBestCoord(Double32_t cogCoord, 
			   Double32_t centerCellCoord,
			   Double32_t lnEnergy) const;
   
 private:
   Double32_t  energyCorrection[2];
   Double32_t  zCorrection[2];
   Double32_t  sShapeParameter[4];

   ClassDef(ecalClusterTuning, 1)
};

#endif
