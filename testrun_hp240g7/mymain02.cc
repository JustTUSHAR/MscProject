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
 /*   TFile *output = new TFile("tut3.root", "recreate");
    TTree *tree = new TTree("tree", "tree");
    TCanvas *canvas = new TCanvas("canvas");
    int id, events, size ;
    double e,m, px, py, pz, higgsMass, ZBosonMass;
    tree->Branch("events", &events, "events/I");
    tree->Branch("size", &size, "size/I");
    tree->Branch("no", &no, "no/I");
    tree->Branch("id", &id, "id/I");
    tree->Branch("m", &m, "m/D");
    tree->Branch("px", &px, "px/D");
    tree->Branch("py", &py, "py/D");
    tree->Branch("pz", &pz, "pz/D");
    tree->Branch("higgsMass", &higgsMass, "higgsMass/D");
    tree->Branch("ZBosonMass", &ZBosonMass, "ZBosonMass/D");
  */
    Pythia8::Pythia pythia;

    pythia.readString("Beams:idA = 2212");
    pythia.readString("Beams:idB = 2212");
    pythia.readString("Beams:eCM = 7000");
  //  pythia.readString("HardQCD:all = on");
    pythia.readString("25:m0 = 125");
    pythia.readString("HiggsSM:all=on");
//  pythia.readString("HiggsSM:gg2H = on");
    pythia.readString("25:onMode = off"); 
    pythia.readString("25:onIfAny = 23 22"); 
    pythia.readString("23:onMode = off"); 
    pythia.readString("23:onIfAny= 11 -11");
    pythia.init();

   // TH1D *histHiggsMass = new TH1D("histHiggsMass", "Reconstructed Higgs boson mass", 100, 0, 200);
   // TH1D *histZBosonMass = new TH1D("ZBosonMass", "Reconstructed Zboson mass", 100, 0, 150);
     for (int i = 0; i < 10000; ++i) {
        if (!pythia.next()) continue;
        
        for(int j=0;j<pythia.event.size();j++)
        {
        if(pythia.event[j].id() == 23) cout<<"Z boson produced"<<endl;
        }
        
        
        
        
        
     /*       size =  pythia.event.size();
            events =i;
            cout << "Event: " << i << endl;
            cout << "Event size: " <<  size<< endl;
           
       for (int j = 0; j < pythia.event.size(); ++j) {
       
            id = pythia.event[j].id();
            m = pythia.event[j].m();
            px = pythia.event[j].px();
            py = pythia.event[j].py();
            pz = pythia.event[j].pz();
            e =  pythia.event[j].e();
            
          //  std::cout <<" Pythia ID : " << id << "   Mass : " << m <<" Px : " << px << " Py: " << py<< " Pz : " << pz<<endl;
            if (id == 11 ) 
            {
                cout << " electron energy: " << pythia.event[j].e() << " GeV  " ; 
                for (int k = j + 1; k <  pythia.event.size(); k++)
                {
                    if (pythia.event[k].id() == -11 ) 
                    {  
                        cout << "positron energy: "<< pythia.event[k].e() <<" GeV  "<< endl ;
                        TLorentzVector vece1(px, py, pz, pythia.event[j].e());
                        TLorentzVector vece2(pythia.event[k].px(), pythia.event[k].py(), pythia.event[k].pz(), pythia.event[k].e());
                        TLorentzVector vecSum1 = vece1 + vece2;
                        double ZBososnMass = vecSum1.M();
                        tree->Fill();
                        histZBosonMass->Fill(ZBosonMass);
                        
                    if(pythia.event[k].id() == 22)
                    {
                    cout<< "energy of photon : " << pythia.event[k].e() << "  GeV  " ;
                    TLorentzVector vecPhoton(px,py,pz,pythia.event[j].e());
                    TLorentzVector vecSum2 = vecSum1 + vecPhoton;
                    double higgsMass = vecSum2.M();
                    tree->Fill();
                    histHiggsMass->Fill(higgsMass);
                   } 
                 }     
              }
           }
        }
     }   
    histZBosonMass->SetXTitle("Z Boson Mass [GeV]");
    histZBosonMass->SetYTitle("Events");
    histZBosonMass->Draw();
    histZBosonMass->Write();
    
    histHiggsMass->SetXTitle("Higgs Boson Mass [GeV]");
    histHiggsMass->SetYTitle("Events");
    histHiggsMass->Draw();
    histHiggsMass->Write();

   
    canvas->Draw();
    canvas->SaveAs("histogram.png");

    
    output->Write();
    output->Close();
    return 0;
*/
}
pythia.stat();
return 0;
}


