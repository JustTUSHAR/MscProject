#include<iostream>
#include<stdio.h>
#include "TFile.h"
#include "TTree.h"
void RAn()
{
 TFile *f = new TFile("r_pbpb_data.root");
 TTree *e = (TTree*)f->Get("e");

 TFile *f2 = new TFile("r_pp_data.root");
 TTree *e2 = (TTree*)f2->Get("e");

int ne=e->GetEntries();
int ne2=e2->GetEntries();
int nchrge,nchrge2;
long i,j;
float nr11,nr12;
int nchmax1=0;
e->SetBranchAddress("nchrge",&nchrge);
e2->SetBranchAddress("nchrge",&nchrge2);
e->SetBranchAddress("eeid",&eeid);
e2->SetBranchAddress("eeid",&eeid2);

for(i=0;i<ne;i++)
{
e->GetEntry(i);
 if(nchrge>nchmax1)
 {
 	nchmax1=nchrge;
 }
}

nr11=nchmax1*(0.0/100);
nr12=nchmax1*(20.0/100);

int cnchrg=0;
for(i=0;i<ne;i++)
{
e->GetEntry(i);
 if(nchrge>=nr11 && nchrge<=nr12)
 {
 cnchrg=cnchrg+nchrge;
 }
}

int cnchrg2=0;
for(i=0;i<ne;i++)
{
e2->GetEntry(i);
 cnchrg2=cnchrg2+nchrge;
}

printf("pb02=%d\n",cnchrg);
printf("pp=%d\n",cnchrg2);

}

