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
  pythia.readString("Beams:eCM = 13000");
  pythia.readString("Beams:idA = 11");
  pythia.readString("Beams:idB = 2212");
  
  pythia.readString("Random:setSeed = on");
  pythia.readString("Random:seed = 0");

  pythia.readString("HiggsSM:all = on");   
  pythia.readString("Higgs:useBSM = off");

typedef struct{
float m;
float px;
float py;
float pz;
int eid;
int pid;
int p_id;
}s;

typedef struct{
int eid;
int esize;
}a;
  
pythia.init();
	
  TFile outFile("pp_data.root", "RECREATE");

int nevents=1000,i,size;
s p;
a b;
	TTree t("t","Tree for track parameters data");
	t.Branch("p",&p,"m/F:px/F:py/F:pz/F:eid/I:pid/I:p_id/I");
	
	TTree e("e","Tree for event parameters data");
	e.Branch("b",&b,"eid/I:esize/I");
	
for (int iEvent = 0; iEvent < nevents; ++iEvent) 
{
 	if (!pythia.next()) continue;
 p.eid=iEvent;
 b.eid=iEvent;
 b.esize=pythia.event.size();	 
 for (i = 0; i < pythia.event.size(); ++i) 
 {
 p.p_id=i;
 p.pid=pythia.event[i].id();  
 p.m=pythia.event[i].m();
 p.px=pythia.event[i].px();
 p.py=pythia.event[i].py();
 p.pz=pythia.event[i].pz();
 t.Fill();
 }
e.Fill();
}
e.Write();
t.Write();
pythia.stat();
return 0;
}
