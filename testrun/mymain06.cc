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
#include "TGraph.h"
#include "THStack.h"

using namespace Pythia8;
int main(int argc, char* argv[]) {

TApplication theApp("hist", &argc, argv);
Pythia pythia;  
  pythia.readString("Beams:eCM = 13000");
  pythia.readString("Beams:idA = 2212");
  pythia.readString("Beams:idB = 2212");
  
  pythia.readString("Random:setSeed = on");
  pythia.readString("Random:seed = 0");

  pythia.readString("HiggsSM:all = on");   
  pythia.readString("Higgs:useBSM = off");
  
  //pythia.readString("25:m0 = 125.02");
  pythia.readString("25:onMode = off");
  pythia.readString("25:onIfAny = 24 -24 ");
  
  pythia.readString("24:onMode = off");
  pythia.readString("24:onIfAny = -13 14");
  
  pythia.readString("-24:onMode = off");
  pythia.readString("-24:onIfAny = 13 -14 ");
  
pythia.init();
  TFile* outFile = new TFile("pt_u.root", "RECREATE");
  
TH1F *h1 = new TH1F("h1","muon transverse momentum(In GeV) (In channel H->WW->2l+2v-) for 0.1 million events", 130,0.0, 130.0);
TH1F *h2 = new TH1F("h2","muon+ transverse momentum(In GeV) (In channel H->WW->2l+2v-) for 0.1 million events", 130,0.0, 130.0);
//TH1F *h3 = new TH1F("h3","Ratio of muon and muon+ transverse momentum(In GeV) (In channel H->WW->2l+2v-) for 20k events", 130,0.0, 130.0);



int nevents=100000;
int i;
float e1,px1,py1,pz1;
float e2,px2,py2,pz2;
float ve1,vpx1,vpy1,vpz1;
float ve2,vpx2,vpy2,vpz2;
float ne1,npx1,npy1,npz1,ne2,npx2,npy2,npz2,rwp,rwm;
float ptu,ptup;
float ratio;
int chk1=0,chk2=0;

for (int iEvent = 0; iEvent < nevents; ++iEvent) 
{
 	  if (!pythia.next()) continue;
 	  chk1=0; chk2=0;
 for (i = 0; i < pythia.event.size(); ++i) 
 {
  if(pythia.event[i].id()==-13)
  {
   e1=pythia.event[i].e();
   px1=pythia.event[i].px();
   py1=pythia.event[i].py();
   pz1=pythia.event[i].pz();
   chk1=1;
  }
  else if(pythia.event[i].id()==14 && chk1==1)
  {
  	ve1=pythia.event[i].e();
  	vpx1=pythia.event[i].px();
  	vpy1=pythia.event[i].py();
  	vpz1=pythia.event[i].pz();
  	chk1=0;
  }
    if(pythia.event[i].id()==13)
  {
   e2=pythia.event[i].e();
   px2=pythia.event[i].px();
   py2=pythia.event[i].py();
   pz2=pythia.event[i].pz();
   chk2=1;
  }
  else if(pythia.event[i].id()==-14 && chk2==1)
  {
  	ve2=pythia.event[i].e();
  	vpx2=pythia.event[i].px();
  	vpy2=pythia.event[i].py();
  	vpz2=pythia.event[i].pz();
  	chk2=0;
  }     
 }

ptup=sqrt(pow(px1,2.0)+pow(py1,2.0));
ptu=sqrt(pow(px2,2.0)+pow(py2,2.0));
if(ptup==0) continue;
ratio=ptu/ptup;


//ne1=e1+ve1;
//npx1=px1+vpx1;
//npy1=py1+vpy1;
//npz1=pz1+vpz1;

//ne2=e2+ve2;
//npx2=px2+vpx2;
//npy2=py2+vpy2;
//npz2=pz2+vpz2;

//rwp=sqrt(pow(ne1,2.0)-pow(npx1,2.0)-pow(npy1,2.0)-pow(npz1,2.0));
//rwm=sqrt(pow(ne2,2.0)-pow(npx2,2.0)-pow(npy2,2.0)-pow(npz2,2.0));

h1->Fill(ptu);
h2->Fill(ptup);
}
pythia.stat();
 TH1F *h3 = (TH1F*)h1->Clone("h3");
h3->SetTitle("Ratio of muon and muon+ transverse momentum(In GeV) (In channel H->WW->2l+2v-) for 0.1 million events");
  h3->Divide(h2);
 h1->Write();
 h2->Write();
 h3->Write();
 delete outFile;

return 0;
}
