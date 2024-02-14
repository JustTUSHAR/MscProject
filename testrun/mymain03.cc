#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "Pythia8/Pythia.h"
#include "TH1.h"
#include "TVirtualPad.h"
#include "TApplication.h"
#include "TFile.h"
#include "TMath.h"
#include "TCanvas.h"
#include "THStack.h"
#include "TGraph.h"
#include "RooNumber.h"

using namespace Pythia8;
int main(int argc, char* argv[]) {

TApplication theApp("hist", &argc, argv);
Pythia pythia;  
  pythia.readString("Beams:idA = 1000791970");
  pythia.readString("Beams:idB = 1000791970");
  pythia.readString("Beams:eCM = 13000");
  
  //pythia.readString("Beams:idB = 2212");
  
//  pythia.readString("Random:setSeed = on");
 // pythia.readString("Random:seed = 0");

  //pythia.readString("HardQCD:all = on");
  //pythia.readString("SoftQCD:all = on");
  pythia.readString("HiggsSM:all = on");   
  pythia.readString("Higgs:useBSM = off");
   
pythia.init();
  TFile* outFile = new TFile("muAu_ratio.root", "RECREATE");

  TH1F *h1 = new TH1F("h1","mu+ mu- ratio in each event (For pp collision)", 100,-10.0, 10.0);

int nevents=20000,i,mup=0,mum=0;
float ratio;
for (int iEvent = 0; iEvent < nevents; ++iEvent) 
{
 	  if (!pythia.next()) continue;
 	 mup=0; mum=0;
 for (i = 0; i < pythia.event.size(); ++i) 
 {
 	if(pythia.event[i].id()==13) mup++;  
 	if(pythia.event[i].id()==-13) mum--;
 }
 if(mum!=0)
 {
 ratio=mup/mum;
 h1->Fill(ratio);}
}
h1->Draw();
h1->Write();
pythia.stat();
gPad->WaitPrimitive();
delete outFile;
return 0;
}
