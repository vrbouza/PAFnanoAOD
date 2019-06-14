#pragma once

#include "PAFChainItemSelector.h"
#include "Functions.h"
#include "BTagSFUtil.h"
#include <iostream>
#include <vector>

const Int_t nChannels = 3;
enum eSysts   {inorm, nSysts};
const Int_t nWeights = 248;
const TString gChanLabel[nChannels] = {"ElMu", "Muon","Elec"};


class TWTTbarAnalysis : public PAFChainItemSelector{
  public:
    // Main methods
    TWTTbarAnalysis();
    virtual ~TWTTbarAnalysis(){}
    virtual void InsideLoop();
    virtual void Initialise();
    virtual void Summary();
    

    // Other methods
    void SetTWTTbarVariables();
    void ResetTWTTbarVariables();
    void GetLeptonVariables();
    void GetGenLepVariables();
    void GetJetVariables();
    void GetGenJetVariables();
    void GetMETandGenMET();

    void CalculateDressTWTTbarVariables();
    void CalculateTWTTbarVariables();

    void CalculateSFAndWeights();
    void SetMinimaAndMaxima();

    void DoesItReallyPassDress();
    void DoesItReallyPassReco();

    TLorentzVector getSysVector(const TString& sys = "");
    Double_t getMiniMax(Double_t ml1j1, Double_t ml1j2, Double_t ml2j1, Double_t ml2j2);
    Double_t getTopPtRW();


    // Attributes
    std::vector<Lepton> DressLeptons;
    std::vector<Lepton> selLeptons;
    std::vector<Jet>    selJets;
    std::vector<Jet>    selJetsJecUp;
    std::vector<Jet>    selJetsJecDown;
    std::vector<Jet>    selJetsJER;

    std::vector<Jet>    genJets;
    std::vector<Jet>    vetoJets;

    std::vector<Jet>    DressJets;
    std::vector<Jet>    DressLooseCentralJets;
    std::vector<Jet>    DressLooseFwdJets;

    std::vector<Jet> LooseCentralJets, LooseFwdJets;
    std::vector<Jet> LooseCentralJetsJESUp, LooseFwdJetsJESUp;
    std::vector<Jet> LooseCentralJetsJESDown, LooseFwdJetsJESDown;
    std::vector<Jet> LooseCentralJetsJERUp, LooseFwdJetsJERUp;
    
    TTree* fMiniTree;
    TH1F* fhDummy;
    Double_t  TLHEWeight[254];

    Int_t  TChannel, GenChannel;
    Bool_t TIsSS, TDressIsSS;
    Bool_t TPassReco, TPassRecoJESUp, TPassRecoJESDown, TPassRecoJERUp;
    Bool_t TPassDress, TPassPart;

    UShort_t TNBJets, TNBJetsJESUp, TNBJetsJESDown, TNBJetsJERUp;
    UShort_t NLooseCentral, NLooseCentralJESUp, NLooseCentralJESDown, NLooseCentralJERUp;
    UShort_t NLooseFwd, NLooseFwdJESUp, NLooseFwdJESDown, NLooseFwdJERUp;
    UShort_t NBLooseCentral, NBLooseCentralJESUp, NBLooseCentralJESDown, NBLooseCentralJERUp;
    UShort_t DressNJets, DressNLooseCentral, DressNLooseFwd, DressNBJets, DressNBLooseCentral;

    Double_t TLep1_Pt, TLep1_PtJESUp, TLep1_PtJESDown, TLep1_PtJERUp;
    Double_t TLep1_E, TLep1_EJESUp, TLep1_EJESDown, TLep1_EJERUp;
    Double_t TLep1_Phi, TLep1_PhiJESUp, TLep1_PhiJESDown, TLep1_PhiJERUp;
    Double_t TLep1_Eta, TLep1_EtaJESUp, TLep1_EtaJESDown, TLep1_EtaJERUp;
    Double_t TLep2_Pt, TLep2_PtJESUp, TLep2_PtJESDown, TLep2_PtJERUp;
    Double_t TLep2_E, TLep2_EJESUp, TLep2_EJESDown, TLep2_EJERUp;
    Double_t TLep2_Phi, TLep2_PhiJESUp, TLep2_PhiJESDown, TLep2_PhiJERUp;
    Double_t TLep2_Eta, TLep2_EtaJESUp, TLep2_EtaJESDown, TLep2_EtaJERUp;
    Double_t TJet1_Pt, TJet1_PtJESUp, TJet1_PtJESDown, TJet1_PtJERUp;
    Double_t TJet1_E, TJet1_EJESUp, TJet1_EJESDown, TJet1_EJERUp;
    Double_t TJet1_Eta, TJet1_EtaJESUp, TJet1_EtaJESDown, TJet1_EtaJERUp;
    Double_t TJet1_Phi, TJet1_PhiJESUp, TJet1_PhiJESDown, TJet1_PhiJERUp;
    Double_t TJet2_Pt, TJet2_PtJESUp, TJet2_PtJESDown, TJet2_PtJERUp;
    Double_t TJet2_E, TJet2_EJESUp, TJet2_EJESDown, TJet2_EJERUp;
    Double_t TJet2_Eta, TJet2_EtaJESUp, TJet2_EtaJESDown, TJet2_EtaJERUp;
    Double_t TLep1Lep2_Pt, TLep1Lep2_PtJESUp, TLep1Lep2_PtJESDown, TLep1Lep2_PtJERUp;
    Double_t TLep1Lep2_M, TLep1Lep2_MJESUp, TLep1Lep2_MJESDown, TLep1Lep2_MJERUp;
    Double_t TLep1Lep2_DPhi, TLep1Lep2_DPhiJESUp, TLep1Lep2_DPhiJESDown, TLep1Lep2_DPhiJERUp;
    Double_t TLep1Jet1_M, TLep1Jet1_MJESUp, TLep1Jet1_MJESDown, TLep1Jet1_MJERUp;
    Double_t TLep1Jet1_DPhi, TLep1Jet1_DPhiJESUp, TLep1Jet1_DPhiJESDown, TLep1Jet1_DPhiJERUp;
    Double_t TLep1Jet2_M, TLep1Jet2_MJESUp, TLep1Jet2_MJESDown, TLep1Jet2_MJERUp;
    Double_t TLep1Jet2_DPhi, TLep1Jet2_DPhiJESUp, TLep1Jet2_DPhiJESDown, TLep1Jet2_DPhiJERUp;
    Double_t TLep2Jet1_M, TLep2Jet1_MJESUp, TLep2Jet1_MJESDown, TLep2Jet1_MJERUp;
    Double_t TLep2Jet1_DPhi, TLep2Jet1_DPhiJESUp, TLep2Jet1_DPhiJESDown, TLep2Jet1_DPhiJERUp;
    Double_t TLep2Jet2_M, TLep2Jet2_MJESUp, TLep2Jet2_MJESDown, TLep2Jet2_MJERUp;
    Double_t TLep2Jet2_DPhi, TLep2Jet2_DPhiJESUp, TLep2Jet2_DPhiJESDown, TLep2Jet2_DPhiJERUp;
    Double_t Sys_Pt, Sys_PtJESUp, Sys_PtJESDown, Sys_PtJERUp;
    Double_t Sys_E, Sys_EJESUp, Sys_EJESDown, Sys_EJERUp;
    Double_t Sys_Eta, Sys_EtaJESUp, Sys_EtaJESDown, Sys_EtaJERUp;
    Double_t Sys_M, Sys_MJESUp, Sys_MJESDown, Sys_MJERUp;
    Double_t Sys_Pz, Sys_PzJESUp, Sys_PzJESDown, Sys_PzJERUp;
    Double_t TMiniMax, TMiniMaxJESUp, TMiniMaxJESDown, TMiniMaxJERUp;
    Double_t THT, THTJESUp, THTJESDown, THTJERUp;
    Double_t TMET, TMETJESUp, TMETJESDown, TMETJERUp;
    Double_t TMET_Phi, TMET_PhiJESUp, TMET_PhiJESDown, TMET_PhiJERUp;

    Double_t TDressLep1_Pt;
    Double_t TDressLep1_E;
    Double_t TDressLep1_Phi;
    Double_t TDressLep1_Eta;
    Double_t TDressLep2_Pt;
    Double_t TDressLep2_E;
    Double_t TDressLep2_Phi;
    Double_t TDressLep2_Eta;
    Double_t TDressJet1_Pt;
    Double_t TDressJet1_E;
    Double_t TDressJet1_Eta;
    Double_t TDressJet1_Phi;
    Double_t TDressJet2_Pt;
    Double_t TDressJet2_E;
    Double_t TDressJet2_Eta;
    Double_t TDressLep1Lep2_Pt;
    Double_t TDressLep1Lep2_M;
    Double_t TDressLep1Lep2_DPhi;
    Double_t TDressLep1Jet1_M;
    Double_t TDressLep1Jet1_DPhi;
    Double_t TDressLep1Jet2_M;
    Double_t TDressLep1Jet2_DPhi;
    Double_t TDressLep2Jet1_M;
    Double_t TDressLep2Jet1_DPhi;
    Double_t TDressLep2Jet2_M;
    Double_t TDressLep2Jet2_DPhi;
    Double_t DressSys_Pt;
    Double_t DressSys_E;
    Double_t DressSys_Eta;
    Double_t DressSys_M;
    Double_t DressSys_Pz;
    Double_t TDressMiniMax;
    Double_t TDressHT;
    Double_t TDressMET, TDressMET_Phi;

    Double_t TPartMET, TPartMET_Phi;


    UShort_t TNSelLeps, DressNLeps;

    UShort_t TNJets, TNJetsJESUp, TNJetsJESDown, TNJetsJERUp;

    Double_t ElecSF, MuonSF, ElecSFUp, ElecSFDo, MuonSFUp, MuonSFDo, lepSF;
    Double_t TrigSF, TrigSFerr;
    Double_t PUSF, PUSF_Up, PUSF_Down;
    Double_t BtagSF;
    Double_t BtagSFBtagUp, BtagSFBtagDown;
    Double_t BtagSFMistagUp, BtagSFMistagDown;
    Double_t TWeight, TWeight_normal;
    Double_t TWeight_LepEffUp, TWeight_LepEffDown;
    Double_t TWeight_ElecEffUp, TWeight_ElecEffDown;
    Double_t TWeight_MuonEffUp, TWeight_MuonEffDown;
    Double_t TWeight_TrigUp, TWeight_TrigDown;
    Double_t TWeight_FSUp, TWeight_FSDown;
    Double_t TWeight_PUDown, TWeight_PUUp;
    Double_t TWeight_MistagUp, TWeight_MistagDown;
    Double_t TWeight_BtagUp, TWeight_BtagDown;
    
  protected:
    // Parameters
    Bool_t   gIsData;
    Int_t    gSelection;
    TString  gSampleName;
    Bool_t   gIsTTbar;
    Bool_t   gIsLHE;
    Int_t    gChannel;
    TString  gPar;
    Bool_t   passMETfilters;
    Bool_t   passTrigger;
    Bool_t   isSS;
    Double_t NormWeight;
    UShort_t year;
    
    ClassDef(TWTTbarAnalysis, 0);
};
