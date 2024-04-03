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
    int id, events=20000;
    float m,e,px,py,pz;
    TFile *output = new TFile("pp_data.root", "recreate");
    TTree *tree = new TTree("tree", "tree");    
      tree->Branch("m", &m, "m/F");
      tree->Branch("px", &px, "px/F");
      tree->Branch("py", &py, "py/F");
      tree->Branch("pz", &pz, "pz/F");
    TH1D *size = new TH1D("size", "Events size", 100, 0, 2500);
    Pythia8::Pythia pythia;
    pythia.readString("Beams:idA = 2212");
    pythia.readString("Beams:idB = 2212");
    pythia.readString("Beams:eCM = 13000");
    pythia.readString("HardQCD:all = on");
   // pythia.readString("SoftQCD:all = on");
    pythia.readString("HiggsSM:all=on");
    pythia.init();
for (int i = 0; i < events; ++i) 
{
        if (!pythia.next()) continue;
        size->Fill(pythia.event.size());
        for(int j=0;j<pythia.event.size();j++)
        {
 	      m=1000*pythia.event[j].m();
 	      e=1000*pythia.event[j].e();
 	      px=1000*pythia.event[j].px();
 	      py=1000*pythia.event[j].py();
 	      pz=1000*pythia.event[j].pz();
 	      tree->Fill();
 	}
}
tree->Write();
size->Write();
delete output;
pythia.stat();
return 0;
}

