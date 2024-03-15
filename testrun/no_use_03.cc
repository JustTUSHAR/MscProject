//In non waorking condition needs some modifications
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
  pythia.readString("Beams:eCM = 13000");
  pythia.readString("Beams:idA = 2212");
  pythia.readString("Beams:idB = 2212");
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
  
pythia.init();

auto gr = new TGraph();
int nevents=100;
int i;
float e1,px1,py1,pz1;
float e2,px2,py2,pz2;
float theta;
float he;

for (int iEvent = 0; iEvent < nevents; ++iEvent) 
{
 	  if (!pythia.next()) continue;	 
 for (i = 0; i < pythia.event.size(); ++i) 
 {  
 	if(pythia.event[i].id()==25)
 		{
 		he=pythia.event[i].e();
 		}
	if(pythia.event[i].id()==24)
		{
		px1=pythia.event[i].px();
		py1=pythia.event[i].py();
		pz1=pythia.event[i].pz();
		}
	if(pythia.event[i].id()==-24)
		{
		px2=pythia.event[i].px();
		py2=pythia.event[i].py();
		pz2=pythia.event[i].pz();
		}
	theta=(px1*px2+py1*py2+pz1*pz2)/(sqrt(px1*px1+py1*py1+pz1*pz1)*sqrt(px2*px2+py2*py2+pz2*pz2));
	//theta=TMath::ACos(theta);
	gr->AddPoint(he,theta);
 }
}
pythia.stat();
gr->Draw();
gPad->WaitPrimitive();
return 0;
}
