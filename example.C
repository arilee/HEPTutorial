#include "MyAnalysis.h"
#include "Plotter.h"
#include <iostream>
#include <TChain.h>
#include <TGraphAsymmErrors.h>
#include <string>

int main() {
   
   float lumi = 2300.;
   
   TString dir = "/xrootd/store/user/tjkim/ntuples/hep/V3";
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

   MyAnalysis *A = new MyAnalysis();
   TChain* ch = new TChain("TopTree/events");
   ch->Add(Form("%s/hep_data_json.root",dir.Data()));
   ch->Process(A);

   MyAnalysis *B = new MyAnalysis(1,1,831.8,lumi,hB->GetBinContent(1));
   TChain* ch2 = new TChain("TopTree/events");
   ch2->Add(Form("%s/hep_TT_powheg.root",dir.Data()));
   ch2->Process(B);

   MyAnalysis *C = new MyAnalysis(1,1,61524,lumi,hC->GetBinContent(1));
   TChain* ch3 = new TChain("TopTree/events");
   ch3->Add(Form("%s/hep_WJets.root",dir.Data()));
   ch3->Process(C);
   
   MyAnalysis *D = new MyAnalysis(1,1,6025.2,lumi,hD->GetBinContent(1));
   TChain* ch4 = new TChain("TopTree/events");
   ch4->Add(Form("%s/hep_DYJets.root",dir.Data()));
   ch4->Process(D);
  
   MyAnalysis *E = new MyAnalysis(1,1,18610.0,lumi,hE->GetBinContent(1));
   TChain* ch5 = new TChain("TopTree/events");
   ch5->Add(Form("%s/hep_DYJets_10to50.root",dir.Data()));
   ch5->Process(E);
 
   MyAnalysis *I = new MyAnalysis(1,1,136.02,lumi,hI->GetBinContent(1));
   TChain* ch6 = new TChain("TopTree/events");
   ch6->Add(Form("%s/hep_SingleTop_t.root",dir.Data()));
   ch6->Process(I);

   MyAnalysis *J = new MyAnalysis(1,1,80.95,lumi,hJ->GetBinContent(1));
   TChain* ch7 = new TChain("TopTree/events");
   ch7->Add(Form("%s/hep_SingleTbar_t.root",dir.Data()));
   ch7->Process(J);

   MyAnalysis *K = new MyAnalysis(1,1,35.6,lumi,hK->GetBinContent(1));
   TChain* ch8 = new TChain("TopTree/events");
   ch8->Add(Form("%s/hep_SingleTop_tW.root",dir.Data()));
   ch8->Process(K);

   Plotter P;
   P.SetData(A->histograms, std::string("Data"));
   P.AddBg(B->histograms, std::string("TTbar"));
   P.AddBg(C->histograms, std::string("Wjets"));
   P.AddBg(D->histograms, std::string("DY"));
   P.AddBg(E->histograms, std::string("DY20to50"));
//P.AddBg(E->histograms, std::string("WW"));
//P.AddBg(F->histograms, std::string("WZ"));
//P.AddBg(G->histograms, std::string("ZZ"));
//P.AddBg(H->histograms, std::string("QCD"));

   P.AddBg(I->histograms, std::string("single Top-t"));
   P.AddBg(J->histograms, std::string("single Tbar-t"));
   P.AddBg(K->histograms, std::string("single Top-tW"));

   P.Plot(string("results.pdf"));

}
