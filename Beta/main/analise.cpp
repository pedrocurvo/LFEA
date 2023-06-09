/* Authors: Pedro Curvo, Estevão Gomes, Salvador Torpes, Sofia Tété

 * This program is used to analyze the data from the Beta experiment. 
 * It reads the data from the files and plots the graphs.
 * It also calculates the energy of the peaks and the calibration curve.
 * The Calibration is done using the peaks from the Bismuth spectrum.
 * Then we use the calibration and a peak of Cesium to find the thickness of the absorber (polyethylene).
 * this is done because we have closed and open fonts
 * Then We recalibrate the graphs
 * We calculate the End Point Energy of the Beta Decay for an open and closed recalibrated font of Talium 
 * We do this using the Kurie Plot and a derivative method to find the maximum of the curve
 * Using the Saturation Zone seen in spectrums we calculate the thickness of the detector
 * 
 * Changes in Code to be made for self use: 
 * 1. You need a bin folder
 * 2. You need a data folder
 * 3. You need a graphs folder
 * 4. Instead you can use your own folders but you need to change the path in the code
 * 5. Change the name of the files to your own files
 * 6. All the other changes are commented in the code with the comment "Change For Self Use"
 * 7. Find it using Cmd (Ctrl) + F
 * 
 * 
*/


#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <cmath>
#include <numeric>
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
#include "TSpline.h"
#include <TError.h>
using namespace std;

void CustomizeGraph(TGraphErrors& graph, Color_t markerColor, Color_t lineColor, const std::string& title, const std::string& xAxisTitle, const std::string& yAxisTitle, double xMin = 0.0, double xMax = 300.0, double MarkerStyle = 1) {
    graph.SetMarkerStyle(MarkerStyle);
    graph.SetMarkerColor(markerColor);
    graph.SetLineColor(lineColor);
    graph.SetTitle(title.c_str());
    graph.GetXaxis()->SetTitle(xAxisTitle.c_str());
    graph.GetYaxis()->SetTitle(yAxisTitle.c_str());
    graph.GetXaxis()->CenterTitle();
    graph.GetYaxis()->CenterTitle();
    graph.GetXaxis()->SetRangeUser(xMin, xMax);
}
void SaveCanvas(TCanvas& canvas, const std::string& filename, bool Clear = true) {
    canvas.Update();
    canvas.SaveAs(filename.c_str());
    canvas.WaitPrimitive();
    gSystem->ProcessEvents();
    if(Clear){
        canvas.Clear();
    }
}

std::vector<std::pair<double, long double>> calculateDerivative(const std::vector<std::pair<double, double>>& points) {
    std::vector<std::pair<double, long double>> derivativePoints;

    for (size_t i = 1; i < points.size(); ++i) {
        double x = points[i].first;
        long double y = (points[i].second - points[i - 1].second) / (points[i].first - points[i - 1].first);
        derivativePoints.emplace_back(x, y);
    }

    return derivativePoints;
}

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
    gErrorIgnoreLevel = kWarning; // Ignore ROOT messages Info: Graph saved as ...

    //////////////////////////////// Ambiente ////////////////////////////////
    vector<pair<double, double>> ambiente;
    ReadFile("data/ambient.dat", ambiente);
    TGraphErrors amb;
    for (int i = 0; i < ambiente.size(); i++){
        amb.SetPoint(i, ambiente[i].first, ambiente[i].second);
        amb.SetPointError(i, 0, sqrt(ambiente[i].second));
    }
    CustomizeGraph(amb, kBlack, kBlack, "Ambiente", "Channels", "Counts");
    amb.Draw("APL");
    SaveCanvas(c1, "graphs/Ambiente.png");
    

    //////////////////////////////// Bismuto ////////////////////////////////
    gStyle->SetOptFit(kFALSE); 
    vector<pair<double, double>> bismuto;
    ReadFile("data/bismuto.dat", bismuto);
    double counts = 0;
    for(int i=0; i<bismuto.size(); i++){
        counts += bismuto[i].second;
    }
    cout << "Bismuth Counts: " << counts << endl;

    TGraphErrors bis;
    for (int i = 0; i < bismuto.size(); i++){
        bis.SetPoint(i, bismuto[i].first, bismuto[i].second);
        bis.SetPointError(i, 0, sqrt(bismuto[i].second));
    }
    CustomizeGraph(bis, kRed, kRed, "Bismuto", "Channels", "Counts");
    bis.Draw("APL");
    SaveCanvas(c1, "graphs/Bismuto.png");

    // Find peaks for further calibration 
    double first_peak = find_max(6, 30, bismuto);
    double second_peak = find_max(30, 45, bismuto);
    double third_peak = find_max(100, 108, bismuto);
    double fourth_peak = find_max(116, 125, bismuto);
    double fifth_peak = find_max(207, 215, bismuto);
    double sixth_peak = find_max(223, 234, bismuto);

    // gaussians in peaks 
    TF1* gaus1 = new TF1("gaus1", "gaus", third_peak - 2, third_peak + 1.7);
    TF1* gaus2 = new TF1("gaus2", "[0]*exp(-0.5*((x-[1])/[2])*((x-[1])/[2])) + [3]*exp(-0.5*((x-[4])/[5])*((x-[4])/[5]))", fourth_peak - 2.25, fourth_peak + 4.2);
    TF1* gaus3 = new TF1("gaus3", "gaus", fifth_peak - 3.5, fifth_peak + 3.5);
    TF1* gaus4 = new TF1("gaus4", "[0]*exp(-0.5*((x-[1])/[2])*((x-[1])/[2])) + [3]*exp(-0.5*((x-[4])/[5])*((x-[4])/[5]))", sixth_peak - 3.9, sixth_peak + 4.2);

    gaus1->SetParameters(1300,third_peak,1);
    gaus2->SetParameters(250,fourth_peak,1,100,fourth_peak+2,1);
    gaus2->SetParNames("C_{1}","#mu_{1}", "#sigma_{1}","C_{2}","#mu_{2}", "#sigma_{2}","C_{3}","#mu_{3}", "#sigma_{3}");
    gaus4->SetParNames("C_{1}","#mu_{1}", "#sigma_{1}","C_{2}","#mu_{2}", "#sigma_{2}","C_{3}","#mu_{3}", "#sigma_{3}");
    gaus2->SetParLimits(0,0,350);
    gaus2->SetParLimits(1,fourth_peak-1,fourth_peak+1);

    gaus2->SetParLimits(2,0,2);
    gaus2->SetParLimits(3,0,300);
    //gaus2->SetParLimits(4,120,121.87);
    gaus2->SetParLimits(5,0,1.23);
    gaus4->SetParameters(50,sixth_peak,1,20,sixth_peak+2,1);


    gaus1->SetLineColor(kBlue);
    gaus2->SetLineColor(kBlue);
    gaus3->SetLineColor(kBlue);
    gaus4->SetLineColor(kBlue);

    bis.Fit(gaus1, "R");
    bis.Fit(gaus2, "R");
    bis.Fit(gaus3, "R");
    bis.Fit(gaus4, "R");

    c1.Clear();
    bis.Draw("APL");
    gaus1->Draw("same");
    gaus2->Draw("same");
    gaus3->Draw("same");
    gaus4->Draw("same");
    c1.Update();
    c1.SaveAs("graphs/Bismuto_peaks.png");
    c1.WaitPrimitive();
    gSystem->ProcessEvents();



    /// Find Number of Counts
    double counts_one = 0;
    double counts_two = 0;
    double counts_three = 0;
    double counts_four = 0;

    for(int i = 0; i < bismuto.size(); i++){
        if(bismuto[i].first > 100 && bismuto[i].first < 107){
            counts_one += bismuto[i].second;
        }
        if(bismuto[i].first > 116 && bismuto[i].first < 126){
            counts_two += bismuto[i].second;
        }
        if(bismuto[i].first > 208 && bismuto[i].first < 213){
            counts_three += bismuto[i].second;
        }
        if(bismuto[i].first > 225 && bismuto[i].first < 231){
            counts_four += bismuto[i].second;
        }
    }

    cout << "Counts in first peak: " << counts_one << endl;
    cout << "Counts in second peak: " << counts_two << endl;
    cout << "Counts in third peak: " << counts_three << endl;
    cout << "Counts in fourth peak: " << counts_four << endl << endl;



    //////////////////////////////// Closed Talium ////////////////////////////////
    vector<pair<double, double>> talium;
    ReadFile("data/talium_closed.dat", talium);
    TGraphErrors tal;
    for (int i = 0; i < talium.size(); i++){
        tal.SetPoint(i, talium[i].first, talium[i].second);
        tal.SetPointError(i, 0, sqrt(talium[i].second));
    }
    CustomizeGraph(tal, kBlue, kBlue, "Talio", "Channels", "Counts");
    c1.Clear();
    tal.Draw("APL");
    SaveCanvas(c1, "graphs/Talio.png");

    //////////////////////////////// Open Talium ////////////////////////////////
    vector<pair<double, double>> talium_open;
    ReadFile("data/talium_open.dat", talium_open);
    counts = 0; 
    for(int i=0; i<talium_open.size(); i++){
        counts += talium_open[i].second;
    }
    cout << "Counts in open talium: " << counts << endl;
    TGraphErrors tal_open;
    for (int i = 0; i < talium_open.size(); i++){
        tal_open.SetPoint(i, talium_open[i].first, talium_open[i].second);
        tal_open.SetPointError(i, 0, sqrt(talium_open[i].second));
    }
    CustomizeGraph(tal_open, kBlue, kBlue, "Talio", "Channels", "Counts");
    tal_open.Draw("APL");
    SaveCanvas(c1, "graphs/Talio_open.png");

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
    SaveCanvas(c1, "graphs/Talio_both.png");

    //////////////////////////////// Césio ////////////////////////////////
    vector<pair<double, double>> cesio;
    ReadFile("data/cesium.dat", cesio);
    TGraphErrors ces;
    for (int i = 0; i < cesio.size(); i++){
        ces.SetPoint(i, cesio[i].first, cesio[i].second);
        ces.SetPointError(i, 0, sqrt(cesio[i].second));
    }
    CustomizeGraph(ces, kGreen, kGreen, "Cesio", "Channels", "Counts");
    ces.Draw("APL");
    SaveCanvas(c1, "graphs/Cesio.png");

    // Find peaks for further analysis
    double cesium_peak_channels = find_max(100, 150, cesio);
    double cesium_peak_theoretical_energy = 624.216;

    //////////////////////////////// Strontium ////////////////////////////////
    vector<pair<double, double>> strontium;
    ReadFile("data/strontium.dat", strontium);
    TGraphErrors str;
    for (int i = 0; i < strontium.size(); i++){
        str.SetPoint(i, strontium[i].first, strontium[i].second);
        str.SetPointError(i, 0, sqrt(strontium[i].second));
    }
    CustomizeGraph(str, kBlack, kBlack, "Estroncio", "Channels", "Counts");
    str.Draw("APL");
    SaveCanvas(c1, "graphs/Estroncio.png");

    /// Find Number of Counts
    double counts_one2 = 0;
    double counts_two2 = 0;
    double counts_three2 = 0;
    double counts_four2 = 0;

    for(int i = 0; i < strontium.size(); i++){
        if(strontium[i].first > 100 && strontium[i].first < 107){
            counts_one2 += strontium[i].second;
        }
        if(strontium[i].first > 116 && strontium[i].first < 126){
            counts_two2 += strontium[i].second;
        }
        if(strontium[i].first > 208 && strontium[i].first < 213){
            counts_three2 += strontium[i].second;
        }
        if(strontium[i].first > 225 && strontium[i].first < 231){
            counts_four2 += strontium[i].second;
        }
    }

    cout << "Counts in first peak Str: " << counts_one - counts_one2 << endl;
    cout << "Counts in second peak: " << counts_two - counts_two2 << endl;
    cout << "Counts in third peak: " << counts_three - counts_three2 << endl;
    cout << "Counts in fourth peak: " << counts_four - counts_four2 << endl << endl;

    //////////////////////////////// Pontos de Calibração ////////////////////////////////
    /*
    vector<pair<double, double>> calib;
    ReadFile("data/calib.dat", calib);
    TGraphErrors cal;
    for (int i = 0; i < calib.size(); i++){
        cal.SetPoint(i, calib[i].first, calib[i].second);
        cal.SetPointError(i, 0, sqrt(calib[i].second));
    }
    CustomizeGraph(cal, kBlack, kBlack, "Calibracao", "Channels", "Counts");
    c1.Clear();
    cal.Draw("APL");
    c1.Update();
    c1.SaveAs("graphs/Calib.png");
    c1.WaitPrimitive();
    gSystem->ProcessEvents();
    */

    //////////////////////////////// Talium + Aluminum ////////////////////////////////
    vector<pair<double, double>> taliumAl;
    ReadFile("data/talium_closedAl.dat", taliumAl);
    TGraphErrors talAl;
    for (int i = 0; i < taliumAl.size(); i++){
        talAl.SetPoint(i, taliumAl[i].first, taliumAl[i].second);
        talAl.SetPointError(i, 0, sqrt(taliumAl[i].second));
    }
    CustomizeGraph(talAl, kBlue, kBlue, "Talio com placa de Aluminio", "Channels", "Counts");
    talAl.Draw("APL");
    SaveCanvas(c1, "graphs/TalioAluminio.png");

    //////////////////////////////// Cesium + Aluminum ////////////////////////////////
    vector<pair<double, double>> cesiumAl;
    ReadFile("data/cesiumAl.dat", cesiumAl);
    TGraphErrors cesAl;
    for (int i = 0; i < cesiumAl.size(); i++){
        cesAl.SetPoint(i, cesiumAl[i].first, cesiumAl[i].second);
        cesAl.SetPointError(i, 0, sqrt(cesiumAl[i].second));
    }
    CustomizeGraph(cesAl, kGreen, kGreen, "Cesio com placa de Aluminio", "Channels", "Counts");
    cesAl.Draw("APL");
    SaveCanvas(c1, "graphs/CesioAluminio.png");

    //////////////////////////////// Bismuth + Air ////////////////////////////////
    vector<pair<double, double>> bismuthAir;
    ReadFile("data/bis_air.dat", bismuthAir);
    TGraphErrors bisAir;
    for (int i = 0; i < bismuthAir.size(); i++){
        bisAir.SetPoint(i, bismuthAir[i].first, bismuthAir[i].second);
        bisAir.SetPointError(i, 0, sqrt(bismuthAir[i].second));
    }
    CustomizeGraph(bisAir, kBlue, kBlue, "Bismuto com ar", "Channels", "Counts");
    bisAir.Draw("APL");
    SaveCanvas(c1, "graphs/BismutoAr.png");

    //////////////////////////////// Bismuth + Car ////////////////////////////////
    vector<pair<double, double>> bismuthCar;
    ReadFile("data/bis_car.dat", bismuthCar);
    TGraphErrors bisCar;
    for (int i = 0; i < bismuthCar.size(); i++){
        bisCar.SetPoint(i, bismuthCar[i].first, bismuthCar[i].second);
        bisCar.SetPointError(i, 0, sqrt(bismuthCar[i].second));
    }
    CustomizeGraph(bisCar, kOrange, kOrange, "Bismuto com cartao", "Channels", "Counts");
    bisCar.Draw("APL");
    SaveCanvas(c1, "graphs/BismutoCartao.png");

    //////////////////////////////// Bismuth + Acrylic ////////////////////////////////
    vector<pair<double, double>> bismuthAcrylic;
    ReadFile("data/bis_acr.dat", bismuthAcrylic);
    TGraphErrors bisAcr;
    for (int i = 0; i < bismuthAcrylic.size(); i++){
        bisAcr.SetPoint(i, bismuthAcrylic[i].first, bismuthAcrylic[i].second);
        bisAcr.SetPointError(i, 0, sqrt(bismuthAcrylic[i].second));
    }
    CustomizeGraph(bisAcr, kGreen, kGreen, "Bismuto com acrilico", "Channels", "Counts");
    bisAcr.Draw("APL");
    SaveCanvas(c1, "graphs/BismutoAcrilico.png");


    //////////////////////////////// Bismuth with All 3 Materials ////////////////////////////////
    leg.Clear();
    leg.SetHeader("Bismuto");
    leg.AddEntry(&bis, "Bismuto", "l");
    leg.AddEntry(&bisAir, "Bismuto com ar", "l");
    leg.AddEntry(&bisCar, "Bismuto com cartao", "l");
    leg.AddEntry(&bisAcr, "Bismuto com acrilico", "l");
    bis.Draw("APL");
    bisAir.Draw("PL");
    bisCar.Draw("PL");
    bisAcr.Draw("PL");
    leg.Draw();
    SaveCanvas(c1, "graphs/Bismuto_Atenuation.png");

    //////////////////////////////// Calibration Function ////////////////////////////////
    // Using Bismuth Peaks 
    gStyle->SetOptFit(kTRUE);
    vector<double> theoretical_peaks = {481.694, 555.251, 975.655, 1049.211};
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
    
    CustomizeGraph(calibration, kRed, kRed, "Calibration", "Channels", "Energy [keV]");
    calibration.SetMarkerStyle(20);
    
    TF1 *calibrationFunction = new TF1("calibrationFunction", "[0] + [1]*x", 0, 300);
    calibrationFunction->SetParameter(0, 0);
    calibrationFunction->SetParameter(1, 1);
    calibrationFunction->SetParName(0, "intercept");
    calibrationFunction->SetParName(1, "slope");
    calibration.Fit("calibrationFunction", "RQ"); // R = fit between range, Q = quiet
    calibration.Draw("APL"); 
    SaveCanvas(c1, "graphs/Calibration.png");
    cout << "Pico do Césio Experimental: " << calibrationFunction->Eval(cesium_peak_channels) << endl << endl;

    // inverse calibration
    TGraphErrors inverseCalibration;
    inverseCalibration.SetPoint(0, first_theoretical, first_experimental);
    inverseCalibration.SetPoint(1, second_theoretical, second_experimental);
    inverseCalibration.SetPoint(2, third_theoretical, third_experimental);
    inverseCalibration.SetPoint(3, fourth_theoretical, fourth_experimental);
    CustomizeGraph(inverseCalibration, kRed, kRed, "Inverse Calibration", "Energy [keV]", "Channels", 0, 1200, 20);
    
    TF1 f = TF1("f", "[0]*x+[1]", 0, 1200);
    f.SetParName(0, "slope");
    f.SetParName(1, "intercept");
    inverseCalibration.Fit("f", "RQ");
    
    inverseCalibration.Draw("APL");
    f.Draw("same");
    inverseCalibration.SetTitle("Inverse Calibration");
    c1.Update();
    c1.SaveAs("graphs/InverseCalibration.png");
    c1.WaitPrimitive();
    gSystem->ProcessEvents();
    gStyle->SetOptFit(kFALSE); 

    //////////////////////////////// Resolução ////////////////////////////////

    //Os vetores vão ter 6 valores, relativos aos picos K, L, M, K, L, M
    vector<double> centroides = {
        calibrationFunction->Eval(gaus1->GetParameter(1)),
        calibrationFunction->Eval(gaus2->GetParameter(1)),
        calibrationFunction->Eval(gaus2->GetParameter(4)),
        calibrationFunction->Eval(gaus3->GetParameter(1)),
        calibrationFunction->Eval(gaus4->GetParameter(1)),
        calibrationFunction->Eval(gaus4->GetParameter(4)),
    };
    vector<double> erro_centroides = {
        calibrationFunction->Eval(gaus1->GetParError(1)),
        calibrationFunction->Eval(gaus2->GetParError(1)),
        calibrationFunction->Eval(gaus2->GetParError(4)),
        calibrationFunction->Eval(gaus3->GetParError(1)),
        calibrationFunction->Eval(gaus4->GetParError(1)),
        calibrationFunction->Eval(gaus4->GetParError(4)),
    };
    /*
    vector<double> sigma = {
        calibrationFunction->GetParameter(1)*gaus1->GetParError(2),
        calibrationFunction->GetParameter(1)*gaus2->GetParError(2),
        calibrationFunction->GetParameter(1)*gaus2->GetParError(5),
        calibrationFunction->GetParameter(1)*gaus3->GetParError(2),
        calibrationFunction->GetParameter(1)*gaus4->GetParError(2),
        calibrationFunction->GetParameter(1)*gaus4->GetParError(5)
    };
    vector<double> erro_sigma = {
        calibrationFunction->GetParameter(1)*gaus1->GetParError(2),
        calibrationFunction->GetParameter(1)*gaus2->GetParError(2),
        calibrationFunction->GetParameter(1)*gaus2->GetParError(5),
        calibrationFunction->GetParameter(1)*gaus3->GetParError(2),
        calibrationFunction->GetParameter(1)*gaus4->GetParError(2),
        calibrationFunction->GetParameter(1)*gaus4->GetParError(5)
    };
    */
    vector<double> sigma = {
        calibrationFunction->GetParameter(1)*1.29,
        calibrationFunction->GetParameter(1)*1.25,
        calibrationFunction->GetParameter(1)*1.17,
        calibrationFunction->GetParameter(1)*0.89,
        calibrationFunction->GetParameter(1)*0.84,
        calibrationFunction->GetParameter(1)*0.65
    };
    vector<double> erro_sigma = {
        calibrationFunction->GetParameter(1)*0.05,
        calibrationFunction->GetParameter(1)*0.11,
        calibrationFunction->GetParameter(1)*0.07,
        calibrationFunction->GetParameter(1)*0.08,
        calibrationFunction->GetParameter(1)*0.13,
        calibrationFunction->GetParameter(1)*0.12
    };
    
    gStyle->SetOptFit(kTRUE);
    TGraphErrors G_resolucao;
    for (int i = 0; i < 6; i++){
        cout << "Centroide: " << centroides[i]  << " +- " << erro_centroides[i] << endl;
        cout << "Sigma [CHN]: " << sigma[i]/calibrationFunction->GetParameter(1) << " +- " << erro_sigma[i]/calibrationFunction->GetParameter(1) << endl;
        cout << "FWHM: " << sigma[i]*2.355 << " +- " << erro_sigma[i]*2.355 << endl;
        cout << "R: " << sigma[i]*2.355/centroides[i] << " +- " << abs(471 / 200 / centroides[i]) * erro_sigma[i] + abs(sigma[i] * -471 / 200 / (centroides[i]*centroides[i])) * erro_centroides[i] << endl;
        cout << "------------" << endl;
        G_resolucao.SetPoint(i, centroides[i], sigma[i]*2.355/centroides[i]);
        G_resolucao.SetPointError(i, erro_centroides[i], abs(471 / 200 / centroides[i]) * erro_sigma[i] + abs(sigma[i] * -471 / 200 / (centroides[i]*centroides[i])) * erro_centroides[i]);
    }
    CustomizeGraph(G_resolucao, kRed, kRed, "Dependencia da Resolucao com a Energia", "Energia [keV]", "Resolucao");
    TF1 f_resolucao = TF1("f_resolucao", "[0]/sqrt(x)+[1]", 0, 1200);
    f_resolucao.SetParName(0, "slope");
    f_resolucao.SetParName(1, "intercept");
    G_resolucao.Fit("f_resolucao", "R");

    c1.Clear();
    G_resolucao.Draw("AP");
    f_resolucao.Draw("same");
    c1.Update();
    c1.SaveAs("graphs/Resolucao.png");
    c1.WaitPrimitive();
    gSystem->ProcessEvents();
    gStyle->SetOptFit(kFALSE);

    ///////////////////////////////////////////////////////////////////////////

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
    CustomizeGraph(polyethylene_stopping_powers, kRed, kRed, "Polyethylene Stopping Powers", "Kinetical Energy [MeV]", "Stopping Power [MeV cm^{2}/g]", 0, 1);

    c1.SetLogx();
    c1.SetLogy();
    c1.Clear();
    polyethylene_stopping_powers.Draw("APL");
    SaveCanvas(c1, "graphs/Polyethylene_Stopping_Powers.png");

    // Composition of Polyethylene
    double density = 0.94; // g/cm^3
    double mean_excitation_energy = 57.4; // eV

    // Thickness of Polyethylene by Num. Integration
    double integral = 0;
    for(int i = 0; i < KineticalEnergy.size(); i++){
        if(KineticalEnergy[i]*1000 > calibrationFunction->Eval(cesium_peak_channels) && KineticalEnergy[i]*1000 < cesium_peak_theoretical_energy){
            double dx = KineticalEnergy[i] - KineticalEnergy[i - 1];
            integral += (1/(Total[i] * density) + 1/(Total[i - 1] * density)) * dx / 2.0;
        }
    }
    cout << "Thickness of Poly by Num. Integration "<< integral << endl;

    vector<double> KineticalEnergy2;
    vector<double> Collision2;
    vector<double> Radiative2;
    vector<double> Total2;
    vector<double> CSDA2;
    vector<double> Y2;
    vector<double> Param2;

    ReadFile("data/polyethylene_no_use.dat", KineticalEnergy2, Collision2, Radiative2, Total2, CSDA2,Param2);
    TGraphErrors polyethylene_stopping_powers2 = TGraphErrors(KineticalEnergy2.size(), KineticalEnergy2.data(), CSDA2.data(), 0, 0);
    CustomizeGraph(polyethylene_stopping_powers2, kRed, kRed, "Polyethylene CSDA Range", "Kinetical Energy [MeV]", "CSDA [MeV cm^{2}/g]", 0, 1000);
    c1.SetLogx();
    c1.SetLogy();
    polyethylene_stopping_powers2.Draw("APL");
    c1.Update();
    c1.SaveAs("graphs/Polyethylene_CSDA_Range.png");
    c1.WaitPrimitive();
    gSystem->ProcessEvents();

    double integral2 = polyethylene_stopping_powers2.Eval(cesium_peak_theoretical_energy/1000);
    double integral3 = polyethylene_stopping_powers2.Eval(calibrationFunction->Eval(cesium_peak_channels)/1000);
    cout << "Thickness of Poly by Interpolation: "<< (integral2 - integral3) / density << endl << endl;

    // Reajust cesium spectrum
    double thickness = (integral2 - integral3) / density;
    TGraphErrors cesium_spectrum_reajusted;
    vector<pair<double, double>> cesio_kurie;
    double first = 0;
    double energy = 0;
    double difference2 = thickness/100;
    for (int i = 0; i < cesio.size(); i++){
        first = linearInterpolation(KineticalEnergy2, CSDA2, calibrationFunction->Eval(cesio[i].first)/1000);
        energy = 0;
        for(int j = i; j < KineticalEnergy.size(); j++){
            double second = linearInterpolation(KineticalEnergy2, CSDA2, KineticalEnergy[j]);
            if(abs(abs(second - first)/density - thickness) < difference2){
                energy = f.Eval(KineticalEnergy[j]*1000);
            }
            
        }
        cesium_spectrum_reajusted.SetPoint(i, energy, cesio[i].second);
        cesio_kurie.push_back(make_pair(energy, cesio[i].second));
    }

    CustomizeGraph(cesium_spectrum_reajusted, kRed, kRed, "Cesium Spectrum Reajusted", "Channels", "Counts", 0, 300);
    TLegend ces_leg = TLegend(0.65,0.65,0.85,0.75);
    ces_leg.AddEntry(&cesium_spectrum_reajusted, "Cesium Spectrum Reajusted", "l");
    ces_leg.AddEntry(&ces, "Cesium Spectrum", "l");

    c1.SetLogx(0);
    c1.SetLogy(0);
    c1.Clear();
    cesium_spectrum_reajusted.Draw("APL");
    ces.Draw("same");
    ces_leg.Draw();
    c1.Update();
    c1.SaveAs("graphs/Cesium_Spectrum_Reajusted.png");
    c1.WaitPrimitive();
    gSystem->ProcessEvents();

    // Reajust talium spectrum
    double thickness2 = (integral2 - integral3) / density;
    vector<pair<double, double>> reaj_talium_spectrum;
    TGraphErrors talium_spectrum_reajusted;
    double first2 = 0;
    double energy2 = 0;
    double difference3 = thickness2/100;
    for (int i = 0; i < talium.size(); i++){
        first2 = linearInterpolation(KineticalEnergy2, CSDA2, calibrationFunction->Eval(talium[i].first)/1000);
        energy2 = 0;
        for(int j = i; j < KineticalEnergy.size(); j++){
            double second2 = linearInterpolation(KineticalEnergy2, CSDA2, KineticalEnergy[j]);
            //second2 = polyethylene_stopping_powers2.Eval(KineticalEnergy[j]);
            if(abs(abs(second2 - first2)/density - thickness2) < difference3){
                energy2 = f.Eval(KineticalEnergy[j]*1000);
            }
            
        }
        reaj_talium_spectrum.push_back(make_pair(energy2, talium[i].second));
        talium_spectrum_reajusted.SetPoint(i, energy2, talium[i].second);
    }
    CustomizeGraph(talium_spectrum_reajusted, kBlack, kBlack, "Talium Spectrum Reajusted", "Channels", "Counts", 0, 300);
    
    TLegend t(0.65,0.65,0.85,0.75);
    t.AddEntry(&tal, "Closed Talium", "l");
    t.AddEntry(&talium_spectrum_reajusted, "Closed Talium Reajusted", "l");
    t.AddEntry(&tal_open, "Open Talium", "l");
    
    c1.Clear();
    tal_open.Draw("APL");
    talium_spectrum_reajusted.Draw("same");
    tal.Draw("same");
    t.Draw();
    c1.Update();
    c1.SaveAs("graphs/Talium_Spectrum_Reajusted.png");
    c1.WaitPrimitive();
    gSystem->ProcessEvents();

    /////////////////////////////////// Derivative of Closed Talium
    /*
    vector<pair<double, long double> > end_point_closed = calculateDerivative(reaj_talium_spectrum);
    TGraphErrors talium_spectrum_derivative_closed;
    for (int i = 0; i < end_point_closed.size(); i++){
        talium_spectrum_derivative_closed.SetPoint(i, end_point_closed[i].first, end_point_closed[i].second);
        talium_spectrum_derivative_closed.SetPointError(i, 0, sqrt(end_point_closed[i].second));
    }
    CustomizeGraph(talium_spectrum_derivative_closed, kBlack, kBlack, "Talium Spectrum Derivative Closed", "Channels", "Counts", 0, 300);

    c1.Clear();
    talium_spectrum_derivative_closed.Draw("APL");
    c1.Update();
    c1.SaveAs("graphs/Talium_Spectrum_Derivative_Closed.png");
    c1.WaitPrimitive();
    gSystem->ProcessEvents();
    double error_end_point_closed = 0.001;
    double error_end_point_open = 0.001;
    double value_end_point_closed = 0;
    for(int i = 0; i < end_point_closed.size(); i++){
        if(abs(end_point_closed[i].second) < error_end_point_closed && end_point_closed[i].first < 167){
            value_end_point_closed = end_point_closed[i].first;
            if(abs(end_point_closed[i].second) > 0){
                value_end_point_closed = end_point_closed[i].first;
            }
        }
    }
    cout << "Value end point closed: " << calibrationFunction->Eval(value_end_point_closed) << endl;
    */

    //TF1 *integral_one = new TF1("integral_one", "[0] * ([1] - x)^2 * sqrt(x^2 + 2 * x * 0.511) * (x + 0.511) / sqrt([1]) / (1 - exp(-[2]/sqrt([1])))", 0, 763.67);
    TF1 *integral_one = new TF1("integral_one", "[0] * ([1] - x)^2 * (1.002037 - 0.00147 * sqrt( (x/0.511 + 1)^2 -1)) / (x/0.511 + 1)", 0, 763.67);
    vector<pair<double, double> > integral_one_points;
    for(int i = 0; i < 300; i++){
        integral_one_points.push_back(make_pair(calibrationFunction->Eval(talium_open[i].first) /1000, talium_open[i].second));
    }
    TGraphErrors integral_one_graph;
    for(int i = 0; i < integral_one_points.size(); i++){
        integral_one_graph.SetPoint(i, integral_one_points[i].first, integral_one_points[i].second);
    }
    integral_one->SetParameter(0, 1200);
    integral_one->SetParameter(1, 763.67);
    integral_one->FixParameter(2, 26484);
    integral_one_graph.Fit("integral_one", "R");
    integral_one_graph.Draw("APL");
    c1.Update();
    c1.SaveAs("graphs/Integral_One.png");
    c1.WaitPrimitive();
    gSystem->ProcessEvents();

    ////////////////////////////// Derivative of Talium Open Spectrum //////////////////////////////
    vector<pair<double, double> > der_tal;
    ReadFile("data/talium_open_Smoothed_Smoothed.dat", der_tal);
    vector<pair<double, long double> > end_point = calculateDerivative(der_tal);
    TGraphErrors talium_spectrum_derivative;
    for (int i = 0; i < end_point.size(); i++){
        talium_spectrum_derivative.SetPoint(i, end_point[i].first, end_point[i].second);
        talium_spectrum_derivative.SetPointError(i, 0, sqrt(end_point[i].second));
    }
    CustomizeGraph(talium_spectrum_derivative, kRed, kRed, "Talium Spectrum Derivative", "Channels", "Counts", 0, 300);

    c1.Clear();
    talium_spectrum_derivative.Draw("APL");
    c1.Update();
    c1.SaveAs("graphs/Talium_Spectrum_Derivative.png");
    c1.WaitPrimitive();
    gSystem->ProcessEvents();
    double error_endpoint = 0.001;
    double value_end_point = 0;
    for(int i = 0; i < end_point.size(); i++){
        if(abs(end_point[i].second) < error_endpoint && end_point[i].first < 167){
            value_end_point = end_point[i].first;
            if(abs(end_point[i].second) > 0){
                value_end_point = end_point[i].first;
            }
        }
    }
    
    cout << "Zero Derivative EndPoint: "<< calibrationFunction->Eval(value_end_point) << endl << endl;
    /*TF1 *ajuste = new TF1("ajuste", "[0] * sqrt(x**2 + 2*x*0.511) * (x*0.511) * (x-[2])**2",70, 800);
    ajuste->SetParameter(0, 80);
    ajuste->SetParLimits(0, 50, 1000);
    ajuste->SetParameter(2, 167);
    ajuste->SetLineColor(kBlack);

    talium_spectrum_derivative.Fit("ajuste", "RQ");
    */
    c1.Clear();
    talium_spectrum_derivative.Draw("APL");
    //ajuste->Draw("same");
    c1.Update();
    //c1.SaveAs("graphs/Talium_Spectrum_Derivative_Fit.png");
    c1.WaitPrimitive();
    gSystem->ProcessEvents();
    
    // velocity of light to the power of 5? ... 3e8^5
    // what is mass of electron? ... 0.511 MeV/c^2


    //////////////// Strontium and Bismuth Spectrum ///////////////////////
    gStyle->SetOptFit(kFALSE);
    c1.Clear();
    TLegend *leg_str_bis = new TLegend(0.65, 0.65, 0.85, 0.75);
    leg_str_bis->SetHeader("Strontium and Bismuth Spectrum", "C");
    leg_str_bis->AddEntry(&str, "Strontium", "l");
    leg_str_bis->AddEntry(&bis, "Bismuth", "l");
    bis.Draw("APL");
    str.Draw("same");
    leg_str_bis->Draw();
    c1.Update();
    c1.SaveAs("graphs/Strontium_Bismuth_Spectrum_For_Thickness.png");
    c1.WaitPrimitive();
    gSystem->ProcessEvents();

    //////////////////////////////////// Find Thickness of Silicon Detector ////////////////////////////////////
    TF1 gaus_bismuth("gaus_bismuth", "gaus", 20, 43);
    TF1 gaus_strontium("gaus_strontium", "gaus", 20, 43);
    gaus_bismuth.SetParameter(0, 800);
    gaus_strontium.SetParameter(0, 600);
    gaus_bismuth.SetParameter(1, 23);
    gaus_strontium.SetParameter(1, 23);
    bis.Fit("gaus_bismuth", "RQ");
    str.Fit("gaus_strontium", "RQ");
    double mean_bismuth = gaus_bismuth.GetParameter(1);
    double mean_strontium = gaus_strontium.GetParameter(1);
    double sigma_bismuth = gaus_bismuth.GetParameter(2);
    double sigma_strontium = gaus_strontium.GetParameter(2);
    gaus_bismuth.SetLineColor(kRed);
    gaus_strontium.SetLineColor(kBlue);
    gaus_bismuth.SetLineStyle(2);
    gaus_strontium.SetLineStyle(2);
    gaus_bismuth.SetLineWidth(2);
    gaus_strontium.SetLineWidth(2);
    gaus_bismuth.Draw("same");
    gaus_strontium.Draw("same");
    c1.Update();
    c1.SaveAs("graphs/Strontium_Bismuth_Spectrum_For_Thickness_Fit.png");
    c1.WaitPrimitive();
    gSystem->ProcessEvents();

    double mean_channels = (mean_bismuth + mean_strontium) / 2;
    double mean_channels_energy = calibrationFunction->Eval(mean_channels);

    vector<double> KineticalEnergySilicon;
    vector<double> CollisionSilicon;
    vector<double> RadiativeSilicon;
    vector<double> TotalSilicon;
    vector<double> CSDASilicon;
    vector<double> YSilicon;
    vector<double> ParamSilicon;
    double silicon_density = 2.33;

    ReadFile("data/silicon_one.dat", KineticalEnergySilicon, CollisionSilicon, RadiativeSilicon, TotalSilicon, CSDASilicon, ParamSilicon);
    TGraphErrors silicon_graph_normal = TGraphErrors(KineticalEnergySilicon.size(), KineticalEnergySilicon.data(), TotalSilicon.data(), 0, 0);
    CustomizeGraph(silicon_graph_normal, kRed, kRed, "Silicon Normal", "Kinetic Energy [MeV]", "Total Stopping Power [MeV cm^{2} g^{-1}]", 0, 1000);
    c1.SetLogx();
    c1.SetLogy();
    c1.Clear();
    silicon_graph_normal.Draw("APL");
    c1.Update();
    c1.SaveAs("graphs/Silicon_Stopping_Power.png");
    c1.WaitPrimitive();
    gSystem->ProcessEvents();
    double testar = 0;
    double control = 0;
    for(int i = 0; i < KineticalEnergySilicon.size(); i++){
        if(KineticalEnergySilicon[i] >= 1 && KineticalEnergySilicon[i] <= 3){
            testar += TotalSilicon[i];
            control++;
        }
    }
    cout << "Silicon Thickness: " << mean_channels_energy / 1000/ (testar / control * silicon_density) * 10000 << " microns" << endl << endl;

    //////////////// TGraph 1/Stopping Power * density ///////////////////////
    TGraphErrors silicon_graph_normal_density;
    for (int i = 0; i < KineticalEnergySilicon.size(); i++){
        silicon_graph_normal_density.SetPoint(i, KineticalEnergySilicon[i], 1 / TotalSilicon[i] / silicon_density);
        silicon_graph_normal_density.SetPointError(i, 0, 0);
    }
    CustomizeGraph(silicon_graph_normal_density, kRed, kRed, "Silicon Normal", "Kinetic Energy [MeV]", "1 / Stopping Power * Density [cm MeV^{-1}]");
    c1.Clear();
    silicon_graph_normal_density.Draw("APL");
    c1.Update();
    c1.SaveAs("graphs/Silicon_1_Stopping_Power_Density.png");
    c1.WaitPrimitive();
    gSystem->ProcessEvents();
    
    
    
    TGraphErrors silicon_graph;
    for (int i = 0; i < KineticalEnergySilicon.size(); i++){
        silicon_graph.SetPoint(i, KineticalEnergySilicon[i], CSDASilicon[i] / silicon_density);
        silicon_graph.SetPointError(i, 0, 0);
    }
    CustomizeGraph(silicon_graph, kRed, kRed, "Silicon CSDA", "Kinetic Energy [MeV]", "CSDA [cm]", 0, 1000);
    c1.Clear();
    silicon_graph.Draw("APL");
    c1.Update();
    c1.SaveAs("graphs/Silicon_CSDA.png");
    c1.WaitPrimitive();
    gSystem->ProcessEvents();
    c1.SetLogx(0);
    c1.SetLogy(0);

    //////////////////////////////////////////// Kurie Plot ////////////////////////////////////////////
    vector<double> P = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0, 1.2, 1.4, 1.6, 1.8, 2, 2.2, 2.4};
    vector<double> G = {28.26, 28.19, 27.99, 27.67, 27.25, 26.76, 26.23, 25.66, 25.09, 24.53, 23.98, 22.95, 22.01, 21.17, 20.41, 19.72, 19.10, 18.54};

    TGraphErrors kurie_graph = TGraphErrors(P.size(), P.data(), G.data(), 0, 0);
    TSpline5 *kurie_spline = new TSpline5("kurie_spline", &kurie_graph);
    CustomizeGraph(kurie_graph, kRed, kRed, "Fermi Modified Function", "P", "G(Z, W)", 0, 2.5);
    c1.Clear();
    kurie_graph.Draw("AP");
    kurie_spline->Draw("same C");
    SaveCanvas(c1, "graphs/CubicSplineInterpolation.png");

    // Kurie Plot for Open Talium
    gStyle->SetOptFit(1);
    TGraphErrors kurie_graph_open_talium;
    for(int i = 0; i < talium_open.size(); i++){
        double x = calibrationFunction->Eval(talium_open[i].first);
        double W = x / 511 + 1;
        double P = sqrt(W * W - 1);
        double G = kurie_spline->Eval(P);
        double N = talium_open[i].second;
        double y = 1/W * sqrt(N/G);

        double set_point_error = 1/(W*W*W*W)*sqrt(N/G) * 0.5 * (0.1/0.511) * (0.1 / 0.511) + 1 / (4 * W * W * G);
        kurie_graph_open_talium.SetPoint(i, x, y);
        kurie_graph_open_talium.SetPointError(i, 0, set_point_error);
    }

    CustomizeGraph(kurie_graph_open_talium, kRed, kRed, "Kurie Plot for Open Talium", "Energy [keV]", "#frac{1}{W} #sqrt{#frac{N}{G}}"
, 0, 800);

    TF1 *kurie_fit = new TF1("kurie_fit", "[0] * x + [1]", 70, 720);
    kurie_graph_open_talium.Fit(kurie_fit, "RQ");
    kurie_graph_open_talium.Draw("AP");
    kurie_fit->Draw("same");
    c1.Update();
    c1.SaveAs("graphs/KuriePlotOpenTalium.png");
    c1.WaitPrimitive();
    double s_m = kurie_fit->GetParError(0);
    double s_b = kurie_fit->GetParError(1);
    double m = kurie_fit->GetParameter(0);
    double b = kurie_fit->GetParameter(1);
    double s_ratio = sqrt(pow((s_b/m),2) + pow((pow(b/m, 2) * s_m), 2));
    double ratio = b/m;
    double end_point_theoretical = 763.7;
    cout << "EndPoint for Open Talium: " << abs(ratio) << " +- " << s_ratio << endl;
    cout << "Error Exp %" << (abs(ratio) - end_point_theoretical) / end_point_theoretical  * 100<< endl;


    // Kurie Plot for Closed Talium Recalibrated
    TGraphErrors kurie_graph_closed_talium;
    for(int i = 0; i < talium_spectrum_reajusted.GetN(); i++){
        double x = calibrationFunction->Eval(talium_spectrum_reajusted.GetX()[i]);
        double W = x / 511 + 1;
        double P = sqrt(W * W - 1);
        double G = kurie_spline->Eval(P);
        double N = talium_spectrum_reajusted.GetY()[i];
        double y = 1/W * sqrt(N/G);

        double set_point_error = 1/(W*W*W*W)*sqrt(N/G) * 0.5 * (0.1/0.511) * (0.1 / 0.511) + 1 / (4 * W * W * G);
        kurie_graph_closed_talium.SetPoint(i, x, y);
        kurie_graph_closed_talium.SetPointError(i, 0, set_point_error);
    }

    CustomizeGraph(kurie_graph_closed_talium, kRed, kRed, "Kurie Plot for Closed Talium", "Energy [keV]", "#frac{1}{W} #sqrt{#frac{N}{G}}", 0, 800, 2);

    TF1 *kurie_fit2 = new TF1("kurie_fit2", "[0] * x + [1]", 300, 780);
    kurie_graph_closed_talium.Fit(kurie_fit2, "RQ");
    c1.Clear();
    kurie_graph_closed_talium.Draw("AP");
    kurie_fit2->Draw("same");
    SaveCanvas(c1, "graphs/KuriePlotClosedTaliumReajusted.png");

    double s_m2 = kurie_fit2->GetParError(0);
    double s_b2 = kurie_fit2->GetParError(1);
    double m2 = kurie_fit2->GetParameter(0);
    double b2 = kurie_fit2->GetParameter(1);
    double s_ratio2 = sqrt(pow((s_b2/m2),2) + pow((pow(b2/m2, 2) * s_m2), 2));
    double ratio2 = b2/m2;
    cout << "EndPoint for Closed Talium Recalibrated: " << abs(ratio2) << " +- " << s_ratio2 << endl;
    cout << "Error Exp %" << (abs(ratio2) - end_point_theoretical) / end_point_theoretical  * 100<< endl;

    // Kurie Plot for Cesium Kurie
    TGraphErrors kurie_graph_cesium;
    for(int i = 0; i < cesium_spectrum_reajusted.GetN(); i++){
        double x = calibrationFunction->Eval(cesium_spectrum_reajusted.GetX()[i]);
        double W = x / 511 + 1;
        double P = sqrt(W * W - 1);
        double G = kurie_spline->Eval(P);
        double N = cesium_spectrum_reajusted.GetY()[i];
        double y = 1/W * sqrt(N/G);

        double set_point_error = 1/(W*W*W*W)*sqrt(N/G) * 0.5 * (0.1/0.511) * (0.1 / 0.511) + 1 / (4 * W * W * G);
        kurie_graph_cesium.SetPoint(i, x, y);
        kurie_graph_cesium.SetPointError(i, 0, set_point_error);
    }

    CustomizeGraph(kurie_graph_cesium, kRed, kRed, "Kurie Plot for Cesium", "Energy [keV]", "#frac{1}{W} #sqrt{#frac{N}{G}}", 0, 800, 2);

    TF1 *kurie_fit3 = new TF1("kurie_fit3", "[0] * x + [1]", 280, 490);
    kurie_graph_cesium.Fit(kurie_fit3, "RQ");
    c1.Clear();
    kurie_graph_cesium.Draw("AP");
    kurie_fit3->Draw("same");
    SaveCanvas(c1, "graphs/KuriePlotCesium.png");

    double s_m3 = kurie_fit3->GetParError(0);
    double s_b3 = kurie_fit3->GetParError(1);
    double m3 = kurie_fit3->GetParameter(0);
    double b3 = kurie_fit3->GetParameter(1);
    double s_ratio3 = sqrt(pow((s_b3/m3),2) + pow((pow(b3/m3, 2) * s_m3), 2));
    double ratio3 = b3/m3;
    cout << "EndPoint for Cesium: " << abs(ratio3) << " +- " << s_ratio3 << endl;
    cout << "Error Exp %" << (abs(ratio3) - end_point_theoretical) / end_point_theoretical  * 100<< endl;





}