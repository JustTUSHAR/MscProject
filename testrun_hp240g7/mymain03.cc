#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "Pythia8/Pythia.h"
#include "TVirtualPad.h"
#include "TApplication.h"
#include "TLorentzVector.h"
#include "TCanvas.h"
#include "TGraph.h"
using namespace Pythia8;
int main(int argc, char* argv[]) 
{
TApplication theApp("graph",&argc, argv);
Pythia pythia;  
  pythia.readString("Beams:eCM = 13000");
  pythia.readString("Beams:idA = 2212");
  pythia.readString("Beams:idB = 2212");
  pythia.readString("HiggsSM:all = on");   
  pythia.readString("Higgs:useBSM = off");
  pythia.readString("25:m0 = 125.09");
  pythia.readString("25:onMode = off");
  pythia.readString("25:onIfAny = 22 23 ");
  pythia.readString("23:onMode = off");
  pythia.readString("23:onIfAny = 13 -13 ");
  
pythia.init();
TLorentzVector v1,v2;
int nevents=30000,i,a=0,b=0,prev=0,prev2=0,p1=0,p2=0,l=0;
float e,eh,e1,px1,py1,pz1,e2,px2,py2,pz2;
float x[30000],t[30000];

for (int iEvent = 0; iEvent < nevents; iEvent++) 
{
    if (!pythia.next()) continue;
    a=0; prev=0; prev2=0; b=0;
 for (i = 0; i < pythia.event.size(); i++) 
 { a=0;  
   if(pythia.event[i].id()==23 && prev==22)a=1;
      
      if(p1==1 && pythia.event[i].id()==13)
      {
   v1.SetE(pythia.event[i].e());//e1=
   v1.SetPx(pythia.event[i].px());//px1=
   v1.SetPy(pythia.event[i].py());//py1=
   v1.SetPz(pythia.event[i].pz());//pz1=
      p1=0;
      }
      
      if(p2==1 && pythia.event[i].id()== -13)
      {
   v2.SetE(pythia.event[i].e());//+e1;//e2=
   v2.SetPx(pythia.event[i].px());//+px1;//px2=
   v2.SetPy(pythia.event[i].py());//+py1;//py2=
   v2.SetPz(pythia.event[i].pz());//+pz1;//pz2=
   p2=0;
   t[l]=TMath::ACos((v1.Px()*v2.Px()+v1.Py()*v2.Py()+v1.Pz()*v2.Pz())/(sqrt(v1.Px()*v1.Px()+v1.Py()*v1.Py()+v1.Pz()*v1.Pz())*sqrt(v2.Px()*v2.Px()+v2.Py()*v2.Py()+v2.Pz()*v2.Pz())));
   l++;
      }
      
    if(a==1 && b==1)      
     {p1=1;
      p2=1;  }
    
    if(pythia.event[i].id()==25)
    {
   if(pythia.event[i].e()>=1000) continue;
   prev2=pythia.event[i].id();
   x[l]=pythia.event[i].e();//=eh
   b=1;
    }
    
   prev=pythia.event[i].id();
   
 }
}
pythia.stat();
auto gh= new TGraph((l-1),x,t);
gh->SetTitle("Muon pair angle distribution;Energy of Higgs(In Gev);Angle between muon pair(Angle in radians)");
gh->Draw("A*");
gPad->WaitPrimitive();
return 0;
}
