#include<iostream>
#include<stdio.h>
#include "TFile.h"
#include "TTree.h"
void RAn()
{
 TFile *f = new TFile("pbp_data.root");
 TTree *e = (TTree*)f->Get("e");

 int ne=e->GetEntries();
 int i;
 int h;
 typedef struct{
int eid;//event id
int esize;//event size
int nchrge;//no of charge particels in events
}a;

a *b=new a();

e->SetBranchAddress("b",&b);
 
for(i=0;i<ne;i++)
{
e->GetEntry(i);
h=e->eid;
printf("%d\n",h)
}

delete b;

}
