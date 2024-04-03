#include<iostream>
#include<stdio.h>
#include "TFile.h"
#include "TTree.h"
void RAn()
{


 TFile *f = new TFile("raa_pbpb_data_1.root");
 TTree *e = (TTree*)f->Get("e");
// TTree *t = (TTree*)f->Get("t");

 TFile *f2 = new TFile("raa_pp_data.root");
 TTree *e2 = (TTree*)f2->Get("e");
// TTree *t2 = (TTree*)f2->Get("t");

int ne=e->GetEntries();
int ne2=e2->GetEntries();
//int nt=t->GetEntries();
//int nt2=t2->GetEntries();

/*
TFile* outFile = new TFile("Raa_step1.root", "RECREATE");
TH1F *h1 = new TH1F("h1","In PbPb muon transverse momentum", 100,0.0, 100.0);
TH1F *h2 = new TH1F("h2","In PbPb muon pseudorapdity", 30,-15.0, 15.0);

TFile* outFile = new TFile("Raa_step1.root", "RECREATE");
TH1F *h3 = new TH1F("h3","In pp muon transverse momentum", 100,0.0, 100.0);
TH1F *h4 = new TH1F("h4","In pp muon pseudorapdity", 30,-15.0, 15.0);
 
int ne=e->GetEntries();
int nt=t->GetEntries();
int i,j,pid;
float pt,prap;

int ne2=e2->GetEntries();
int nt2=t2->GetEntries();
int pid2;
float pt2,prap2;

t->SetBranchAddress("pt",&pt);
t->SetBranchAddress("prap",&prap);
t->SetBranchAddress("pid",&pid);

t2->SetBranchAddress("pt",&pt2);
t2->SetBranchAddress("prap",&prap2);
t2->SetBranchAddress("pid",&pid2);

for(i=0;i<nt;i++)
{
printf("1i%d\n",i);
t->GetEntry(i);
 if(pid==13)
  {
   h1->Fill(pt);
   h2->Fill(prap);
  }
}

for(i=0;i<nt2;i++)
{
printf("2i%d\n",i);
t2->GetEntry(i);
 if(pid2==13)
  {
   h3->Fill(pt2);
   h4->Fill(prap2);
  }
}

h1->Write();
h2->Write();
h3->Write();
h4->Write();
delete outFile;

*/

 
int nchrge,nchrge2,i,j;//,count=0,ptc=0,etac=0,n;
int eeid,eeid2;
int eid,eid2;
float raa,pt,rap,pt2,rap2;
int count;
float nr11,nr12,nr21,nr22;
int nchmax1=0,nchmax2=0;
int seid,seid2;

e->SetBranchAddress("nchrge",&nchrge);
e2->SetBranchAddress("nchrge",&nchrge2);
//e->SetBranchAddress("eeid",&eeid);
//e2->SetBranchAddress("eeid",&eeid2);
//t->SetBranchAddress("eid",&eid);
//t->SetBranchAddress("pt",&pt);
//t->SetBranchAddress("rap",&rap);
//t2->SetBranchAddress("eid",&eid2);
//t2->SetBranchAddress("pt",&pt2);
//t2->SetBranchAddress("rap",&rap2);

for(i=0;i<ne;i++)
{
e->GetEntry(i);
 if(nchrge>nchmax1)
 {
 	nchmax1=nchrge;
 }
}

for(j=0;j<ne2;j++)
{
e2->GetEntry(j);
 if(nchrge2>nchmax2)
 {
 	nchmax2=nchrge2;
 }
}
printf("---%d\n",nchmax1);
printf("---%d\n",nchmax2);
/*
nr11=nchmax1*(89.5/100);
nr12=nchmax1*(90.5/100);
nr21=nchmax2*(89.5/100);
nr22=nchmax2*(90.5/100);
*/
nr11=nchmax1;
nr12=nchmax1;
nr21=nchmax2;
nr22=nchmax2;

printf("a-%f\n",nr11);
printf("a-%f\n",nr12);
printf("a-%f\n",nr21);
printf("a-%f\n",nr22);

for(i=0;i<ne;i++)
{
//printf("1l%d=\n",i);
e->GetEntry(i);
 if(nchrge>=nr11 && nchrge<=nr12)
 {
 	raa=(float)nchrge/nchmax1;//nchmax1;
 printf("nchrge first=%d\n",nchrge);
 printf("raa first=%f\n",raa);

 //seid=eeid;
 	break;
 }
}
float p;
for(j=0;j<ne2;j++)
{
//printf("2l%d=\n",j);
e2->GetEntry(j);
 if(nchrge2>=nr21 && nchrge2<=nr22)
 {
printf("nchrge second=%d\n",nchrge2);
 	//raa=raa/(float)nchrge2/nchmax2;
 	p=(float)nchrge2/nchmax2;
 	printf("normalised nchrge second=%f\n",p);
 raa=raa/p;
 //	raa=raa/nchrge2;//*nchmax2;
 //sid2=eeid2;
 	break;
 }
} 	

/*
for(i=0;i<nt;t++)
{

}
*/
printf("%f=\n",raa);

}
