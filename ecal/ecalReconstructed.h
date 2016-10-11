#ifndef ECALRECONSTRUCTED
#define ECALRECONSTRUCTED

#include "TObject.h"

class ecalReconstructed : public TObject
{
friend class ecalReco;
public:
  /** For framework compatibility **/
  ecalReconstructed() : TObject() {}; 
  /** Standard constructor**/
 ecalReconstructed(Float_t rawE, Float_t recoE, Float_t x, Float_t y, Int_t cellnum, Int_t clusternum, Int_t mc=-1111)
    : TObject(), fRawE(rawE), fRecoE(recoE), fX(x), fY(y), fXbest(x), fYbest(y), fZbest(0.), fCellNum(cellnum), fClusterNum(clusternum), fMCTrack(mc)
{};
  ~ecalReconstructed() {};

  /** Getters/setters **/
  inline Float_t RawE() const {return fRawE;}
  inline Float_t RecoE() const {return fRecoE;}
  inline Float_t X() const {return fX;}
  inline Float_t Y() const {return fY;}
  inline Float_t Xbest() const {return fXbest;}
  inline Float_t Ybest() const {return fYbest;}
  inline Float_t Zbest() const {return fZbest;}
  inline Int_t CellNum() const {return fCellNum;}
  inline Int_t ClusterNum() const {return fClusterNum;}
  inline Int_t MCTrack() const {return fMCTrack;}
  inline void SetMCTrack(Int_t mctrack) {fMCTrack=mctrack;}
  inline void SetXbest(Float_t x) {fXbest = x;}
  inline void SetYbest(Float_t y) {fYbest = y;}
  inline void SetZbest(Float_t z) {fZbest = z;}
  inline void SetEbest(Float_t e) {fRecoE = e;}

private:
  /** Uncalibrated energy **/
  Float_t fRawE;
  /** Reconstructed energy **/
  Float_t fRecoE;
  /** Coordinates of impact point **/
  Float_t fX;
  Float_t fY;
  /** Coordinates of the Shower Maximum **/
  Float_t fXbest;
  Float_t fYbest;
  Float_t fZbest;
  /** Serial number of maximum **/
  Int_t fCellNum;
  /** Serial number of cluster **/
  Int_t fClusterNum;
  /** Serial number of MC track (if any) **/
  Int_t fMCTrack;

  ClassDef(ecalReconstructed, 1)
};

#endif
