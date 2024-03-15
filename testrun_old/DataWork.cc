#include<iostream>
#include<stdio.h>
void DataWork()
{
TFile *f = new TFile("ptu_var.root");
TFile *p = new TFile("All_ptu_var.root");

TH1F *hist1 = new TH1F("hist1","hist1 title" , 130, 0, 130);
TH1F *hist2 = new TH1F("hist2","hist2 title" , 130, 0, 130);

hist1 = (TH1F*)f->Get("h4");
hist2 = (TH1F*)p->Get("h4");

TH1F *hist3 = (TH1F*)hist1->Clone("hist3");
hist3->Divide(hist2);
hist3->SetTitle("Signal/(Signal+Background)");

hist3->Draw();

}
