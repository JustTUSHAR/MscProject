#include <iostream>
#include "TFile.h"
#include "TTree.h"
#include "TH1D.h"
#include "TCanvas.h"
#include "Pythia8/Pythia.h"
#include "TLorentzVector.h"
using namespace std;

int main()
{
	Pythia8::Pythia pythia;
    pythia.readString("Beams:idA = 1000791970");
    pythia.readString("Beams:idB = 1000791970");
    pythia.readString("Beams:eCM = 7.7");
    pythia.readString("HardQCD:all = on");
    pythia.readString("SoftQCD:all = on");
    
    int events=1000;
    float m1,e1;
   TFile *output = new TFile("dummy.root", "recreate");
    TTree *t = new TTree("t", "tree");  
     t->Branch("e1", &e1, "e1/F");
     t->Branch("m1", &m1, "m1/F");
     
    TH1D *size = new TH1D("size", "Events size", 300, 0, 3000);
    pythia.init();

for (int i = 0; i < events; ++i) 
{
        if (!pythia.next()) continue;
        size->Fill(pythia.event.size());
        for(int j=0;j<pythia.event.size();j++)
        {
   	      m1=1000*pythia.event[j].m();
          e1=1000*pythia.event[j].e();
 	 	  printf("m=%f e=%f \n",m1,e1);
 	 t->Fill();
 	}
 	
} 
t->Write();
size->Write();
delete output;
pythia.stat();
return 0;
}
