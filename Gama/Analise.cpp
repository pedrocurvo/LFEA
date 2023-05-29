# include <iostream>
# include <cmath>
# include <vector>
# include <string>
#include "TCanvas.h"
#include "TApplication.h"
#include "TSystem.h"
#include "TH1F.h"
#include "TGraph.h"
#include "TF1.h"
# include "Read.cpp"
using namespace std;

int main(){
    TApplication A("A", nullptr, nullptr);
    // Create Canvas
    TCanvas c1("c1", "c1", 1200, 800); 

    // Espetro de Radiação do Ambiente
    TGraph G_Amb; 
    vector<pair<double, double>> rad_ambiente = ReadFile("Data_Files/Nuno_Cobalto.dat");
    for (int i = 0; i < rad_ambiente.size(); i++){
        G_Amb.AddPoint(rad_ambiente[i].first, rad_ambiente[i].second);
    }
    G_Amb.SetLineColor(kBlue+1);
    G_Amb.SetMarkerStyle(20);
    G_Amb.SetMarkerSize(0.5);
    G_Amb.SetTitle("Espetro de Radiacao Ambiente; E [keV]; Counts");
    G_Amb.GetXaxis()->CenterTitle();
    G_Amb.GetYaxis()->CenterTitle();

    G_Amb.Draw("AC");
    c1.Update();
    c1.SaveAs("PNGs/Espetro_Ambiente4.png");
    c1.WaitPrimitive();
    gSystem->ProcessEvents();

}