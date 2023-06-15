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
#include "ReadEth.h"

using namespace std;

// Perform linear interpolation
double linearInterpolation(const std::vector<double>& x, const std::vector<double>& y, double xValue) {
    int n = x.size();
    if (n != y.size() || n < 2) {
        // Invalid input, return 0 or handle error appropriately
        return 0.0;
    }

    for (int i = 0; i < n - 1; ++i) {
        if (xValue >= x[i] && xValue <= x[i + 1]) {
            double xDiff = x[i + 1] - x[i];
            double yDiff = y[i + 1] - y[i];
            double slope = yDiff / xDiff;
            double interpolatedValue = y[i] + slope * (xValue - x[i]);
            return interpolatedValue;
        }
    }

    // xValue is outside the range of given x values
    // Return 0 or handle error appropriately
    return 0.0;
}

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
    TApplication A("A", nullptr, nullptr);
    TCanvas c1("c1", "c1", 1200, 800); 

    //////////////////////////////// Ambiente ////////////////////////////////
    vector<pair<double, double>> ambiente;
    ReadFile("data/ambient.dat", ambiente);
    TGraphErrors amb;
    for (int i = 0; i < ambiente.size(); i++){
        amb.SetPoint(i, ambiente[i].first, ambiente[i].second);
        amb.SetPointError(i, 0, sqrt(ambiente[i].second));
    }
    amb.SetMarkerStyle(1);
    amb.SetMarkerColor(kOrange);
    amb.SetLineColor(kOrange);
    amb.SetTitle("Ambiente");
    amb.GetXaxis()->SetTitle(" Channels");
    amb.GetYaxis()->SetTitle("Counts");
    amb.GetXaxis()->CenterTitle();
    amb.GetYaxis()->CenterTitle();
    amb.GetXaxis()->SetRangeUser(0, 300);
    c1.Clear();
    amb.Draw("APL");
    c1.Update();
    c1.SaveAs("graphs/Ambiente.png");
    c1.WaitPrimitive();
    gSystem->ProcessEvents();

    //////////////////////////////// Bismuto ////////////////////////////////
    vector<pair<double, double>> bismuto;
    ReadFile("data/bismuto.dat", bismuto);
    TGraphErrors bis;
    for (int i = 0; i < bismuto.size(); i++){
        bis.SetPoint(i, bismuto[i].first, bismuto[i].second);
        bis.SetPointError(i, 0, sqrt(bismuto[i].second));
    }
    bis.SetMarkerStyle(1);
    bis.SetMarkerColor(kRed);
    bis.SetLineColor(kRed);
    bis.SetTitle("Bismuto");
    bis.GetXaxis()->SetTitle(" Channels");
    bis.GetYaxis()->SetTitle("Counts");
    bis.GetXaxis()->CenterTitle();
    bis.GetYaxis()->CenterTitle();
    bis.GetXaxis()->SetRangeUser(0, 300);
    bis.Draw("APL");
    c1.Update();
    c1.SaveAs("graphs/Bismuto.png");
    c1.WaitPrimitive();
    gSystem->ProcessEvents();

    // Find peaks for further calibration 
    double first_peak = find_max(6, 30, bismuto);
    double second_peak = find_max(30, 45, bismuto);
    double third_peak = find_max(100, 108, bismuto);
    double fourth_peak = find_max(116, 125, bismuto);
    double fifth_peak = find_max(207, 215, bismuto);
    double sixth_peak = find_max(223, 234, bismuto);

    cout << first_peak << " " << second_peak << " " << third_peak << " " << fourth_peak << " " << fifth_peak << " " << sixth_peak << endl;



    //////////////////////////////// Closed Talium ////////////////////////////////
    vector<pair<double, double>> talium;
    ReadFile("data/talium_closed.dat", talium);
    TGraphErrors tal;
    for (int i = 0; i < talium.size(); i++){
        tal.SetPoint(i, talium[i].first, talium[i].second);
        tal.SetPointError(i, 0, sqrt(talium[i].second));
    }
    tal.SetMarkerStyle(1);
    tal.SetMarkerColor(kBlue);
    tal.SetLineColor(kBlue);
    tal.SetTitle("Talio");
    tal.GetXaxis()->SetTitle(" Channels");
    tal.GetYaxis()->SetTitle("Counts");
    tal.GetXaxis()->CenterTitle();
    tal.GetYaxis()->CenterTitle();
    tal.GetXaxis()->SetRangeUser(0, 300);
    c1.Clear();
    tal.Draw("APL");
    c1.Update();
    c1.SaveAs("graphs/Talio.png");
    c1.WaitPrimitive();
    gSystem->ProcessEvents();

    //////////////////////////////// Open Talium ////////////////////////////////
    vector<pair<double, double>> talium_open;
    ReadFile("data/talium_open.dat", talium_open);
    TGraphErrors tal_open;
    for (int i = 0; i < talium_open.size(); i++){
        tal_open.SetPoint(i, talium_open[i].first, talium_open[i].second);
        tal_open.SetPointError(i, 0, sqrt(talium_open[i].second));
    }
    tal_open.SetMarkerStyle(1);
    tal_open.SetMarkerColor(kBlue);
    tal_open.SetLineColor(kBlue);
    tal_open.SetTitle("Talio");
    tal_open.GetXaxis()->SetTitle(" Channels");
    tal_open.GetYaxis()->SetTitle("Counts");
    tal_open.GetXaxis()->CenterTitle();
    tal_open.GetYaxis()->CenterTitle();
    tal_open.GetXaxis()->SetRangeUser(0, 300);
    c1.Clear();
    tal_open.Draw("APL");
    c1.Update();
    c1.SaveAs("graphs/Talio_open.png");
    c1.WaitPrimitive();
    gSystem->ProcessEvents();

    //////////////////////////////// Graph Both Tals ////////////////////////////////
    c1.Clear();
    TLegend leg(0.65, 0.75, 0.85, 0.85);
    leg.AddEntry(&tal, "Talio Fechado", "l");
    leg.AddEntry(&tal_open, "Talio Aberto", "l");
    tal_open.SetTitle("Talio Aberto e Talio Fechado");
    tal_open.SetLineColor(kRed);
    tal_open.Draw("APL");
    tal.Draw("PL");
    leg.Draw();
    c1.Update();
    c1.SaveAs("graphs/Talio_both.png");
    c1.WaitPrimitive();
    gSystem->ProcessEvents();

    //////////////////////////////// Césio ////////////////////////////////
    vector<pair<double, double>> cesio;
    ReadFile("data/cesium.dat", cesio);
    TGraphErrors ces;
    for (int i = 0; i < cesio.size(); i++){
        ces.SetPoint(i, cesio[i].first, cesio[i].second);
        ces.SetPointError(i, 0, sqrt(cesio[i].second));
    }
    ces.SetMarkerStyle(1);
    ces.SetMarkerColor(kGreen);
    ces.SetLineColor(kGreen);
    ces.SetTitle("Cesio");
    ces.GetXaxis()->SetTitle(" Channels");
    ces.GetYaxis()->SetTitle("Counts");
    ces.GetXaxis()->CenterTitle();
    ces.GetYaxis()->CenterTitle();
    ces.GetXaxis()->SetRangeUser(0, 300);
    c1.Clear();
    ces.Draw("APL");
    c1.Update();
    c1.SaveAs("graphs/Cesio.png");
    c1.WaitPrimitive();
    gSystem->ProcessEvents();

    // Find peaks for further analysis
    double cesium_peak_channels = find_max(100, 150, cesio); // add range
    double cesium_peak_theoretical_energy = 624.216; // add theoretical value

    //////////////////////////////// Strontium ////////////////////////////////
    vector<pair<double, double>> strontium;
    ReadFile("data/strontium.dat", strontium);
    TGraphErrors str;
    for (int i = 0; i < strontium.size(); i++){
        str.SetPoint(i, strontium[i].first, strontium[i].second);
        str.SetPointError(i, 0, sqrt(strontium[i].second));
    }
    str.SetMarkerStyle(1);
    str.SetMarkerColor(kBlack);
    str.SetLineColor(kBlack);
    str.SetTitle("Estroncio");
    str.GetXaxis()->SetTitle(" Channels");
    str.GetYaxis()->SetTitle("Counts");
    str.GetXaxis()->CenterTitle();
    str.GetYaxis()->CenterTitle();
    str.GetXaxis()->SetRangeUser(0, 300);
    c1.Clear();
    str.Draw("APL");
    c1.Update();
    c1.SaveAs("graphs/Estroncio.png");
    c1.WaitPrimitive();
    gSystem->ProcessEvents();

    //////////////////////////////// Pontos de Calibração ////////////////////////////////
    vector<pair<double, double>> calib;
    ReadFile("data/calib.dat", calib);
    TGraphErrors cal;
    for (int i = 0; i < calib.size(); i++){
        cal.SetPoint(i, calib[i].first, calib[i].second);
        cal.SetPointError(i, 0, sqrt(calib[i].second));
    }
    cal.SetMarkerStyle(1);
    cal.SetMarkerColor(kBlack);
    cal.SetLineColor(kBlack);
    cal.SetTitle("Calibracao");
    cal.GetXaxis()->SetTitle(" Channels");
    cal.GetYaxis()->SetTitle("Counts");
    cal.GetXaxis()->CenterTitle();
    cal.GetYaxis()->CenterTitle();
    cal.GetXaxis()->SetRangeUser(0, 300);
    c1.Clear();
    cal.Draw("APL");
    c1.Update();
    c1.SaveAs("graphs/Calib.png");
    c1.WaitPrimitive();
    gSystem->ProcessEvents();

    //////////////////////////////// Talium + Aluminum ////////////////////////////////
    vector<pair<double, double>> taliumAl;
    ReadFile("data/talium_closedAl.dat", taliumAl);
    TGraphErrors talAl;
    for (int i = 0; i < taliumAl.size(); i++){
        talAl.SetPoint(i, taliumAl[i].first, taliumAl[i].second);
        talAl.SetPointError(i, 0, sqrt(taliumAl[i].second));
    }
    talAl.SetMarkerStyle(1);
    talAl.SetMarkerColor(kBlue);
    talAl.SetLineColor(kBlue);
    talAl.SetTitle("Talio c placa de Aluminio");
    talAl.GetXaxis()->SetTitle(" Channels");
    talAl.GetYaxis()->SetTitle("Counts");
    talAl.GetXaxis()->CenterTitle();
    talAl.GetYaxis()->CenterTitle();
    talAl.GetXaxis()->SetRangeUser(0, 300);
    c1.Clear();
    talAl.Draw("APL");
    c1.Update();
    c1.SaveAs("graphs/TalioAluminio.png");
    c1.WaitPrimitive();
    gSystem->ProcessEvents();

    //////////////////////////////// Cesium + Aluminum ////////////////////////////////
    vector<pair<double, double>> cesiumAl;
    ReadFile("data/cesiumAl.dat", cesiumAl);
    TGraphErrors cesAl;
    for (int i = 0; i < cesiumAl.size(); i++){
        cesAl.SetPoint(i, cesiumAl[i].first, cesiumAl[i].second);
        cesAl.SetPointError(i, 0, sqrt(cesiumAl[i].second));
    }
    cesAl.SetMarkerStyle(1);
    cesAl.SetMarkerColor(kGreen);
    cesAl.SetLineColor(kGreen);
    cesAl.SetTitle("Cesio c placa de Aluminio");
    cesAl.GetXaxis()->SetTitle(" Channels");
    cesAl.GetYaxis()->SetTitle("Counts");
    cesAl.GetXaxis()->CenterTitle();
    cesAl.GetYaxis()->CenterTitle();
    cesAl.GetXaxis()->SetRangeUser(0, 300);
    c1.Clear();
    cesAl.Draw("APL");
    c1.Update();
    c1.SaveAs("graphs/CesioAluminio.png");
    c1.WaitPrimitive();
    gSystem->ProcessEvents();

    //////////////////////////////// Bismuth + Air ////////////////////////////////
    vector<pair<double, double>> bismuthAir;
    ReadFile("data/bis_air.dat", bismuthAir);
    TGraphErrors bisAir;
    for (int i = 0; i < bismuthAir.size(); i++){
        bisAir.SetPoint(i, bismuthAir[i].first, bismuthAir[i].second);
        bisAir.SetPointError(i, 0, sqrt(bismuthAir[i].second));
    }
    bisAir.SetMarkerStyle(1);
    bisAir.SetMarkerColor(kBlue);
    bisAir.SetLineColor(kBlue);
    bisAir.SetTitle("Bismuto c ar");
    bisAir.GetXaxis()->SetTitle(" Channels");
    bisAir.GetYaxis()->SetTitle("Counts");
    bisAir.GetXaxis()->CenterTitle();
    bisAir.GetYaxis()->CenterTitle();
    bisAir.GetXaxis()->SetRangeUser(0, 300);
    c1.Clear();
    bisAir.Draw("APL");
    c1.Update();
    c1.SaveAs("graphs/BismutoAr.png");
    c1.WaitPrimitive();
    gSystem->ProcessEvents();

    //////////////////////////////// Bismuth + Car ////////////////////////////////
    vector<pair<double, double>> bismuthCar;
    ReadFile("data/bis_car.dat", bismuthCar);
    TGraphErrors bisCar;
    for (int i = 0; i < bismuthCar.size(); i++){
        bisCar.SetPoint(i, bismuthCar[i].first, bismuthCar[i].second);
        bisCar.SetPointError(i, 0, sqrt(bismuthCar[i].second));
    }
    bisCar.SetMarkerStyle(1);
    bisCar.SetMarkerColor(kOrange);
    bisCar.SetLineColor(kOrange);
    bisCar.SetTitle("Bismuto c cartao");
    bisCar.GetXaxis()->SetTitle(" Channels");
    bisCar.GetYaxis()->SetTitle("Counts");
    bisCar.GetXaxis()->CenterTitle();
    bisCar.GetYaxis()->CenterTitle();
    bisCar.GetXaxis()->SetRangeUser(0, 300);
    c1.Clear();
    bisCar.Draw("APL");
    c1.Update();
    c1.SaveAs("graphs/BismutoCartao.png");
    c1.WaitPrimitive();
    gSystem->ProcessEvents();

    //////////////////////////////// Bismuth + Acrylic ////////////////////////////////
    vector<pair<double, double>> bismuthAcrylic;
    ReadFile("data/bis_acr.dat", bismuthAcrylic);
    TGraphErrors bisAcr;
    for (int i = 0; i < bismuthAcrylic.size(); i++){
        bisAcr.SetPoint(i, bismuthAcrylic[i].first, bismuthAcrylic[i].second);
        bisAcr.SetPointError(i, 0, sqrt(bismuthAcrylic[i].second));
    }
    bisAcr.SetMarkerStyle(1);
    bisAcr.SetMarkerColor(kGreen);
    bisAcr.SetLineColor(kGreen);
    bisAcr.SetTitle("Bismuto c acrilico");
    bisAcr.GetXaxis()->SetTitle(" Channels");
    bisAcr.GetYaxis()->SetTitle("Counts");
    bisAcr.GetXaxis()->CenterTitle();
    bisAcr.GetYaxis()->CenterTitle();
    bisAcr.GetXaxis()->SetRangeUser(0, 300);
    c1.Clear();
    bisAcr.Draw("APL");
    c1.Update();
    c1.SaveAs("graphs/BismutoAcrilico.png");
    c1.WaitPrimitive();
    gSystem->ProcessEvents();


    //////////////////////////////// Bismuth with 3 ////////////////////////////////
    c1.Clear();
    leg.Clear();
    leg.SetHeader("Bismuto");
    leg.AddEntry(&bis, "Bismuto", "l");
    leg.AddEntry(&bisAir, "Bismuto c ar", "l");
    leg.AddEntry(&bisCar, "Bismuto c cartao", "l");
    leg.AddEntry(&bisAcr, "Bismuto c acrilico", "l");
    bis.Draw("APL");
    bisAir.Draw("PL");
    bisCar.Draw("PL");
    bisAcr.Draw("PL");
    leg.Draw();
    c1.Update();
    c1.SaveAs("graphs/Bismuto_Atenuation.png");
    c1.WaitPrimitive();
    gSystem->ProcessEvents();

    //////////////////////////////// Calibration Function ////////////////////////////////
    // Using Bismuth Peaks 
    gStyle->SetOptFit(111);
    double first_theoretical = 481.694;
    double second_theoretical = 555.251;
    double third_theoretical = 975.655; 
    double fourth_theoretical = 1049.211; 

    double first_experimental = third_peak; 
    double second_experimental = fourth_peak; 
    double third_experimental = fifth_peak;
    double fourth_experimental = sixth_peak; 

    TGraphErrors calibration;
    calibration.SetPoint(0, first_experimental, first_theoretical);
    calibration.SetPoint(1, second_experimental, second_theoretical);
    calibration.SetPoint(2, third_experimental, third_theoretical);
    calibration.SetPoint(3, fourth_experimental, fourth_theoretical);
    
    calibration.SetMarkerStyle(20);
    calibration.SetMarkerColor(kRed);
    calibration.SetLineColor(kRed);
    calibration.SetTitle("Calibration");
    calibration.GetXaxis()->SetTitle(" Channels [keV]");
    calibration.GetYaxis()->SetTitle("Energy [keV]");
    calibration.GetXaxis()->CenterTitle();
    calibration.GetYaxis()->CenterTitle();
    calibration.GetXaxis()->SetRangeUser(0, 300);
    
    TF1 *calibrationFunction = new TF1("calibrationFunction", "[0] + [1]*x", 0, 300);
    calibrationFunction->SetParameter(0, 0);
    calibrationFunction->SetParameter(1, 1);
    calibrationFunction->SetParName(0, "slope");
    calibrationFunction->SetParName(1, "intercept");
    calibration.Fit("calibrationFunction", "R");
    c1.Clear();
    calibration.Draw("APL");
    c1.Update();
    c1.SaveAs("graphs/Calibration.png");
    c1.WaitPrimitive();
    gSystem->ProcessEvents();

    //////////////////////////////// Find Material with Cesium ////////////////////////////////
    double difference = abs(cesium_peak_theoretical_energy - calibrationFunction->Eval(cesium_peak_channels));
    cout << "Difference in Energy: " << difference << endl;

    vector<double> KineticalEnergy;
    vector<double> Collision;
    vector<double> Radiative;
    vector<double> Total;
    vector<double> CSDA;
    vector<double> Y;
    vector<double> Param;

    ReadFile("data/polyethylene.dat", KineticalEnergy, Collision, Radiative, Total, Param);

    TGraphErrors polyethylene_stopping_powers;
    for (int i = 0; i < KineticalEnergy.size(); i++){
        polyethylene_stopping_powers.SetPoint(i, KineticalEnergy[i], Total[i]);
        polyethylene_stopping_powers.SetPointError(i, 0, 0);
    }
    polyethylene_stopping_powers.SetMarkerStyle(1);
    polyethylene_stopping_powers.SetMarkerColor(kRed);
    polyethylene_stopping_powers.SetLineColor(kRed);
    polyethylene_stopping_powers.SetTitle("Polyethylene Stopping Powers");
    polyethylene_stopping_powers.GetXaxis()->SetTitle("Kinetical Energy [MeV]");
    polyethylene_stopping_powers.GetYaxis()->SetTitle("Stopping Power [MeV cm^{2}/g]");
    polyethylene_stopping_powers.GetXaxis()->CenterTitle();
    polyethylene_stopping_powers.GetYaxis()->CenterTitle();
    polyethylene_stopping_powers.GetXaxis()->SetRangeUser(0, 1);
    c1.SetLogx();
    c1.SetLogy();
    c1.Clear();
    polyethylene_stopping_powers.Draw("APL");
    c1.Update();
    c1.SaveAs("graphs/Polyethylene_Stopping_Powers.png");
    c1.WaitPrimitive();
    gSystem->ProcessEvents();
    //c1.SetLogx(0);
    //c1.SetLogy(0);

    // Composition of Polyethylene
    double density = 0.94; //g/cm^3
    double mean_excitation_energy = 57.4; // eV

    // try integration simple
    double integral = 0;
    double tentauva = 0;
    for(int i = 0; i < KineticalEnergy.size(); i++){
        if(KineticalEnergy[i]*1000 > calibrationFunction->Eval(cesium_peak_channels) && KineticalEnergy[i]*1000 < cesium_peak_theoretical_energy){
            double dx = KineticalEnergy[i] - KineticalEnergy[i - 1];
            integral += (1/(Total[i] * density) + 1/(Total[i - 1] * density)) * dx / 2.0;
            tentauva += Total[i];
        }
    }
    cout << integral << endl;
    cout << difference / integral << endl;
    cout << "tentativa" << tentauva << endl;

    // Using Cesium Peak
    // Find Stopping power for cesium peak using integral from theoretical energy to experimental energy
    // Divide Stopping Power by density to find length 
    // Divide difference by Stopping power above
    // That's the thickness of the material, should be around 1/2/3 mm

    vector<double> KineticalEnergy2;
    vector<double> Collision2;
    vector<double> Radiative2;
    vector<double> Total2;
    vector<double> CSDA2;
    vector<double> Y2;
    vector<double> Param2;

    ReadFile("data/polyethylene_no_use.dat", KineticalEnergy2, Collision2, Radiative2, Total2, CSDA2,Param2);
    TGraphErrors polyethylene_stopping_powers2;
    for (int i = 0; i < KineticalEnergy2.size(); i++){
        polyethylene_stopping_powers2.SetPoint(i, KineticalEnergy2[i], CSDA2[i]);
        polyethylene_stopping_powers2.SetPointError(i, 0, 0);
    }
    polyethylene_stopping_powers2.SetMarkerStyle(1);
    polyethylene_stopping_powers2.SetMarkerColor(kRed);
    polyethylene_stopping_powers2.SetLineColor(kRed);
    polyethylene_stopping_powers2.SetTitle("CSDA Range");
    polyethylene_stopping_powers2.GetXaxis()->SetTitle("Kinetical Energy [MeV]");
    polyethylene_stopping_powers2.GetYaxis()->SetTitle("Stopping Power [MeV cm^{2}/g]");
    polyethylene_stopping_powers2.GetXaxis()->CenterTitle();
    polyethylene_stopping_powers2.GetYaxis()->CenterTitle();
    c1.SetLogx();
    c1.SetLogy();
    c1.Clear();
    polyethylene_stopping_powers2.Draw("APL");
    c1.Update();
    //c1.SaveAs("graphs/Polyethylene_Stopping_Powers2.png");
    c1.WaitPrimitive();
    gSystem->ProcessEvents();

    double integral2 = linearInterpolation(KineticalEnergy2, CSDA2, cesium_peak_theoretical_energy/1000);
    double integral3 = linearInterpolation(KineticalEnergy2, CSDA2, calibrationFunction->Eval(cesium_peak_channels)/1000);
    cout << (integral2 - integral3) / density << endl;




    

    















}