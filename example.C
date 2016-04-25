#include "MyAnalysis.h"
#include "Plotter.h"
#include <iostream>
#include <TChain.h>
#include <TGraphAsymmErrors.h>
#include <string>

int main() {
   
   float lumi = 2300.;
   
   TString dir = "/xrootd/store/user/tjkim/ntuples/hep/V1";

   MyAnalysis *A = new MyAnalysis();
   TChain* ch = new TChain("TopTree/events");
   ch->Add(Form("%s/hep_data_json.root",dir.Data()));
   ch->Process(A);
   
   MyAnalysis *B = new MyAnalysis(1,1,831.8,lumi,97994442);
   TChain* ch2 = new TChain("TopTree/events");
   ch2->Add(Form("%s/hep_TT_powheg.root",dir.Data()));
   ch2->Process(B);
   
   MyAnalysis *C = new MyAnalysis(1,1,61524,lumi,24156124);
   TChain* ch3 = new TChain("TopTree/events");
   ch3->Add(Form("%s/hep_WJets.root",dir.Data()));
   ch3->Process(C);
   
   MyAnalysis *D = new MyAnalysis(1,1,6025.2,lumi,114613024);
   TChain* ch4 = new TChain("TopTree/events");
   ch4->Add(Form("%s/hep_DYJets.root",dir.Data()));
   ch4->Process(D);
  
   MyAnalysis *E = new MyAnalysis(1,1,18610.0,lumi,16600229);
   TChain* ch5 = new TChain("TopTree/events");
   ch5->Add(Form("%s/hep_DYJets_10to50.root",dir.Data()));
   ch5->Process(E);
 
   MyAnalysis *I = new MyAnalysis(1,1,136.02,lumi,3299200);
   TChain* ch6 = new TChain("TopTree/events");
   ch6->Add(Form("%s/hep_SingleTop_t.root",dir.Data()));
   ch6->Process(I);

   MyAnalysis *J = new MyAnalysis(1,1,80.95,lumi,1630900);
   TChain* ch7 = new TChain("TopTree/events");
   ch7->Add(Form("%s/hep_SingleTbar_t.root",dir.Data()));
   ch7->Process(J);

   MyAnalysis *K = new MyAnalysis(1,1,35.6,lumi,1950000);
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
