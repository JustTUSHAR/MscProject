//Higgs decay to neutrino and pair of muons(For simultaneous emission of all three)
//Energy of neutrino vs Angle between muon pair

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void hidec2()
{
TRandom *rn=new TRandom(0); //For random number generation
TLorentzVector n,u,au,ex; //Neutrino,muon,antimuon,excited particle Four vectors
double pu,theta,pex;//Temporary variable
double x[1260],y[1260];//For plotting
int i,j=0;//For loop

for(i=0;i<124800;i=i+100)//Maximum energy neutrino can have is 124808.8MeV for production of muon at least at rest
{	
		n.SetE(i);
		do{
		u.SetE(rn->Rndm()*(125020.0-n.E()));
		au.SetE(125020.0-n.E()-u.E());
		}while(u.E()<=105.6 && au.E()<=105.6);

		n.SetPz(0.0); //Setting Z component of all three particles 0
		u.SetPz(0.0);
		au.SetPz(0.0);

		n.SetPx(rn->Rndm()*i);   //Taking x component of momentum of neutrino randomly
		n.SetPy(sqrt(pow(n.E(),2.0)-pow(n.Px(),2.0))); //Calculating y component of momentum using energy momemtum relation for neutrino

		pu=pow(u.E(),2.0)-pow(105.6,2.0);

		u.SetPx(sqrt(rn->Rndm()*pu));//Taking x component of momentum randomly for muon
		au.SetPx(n.Px()-u.Px());//Conserving momemtum in x direction by taking momemtum of muon opposite
			
		u.SetPy(sqrt(pu-pow(u.Px(),2.0)));//Calculating y momentum using energy momemtum relation for muon
		au.SetPy(n.Py()-u.Py());//Conserving momentum in y direction by taking momentum of antimuon opposite to that of muon
	
theta=(u.Px()*au.Px()+u.Py()*au.Py())/(sqrt(u.Px()*u.Px()+u.Py()*u.Py())*sqrt(au.Px()*au.Px()+au.Py()*au.Py()));//Caculating momentum by dot product formula cos()=a.b/|a|*|b|
theta=TMath::ACos(theta);
/*
printf("Energy of neutrino=%lf\n",n.E());
printf("x Mom of neutrino=%lf\n",n.Px());
printf("y Mom of neutrino=%lf\n",n.Py());
printf("z Mom of neutrino=%lf\n",n.Pz());

printf("Energy of muon=%lf\n",u.E());
printf("x Mom of muon=%lf\n",u.Px());
printf("y Mom of muon=%lf\n",u.Py());
printf("z Mom of muon=%lf\n",u.Pz());

printf("Energy of antimuon=%lf\n",au.E());
printf("x Mom of antimuon=%lf\n",au.Px());
printf("y Mom of antimuon=%lf\n",au.Py());
printf("z Mom of antimuon=%lf\n",au.Pz());
*/
x[j]=i;     //Storing values for plotting
y[j]=theta;
j+=1;
}

auto gh= new TGraph((j-1),x,y);
gh->SetTitle("Muon pair angle distribution(For simultaneous emission);Energy of neutrino(In Mev);Angle between muon pair(Angle in radians)"); //Plotting the data
gh->Draw("A*");
}
