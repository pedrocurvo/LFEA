# include <iostream>
# include <cmath>
# include <vector>
# include <string>
#include <cmath>
#include <TLegendEntry.h>
#include "TCanvas.h"
#include "TApplication.h"
#include "TSystem.h"
#include "TLegend.h"
#include "TH1F.h"
#include "TGraph.h"
#include "TF1.h"
#include "Read.h"
#include "TGraphErrors.h"
#include "TStyle.h"
#include "TLatex.h"
using namespace std;

double find_max(double min, double max, vector<pair<double, double>>& cal_1){
    double max_val = 0;
    double integer = 0;
    for (int i = 0; i < cal_1.size(); i++){
        if(cal_1[i].first > min && cal_1[i].first < max){
            if(cal_1[i].second > max_val){
                max_val = cal_1[i].second;
                integer = cal_1[i].first;
            }
        }
    }
    return integer;
}

int main(){
    // Create Application
    TApplication A("A", nullptr, nullptr);
    // Create Canvas
    TCanvas c1("c1", "c1", 1200, 800); 
    // GStyle
    gStyle->SetOptFit(111);
    //////////////////// Calibration of First Pulser ////////////////////
    TGraphErrors Cal1; 
    vector<pair<double, double>> cal_1;
    ReadFile("Data_Files/2Cal.dat", cal_1);

    for (int i = 0; i < cal_1.size(); i++){
        if(cal_1[i].first < 340 || cal_1[i].first > 550){
        Cal1.SetPoint(i, cal_1[i].first, cal_1[i].second);
        }else{
            Cal1.SetPoint(i, cal_1[i].first, 0);
        }
    }

    // Function Fit 
    TF1 *fit1 = new TF1("fit1", "[0]*x+[1]", 0, 1000);
    fit1->SetParameter(0, 0.01);
    fit1->SetParameter(1, 0);
    fit1->SetParName(0, "Slope");
    fit1->SetParName(1, "Offset");
    
    // Draw calibration
    Cal1.SetTitle("Points for Calibration");
    Cal1.GetXaxis()->CenterTitle();
    Cal1.GetYaxis()->CenterTitle();
    Cal1.GetXaxis()->SetTitle("Channel");
    Cal1.GetYaxis()->SetTitle("Counts");
    Cal1.SetMarkerStyle(20);
    Cal1.SetMarkerSize(0.5);
    Cal1.Draw("AP");
    c1.Update();
    c1.SaveAs("Points_for_Calibration.png");
    c1.WaitPrimitive();
    gSystem->ProcessEvents();

    // Cout 1st point
    double first_point = find_max(200, 400, cal_1);
    cout << first_point << endl;

    // Cout 2nd point
    double second_point = find_max(550, 600, cal_1);
    cout << second_point << endl;

    // Cout 3rd point
    double third_point = find_max(600, 800, cal_1);
    cout << third_point << endl;

    // Cout 4th point
    double fourth_point = find_max(800, 1000, cal_1);
    cout << fourth_point << endl;
    
    // Calibration 
    TGraphErrors Calibrations;
    Calibrations.SetPoint(0, first_point, 5);
    Calibrations.SetPointError(0, 0, 0.01);
    Calibrations.SetPoint(1, second_point, 5.5);
    Calibrations.SetPointError(1, 0, 0.01);
    Calibrations.SetPoint(2, third_point, 5.75);
    Calibrations.SetPointError(2, 0, 0.01);
    Calibrations.SetPoint(3, fourth_point, 6);
    Calibrations.SetPointError(3, 0, 0.01);
    Calibrations.Fit("fit1", "R");
    Calibrations.SetTitle("Calibration in Pulser Units");
    Calibrations.GetXaxis()->CenterTitle();
    Calibrations.GetYaxis()->CenterTitle();
    Calibrations.GetXaxis()->SetTitle("Channel");
    Calibrations.GetYaxis()->SetTitle("Pulser Units");
    Calibrations.SetMarkerStyle(20);
    Calibrations.SetMarkerSize(0.5);
    c1.Clear();
    Calibrations.Draw("AP");
    c1.Update();
    c1.SaveAs("Calibration_in_Pulser_Units.png");
    c1.WaitPrimitive();
    gSystem->ProcessEvents();
    

    double pico_am = 474;
    double pico_am_energy = 5485.56; // keV


    double pico_am_unidades_de_pulser = fit1->Eval(pico_am);
    double ratio = pico_am_energy / pico_am_unidades_de_pulser / 1000;
    cout << "Ratio: " << ratio << endl;

    double error_centroide_channel = 0.04391;
    double one = fit1->Eval(pico_am - error_centroide_channel);
    double two = fit1->Eval(pico_am + error_centroide_channel);
    double media = (one + two) / 2;

    // Calibration in Energy
    TGraphErrors Calibrations_Energy;
    Calibrations_Energy.SetPoint(0, first_point, 5 * ratio);
    Calibrations_Energy.SetPointError(0, 0, 0.01* ratio);
    Calibrations_Energy.SetPoint(1, second_point, 5.5 * ratio);
    Calibrations_Energy.SetPointError(1, 0, 0.01* ratio);
    Calibrations_Energy.SetPoint(2, third_point, 5.75 * ratio);
    Calibrations_Energy.SetPointError(2, 0, 0.01* ratio);
    Calibrations_Energy.SetPoint(3, fourth_point, 6 * ratio);
    Calibrations_Energy.SetPointError(3, 0, 0.01* ratio);
    Calibrations_Energy.SetTitle("Calibration in Energy");
    Calibrations_Energy.GetXaxis()->CenterTitle();
    Calibrations_Energy.GetYaxis()->CenterTitle();
    Calibrations_Energy.GetXaxis()->SetTitle("Channel");
    Calibrations_Energy.GetYaxis()->SetTitle("Energy [MeV]");
    Calibrations_Energy.SetMarkerStyle(20);
    Calibrations_Energy.SetMarkerSize(0.5);
    c1.Clear();
    Calibrations_Energy.Fit("fit1", "R");
    Calibrations_Energy.Draw("AP");
    c1.Update();
    c1.SaveAs("Calibration_in_Energy.png");
    c1.WaitPrimitive();
    gSystem->ProcessEvents();







}