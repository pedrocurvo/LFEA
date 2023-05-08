#include "Reader.h"
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
//ROOT
#include "TApplication.h"
#include "TSystem.h"
#include "TCanvas.h"
#include "TF1.h"
#include "TH1D.h"

int main(){
    string filename = "valoreshist_test_OneShot.dat";
    Reader RR(filename, 1);
    vector<vector<double>> rawdata = RR.GetData();
    vector<double> data;
    for(int i=0; i < rawdata.size(); i++){
		data.push_back(rawdata[i][0]);
	}
    
    TApplication app("app", NULL, NULL);
    TCanvas C("C", "Histograma", 1200, 800);
	
	int n_bin=20; //INSERIR
	double minimo=*min_element(data.begin(), data.end()); //inserir canal minimo
	double maximo=*max_element(data.begin(), data.end()); // inserir o canal maximo 

	TH1D h("h","Histograma", n_bin, minimo, maximo);

	for(int i=0; i < data.size(); i++){
		h.Fill(data[i]);
	}
    h.SetFillColor(kBlue-8);
	h.Draw();

	TF1 f("f","gaus",minimo, maximo);
	h.Fit("f");
	f.Draw("same");

    C.Update();
    C.SaveAs("pdf/Histograma.pdf");
    C.WaitPrimitive();
    gSystem->ProcessEvents();

    return 0;
}