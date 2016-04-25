//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Feb  1 07:53:21 2012 by ROOT version 5.32/00
// from TTree data/
// found on file: data.root
//////////////////////////////////////////////////////////

#ifndef MyAnalysis_h
#define MyAnalysis_h

#include <TROOT.h>
#include <TFile.h>
#include <TChain.h>
#include <TSelector.h>
#include <TH1F.h>
#include <TLorentzVector.h>
#include <vector>

#include "MyJet.h"
#include "MyMuon.h"
#include "MyElectron.h"
#include "MyPhoton.h"

using namespace std;

// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.

class MyAnalysis: public TSelector {
public:
   TTree *fChain; //!pointer to the analyzed TTree or TChain
   
   // Declaration of leaf types
   Int_t NBJet;
   Int_t NJet;
   Float_t Jet_Pt[10]; //[NJet]
   Float_t Jet_Eta[10]; //[NJet]
   Float_t Jet_Phi[10]; //[NJet]
   Float_t Jet_E[10]; //[NJet]
   Float_t Jet_bDiscriminator[10]; //[NJet]
   Float_t Jet_ID[10]; //[NJet]
   Int_t NMuon;
   Float_t Muon_Pt[5]; //[NMuon]
   Float_t Muon_Eta[5]; //[NMuon]
   Float_t Muon_Phi[5]; //[NMuon]
   Float_t Muon_E[5]; //[NMuon]
   Int_t Muon_Charge[5]; //[NMuon]
   Float_t Muon_Iso[5]; //[NMuon]
   Int_t NLooseMuon;
   Float_t LooseMuon_Pt[5]; //[NLooseMuon]
   Float_t LooseMuon_Eta[5]; //[NLooseMuon]
   Float_t LooseMuon_Phi[5]; //[NLooseMuon]
   Float_t LooseMuon_E[5]; //[NLooseMuon]
   Int_t LooseMuon_Charge[5]; //[NLooseMuon]
   Float_t LooseMuon_Iso[5]; //[NLooseMuon]
   Int_t NElectron;
   Float_t Electron_Pt[5]; //[NElectron]
   Float_t Electron_Eta[5]; //[NElectron]
   Float_t Electron_Phi[5]; //[NElectron]
   Float_t Electron_E[5]; //[NElectron]
   Int_t Electron_Charge[5]; //[NElectron]
   Float_t Electron_Iso[5]; //[NElectron]
   Int_t NLooseElectron;
   Float_t LooseElectron_Pt[5]; //[NLooseElectron]
   Float_t LooseElectron_Eta[5]; //[NLooseElectron]
   Float_t LooseElectron_Phi[5]; //[NLooseElectron]
   Float_t LooseElectron_E[5]; //[NLooseElectron]
   Int_t LooseElectron_Charge[5]; //[NLooseElectron]
   Float_t LooseElectron_Iso[5]; //[NLooseElectron]
 
   Int_t NPhoton;
   Float_t Photon_Pt[5]; //[NPhoton]
   Float_t Photon_Eta[5]; //[NPhoton]
   Float_t Photon_Phi[5]; //[NPhoton]
   Float_t Photon_E[5]; //[NPhoton]
   Float_t Photon_Iso[5]; //[NPhoton]
   Float_t MET_Px;
   Float_t MET_Py;

   Float_t WMuon_MT[5];
   Float_t WMuon_Phi[5];
   Float_t WElectron_MT[5];
   Float_t WElectron_Phi[5];

   Float_t MChadronicBottom_px;
   Float_t MChadronicBottom_py;
   Float_t MChadronicBottom_pz;
   Float_t MCleptonicBottom_px;
   Float_t MCleptonicBottom_py;
   Float_t MCleptonicBottom_pz;
   Float_t MChadronicWDecayQuark_px;
   Float_t MChadronicWDecayQuark_py;
   Float_t MChadronicWDecayQuark_pz;
   Float_t MChadronicWDecayQuarkBar_px;
   Float_t MChadronicWDecayQuarkBar_py;
   Float_t MChadronicWDecayQuarkBar_pz;
   Float_t MClepton_px;
   Float_t MClepton_py;
   Float_t MClepton_pz;
   Int_t MCleptonPDGid;
   Float_t MCneutrino_px;
   Float_t MCneutrino_py;
   Float_t MCneutrino_pz;
   Int_t NPrimaryVertices;
   //Bool_t triggerIsoMu24;
   Float_t PUWeight;
   
   // List of branches
   TBranch *b_NBJet; //!
   TBranch *b_NJet; //!
   TBranch *b_Jet_Pt; //!
   TBranch *b_Jet_Eta; //!
   TBranch *b_Jet_Phi; //!
   TBranch *b_Jet_E; //!
   TBranch *b_Jet_bDiscriminator; //!
   TBranch *b_Jet_ID; //!
   TBranch *b_NMuon; //!
   TBranch *b_Muon_Pt; //!
   TBranch *b_Muon_Eta; //!
   TBranch *b_Muon_Phi; //!
   TBranch *b_Muon_E; //!
   TBranch *b_Muon_Charge; //!
   TBranch *b_Muon_Iso; //!
   TBranch *b_NLooseMuon; //!
   TBranch *b_LooseMuon_Pt; //!
   TBranch *b_LooseMuon_Eta; //!
   TBranch *b_LooseMuon_Phi; //!
   TBranch *b_LooseMuon_E; //!
   TBranch *b_LooseMuon_Charge; //!
   TBranch *b_LooseMuon_Iso; //!

   TBranch *b_NElectron; //!
   TBranch *b_Electron_Pt; //!
   TBranch *b_Electron_Eta; //!
   TBranch *b_Electron_Phi; //!
   TBranch *b_Electron_E; //!
   TBranch *b_Electron_Charge; //!
   TBranch *b_Electron_Iso; //!
   TBranch *b_NLooseElectron; //!
   TBranch *b_LooseElectron_Pt; //!
   TBranch *b_LooseElectron_Eta; //!
   TBranch *b_LooseElectron_Phi; //!
   TBranch *b_LooseElectron_E; //!
   TBranch *b_LooseElectron_Charge; //!
   TBranch *b_LooseElectron_Iso; //!


   TBranch *b_NPhoton; //!
   TBranch *b_Photon_Pt; //!
   TBranch *b_Photon_Eta; //!
   TBranch *b_Photon_Phi; //!
   TBranch *b_Photon_E; //!
   TBranch *b_Photon_Iso; //!
   TBranch *b_MET_Px; //!
   TBranch *b_MET_Py; //!

   TBranch *b_WMuon_MT;
   TBranch *b_WMuon_Phi;
   TBranch *b_WElectron_MT;
   TBranch *b_WElectron_Phi;

   TBranch *b_MChadronicBottom_px; //!
   TBranch *b_MChadronicBottom_py; //!
   TBranch *b_MChadronicBottom_pz; //!
   TBranch *b_MCleptonicBottom_px; //!
   TBranch *b_MCleptonicBottom_py; //!
   TBranch *b_MCleptonicBottom_pz; //!
   TBranch *b_MChadronicWDecayQuark_px; //!
   TBranch *b_MChadronicWDecayQuark_py; //!
   TBranch *b_MChadronicWDecayQuark_pz; //!
   TBranch *b_MChadronicWDecayQuarkBar_px; //!
   TBranch *b_MChadronicWDecayQuarkBar_py; //!
   TBranch *b_MChadronicWDecayQuarkBar_pz; //!
   TBranch *b_MClepton_px; //!
   TBranch *b_MClepton_py; //!
   TBranch *b_MClepton_pz; //!
   TBranch *b_MCleptonPDGid; //!
   TBranch *b_MCneutrino_px; //!
   TBranch *b_MCneutrino_py; //!
   TBranch *b_MCneutrino_pz; //!
   TBranch *b_NPrimaryVertices; //!
   //TBranch *b_triggerIsoMu24; //!
   TBranch *b_PUWeight; //!
   
   MyAnalysis(float sf = 1., float wf = 1, float Xsection = 1.0 , float lumi = 1.0, float num = 1.0, TTree * /*tree*/= 0) :
   fChain(0) {
      weight_factor = wf;
      norm_scale = lumi/(num/Xsection);
      SF_b = sf;
   }
   virtual ~MyAnalysis() {
   }
   virtual Int_t Version() const {
      return 2;
   }
   virtual void Begin(TTree *tree);
   virtual void SlaveBegin(TTree *tree);
   virtual void Init(TTree *tree);
   virtual Bool_t Notify();
   virtual Bool_t Process(Long64_t entry);
   virtual Int_t GetEntry(Long64_t entry, Int_t getall = 0) {
      return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0;
   }
   virtual void SetOption(const char *option) {
      fOption = option;
   }
   virtual void SetObject(TObject *obj) {
      fObject = obj;
   }
   virtual void SetInputList(TList *input) {
      fInput = input;
   }
   virtual TList *GetOutputList() const {
      return fOutput;
   }
   virtual void SlaveTerminate();
   virtual void Terminate();
   
   void BuildEvent();
   
   int TotalEvents;
   vector<MyJet> Jets;
   vector<MyMuon> Muons;
   vector<MyElectron> Electrons;
   vector<MyPhoton> Photons;
   
   TLorentzVector hadB, lepB, hadWq, hadWqb, lepWl, lepWn;
   TLorentzVector met;
   
   float weight_factor;
   float norm_scale;
   float SF_b;
   
   TH1F *h_Mmumu;
   TH1F *h_NMuon;
   TH1F *h_WMuon_MT;
   TH1F *h_WMuon_Phi;
   TH1F *h_NJet; 
   TH1F *h_NBJet; 
   TH1F *h_WMuon_MT_Final;
 
   vector<TH1F*> histograms;
   vector<TH1F*> histograms_MC;
   
};

#endif

#ifdef MyAnalysis_cxx
void MyAnalysis::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).
   
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fChain->SetMakeClass(1);
   
   fChain->SetBranchAddress("NBJet", &NBJet, &b_NBJet);
   fChain->SetBranchAddress("NJet", &NJet, &b_NJet);
   fChain->SetBranchAddress("Jet_Pt", Jet_Pt, &b_Jet_Pt);
   fChain->SetBranchAddress("Jet_Eta", Jet_Eta, &b_Jet_Eta);
   fChain->SetBranchAddress("Jet_Phi", Jet_Phi, &b_Jet_Phi);
   fChain->SetBranchAddress("Jet_E", Jet_E, &b_Jet_E);
   fChain->SetBranchAddress("Jet_bDiscriminator", Jet_bDiscriminator, &b_Jet_bDiscriminator);
   //fChain->SetBranchAddress("Jet_ID", Jet_ID, &b_Jet_ID);
   fChain->SetBranchAddress("NMuon", &NMuon, &b_NMuon);
   fChain->SetBranchAddress("Muon_Pt", Muon_Pt, &b_Muon_Pt);
   fChain->SetBranchAddress("Muon_Eta", Muon_Eta, &b_Muon_Eta);
   fChain->SetBranchAddress("Muon_Phi", Muon_Phi, &b_Muon_Phi);
   fChain->SetBranchAddress("Muon_E", Muon_E, &b_Muon_E);
   fChain->SetBranchAddress("Muon_Charge", Muon_Charge, &b_Muon_Charge);
   fChain->SetBranchAddress("Muon_Iso", Muon_Iso, &b_Muon_Iso);
   fChain->SetBranchAddress("NLooseMuon", &NLooseMuon, &b_NLooseMuon);
   fChain->SetBranchAddress("LooseMuon_Pt", LooseMuon_Pt, &b_LooseMuon_Pt);
   fChain->SetBranchAddress("LooseMuon_Eta", LooseMuon_Eta, &b_LooseMuon_Eta);
   fChain->SetBranchAddress("LooseMuon_Phi", LooseMuon_Phi, &b_LooseMuon_Phi);
   fChain->SetBranchAddress("LooseMuon_E", LooseMuon_E, &b_LooseMuon_E);
   fChain->SetBranchAddress("LooseMuon_Charge", LooseMuon_Charge, &b_LooseMuon_Charge);
   fChain->SetBranchAddress("LooseMuon_Iso", LooseMuon_Iso, &b_LooseMuon_Iso);

   fChain->SetBranchAddress("NElectron", &NElectron, &b_NElectron);
   fChain->SetBranchAddress("Electron_Pt", Electron_Pt, &b_Electron_Pt);
   fChain->SetBranchAddress("Electron_Eta", Electron_Eta, &b_Electron_Eta);
   fChain->SetBranchAddress("Electron_Phi", Electron_Phi, &b_Electron_Phi);
   fChain->SetBranchAddress("Electron_E", Electron_E, &b_Electron_E);
   fChain->SetBranchAddress("Electron_Charge", Electron_Charge, &b_Electron_Charge);
   fChain->SetBranchAddress("Electron_Iso", Electron_Iso, &b_Electron_Iso);
   fChain->SetBranchAddress("NLooseElectron", &NLooseElectron, &b_NLooseElectron);
   fChain->SetBranchAddress("LooseElectron_Pt", LooseElectron_Pt, &b_LooseElectron_Pt);
   fChain->SetBranchAddress("LooseElectron_Eta", LooseElectron_Eta, &b_LooseElectron_Eta);
   fChain->SetBranchAddress("LooseElectron_Phi", LooseElectron_Phi, &b_LooseElectron_Phi);
   fChain->SetBranchAddress("LooseElectron_E", LooseElectron_E, &b_LooseElectron_E);
   fChain->SetBranchAddress("LooseElectron_Charge", LooseElectron_Charge, &b_LooseElectron_Charge);
   fChain->SetBranchAddress("LooseElectron_Iso", LooseElectron_Iso, &b_LooseElectron_Iso);
   


   fChain->SetBranchAddress("MET_Px", &MET_Px, &b_MET_Px);
   fChain->SetBranchAddress("MET_Py", &MET_Py, &b_MET_Py);

   fChain->SetBranchAddress("WMuon_MT", &WMuon_MT, &b_WMuon_MT);
   fChain->SetBranchAddress("WMuon_Phi", &WMuon_Phi, &b_WMuon_Phi);
   fChain->SetBranchAddress("WElectron_MT", &WElectron_MT, &b_WElectron_MT);
   fChain->SetBranchAddress("WElectron_Phi", &WElectron_Phi, &b_WElectron_Phi);

 //  fChain->SetBranchAddress("MChadronicBottom_px", &MChadronicBottom_px, &b_MChadronicBottom_px);
 //  fChain->SetBranchAddress("MChadronicBottom_py", &MChadronicBottom_py, &b_MChadronicBottom_py);
 //  fChain->SetBranchAddress("MChadronicBottom_pz", &MChadronicBottom_pz, &b_MChadronicBottom_pz);
 //  fChain->SetBranchAddress("MCleptonicBottom_px", &MCleptonicBottom_px, &b_MCleptonicBottom_px);
 //  fChain->SetBranchAddress("MCleptonicBottom_py", &MCleptonicBottom_py, &b_MCleptonicBottom_py);
 //  fChain->SetBranchAddress("MCleptonicBottom_pz", &MCleptonicBottom_pz, &b_MCleptonicBottom_pz);
 //  fChain->SetBranchAddress("MChadronicWDecayQuark_px", &MChadronicWDecayQuark_px, &b_MChadronicWDecayQuark_px);
 //  fChain->SetBranchAddress("MChadronicWDecayQuark_py", &MChadronicWDecayQuark_py, &b_MChadronicWDecayQuark_py);
 //  fChain->SetBranchAddress("MChadronicWDecayQuark_pz", &MChadronicWDecayQuark_pz, &b_MChadronicWDecayQuark_pz);
 //  fChain->SetBranchAddress("MChadronicWDecayQuarkBar_px", &MChadronicWDecayQuarkBar_px, &b_MChadronicWDecayQuarkBar_px);
 //  fChain->SetBranchAddress("MChadronicWDecayQuarkBar_py", &MChadronicWDecayQuarkBar_py, &b_MChadronicWDecayQuarkBar_py);
 //  fChain->SetBranchAddress("MChadronicWDecayQuarkBar_pz", &MChadronicWDecayQuarkBar_pz, &b_MChadronicWDecayQuarkBar_pz);
 //  fChain->SetBranchAddress("MClepton_px", &MClepton_px, &b_MClepton_px);
 //  fChain->SetBranchAddress("MClepton_py", &MClepton_py, &b_MClepton_py);
 //  fChain->SetBranchAddress("MClepton_pz", &MClepton_pz, &b_MClepton_pz);
 //  fChain->SetBranchAddress("MCleptonPDGid", &MCleptonPDGid, &b_MCleptonPDGid);
 //  fChain->SetBranchAddress("MCneutrino_px", &MCneutrino_px, &b_MCneutrino_px);
 //  fChain->SetBranchAddress("MCneutrino_py", &MCneutrino_py, &b_MCneutrino_py);
 //  fChain->SetBranchAddress("MCneutrino_pz", &MCneutrino_pz, &b_MCneutrino_pz);
 //  fChain->SetBranchAddress("NPrimaryVertices", &NPrimaryVertices, &b_NPrimaryVertices);
 //  fChain->SetBranchAddress("triggerIsoMu24", &triggerIsoMu24, &b_triggerIsoMu24);
   fChain->SetBranchAddress("PUWeight", &PUWeight, &b_PUWeight);
   
   TotalEvents = 0;
}

Bool_t MyAnalysis::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.
   
   return kTRUE;
}

#endif // #ifdef MyAnalysis_cxx
