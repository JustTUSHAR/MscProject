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
 // pythia.readString("Beams:idA = 2212");
 // pythia.readString("Beams:idB = 2212");
  pythia.readString("Beams:idA = 1000822080");                            //Modify root file name
  pythia.readString("Beams:idB = 1000822080");
  
  pythia.readString("Random:setSeed = on");
  pythia.readString("Random:seed = 0");

  pythia.readString("HiggsSM:all = on");   
  pythia.readString("Higgs:useBSM = off");

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

int eeid;//event id
int esize;//event size
int nchrge;//no of charge particels in events
  
pythia.init();
	
	TFile* outFile = new TFile("r_pbpb_data.root", "RECREATE");
int nevents=5000,i,size,count=0;

	TTree t("t","Tree for track parameters data");
	
	t.Branch("m",&px,"m/F");
	t.Branch("px",&px,"px/F");
	t.Branch("py",&py,"py/F");
	t.Branch("pz",&pz,"pz/F");
	t.Branch("pt",&pt,"pt/F");
	t.Branch("et",&et,"et/F");
	t.Branch("rap",&rap,"rap/F");
	t.Branch("prap",&prap,"prap/F");
	t.Branch("mt",&mt,"mt/F");
	t.Branch("chrg",&chrg,"chrg/I");
	t.Branch("eid",&eid,"eid/I");
	t.Branch("pid",&pid,"pid/I");
	
	TTree e("e","Tree for event parameters data");
	e.Branch("eeid",&eeid,"eeid/I");
	e.Branch("esize",&esize,"esize/I");
	e.Branch("nchrge",&nchrge,"nchrge/I");

	
for (int iEvent = 0; iEvent < nevents; ++iEvent) 
{
 	if (!pythia.next()) continue;
 	count=0;
 eid=iEvent;
 eeid=iEvent;
 esize=pythia.event.size();	 
 for (i = 0; i < pythia.event.size(); ++i) 
 {
 pid=pythia.event[i].id();  
 m=pythia.event[i].m();
 px=pythia.event[i].px();
 py=pythia.event[i].py();
 pz=pythia.event[i].pz();
 pt=pythia.event[i].pT();
 mt=pythia.event[i].mT();
 chrg=pythia.event[i].chargeType();
 rap=pythia.event[i].y();
 prap=pythia.event[i].eta();
 et=pythia.event[i].eT();
 t.Fill();
 
 if(pythia.event[i].isCharged()){ count++;}
 }
 nchrge=count;
e.Fill();
}
e.Write();
t.Write();
pythia.stat();
delete outFile;
return 0;
}
