#include "MyAnalysis.h"
#include "Plotter.h"
#include <iostream>
#include <TChain.h>
#include <TGraphAsymmErrors.h>
#include <string>

int main() {
   
   float lumi = 1000.;
   
   TString dir = "/xrootd/store/user/tjkim/ntuples/hep2016/V1";

   int nevt = 1000;

   MyAnalysis *A = new MyAnalysis();
   TChain* ch = new TChain("TopTree/events");
   ch->Add(Form("%s/hep_data.root",dir.Data()), nevt);
   ch->Process(A,"data");

   MyAnalysis *B = new MyAnalysis(1,1,831.8,lumi);
   TChain* ch2 = new TChain("TopTree/events");
   ch2->Add(Form("%s/hep_TT_powheg.root",dir.Data()), nevt);
   ch2->Process(B,"TT_powheg");

   MyAnalysis *C = new MyAnalysis(1,1,61524,lumi);
   TChain* ch3 = new TChain("TopTree/events");
   ch3->Add(Form("%s/hep_WJets.root",dir.Data()),nevt);
   ch3->Process(C,"WJets");
   
   MyAnalysis *D = new MyAnalysis(1,1,6025.2,lumi);
   TChain* ch4 = new TChain("TopTree/events");
   ch4->Add(Form("%s/hep_DYJets.root",dir.Data()),nevt);
   ch4->Process(D,"DYJets");

/* 
   MyAnalysis *E = new MyAnalysis(1,1,18610.0,lumi);
   TChain* ch5 = new TChain("TopTree/events");
   ch5->Add(Form("%s/hep_DYJets_10to50.root",dir.Data()),nevt);
   ch5->Process(E,"DYJets_10to50");
 
   MyAnalysis *I = new MyAnalysis(1,1,44.33,lumi);
   TChain* ch6 = new TChain("TopTree/events");
   ch6->Add(Form("%s/hep_SingleTop_t.root",dir.Data()),nevt);
   ch6->Process(I,"SingleTop_t");

   MyAnalysis *J = new MyAnalysis(1,1,26.38,lumi);
   TChain* ch7 = new TChain("TopTree/events");
   ch7->Add(Form("%s/hep_SingleTbar_t.root",dir.Data()),nevt);
   ch7->Process(J,"SingleTbar_t");

   MyAnalysis *K = new MyAnalysis(1,1,35.6,lumi);
   TChain* ch8 = new TChain("TopTree/events");
   ch8->Add(Form("%s/hep_SingleTop_tW.root",dir.Data()),nevt);
   ch8->Process(K,"SingleTop_tW");
*/

   //Plotter P;
   //cout << "plot declare " << endl;
//   for (int i=0; i < D->histograms.size() ;i++) {
     //merge for DY
//     D->histograms[i]->Add(E->histograms[i]);
     //merge for SingleTop
//     I->histograms[i]->Add(J->histograms[i]);
//     I->histograms[i]->Add(K->histograms[i]);
//   } 

 
   //P.SetData(A->histograms, std::string("Data"));
   //P.AddBg(B->histograms, std::string("TTbar"));
   //P.AddBg(C->histograms, std::string("Wjets"));
   //P.AddBg(D->histograms, std::string("DY"));

   //P.AddBg(E->histograms, std::string("DY20to50"));
   //P.AddBg(I->histograms, std::string("Single Top"));
   //P.AddBg(I->histograms, std::string("single Top-t"));
   //P.AddBg(J->histograms, std::string("single Tbar-t"));
   //P.AddBg(K->histograms, std::string("single Top-tW"));
 
   //cout << "pdf" <<endl;
  
   //P.Plot(string("results.pdf"));
   //P.Plot("results.pdf");

   //cout << "plot" << endl;

}
