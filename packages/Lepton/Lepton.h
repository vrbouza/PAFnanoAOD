#ifndef LEPTON_H
#define LEPTON_H 1

#include "TLorentzVector.h"
#include "TString.h"
//#include "ElecScaleClass.h"

enum genLepMatch{kLGMtoGenLep, kLGMgood, kLGMfake, kLGMflip, kLGMconv, kLGMtoGenB, kLGMother};

class Lepton : public TObject{
  public:
    Lepton() {
      p = TLorentzVector(0,0,0,0);
      charge = 0;
      type = -1;
      isElec = 0; isMuon = 0; isTau = 0;
      Mid = 0;
    };
    //Lepton(const Lepton &l): p(l.p), charge(l.charge), type(l.type), index(l.index){ };
    Lepton(TLorentzVector vec,
        Int_t ch = 0,
        Int_t ty = -1,
        Int_t tdecayMode   = -1,
        Int_t tidDecayMode = -1,
        Int_t tidMVA       = -1,
        Int_t tidAntiE     = -1,
        Int_t tidAntiMu    = -1 ):
      charge(ch),
      type(ty),
      decayMode   (tdecayMode  ),
      idDecayMode (tidDecayMode),
      idMVA       (tidMVA      ),
      idAntiE     (tidAntiE    ),
      idAntiMu    (tidAntiMu   ) {
      p = vec;

      if(ty == 0){ isMuon = 1; isElec = 0; isTau = 0;}
      if(ty == 1){ isMuon = 0; isElec = 1; isTau = 0;}
      if(ty == 2){ isMuon = 0; isElec = 0; isTau = 1;}
    }
    ~Lepton(){};
    TLorentzVector p;
    TLorentzVector genp;
    Int_t charge;
    Int_t type;
    Int_t decayMode;
    Int_t idDecayMode;
    Int_t idMVA;
    Int_t idAntiE;
    Int_t idAntiMu;
    Int_t Mid; // mother Id, for gen leptons
    Bool_t isElec;
    Bool_t isMuon;
    Bool_t isTau;
    Double_t GetSF(Int_t sys = 0);
    void SetSF(Double_t val);
    void SetSFerr(Double_t val);
    void SetIso(Float_t val){ Iso = val;}
    void SetR9(Float_t val){ R9 = val;}
    void SetEnergyUnc(Float_t val){ EnergyUnc = val;}
    void SetGenMatch(Int_t m){ genMatch = m;}
    void Setdxy(Float_t t){ dxy = t;}
    void Setdz( Float_t t){ dz  = t;}
    void SetSIP3D(Float_t t){ SIP3D = t;}

    void SetIsIso(       Bool_t is){isIso = is;}
    void SetIsPrompt(    Bool_t is){isPrompt  = is;}
    void SetIsFromTau(   Bool_t is){isFromTau = is;}
    void SetIsConversion(Bool_t is){isConv    = is;}
    void SetIsFromB(Bool_t is){isFromB = is;}
    void SetIsFromC(Bool_t is){isFromC = is;}
    void SetIsFromL(Bool_t is){isFromL = is;}

    Bool_t  IsElec(){return isElec;}
    Bool_t  IsMuon(){return isMuon;}
    Float_t Pt(){return p.Pt();}
    Float_t Eta(){return p.Eta();}
    Float_t Phi(){return p.Phi();}
    Float_t E(){return p.E();}
    Float_t GetIso(){ return Iso;}
    Float_t GetR9(){return R9;}
    Float_t GetEnergyUnc(){return EnergyUnc;}
    Int_t   GetGenMatch(){return genMatch;}
    Float_t Getdxy(){ return dxy;}
    Float_t Getdz(){ return dz;}
    Float_t GetSIP3D(){ return SIP3D;}

    Bool_t IsPrompt(){return isPrompt;}
    Bool_t IsFromTau(){return isFromTau;}
    Bool_t IsConversion(){return isConv;}
    Bool_t IsFromB(){return isFromB;}
    Bool_t IsFromC(){return isFromC;}
    Bool_t IsFromL(){return isFromL;}
    Bool_t IsIso(){return isIso;}

    void SetGen(TLorentzVector t){genp = t;}
    void SetGen(Float_t pt, Float_t eta, Float_t phi, Float_t m){genp.SetPtEtaPhiM(pt, eta, phi, m);}
    TLorentzVector Gen(){ return genp;}
    TLorentzVector P(){   return p;}

  protected:
    Float_t SF;
    Float_t SFerr;
    Float_t Iso;
    Float_t R9;
    Float_t EnergyUnc;
    Int_t   genMatch;
    Float_t dxy;
    Float_t dz;
    Float_t SIP3D;

    Bool_t isIso;
    Bool_t isPrompt;
    Bool_t isConv;
    Bool_t isFromTau;
    Bool_t isFromB;
    Bool_t isFromC;
    Bool_t isFromL;


    //ClassDef(Lepton, 0);
};

#endif
