#define MyAnalysis_cxx
// The class definition in MyAnalysis.h has been generated automatically
// by the ROOT utility TTree::MakeSelector(). This class is derived
// from the ROOT class TSelector. For more information on the TSelector
// framework see $ROOTSYS/README/README.SELECTOR or the ROOT User Manual.

// The following methods are defined in this file:
//    Begin():        called every time a loop on the tree starts,
//                    a convenient place to create your histograms.
//    SlaveBegin():   called after Begin(), when on PROOF called only on the
//                    slave servers.
//    Process():      called for each event, in this function you decide what
//                    to read and fill your histograms.
//    SlaveTerminate: called at the end of the loop on the tree, when on PROOF
//                    called only on the slave servers.
//    Terminate():    called at the end of the loop on the tree,
//                    a convenient place to draw/fit your histograms.
//
// To use this file, try the following session on your Tree T:
//
// Root > T->Process("MyAnalysis.C")
// Root > T->Process("MyAnalysis.C","some options")
// Root > T->Process("MyAnalysis.C+")
//

#include "MyAnalysis.h"
#include <iostream>
#include <TH1F.h>
#include <TLatex.h>

using namespace std;

void MyAnalysis::BuildEvent() {
   
   Muons.clear();
   for (int i = 0; i < NMuon; ++i) {
      MyMuon muon(Muon_Pt[i], Muon_Eta[i], Muon_Phi[i], Muon_E[i]);
      muon.SetIsolation(Muon_Iso[i]);
      muon.SetCharge(Muon_Charge[i]);
      Muons.push_back(muon);
   }
   
   Electrons.clear();
   for (int i = 0; i < NElectron; ++i) {
      MyElectron electron(Electron_Pt[i], Electron_Eta[i], Electron_Phi[i], Electron_E[i]);
      electron.SetIsolation(Electron_Iso[i]);
      electron.SetCharge(Electron_Charge[i]);
      Electrons.push_back(electron);
   }
   
   Photons.clear();
   for (int i = 0; i < NPhoton; ++i) {
      MyPhoton photon(Photon_Pt[i], Photon_Eta[i], Photon_Phi[i], Photon_E[i]);
      photon.SetIsolation(Photon_Iso[i]);
      Photons.push_back(photon);
   }
   
   Jets.clear();
   for (int i = 0; i < NJet; ++i) {
      MyJet jet(Jet_Pt[i], Jet_Eta[i], Jet_Phi[i], Jet_E[i]);
      jet.SetBTagDiscriminator(Jet_bDiscriminator[i]);
      //jet.SetJetID(Jet_ID[i]);
      Jets.push_back(jet);
   }
   
   //hadB.SetXYZM(MChadronicBottom_px, MChadronicBottom_py, MChadronicBottom_pz, 4.8);
   //lepB.SetXYZM(MCleptonicBottom_px, MCleptonicBottom_py, MCleptonicBottom_pz, 4.8);
   //hadWq.SetXYZM(MChadronicWDecayQuark_px, MChadronicWDecayQuark_py, MChadronicWDecayQuark_pz, 0.0);
   //hadWqb.SetXYZM(MChadronicWDecayQuarkBar_px, MChadronicWDecayQuarkBar_py, MChadronicWDecayQuarkBar_pz, 0.0);
   //lepWl.SetXYZM(MClepton_px, MClepton_py, MClepton_pz, 0.0);
   //lepWn.SetXYZM(MCneutrino_px, MCneutrino_py, MCneutrino_pz, 0.0);
   met.SetXYZM(MET_Px, MET_Py, 0., 0.);
   
   PUWeight *= weight_factor*norm_scale;
   
}

void MyAnalysis::Begin(TTree * /*tree*/) {
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).
   
   TString option = GetOption();
   
}

void MyAnalysis::SlaveBegin(TTree * /*tree*/) {
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).
   
   TString option = GetOption();
   
   h_Mmumu = new TH1F("h_Mmumu", "Invariant di-muon mass", 100, 40, 140);
   h_Mmumu->SetXTitle("m_{#mu#mu}");
   h_Mmumu->Sumw2();
   histograms.push_back(h_Mmumu);
   histograms_MC.push_back(h_Mmumu);
   
   h_NMuon = new TH1F("h_NMuon", "Number of muons", 7, 0, 7);
   h_NMuon->SetXTitle("No. Muons");
   h_NMuon->Sumw2();
   histograms.push_back(h_NMuon);
   histograms_MC.push_back(h_NMuon);
  
   h_WMuon_MT = new TH1F("h_WMuon_MT", "Transverse mass", 60, 0, 120);
   h_WMuon_MT->SetXTitle("MT(Gev)");
   h_WMuon_MT->Sumw2();
   histograms.push_back(h_WMuon_MT);
   histograms_MC.push_back(h_WMuon_MT);

   h_WMuon_Phi = new TH1F("h_WMuon_Phi", "DR between muon and MET", 70, 0, 3.5);
   h_WMuon_Phi->SetXTitle("DR between muon and MET");
   h_WMuon_Phi->Sumw2();
   histograms.push_back(h_WMuon_Phi);
   histograms_MC.push_back(h_WMuon_Phi);

   h_NJet = new TH1F("h_NJet", "Number of jets", 14, 0, 14);
   h_NJet->SetXTitle("No. Jets");
   h_NJet->Sumw2();
   histograms.push_back(h_NJet);
   histograms_MC.push_back(h_NJet);

   h_NBJet = new TH1F("h_NBJet", "Number of b jets after jet selection", 5, 0, 5);
   h_NBJet->SetXTitle("No. b Jets");
   h_NBJet->Sumw2();
   histograms.push_back(h_NBJet);
   histograms_MC.push_back(h_NBJet);

   h_WMuon_MT_Final = new TH1F("h_WMuon_MT_Final", "Transverse mass", 60, 0, 120);
   h_WMuon_MT_Final->SetXTitle("MT(Gev)");
   h_WMuon_MT_Final->Sumw2();
   histograms.push_back(h_WMuon_MT_Final);
   histograms_MC.push_back(h_WMuon_MT_Final);

}

Bool_t MyAnalysis::Process(Long64_t entry) {
   // The Process() function is called for each entry in the tree (or possibly
   // keyed object in the case of PROOF) to be processed. The entry argument
   // specifies which entry in the currently loaded tree is to be processed.
   // It can be passed to either MyAnalysis::GetEntry() or TBranch::GetEntry()
   // to read either all or the required parts of the data. When processing
   // keyed objects with PROOF, the object is already loaded and is available
   // via the fObject pointer.
   //
   // This function should contain the "body" of the analysis. It can contain
   // simple or elaborate selection criteria, run algorithms on the data
   // of the event and typically fill histograms.
   //
   // The processing can be stopped by calling Abort().
   //
   // Use fStatus to set the return value of TTree::Process().
   //
   // The return value is currently not used.
   
   ++TotalEvents;
   
   GetEntry(entry);
   
   if (TotalEvents % 100000 == 0)
      cout << "Next event -----> " << TotalEvents << endl;
   
   BuildEvent();

   double MuonPtCut = 39.;
   double MuonRelIsoCut = 0.12;
   
   //   cout << "Jets: " << endl;
   //   for (vector<MyJet>::iterator it = Jets.begin(); it != Jets.end(); ++it) {
   //      cout << "pt, eta, phi, btag, id: " << it->Pt() << ", " << it->Eta() << ", " << it->Phi() << ", " << it->IsBTagged() << ", " << it->GetJetID() //      << endl;
   //   }
   //   cout << "Muons: " << endl;
   //   for (vector<MyMuon>::iterator it = Muons.begin(); it != Muons.end(); ++it) {
   //      cout << "pt, eta, phi, iso, charge: " << it->Pt() << ", " << it->Eta() << ", " << it->Phi() << ", "
   //      << it->GetIsolation() << ", " << it->GetCharge() << endl;
   //   }
   //   cout << "Electrons: " << endl;
   //   for (vector<MyElectron>::iterator it = Electrons.begin(); it != Electrons.end(); ++it) {
   //      cout << "pt, eta, phi, iso, charge: " << it->Pt() << ", " << it->Eta() << ", " << it->Phi() << ", "
   //      << it->GetIsolation() << ", " << it->GetCharge() << endl;
   //   }
   //   cout << "Photons: " << endl;
   //   for (vector<MyPhoton>::iterator it = Photons.begin(); it != Photons.end(); ++it) {
   //      cout << "pt, eta, phi, iso: " << it->Pt() << ", " << it->Eta() << ", " << it->Phi() << ", " << it->GetIsolation()
   //      << endl;
   //   }
   
   
   //////////////////////////////
   // Exercise 1: Invariant Di-Muon mass
    
   int N_IsoMuon = 0;
   MyMuon *muon1, *muon2;
 
   float mt = 0.0; 
   float dphi = 0.0;
   int imu = 0; 

   for (vector<MyMuon>::iterator jt = Muons.begin(); jt != Muons.end(); ++jt) {
      if (jt->Pt() > MuonPtCut && jt->IsIsolated(MuonRelIsoCut)) {
         ++N_IsoMuon;
         if (N_IsoMuon == 1) { 
           muon1 = &(*jt);
           mt = WMuon_MT[imu]; 
           dphi = WMuon_Phi[imu];
         }
         if (N_IsoMuon == 2) muon2 = &(*jt);
      }
      imu++; 
   }
  
   h_NMuon->Fill(N_IsoMuon, PUWeight);

   if (N_IsoMuon > 1 ) {
     h_Mmumu->Fill((*muon1 + *muon2).M(), PUWeight);
   }
   //////////////////////////////
   
   if(N_IsoMuon == 1 && (NLooseMuon + NLooseElectron) < 2){
     h_WMuon_MT->Fill( mt, PUWeight);
     h_WMuon_Phi->Fill( dphi, PUWeight);
     h_NJet->Fill(NJet, PUWeight);

     if( NJet > 3){
       h_NBJet->Fill(NBJet, PUWeight);
     }

     if( NBJet > 1 ){
       h_WMuon_MT_Final->Fill(mt, PUWeight);
     } 
   }
 

   return kTRUE;
}

void MyAnalysis::SlaveTerminate() {
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.
   
}

void MyAnalysis::Terminate() {
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.
   
}
