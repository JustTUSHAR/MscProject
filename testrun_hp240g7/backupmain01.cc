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
int main(int argc, char* argv[]) 
{
TApplication theApp("hist", &argc, argv);
Pythia pythia;  
  pythia.readString("Beams:eCM = 13000");
  pythia.readString("Beams:idA = 2212");
  pythia.readString("Beams:idB = 2212");
  pythia.readString("Random:setSeed = on");
  pythia.readString("Random:seed = 0");
  pythia.readString("HiggsSM:all = on");   
  pythia.readString("Higgs:useBSM = off");
  pythia.readString("25:m0 = 125.09");
  pythia.readString("25:onMode = off");
  pythia.readString("25:onIfAny = 22 23 ");
  pythia.readString("23:onMode = off");
  pythia.readString("23:onIfAny = 13 -13 ");
  
pythia.init();
 TH1F *h1 = new TH1F("h1","Z boson mass", 130,0.0, 130.0);

int nevents=10000,i,a=0,b=0,prev=0,prev2=0,p1=0,p2=0;
float m,e,ide,mh,eh,m1,e1,px1,py1,pz1,m2,e2,px2,py2,pz2;

for (int iEvent = 0; iEvent < nevents; iEvent++) 
{
    if (!pythia.next()) continue;
    a=0; prev=0; prev2=0; b=0;
 for (i = 0; i < pythia.event.size(); i++) 
 { a=0;  
   if(pythia.event[i].id()==23 && prev==22)a=1;
      
      if(p1==1 && pythia.event[i].id()==13)
      {
   e1=pythia.event[i].e();
   px1=pythia.event[i].px();
   py1=pythia.event[i].py();
   pz1=pythia.event[i].pz();
      p1=0;
      }
      
      if(p2==1 && pythia.event[i].id()== -13)
      {
   e2=pythia.event[i].e()+e1;
   px2=pythia.event[i].px()+px1;
   py2=pythia.event[i].py()+py1;
   pz2=pythia.event[i].pz()+pz1;
   m1=sqrt(pow(e2,2.0)-pow(px2,2.0)-pow(py2,2.0)-pow(pz2,2.0));
   h1->Fill(m1);
   p2=0;
      }
      
    if(a==1 && b==1)      
     {p1=1;
      p2=1;  }
    
    if(pythia.event[i].id()==25)
    {
   prev2=pythia.event[i].id();
   mh=pythia.event[i].m();
   eh=pythia.event[i].e(); 
    b=1;
    }
    
   prev=pythia.event[i].id();
   ide=pythia.event[i].id();
   m=pythia.event[i].m();
   e=pythia.event[i].e();
 }
}
pythia.stat();
h1->Draw();
gPad->WaitPrimitive();
return 0;
}
