using namespace std;
void plot()
{
const float r=0.854;
const int n=361;
int i;
/*
float x[n],y[n];
//Without contraction
for(i=0;i<n;i++)
{
x[i]=r*TMath::Cos(i*(TMath::Pi()/180));
y[i]=r*TMath::Sin(i*(TMath::Pi()/180));
}
TGraph *g =new TGraph(n,x,y);
g->Draw();
*/
float gam=8.1967;
const float c=3*pow(10,8);
float v=0.9925*c;
float th;
float x1[n],y1[n];
const float r1=0.854/gam;
//With Contraction
for(i=0;i<n;i++)
{
th=TMath::ATan((TMath::Pi()/180)*gam*(TMath::Tan(i*(TMath::Pi()/180))));
x1[i]=(r*sqrt(1-((v*v)*(cos(i)*cos(i)))/(c*c)))*TMath::Cos(th*TMath::Pi()/180);
y1[i]=(r*sqrt(1-((v*v)*(cos(i)*cos(i)))/(c*c)))*TMath::Sin(th*TMath::Pi()/180);
}
TGraph *f =new TGraph(n,x1,y1);
f->Draw();
}

/*
void plot()
{
  auto c = new TCanvas("myCanvas","myCanvas");//,600,600);
   // double rmin = 0.;
   // double rmax = 10.;
    const int npoints = 360;
    double r[npoints];
    double theta[npoints];
    for (int ipt = 0; ipt < npoints; ipt++) 
    {
        theta[ipt] = ipt;
        r[ipt] = 5;//TMath::Cos(theta[ipt]);
    }
    auto grP1 = new TGraphPolar(npoints,theta,r);
    grP1->SetTitle("Required plot");
    grP1->SetLineWidth(3);
    grP1->SetLineColor(2);
    grP1->Draw("L");
    gPad->Update();
    grP1->GetPolargram()->SetToRadian();
}
*/
