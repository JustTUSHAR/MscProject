#include<math.h>
#include<stdio.h>
#include<stdlib.h>

void hidec3()
{
int i,j=0,k=0;//For loop
TRandom *rn=new TRandom(0); //For random number generation
TLorentzVector h,u,au;
double theta,ph,pu,pau;//Temporary variable
double x[1260],y[1260];//For plotting
FILE *fle=fopen("abc.dat","w");
for(k=0;k<10;k++)
{
j=0;
for(i=10;i<1000;i++)
{
ios:
h.SetE(125.02+i);
ph=sqrt(pow(h.E(),2.0)-pow(125.02,2.0));
h.SetPx(rn->Rndm()*ph);
ph=ph-h.Px();
h.SetPy(rn->Rndm()*ph);
h.SetPz(sqrt(pow(h.E(),2.0)-pow(h.Px(),2.0)-pow(h.Py(),2.0)-pow(125.02,2.0)));

u.SetPx(rn->Rndm()*h.E());
au.SetPx(h.Px()-u.Px());

au.SetPy(rn->Rndm()*h.E());
u.SetPy(h.Py()-au.Py());

u.SetPz(rn->Rndm()*h.Pz());
au.SetPz(h.Pz()-u.Pz());

u.SetE(sqrt(pow(u.Px(),2.0)+pow(u.Py(),2.0)+pow(u.Pz(),2.0)+pow(0.105,2.0)));
au.SetE(sqrt(pow(au.Px(),2.0)+pow(au.Py(),2.0)+pow(au.Pz(),2.0)+pow(0.105,2.0)));

if(fabs(h.E()-u.E()-au.E())>0.01) goto ios;

theta=(u.Px()*au.Px()+u.Py()*au.Py())/(sqrt(u.Px()*u.Px()+u.Py()*u.Py())*sqrt(au.Px()*au.Px()+au.Py()*au.Py()));
theta=TMath::ACos(theta);

/*printf("Energy of higgs=%lf\n",h.E());
printf("x Mom of higgs=%lf\n",h.Px());
printf("y Mom of higgs=%lf\n",h.Py());
printf("z Mom of higgs=%lf\n",h.Pz());

printf("Energy of muon=%lf\n",u.E());
printf("x Mom of muon=%lf\n",u.Px());
printf("y Mom of muon=%lf\n",u.Py());
printf("z Mom of muon=%lf\n",u.Pz());

printf("Energy of antimuon=%lf\n",au.E());
printf("x Mom of antimuon=%lf\n",au.Px());
printf("y Mom of antimuon=%lf\n",au.Py());
printf("z Mom of antimuon=%lf\n",au.Pz());*/

x[j]=h.E();//-125020.0);
y[j]=theta;
fprintf(fle,"%lf %lf \n",x[j],y[j]);
j+=1;
}
}
exit(EXIT_SUCCESS);
auto gh= new TGraph((j-1),x,y);
gh->SetTitle("Muon pair angle distribution(For excited particle case);Energy of Higgs(In Gev);Angle between muon pair(Angle in radians)"); //Plotting the data
gh->Draw("A*");

}
