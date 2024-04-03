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
    TFile *output = new TFile("mu_ratio.root", "recreate");
    //TTree *tree = new TTree("tree", "tree");
    //TCanvas *canvas = new TCanvas("canvas");
    int id, events, size ,i ,j;
    double e,m, px, py, pz, higgsMass, ZBosonMass;
   // tree->Branch("events", &events, "events/I");
   // tree->Branch("size", &size, "size/I");
   // tree->Branch("no", &no, "no/I");
   // tree->Branch("id", &id, "id/I");
   // tree->Branch("m", &m, "m/D");
   // tree->Branch("px", &px, "px/D");
   // tree->Branch("py", &py, "py/D");
   // tree->Branch("pz", &pz, "pz/D");
   // tree->Branch("higgsMass", &higgsMass, "higgsMass/D");
   // tree->Branch("ZBosonMass", &ZBosonMass, "ZBosonMass/D");
	//Pythia8::Pythia
    Pythia8::HeavyIons pythia(0);
//Angantyr:CollisionModel   (0);
    pythia.readString("Beams:idA = 1000791970");
    pythia.readString("Beams:idB = 1000791970");
    pythia.readString("Beams:eCM = 1000");
    pythia.readString("HardQCD:all = on");
    pythia.readString("SoftQCD:all = on");
//    pythia.readString("25:m0 = 125");
//    pythia.readString("HiggsSM:all=on");
//  pythia.readString("HiggsSM:gg2H = on");
//   pythia.readString("25:onMode = off"); 
//    pythia.readString("25:onIfAny = 23 22"); 
//    pythia.readString("23:onMode = off"); 
//    pythia.readString("23:onIfAny= 11 -11");
    //pythia.init();
    pythia.init();

	for (int i = 0; i < 10000; ++i) 
	{
        if (!pythia.next()) continue;        
        for(int j=0;j<pythia.event.size();j++)
        {
        
        }
	}
pythia.stat();
return 0;
}

