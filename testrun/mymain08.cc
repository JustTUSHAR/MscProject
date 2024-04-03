#include<fstream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "Pythia8/Pythia.h"
#include "Pythia8/HeavyIons.h"
#include "TH1.h"
#include "TVirtualPad.h"
#include "TApplication.h"
#include "TFile.h"
#include "TMath.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "THStack.h"

using namespace Pythia8;
int main(int argc, char* argv[]) {

TApplication theApp("hist", &argc, argv);
Pythia pythia;

  pythia.readString("Beams:eCM = 13000");
  pythia.readString("Beams:idA = 2212");
  pythia.readString("Beams:idB = 2212");                             //MODIFY ROOT FILE NAME
 // pythia.readString("Beams:idA = 1000822080");
//  pythia.readString("Beams:idB = 1000822080");
  
  pythia.readString("Random:setSeed = on");
  pythia.readString("Random:seed = 0");

  pythia.readString("HiggsSM:all = on");   
  pythia.readString("Higgs:useBSM = off");

  pythia.readString("25:onMode = off");
  pythia.readString("25:onIfAny = 24 -24 ");
  
  pythia.readString("24:onMode = off");
  pythia.readString("24:onIfAny = -13 14");
  
  pythia.readString("-24:onMode = off");
  pythia.readString("-24:onIfAny = 13 -14 ");

float xEdges[36] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,25,30,34,38,42,46,50,60,70,80,90,100,110,120,130};

pythia.init();
TFile* outFile = new TFile("ptu_var.root", "RECREATE");
//TFile* outFile = new TFile("pb_ptu_var.root", "RECREATE");  
TH1F *h1 = new TH1F("h1","muon transverse momentum(In GeV) (In channel H->WW->2u+2v) for 0.2 million events", 130,0.0, 130.0);
TH1F *h2 = new TH1F("h2","muon+ transverse momentum(In GeV) (In channel H->WW->2u+2v) for 0.2 million events", 130,0.0, 130.0);
int nevents=200000;
int i,j,l=0,m=0,k;
float ptu[200],ptup[200];
float errh1[130],errh2[130],errh3[130],h1co[130],h2co[130]; 

for (int iEvent = 0; iEvent < nevents; ++iEvent) 
{
 	  if (!pythia.next()) continue;
 	  l=0; m=0;
 for (i = 0; i < pythia.event.size(); ++i) 
 {
  if(pythia.event[i].id()==-13)
  {
   ptup[l]=pythia.event[i].pT();
   h2->Fill(0.1081011*ptup[l]);
   l++;
  }
    if(pythia.event[i].id()==13)
  {
   ptu[m]=pythia.event[i].pT();
   h1->Fill(ptu[m]);
   m++;
  }
 }
}

TH1F *h3 = (TH1F*)h1->Clone("h3");
h3->Divide(h2);

for(i=0;i<130;i++)
{
errh1[i]=h1->GetBinError(i);
h1co[i]=h1->GetBinContent(i);
errh2[i]=h2->GetBinError(i);
h2co[i]=h2->GetBinContent(i);
errh3[i]=errh1[i]/h2co[i]+(h1co[i]*errh2[i])/(h2co[i]*h2co[i]);
h3->SetBinError(i,errh3[i]);
}
TH1F *h4 = (TH1F*)h3->Clone("h4");
h4->SetTitle("Ratio of muon and muon+ transverse momentum(In GeV) (In channel H->WW->2u+2v) for 0.2 million events for constant binning");
h3->GetXaxis()->Set(35,xEdges);
h3->SetTitle("Ratio of muon and muon+ transverse momentum(In GeV) (In channel H->WW->2u+2v) for 0.2 million events for variable binning");
pythia.stat();

 h1->Write();
 h2->Write();
 h3->Write();
 h4->Write();
 delete outFile;

return 0;
}
