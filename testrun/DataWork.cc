#include<iostream>
#include<stdio.h>
void DataWork()
{
TFile *f = new TFile("W_bandwidth.root");
TFile *p = new TFile("All_W_bandwidth.root");

TH1F *hist1 = new TH1F("hist1","hist1 title" , 130, 0, 130);
TH1F *hist2 = new TH1F("hist2","hist2 title" , 130, 0, 130);

hist1 = (TH1F*)f->Get("h3");
hist2 = (TH1F*)p->Get("h3");

TH1F *hist3 = (TH1F*)hist1->Clone("hist3");
hist3->Divide(hist2);
//hist3->Add(hist2,-1);
hist3->SetTitle("Signal/(Signal+Background) for Higgs");
hist3->Draw();
}
