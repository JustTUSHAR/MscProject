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
#include "TTree.h"

using namespace Pythia8;
int main(int argc, char* argv[]) {

TApplication theApp("hist", &argc, argv);
Pythia pythia;  
  pythia.readString("Beams:eCM = 5000");
  pythia.readString("Beams:idA = 2212");
  pythia.readString("Beams:idB = 2212");
 // pythia.readString("Beams:idA = 1000822080");                            //Modify root file name
 // pythia.readString("Beams:idB = 1000822080");
  
  pythia.readString("Random:setSeed = on");
  pythia.readString("Random:seed = 0");

  pythia.readString("HiggsSM:all = on");   
  pythia.readString("Higgs:useBSM = off");

typedef struct{
float m;//mass
float px;//x momentum
float py;//y momentum
float pz;//z momentum
float pt;//transverse momentum
float et;//transverse energy
float rap;//rapidity
float prap;//psuedorapidity
float mt;//transverse mass
int chrg;//charge type
int eid;//event id
int pid;//particle id
}s;

typedef struct{
int eid;//event id
int esize;//event size
int nchrge;//no of charge particels in events
}a;
  
pythia.init();
	
	TFile* outFile = new TFile("delete.root", "RECREATE"");//pbpb_data2.root", "RECREATE");
int nevents=100000,i,size,count=0;
s p;
a b;
	TTree t("t","Tree for track parameters data");
	t.Branch("p",&p,"m/F:px/F:py/F:pz/F:pt/F:et/F:rap/F:prap/F:mt/F:chrg/I:eid/I:pid/I");
	
	TTree e("e","Tree for event parameters data");
	e.Branch("b",&b,"eid/I:esize/I:nchrge/I");
	
for (int iEvent = 0; iEvent < nevents; ++iEvent) 
{
 	if (!pythia.next()) continue;
 	count=0;
 p.eid=iEvent;
 b.eid=iEvent;
 b.esize=pythia.event.size();	 
 for (i = 0; i < pythia.event.size(); ++i) 
 {
 p.pid=pythia.event[i].id();  
 p.m=pythia.event[i].m();
 p.px=pythia.event[i].px();
 p.py=pythia.event[i].py();
 p.pz=pythia.event[i].pz();
 p.pt=pythia.event[i].pT();
 p.mt=pythia.event[i].mT();
 p.chrg=pythia.event[i].chargeType();
 p.rap=pythia.event[i].y();
 p.prap=pythia.event[i].eta();
 p.et=pythia.event[i].eT();
 t.Fill();
 
 if(pythia.event[i].isCharged()){ count++;}
 
 }
 b.nchrge=count;
e.Fill();
}
e.Write();
t.Write();
pythia.stat();
delete outFile;
return 0;
}
