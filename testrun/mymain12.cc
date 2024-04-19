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
  pythia.readString("25:m0=160");
 // pythia.readString("25:mWidth=40");
  pythia.readString("25:mMin=140");
  pythia.readString("25:mMax=180");
 // pythia.readString("Higgs:cubicWidth= on");
  pythia.readString("Higgs:useBSM = off");
  pythia.readString("25:onMode = off");
  pythia.readString("25:onIfAny = 24 -24 ");
  pythia.readString("24:onMode = off");
  pythia.readString("24:onIfAny = -13 14"); 
  pythia.readString("-24:onMode = off");
  pythia.readString("-24:onIfAny = 13 -14 ");  
  
  
pythia.init();
  TFile* outFile = new TFile("reconw.root", "RECREATE");
//TH1F *h1 = new TH1F("h1","Muon pt", 100,0.0,100.0);
//TH1F *h2 = new TH1F("h2","Anti Muon pt", 100,0.0,100.0);
TH1F *h3 = new TH1F("h3","W+ mass", 120,0.0,120.0);
TH1F *h4 = new TH1F("h4","W- mass", 120,0.0,120.0);
TH1F *h5 = new TH1F("h5","Higgs mass", 200,0.0,200.0);

int nevents=100000;
int i;
float e1,pt1,px1,py1,pz1;
float e2,pt2,px2,py2,pz2;
float ve1,vpt1,vpx1,vpy1,vpz1;
float ve2,vpt2,vpx2,vpy2,vpz2;
float mh,mwp,mwm;

for (int iEvent = 0; iEvent < nevents; ++iEvent) 
{
 	  if (!pythia.next()) continue;
 	
 for (i = 0; i < pythia.event.size(); ++i) 
 {
  if(pythia.event[i].id()==13 && pythia.event[i].pT()>=35 && pythia.event[i].pT()<=45)
  {
   e1=pythia.event[i].e();
   px1=pythia.event[i].px();
   py1=pythia.event[i].py();
   pz1=pythia.event[i].pz();
  //pt1=pythia.event[i].pT();
  //h1->Fill(pt1);
  }

    if(pythia.event[i].id()==-13 && pythia.event[i].pT()>=35 && pythia.event[i].pT()<=45)
  {
   e2=pythia.event[i].e();
   px2=pythia.event[i].px();
   py2=pythia.event[i].py();
   pz2=pythia.event[i].pz();
   //pt2=pythia.event[i].pT();
  // h2->Fill(pt2);
  }
  
    if(pythia.event[i].id()==14 && pythia.event[i].pT()>=35 && pythia.event[i].pT()<=45)
  {
   ve1=pythia.event[i].e();
   vpx1=pythia.event[i].px();
   vpy1=pythia.event[i].py();
   vpz1=pythia.event[i].pz();
   //vpt1=pythia.event[i].pT();
  // h3->Fill(vpt1);
  }
  
  if(pythia.event[i].id()==-14 && pythia.event[i].pT()>=35 && pythia.event[i].pT()<=45)
  {
   ve2=pythia.event[i].e();
   vpx2=pythia.event[i].px();
   vpy2=pythia.event[i].py();
   vpz2=pythia.event[i].pz();
 //  vpt2=pythia.event[i].pT();
  // h4->Fill(vpt2);
   continue;
  }
 }
 mwp=sqrt(pow(e2+ve1,2)-pow(px2+vpx1,2)-pow(py2+vpy1,2)-pow(pz2+vpz1,2));
 mwm=sqrt(pow(e1+ve2,2)-pow(px1+vpx2,2)-pow(py1+vpy2,2)-pow(pz1+vpz2,2));
mh=sqrt(pow(e1+ve2,2)-pow(px1+vpx2,2)-pow(py1+vpy2,2)-pow(pz1+vpz2,2))+sqrt(pow(e2+ve1,2)-pow(px2+vpx1,2)-pow(py2+vpy1,2)-pow(pz2+vpz1,2));
h3->Fill(mwp);
h4->Fill(mwm);
h5->Fill(mh);
}
pythia.stat();
// h1->Write();
// h2->Write();
 h3->Write();
 h4->Write();
 h5->Write();
  delete outFile;
return 0;
}
