//Higgs boson simultaneous decay to neutrino and a pair of muons
#include<iostream>
#include<math.h>
void HiggsSim()
{
TRandom *rn=new TRandom(0); //For random number generation
TLorentzVector n,u,au; //Neutrino,muon,antimuon particle Four vectors
double pu,theta;//Temporary variable
double x[1260],y[1260];//For plotting
int i,j=0;//For loop

for(i=0;i<124808;i=i+100)
{
/*
n.SetE(i);
do{
u.SetE(rn->Rndm()*(125020.0-n.E()));
au.SetE(125020.0-n.E()-u.E());
}while(u.E()<=105.6 && au.E()<=105.6);

n.SetPz(0.0);
n.SetPz(0.0);
n.SetPz(0.0);

n.SetPx(rn->Rndm()*n.E());
n.SetPy(sqrt(pow(n.E(),2.0)-pow(n.Px(),2.0)));

u.SetPx(rn->Rndm()*u.E());
au.SetPx(n.Px()-u.Px());

u.SetPy(sqrt(pow(u.E(),2.0)-pow(u.Px(),2.0)-pow(105.6,2.0)));
au.SetPy(n.Py()-u.Py());
*/

ios:
n.SetE(i);
n.SetPx(rn->Rndm()*n.E());
pn=pn-n.Px();
n.SetPy(rn->Rndm()*pn);
n.SetPz(sqrt(pow(h.E(),2.0)-pow(n.Px(),2.0)-pow(n.Py(),2.0)));

u.SetPx(rn->Rndm()*n.E());
au.SetPx(n.Px()-u.Px());

au.SetPy(rn->Rndm()*n.E());
u.SetPy(n.Py()-au.Py());

u.SetPz(rn->Rndm()*n.Pz());
au.SetPz(n.Pz()-u.Pz());

u.SetE(sqrt(pow(u.Px(),2.0)+pow(u.Py(),2.0)+pow(u.Pz(),2.0)+pow(105.6,2.0)));
au.SetE(sqrt(pow(au.Px(),2.0)+pow(au.Py(),2.0)+pow(au.Pz(),2.0)+pow(105.6,2.0)));

if(fabs(n.E()-u.E()-au.E())>0.01) goto ios;


theta=(u.Px()*au.Px()+u.Py()*au.Py())/(sqrt(u.Px()*u.Px()+u.Py()*u.Py())*sqrt(au.Px()*au.Px()+au.Py()*au.Py()));//Caculating momentum by dot product formula cos()=a.b/|a|*|b|
theta=TMath::ACos(theta);

x[j]=i;     //Storing values for plotting
y[j]=theta;
j+=1;
}

auto gh= new TGraph((j-1),x,y);
gh->SetTitle("Muon pair angle distribution(For simultaneous emission);Energy of neutrino(In Mev);Angle between muon pair(In degree pi=3.14)"); //Plotting the data
gh->Draw("A*");
}
