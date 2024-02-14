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
  
  //pythia.readString("25:m0 = 125.02");
  pythia.readString("25:onMode = off");
  pythia.readString("25:onIfAny = 24 -24 ");
  
  pythia.readString("24:onMode = off");
  pythia.readString("24:onIfAny = -13 14");
  
  pythia.readString("-24:onMode = off");
  pythia.readString("-24:onIfAny = 13 -14 ");
  
pythia.init();
 // TFile* outFile = new TFile("hist2.root", "RECREATE");
//  auto hs = new THStack("hs","");
//TH1F *h1 = new TH1F("h1","Reconstructed Higgs Mass from it's final decay products for 10K events", 130,0.0, 130.0);
auto gr = new TGraph();
//  TH1F *h1 = new TH1F("h1","With no cuts", 130,0.0, 130.0);
//  TH1F *h2 = new TH1F("h2","With cuts", 130,0.0, 130.0);  
  /*
  h1->SetFillColor(kRed);
  hs->Add(h1);
  h2->SetFillColor(kBlue);
  hs->Add(h2);
  */
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
	theta=TMath::ACos(theta);
//	printf("he=%f  Theta=%f\n",he,theta);
	gr->AddPoint(he,theta);
 }


//if(rm==mh) printf("Correct event\n");
//h1->Fill(rm);
}
pythia.stat();
gr->Draw();
  //mult->Draw();
//  h1->SetFillColor(kRed);
//  hs->Add(h1);
//  h2->SetFillColor(kBlue);
 // hs->Add(h2);
  
  
 // gPad->SetGrid(1,0);
  
//  auto cs = new TCanvas("cs","cs",800,600);
//  cs->cd(1);
 // h1->Draw();
  // hs->Draw();
 // gPad->BuildLegend(0.75,0.75,0.95,0.95,"");
  gPad->WaitPrimitive();
 // h1->Write();
 // h2->Write();
//  cs->Write();
//  delete outFile;
return 0;
}
