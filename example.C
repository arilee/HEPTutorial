#include "MyAnalysis.h"
#include "Plotter.h"
#include <iostream>
#include <TChain.h>
#include <TGraphAsymmErrors.h>
#include <string>

int main() {
   
   float lumi = 50.;
   
   MyAnalysis *A = new MyAnalysis();
   TChain* ch = new TChain("events");
   ch->Add("files/data.root");
   ch->Process(A,"data");
   
   MyAnalysis *B = new MyAnalysis();
   TChain* ch2 = new TChain("events");
   ch2->Add("files/ttbar.root");
   ch2->Process(B,"ttbar");
   
   MyAnalysis *C = new MyAnalysis();
   TChain* ch3 = new TChain("events");
   ch3->Add("files/wjets.root");
   ch3->Process(C,"wjets");
   
   MyAnalysis *D = new MyAnalysis();
   TChain* ch4 = new TChain("events");
   ch4->Add("files/dy.root");
   ch4->Process(D,"dy");
   
   MyAnalysis *E = new MyAnalysis();
   TChain* ch5 = new TChain("events");
   ch5->Add("files/ww.root");
   ch5->Process(E,"ww");

   MyAnalysis *F = new MyAnalysis();
   TChain* ch6 = new TChain("events");
   ch6->Add("files/wz.root");
   ch6->Process(F,"wz");

   MyAnalysis *G = new MyAnalysis();
   TChain* ch7 = new TChain("events");
   ch7->Add("files/zz.root");
   ch7->Process(G,"zz");

   MyAnalysis *H = new MyAnalysis();
   TChain* ch8 = new TChain("events");
   ch8->Add("files/qcd.root");
   ch8->Process(H,"qcd");
   
   MyAnalysis *I = new MyAnalysis();
   TChain* ch9 = new TChain("events");
   ch9->Add("files/single_top.root");
   ch9->Process(I,"single_top");

   Plotter P;
   P.SetData("hists/hist_data.root", std::string("Data"));
   P.AddBg("hists/hist_ttbar.root", std::string("TTbar"));
   P.AddBg("hists/hist_wjets.root", std::string("Wjets"));
   P.AddBg("hists/hist_dy.root", std::string("DY"));
   P.AddBg("hists/hist_ww.root", std::string("WW"));
   P.AddBg("hists/hist_wz.root", std::string("WZ"));
   P.AddBg("hists/hist_zz.root", std::string("ZZ"));
   P.AddBg("hists/hist_qcd.root", std::string("QCD"));
   P.AddBg("hists/hist_single_top.root", std::string("single Top"));
   
   P.Plot(string("results.pdf"));

}
