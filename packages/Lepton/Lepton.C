#include "Lepton.h"

//ClassImp(Lepton);

Double_t Lepton::GetSF(Int_t sys){
  if      (sys ==  0) return SF;
  else if (sys == -1) return SF-SFerr;
  else if (sys ==  1) return SF+SFerr;
  else return SF;
}


void Lepton::SetSF(Double_t val) {
  SF = val;
}


void Lepton::SetSFerr(Double_t val) {
  SFerr = val;
}

