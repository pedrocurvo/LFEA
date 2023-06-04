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
    string filename = "Nuno.dat";
    Reader RR(filename, 0, 3);
    vector<vector<double>> rawdata = RR.GetData();
    double maximo, minimo, tamanho;
    tamanho = rawdata.size();
    minimo = rawdata[0][0];
    maximo = rawdata[tamanho-1][0];
    
    TApplication app("app", NULL, NULL);
    TCanvas C("C", "Histograma", 1200, 800);
	TH1D h("h","Histograma", tamanho, minimo, maximo);

	for(int i=0; i < tamanho; i++){
		h.Fill(rawdata[i][0] - minimo + 1, rawdata[i][1]);
	}

    h.SetFillColor(kBlue-8);
	h.Draw();

	TF1 f("f","gaus",minimo, maximo);
    f.SetParameters(5000,210, 30);
	h.Fit("f");
	f.Draw("same");

    C.Update();
    C.SaveAs("pdf/Nuno.pdf");
    C.WaitPrimitive();
    gSystem->ProcessEvents();

    return 0;
}