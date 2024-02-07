void p1()
{
TRandom *a = new TRandom(0);
TTree *tr = new TTree("tr","First tree");
TFile *fl = new TFile("p1out.root","recreate");
int i,j[500],k,p[10],b,l,n,m,ev,eve;
float px[1000],py[1000],pz[1000],ms[1000];

//Initial entities accelerated with 20Mev set

cout<<"Enter the no of events(Max. 100)"<<endl;
cin>>ev;
tr->Branch("Event",&eve,"eve/I");
tr->Branch("ms",&ms,"ms[100]/F");
tr->Branch("px",&px,"px[100]/F");
tr->Branch("py",&py,"py[100]/F");
tr->Branch("pz",&pz,"pz[100]/F");

 for(i=0;i<ev;i++) //No of events
 {	
 eve=i+1;
 j[i]= a->Rndm()*500;//No of particles generated  //Max 500 Set
 	for(k=0;k<j[i];k++)
 	{ b=a->Rndm()*10; //Particle selector for giving weight
 	 p[b]++;  //Giving weight to particles}
        for(l=0;l<10;l++)
 	{n=sizeof(p[l]); //No of particles produced of one type
 	    for(m=0;m<n;m++)
 	    {       	     
       	     if(b==1)
       	     {ms[m]=a->Gaus(938.27,50);}  //for proton
 	     else if(b==2)
 	     {ms[m]=a->Gaus(939.6,50);}  //for neutron
 	     else if(b==3)
 	     {ms[m]=a->Gaus(139.6,50);} //for pion
 	     else if(b==4)
 	     {ms[m]=a->Gaus(493.7,50);} //for kaon
 	     else if(b==5)
 	     {ms[m]=a->Gaus(1115.7,50);} //for lambda baryon
 	     else if(b==6)
 	     {ms[m]=a->Gaus(1189.4,50);} //for sigma baryon
 	     else if(b==7)
 	     {ms[m]=a->Gaus(1672.5,50);} //for omega baryon
 	     else if(b==8)
 	     {ms[m]=a->Gaus(548.8,50);}  //for eta meson
 	     else if(b==9)
 	     {ms[m]=a->Gaus(770,50);}  //for rho meson
 	     else if(b==10)
 	     {ms[m]=a->Gaus(782,50);}  //for omega meson
 	     
 	     px[m]=a->Rndm()*20000;  // Max range of momentum in x dir. of particles produced
 	     py[m]=a->Rndm()*(20000-px[m]); // Max range of momentum in y dir. of particles produced
 	     pz[m]=pow(20000,2)-pow(px[m],2)-pow(py[m],2);  // Max range of momentum in z dir. of particles produced
 	     
 	    }
 	}
 }
tr->Print();
tr->Fill();	     
}
tr->Write();
fl->Close();
}
