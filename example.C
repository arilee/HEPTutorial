#include "MyAnalysis.h"
#include "Plotter.h"
#include <iostream>
#include <TChain.h>
#include <TGraphAsymmErrors.h>
#include <string>

int main() {
   
   float lumi = 2260.;
   
   TString dir = "/xrootd/store/user/tjkim/ntuples/hep/V6";
   TFile * fB = TFile::Open(dir+"/hep_TT_powheg.root");
   TFile * fC = TFile::Open(dir+"/hep_WJets.root");
   TFile * fD = TFile::Open(dir+"/hep_DYJets.root");
   TFile * fE = TFile::Open(dir+"/hep_DYJets_10to50.root");
   TFile * fI = TFile::Open(dir+"/hep_SingleTop_t.root");
   TFile * fJ = TFile::Open(dir+"/hep_SingleTbar_t.root");
   TFile * fK = TFile::Open(dir+"/hep_SingleTop_tW.root");
   TH1F * hB = (TH1F*) fB->Get("TopTree/EventSummary");
   TH1F * hC = (TH1F*) fC->Get("TopTree/EventSummary");
   TH1F * hD = (TH1F*) fD->Get("TopTree/EventSummary");
   TH1F * hE = (TH1F*) fE->Get("TopTree/EventSummary");
   TH1F * hI = (TH1F*) fI->Get("TopTree/EventSummary");
   TH1F * hJ = (TH1F*) fJ->Get("TopTree/EventSummary");
   TH1F * hK = (TH1F*) fK->Get("TopTree/EventSummary");

   int nevt = -1;
   MyAnalysis *A = new MyAnalysis();
   TChain* ch = new TChain("TopTree/events");
   ch->Add(Form("%s/hep_data_json.root",dir.Data()), nevt);
   ch->Process(A);

   MyAnalysis *B = new MyAnalysis(1,1,831.8,lumi,hB->GetBinContent(1));
   TChain* ch2 = new TChain("TopTree/events");
   ch2->Add(Form("%s/hep_TT_powheg.root",dir.Data()), nevt);
   ch2->Process(B);

   MyAnalysis *C = new MyAnalysis(1,1,61524,lumi,hC->GetBinContent(2));
   TChain* ch3 = new TChain("TopTree/events");
   ch3->Add(Form("%s/hep_WJets.root",dir.Data()),nevt);
   ch3->Process(C);
   
   MyAnalysis *D = new MyAnalysis(1,1,6025.2,lumi,hD->GetBinContent(1));
   TChain* ch4 = new TChain("TopTree/events");
   ch4->Add(Form("%s/hep_DYJets.root",dir.Data()),nevt);
   ch4->Process(D);
  
   MyAnalysis *E = new MyAnalysis(1,1,18610.0,lumi,hE->GetBinContent(1));
   TChain* ch5 = new TChain("TopTree/events");
   ch5->Add(Form("%s/hep_DYJets_10to50.root",dir.Data()),nevt);
   ch5->Process(E);
 
   MyAnalysis *I = new MyAnalysis(1,1,44.33,lumi,hI->GetBinContent(1));
   TChain* ch6 = new TChain("TopTree/events");
   ch6->Add(Form("%s/hep_SingleTop_t.root",dir.Data()),nevt);
   ch6->Process(I);

   MyAnalysis *J = new MyAnalysis(1,1,26.38,lumi,hJ->GetBinContent(1));
   TChain* ch7 = new TChain("TopTree/events");
   ch7->Add(Form("%s/hep_SingleTbar_t.root",dir.Data()),nevt);
   ch7->Process(J);

   MyAnalysis *K = new MyAnalysis(1,1,35.6,lumi,hK->GetBinContent(1));
   TChain* ch8 = new TChain("TopTree/events");
   ch8->Add(Form("%s/hep_SingleTop_tW.root",dir.Data()),nevt);
   ch8->Process(K);

   Plotter P;

   for (int i=0; i < D->histograms.size() ;i++) {
     //merge for DY
     D->histograms[i]->Add(E->histograms[i]);
     //merge for SingleTop
     I->histograms[i]->Add(J->histograms[i]);
     I->histograms[i]->Add(K->histograms[i]);
   } 

 
   P.SetData(A->histograms, std::string("Data"));
   P.AddBg(B->histograms, std::string("TTbar"));
   P.AddBg(C->histograms, std::string("Wjets"));

   P.AddBg(D->histograms, std::string("DY"));
   //P.AddBg(E->histograms, std::string("DY20to50"));

   P.AddBg(I->histograms, std::string("Single Top"));
   //P.AddBg(I->histograms, std::string("single Top-t"));
   //P.AddBg(J->histograms, std::string("single Tbar-t"));
   //P.AddBg(K->histograms, std::string("single Top-tW"));
 
  
   P.Plot(string("results.pdf"));


   TFile * outA = TFile::Open("hist_data.root","RECREATE");
   for(int i=0; i < A->histograms.size(); i++){
     TH1F * tmp = (TH1F *) A->histograms[i];
     tmp->Write();
   }
   outA->Write();
   outA->Close();

   TFile * outB = TFile::Open("hist_TT_powheg.root","RECREATE");
   for(int i=0; i < B->histograms.size(); i++){
     TH1F * tmp = (TH1F *) B->histograms[i];
     tmp->Write();
   }
   outB->Write();
   outB->Close();

   TFile * outC = TFile::Open("hist_WJets.root","RECREATE");
   for(int i=0; i < C->histograms.size(); i++){
     TH1F * tmp = (TH1F *) C->histograms[i];
     tmp->Write();
   }
   outC->Write();
   outC->Close();

   TFile * outD = TFile::Open("hist_DY.root","RECREATE");
   for(int i=0; i < D->histograms.size(); i++){
     TH1F * tmp = (TH1F *) D->histograms[i];
     tmp->Write();
   }
   outD->Write();
   outD->Close();

//   TFile * outE = TFile::Open("hist_DY20to50.root","RECREATE");
//   for(int i=0; i < E->histograms.size(); i++){
//     TH1F * tmp = (TH1F *) E->histograms[i];
//     tmp->Write();
//   }
//   outE->Write();
//   outE->Close();

    TFile * outI = TFile::Open("hist_SingleTop.root","RECREATE");
    for(int i=0; i < I->histograms.size(); i++){
      TH1F * tmp = (TH1F *) I->histograms[i];
      tmp->Write();
    }
    outI->Write();
    outI->Close();


//   TFile * outI = TFile::Open("hist_SingleTop_t.root","RECREATE");
//   for(int i=0; i < I->histograms.size(); i++){
//     TH1F * tmp = (TH1F *) I->histograms[i];
//     tmp->Write();
//   }
//   outI->Write();
//   outI->Close();
 
//   TFile * outJ = TFile::Open("hist_SingleTbar_t.root","RECREATE");
//   for(int i=0; i < J->histograms.size(); i++){
//     TH1F * tmp = (TH1F *) J->histograms[i];
//     tmp->Write();
//   }
//   outJ->Write();
//   outJ->Close();

//   TFile * outK = TFile::Open("hist_SingleTop_tW.root","RECREATE");
//   for(int i=0; i < K->histograms.size(); i++){
//     TH1F * tmp = (TH1F *) K->histograms[i];
//     tmp->Write();
//   }
//   outK->Write();
//   outK->Close();


}
