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
 // pythia.readString("Beams:idA = 2212");
 // pythia.readString("Beams:idB = 2212");                         // REMEMBER TO MODFIY THE ROOT FILE NAME
  pythia.readString("Beams:idA = 1000822080");
  pythia.readString("Beams:idB = 1000822080");
  pythia.readString("Random:setSeed = on");
  pythia.readString("Random:seed = 0");
  pythia.readString("HiggsSM:all = on");   
  pythia.readString("Higgs:useBSM = off");
  pythia.readString("25:onMode = on");
 // pythia.readString("25:onIfAny = 24 -24 ");
 // pythia.readString("24:onMode = off");
 // pythia.readString("24:onIfAny = -13 14");  
 // pythia.readString("-24:onMode = off");
 // pythia.readString("-24:onIfAny = 13 -14 ");
 
pythia.init();
TFile* outFile = new TFile("check_charge.root", "RECREATE");
//TH1F *h1 = new TH1F("h1","No of charged particles", 200,0.0, 10000);  

int nevents=100000,j,count=0;

for (int iEvent = 0; iEvent < nevents; ++iEvent) 
{
  count=0;
	if (!pythia.next()) continue;
	for(j=0;j<pythia.event.size();j++)
	{
		if(pythia.event[j].isCharged())
		{count++;}
		h1->Fill(count);
 	}
}
pythia.stat();
 h1->Write();
 delete outFile;
return 0;
}
