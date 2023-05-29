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

    // Calibration
    TGraph CalibratioGraph;
    vector<pair<double, double>> calibration;
    //Energy = [32, 662, 1173, 1333] # Cs and Co energies
    // Channels = [28.8, 437.07, 760.24, 861.42] # Cs-137 and Co-60 channels
    calibration.push_back(pair<double, double> (28.8, 32));
    calibration.push_back(pair<double, double> (437.07, 662));
    calibration.push_back(pair<double, double> (760.24, 1173));
    calibration.push_back(pair<double, double> (861.42, 1333));
    for (int i = 0; i < calibration.size(); i++){
        CalibratioGraph.AddPoint(calibration[i].first, calibration[i].second);
    }
    CalibratioGraph.SetLineColor(kRed);
    CalibratioGraph.SetMarkerStyle(20);
    CalibratioGraph.SetMarkerSize(0.5);
    CalibratioGraph.SetTitle("Calibration; Channels; Energy [keV]");
    CalibratioGraph.GetXaxis()->CenterTitle();
    CalibratioGraph.GetYaxis()->CenterTitle();
    CalibratioGraph.Draw("*");
    TF1 *f1 = new TF1("f1", "[0]*x+[1]");
    CalibratioGraph->Fit("f1");
    c1.Update();
    c1.SaveAs("PNGs/Calibracao.png");
    c1.WaitPrimitive();
    gSystem->ProcessEvents();


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