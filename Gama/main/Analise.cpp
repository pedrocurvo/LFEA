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

int main(){
    int n;
    // Create Application
    TApplication A("A", nullptr, nullptr);
    // Create Canvas
    TCanvas c1("c1", "c1", 1200, 800); 
    double acq_time = 150;
    double acq_time_amb = 1200;


    // Calibration
    TGraph CalibratioGraph;
    vector<pair<double, double>> calibration;
    //Energy = [32, 662, 1173, 1333] # Cs and Co energies
    // Channels = [28.8, 437.07, 760.24, 861.42] # Cs-137 and Co-60 channels
    calibration.push_back(pair<double, double> (28.8, 32.2));
    calibration.push_back(pair<double, double> (436.07, 661.7));
    calibration.push_back(pair<double, double> (760.24, 1173.2));
    calibration.push_back(pair<double, double> (861.42, 1332.5));
    calibration.push_back(pair<double, double> (0.01, 0.1));
    calibration.push_back(pair<double, double> (0.04, 0.1));
    calibration.push_back(pair<double, double> (0.32, 0.1));
    calibration.push_back(pair<double, double> (0.36, 0.1));
    int m = 0;
    for (int i = 0; i < calibration.size()/2; i++){
        //m = CalibratioGraph.GetN();
        CalibratioGraph.AddPoint(calibration[i].first, calibration[i].second);
        //CalibratioGraph.SetPointError(m, calibration[i+4].first, calibration[i+4].second);
    }
    CalibratioGraph.SetLineColor(kRed);
    CalibratioGraph.SetMarkerStyle(20);
    CalibratioGraph.SetMarkerSize(1.5);
    CalibratioGraph.SetTitle("Calibration; Channels; Energy [keV]");
    CalibratioGraph.GetXaxis()->CenterTitle();
    CalibratioGraph.GetYaxis()->CenterTitle();
    CalibratioGraph.GetXaxis()->SetLimits(0, 1024);
    CalibratioGraph.GetYaxis()->SetLimits(0, 1400);
    CalibratioGraph.Draw("AP");
    TF1 *f1 = new TF1("f1", "[0]*x+[1]");
    f1->SetParNames("declive","y_{0}");
    CalibratioGraph.Fit("f1");
    double slope = f1->GetParameter(0);
    double intercept = f1->GetParameter(1);
    
    c1.Update();
    c1.SaveAs("Graphs/Calibracao.png");
    c1.WaitPrimitive();
    gSystem->ProcessEvents();

    
    // Espetro de Radiação do Ambiente
    gStyle->SetOptFit(kTRUE);
    TGraphErrors G_Amb; 
    vector<pair<double, double>> rad_ambiente;
    ReadFile("Data_Files/Ruido_Energy.dat", rad_ambiente);
    for (int i = 0; i < rad_ambiente.size(); i++){
        n = G_Amb.GetN();
        G_Amb.SetPoint(n, rad_ambiente[i].first, rad_ambiente[i].second);
        G_Amb.SetPointError(n,0/*0.006*rad_ambiente[i].first+3.6*/,sqrt(rad_ambiente[i].second));
    }
    G_Amb.SetLineColor(kGray+1);
    G_Amb.SetMarkerStyle(20);
    G_Amb.SetMarkerSize(0.5);
    G_Amb.SetTitle("Espetro de Radiacao Ambiente; E [keV]; Counts");
    G_Amb.GetXaxis()->CenterTitle();
    G_Amb.GetYaxis()->CenterTitle();


    // Espetro de Radiacao Ambiente Smoothed
    TGraph G_Amb_Smoothed;
    vector<pair<double, double>> rad_ambiente_smoothed;
    ReadFile("Data_Files/Ruido_Energy_Smoothed.dat", rad_ambiente_smoothed);
    for(int i=0; i<rad_ambiente_smoothed.size(); i++){
        G_Amb_Smoothed.AddPoint(rad_ambiente_smoothed[i].first, rad_ambiente_smoothed[i].second);
    }
    G_Amb_Smoothed.SetLineColor(kRed);
    G_Amb_Smoothed.SetMarkerStyle(20);
    G_Amb_Smoothed.SetMarkerSize(0.5);
    G_Amb_Smoothed.SetLineWidth(3);

    TF1 *F_Amb = new TF1("F_Amb", "[0]*exp(-0.5*((x-[1])/[2])**2)", 1400, 1510);
    F_Amb->SetParNames("C","#mu", "#sigma");
    F_Amb->SetParameters(50, 1460, 30);
    F_Amb->SetLineColor(kBlue);
    G_Amb.Fit("F_Amb","","",1400,1510);

    // Create a legend
    TLegend* ambient = new TLegend(0.65, 0.75, 0.85, 0.85); // Specify the position of the legend
    
    // Add an entry to the legend
    ambient->AddEntry(&G_Amb, "Signal", "l"); // "p" for a point
    ambient->AddEntry(&G_Amb_Smoothed, "Clear Signal", "l"); // "l" for a solid line
    ambient->AddEntry(F_Amb, "Fit", "l");

    c1.Clear();
    G_Amb.Draw("AP");
    G_Amb_Smoothed.Draw("same C");
    F_Amb->Draw("same C");
    ambient->Draw();
    c1.SetLogy();
    c1.Update();
    c1.SaveAs("Graphs/Espetro_Ambiente_Smoothed.png");
    c1.WaitPrimitive();
    //A.Run("TRUE");
    gSystem->ProcessEvents();

        
//////////////////////////////////// Cs-137  ////////////////////////////////////
    // Espetro de Radiação do Cs-137 
    gStyle->SetOptFit(kFALSE);
    TGraphErrors G_Cs;
    n=0;
    vector<pair<double, double>> rad_cs;
    ReadFile("Data_Files/Cesio_Energy.dat", rad_cs);
    for (int i = 0; i < rad_cs.size(); i++){
        if(rad_cs[i].first < 720){
            n = G_Cs.GetN();
            G_Cs.SetPoint(n, rad_cs[i].first, rad_cs[i].second);
            G_Cs.SetPointError(n,0/*0.006*rad_cs[i].first+3.6*/,sqrt(rad_cs[i].second));
        }
    }
    G_Cs.SetLineColor(kGray+1);
    G_Cs.SetMarkerStyle(20);
    G_Cs.SetMarkerSize(0.5);
    G_Cs.SetTitle("Espetro de Radiacao do Cs-137; E [keV]; Counts");
    G_Cs.GetXaxis()->CenterTitle();
    G_Cs.GetYaxis()->CenterTitle();

    // Espetro de Radiaçao do Cs-137 Smoothed
    TGraph G_Cs_Smoothed;
    vector<pair<double, double>> rad_cs_smoothed;
    ReadFile("Data_Files/Cesio_Energy_Smoothed.dat", rad_cs_smoothed);
    for (int i = 0; i < rad_cs_smoothed.size(); i++){
        if(rad_cs_smoothed[i].first < 720){
        G_Cs_Smoothed.AddPoint(rad_cs_smoothed[i].first, rad_cs_smoothed[i].second);
        }
    }
    G_Cs_Smoothed.SetLineColor(kRed);
    G_Cs_Smoothed.SetMarkerStyle(20);
    G_Cs_Smoothed.SetMarkerSize(0.5);
    G_Cs_Smoothed.SetLineWidth(3);
    G_Cs_Smoothed.SetTitle("Espetro de Radiacao do Cs-137 Smoothed; E [keV]; Counts");
    G_Cs_Smoothed.GetXaxis()->CenterTitle();
    G_Cs_Smoothed.GetYaxis()->CenterTitle();
    
    TF1 *F_Cs2 = new TF1("F_Cs2", "[0]*exp(-0.5*((x-[1])/[2])**2)", 175, 220);
    F_Cs2->SetParNames("C","#mu", "#sigma");
    F_Cs2->SetParameters(200, 184, 20);
    F_Cs2->SetLineColor(kGreen);
    G_Cs.Fit("F_Cs2","","",175,220);
    
    TF1 *F_Cs1 = new TF1("F_Cs1", "[0]*exp(-0.5*((x-[1])/[2])**2)", 23, 36.5);
    F_Cs1->SetParameters(2000, 27, 2);
    F_Cs1->SetLineColor(kBlue);
    G_Cs.Fit("F_Cs1","","",23,36.5);
    
    TF1 *F_Cs3 = new TF1("F_Cs3", "[0]*exp(-0.5*((x-[1])/[2])**2)", 615, 720);
    F_Cs3->SetParameters(1000, 650, 50);
    F_Cs3->SetLineColor(kBlue);
    G_Cs.Fit("F_Cs3","","",615,720);
    
    // Backscatter Peak
    TGraph Cs_Backscatter;
    double x_p1 = 130, x_p2 = 255;
    double medium_x1 = (x_p1 + x_p2) / 2;
    int inte1 = 0;
    for (int i = 0; i < rad_cs_smoothed.size(); i++){
        if (rad_cs[i].first > medium_x1){
            cout << "Backscatter Peak: " << rad_cs_smoothed[i].first << endl;
            inte1 = i;
            break;
        }
    }
    Cs_Backscatter.AddPoint(rad_cs_smoothed[inte1].first, rad_cs_smoothed[inte1].second);
    Cs_Backscatter.AddPoint(184, 0);
    Cs_Backscatter.SetMarkerSize(1.5);
    Cs_Backscatter.SetMarkerStyle(22);
    Cs_Backscatter.SetMarkerColor(kGreen+2);

    // Compton Edge
    // Find the Compton Edge for Cs-137
    double x_1 = 434, x_2 = 540;
    double medium_x = (x_1 + x_2) / 2;
    int inte = 0;
    for (int i = 0; i < rad_cs_smoothed.size(); i++){
        if (rad_cs[i].first > medium_x){
            cout << "Compton Edge: " << rad_cs_smoothed[i].first << endl;
            inte = i;
            break;
        }
    }
    TGraph Cs_Compton;
    Cs_Compton.AddPoint(rad_cs_smoothed[inte].first, rad_cs_smoothed[inte].second);
    Cs_Compton.SetMarkerSize(1.5);
    Cs_Compton.SetMarkerStyle(22);
    Cs_Compton.SetMarkerColor(kYellow+0);


    // Create a legend
    TLegend* cesio = new TLegend(0.65, 0.79, 0.90, 0.94); // Specify the position of the legend
    cesio->AddEntry(&G_Cs, "Signal", "l"); 
    cesio->AddEntry(&G_Cs_Smoothed, "Clear Signal", "l"); // "l" for a solid line
    cesio->AddEntry(F_Cs3, "Calibration Peaks Fit", "l"); // "l" for a solid line
    cesio->AddEntry(F_Cs2, "Back Scattering", "l"); // "l" for a solid line
    cesio->AddEntry(&Cs_Backscatter, "Backscatter Peak", "p"); // "p" for a point
    cesio->AddEntry(&Cs_Compton, "Compton Edge", "p"); // "p" for a point

    c1.Clear();
    G_Cs.Draw("AP");
    G_Cs_Smoothed.Draw("same C");
    F_Cs1->Draw("same C");
    F_Cs3->Draw("same C");
    F_Cs2->Draw("same C");
    Cs_Backscatter.Draw("same P");
    Cs_Compton.Draw("same P");
    cesio->Draw();
    c1.SetLogy();
    c1.Update();
    c1.SaveAs("Graphs/Espetro_Cs_Smoothed.png");
    c1.WaitPrimitive();
    //A.Run("TRUE");
    gSystem->ProcessEvents();
    //gStyle->SetOptFit(kFALSE);
        
//////////////////////////////////// Co-60  ////////////////////////////////////
    // Espetro de Radiação do Co-60
    gStyle->SetOptFit(kTRUE);
    TGraphErrors G_Co;
    vector<pair<double, double>> rad_co;
    n=0;
    ReadFile("Data_Files/Cobalto_Energy.dat", rad_co);
    for (int i = 0; i < rad_co.size(); i++){
        if(rad_co[i].first > 1400){continue;}
        n = G_Co.GetN();
        G_Co.SetPoint(n, rad_co[i].first, rad_co[i].second);
        G_Co.SetPointError(n,0/*0.006*rad_co[i].first+3.6*/,sqrt(rad_co[i].second));
    }
    G_Co.SetLineColor(kGray+1);
    G_Co.SetMarkerStyle(20);
    G_Co.SetMarkerSize(0.5);
    G_Co.SetTitle("Espetro de Radiacao do Co-60; E [keV]; Counts");
    G_Co.GetXaxis()->CenterTitle();
    G_Co.GetYaxis()->CenterTitle();

    c1.Clear();
    G_Co.Draw("AP");
    
    
    TF1 *F_Co3 = new TF1("F_Co3", "[0]*exp(-0.5*((x-[1])/[2])**2)", 223, 256);
    F_Co3->SetParameters(100, 234, 50);
    F_Co3->SetParNames("C","#mu", "#sigma");
    F_Co3->SetLineColor(kGreen);
    G_Co.Fit("F_Co3","","", 223, 256);

    // Espetro de Radiação do Co-60 Smoothed
    TGraph G_Co_Smoothed;
    vector<pair<double, double>> rad_co_smoothed;
    ReadFile("Data_Files/Cobalto_Energy_Smoothed.dat", rad_co_smoothed);
    for (int i = 0; i < rad_co_smoothed.size(); i++){
        if(rad_co[i].first > 1400){continue;}
        else if(rad_co_smoothed[i].first < 225 || rad_co_smoothed[i].first > 256)
        {
        G_Co_Smoothed.AddPoint(rad_co_smoothed[i].first, rad_co_smoothed[i].second);
        }
        else{
            G_Co_Smoothed.AddPoint(rad_co_smoothed[i].first, F_Co3->Eval(rad_co_smoothed[i].first));
        }
    }
    G_Co_Smoothed.SetLineColor(kRed);
    G_Co_Smoothed.SetMarkerStyle(20);
    G_Co_Smoothed.SetMarkerSize(0.5);
    G_Co_Smoothed.SetLineWidth(3);
    /*
    TF1 *F_Co1 = new TF1("F_Co1", "[0]*exp(-0.5*((x-[1])/[2])**2)", 1115, 1230);
    F_Co1->SetParameters(100, 1160, 50);
    F_Co1->SetLineColor(kBlue);
    G_Co.Fit("F_Co1","","",1115,1230);

    TF1 *F_Co2 = new TF1("F_Co2", "[0]*exp(-0.5*((x-[1])/[2])**2)", 1270, 1390);
    F_Co2->SetParameters(100, 1320, 50);
    F_Co2->SetLineColor(kBlue);
    G_Co.Fit("F_Co2","","",1270, 1390);
    */

    // Find the Compton Edge for Co-60
    TGraph Point;
    Point.SetMarkerSize(1);
    Point.SetMarkerStyle(22);
    Point.SetMarkerColor(kYellow+0);
    // First One
    x_1 = 900, x_2 = 1000;
    medium_x = (x_1 + x_2) / 2;
    for (int i = 0; i < rad_co.size(); i++){
        if (rad_co[i].first > medium_x){
            cout << "Compton Edge One: " << rad_co_smoothed[i].first << endl;
            Point.SetPoint(1, rad_co_smoothed[i].first, rad_co_smoothed[i].second);
            break;
        }
    }
    // Second One
    x_1 = 1000, x_2 = 1150;
    medium_x = (x_1 + x_2) / 2;
    for (int i = 0; i < rad_co.size(); i++){
        if (rad_co[i].first > medium_x){
            cout << "Compton Edge One: " << rad_co_smoothed[i].first << endl;
            Point.SetPoint(0, rad_co_smoothed[i].first, rad_co_smoothed[i].second);
            break;
        }
    }

    // Create a legend
    TLegend* legend = new TLegend(0.65, 0.79, 0.85, 0.89); // Specify the position of the legend
    
    // Add an entry to the legend
    legend->AddEntry(&G_Co, "Signal", "l"); 
    legend->AddEntry(&G_Co_Smoothed, "Clear Signal", "l"); // "l" for a solid line
    legend->AddEntry(F_Co3, "Back Scattering", "l"); // "l" for a solid line
    legend->AddEntry(&Point, "Compton Edge", "p"); // "p" for a point
    //legend->AddEntry(F_Co1, "Calibration Peak", "l"); // "l" for a solid line
    // Draw
    legend->Draw();
    G_Co_Smoothed.Draw("same C");
    //F_Co1->Draw("same C");
    //F_Co2->Draw("same C");
    F_Co3->Draw("same C");
    Point.Draw("same P");

    c1.SetLogy();
    c1.Update();
    c1.SaveAs("Graphs/Espetro_Co.png");
    c1.WaitPrimitive();
    //A.Run("TRUE");
    gSystem->ProcessEvents();
    
//////////////////////////////////// Fonte-Desconhecida  ////////////////////////////////////
    // Espetro de Radiação da Fonte Desconhecida
    gStyle->SetOptFit(kFALSE);
    TGraphErrors G_Am;
    vector<pair<double, double>> rad_am;
    ReadFile("Data_Files/Fonte_Desconhecida_Energy.dat", rad_am);
    n = 0;
    for (int i = 0; i < rad_am.size(); i++){
        n = G_Am.GetN();
        G_Am.SetPoint(n, rad_am[i].first, rad_am[i].second - rad_ambiente_smoothed[i].second/4);
        G_Am.SetPointError(n,0/*0.006*rad_am[i].first+3.6*/,sqrt(rad_am[i].second));
    }
    G_Am.SetLineColor(kGray+1);
    G_Am.SetMarkerStyle(20);
    G_Am.SetMarkerSize(0.5);
    G_Am.SetTitle("Espetro de Radiacao da Fonte Desconhecida; E [keV]; Counts");
    G_Am.GetXaxis()->CenterTitle();
    G_Am.GetYaxis()->CenterTitle();

    c1.Clear();
    c1.SetLogy();
    G_Am.Draw("AP");

    // Espetro de Radiação da Fonte Desconhecida Smoothed
    TGraph G_Am_Smoothed;
    vector<pair<double, double>> rad_am_smoothed;
    ReadFile("Data_Files/Fonte_Desconhecida_Energy_Smoothed.dat", rad_am_smoothed);
    for (int i = 0; i < rad_am_smoothed.size(); i++){
        G_Am_Smoothed.AddPoint(rad_am_smoothed[i].first, rad_am_smoothed[i].second - rad_ambiente_smoothed[i].second/4);
    }
    G_Am_Smoothed.SetLineColor(kRed);
    G_Am_Smoothed.SetMarkerStyle(20);
    G_Am_Smoothed.SetMarkerSize(0.5);
    G_Am_Smoothed.SetLineWidth(3);
    G_Am_Smoothed.Draw("same C");

    TF1 *F_Des1 = new TF1("F_Des1", "[0]*exp(-0.5*((x-[1])/[2])**2)", 3.4, 9.2);
    F_Des1->SetParameters(300, 6, 1);
    F_Des1->SetParNames("C","#mu", "#sigma");
    F_Des1->SetLineColor(kBlue);
    F_Des1->SetLineWidth(3);
    G_Am.Fit("F_Des1","","",3.4,9.2);
    F_Des1->Draw("same C");
    
    TF1 *F_Des4 = new TF1("F_Des4", "[0]*exp(-0.5*((x-[1])/[2])**2)", 26, 50);
    F_Des4->SetParameters(2000, 39, 6);
    F_Des4->SetParNames("C","#mu", "#sigma");
    F_Des4->SetLineColor(kBlue);
    F_Des4->SetLineWidth(3);
    G_Am.Fit("F_Des4","","",26, 50);
    F_Des4->Draw("same C");
    
    
    TF1 *F_Des6 = new TF1("F_Des6", "[0]*exp(-0.5*((x-[1])/[2])**2)", 114, 136);
    F_Des6->SetParameters(100, 125, 1);
    F_Des6->SetParNames("C","#mu", "#sigma");
    F_Des6->SetLineColor(kBlue);
    F_Des6->SetLineWidth(3);
    G_Am.Fit("F_Des6","","",114, 136);
    F_Des6->Draw("same C");
    
    TF1 *F_Des2 = new TF1("F_Des2", "[0]*exp(-0.5*((x-[1])/[2])**2)", 230, 258);
    F_Des2->SetParameters(600, 235, 10);
    F_Des2->SetParNames("C","#mu", "#sigma");
    F_Des2->SetLineColor(kBlue);
    F_Des2->SetLineWidth(3);
    G_Am.Fit("F_Des2","","",228,268);
    F_Des2->Draw("same C");
    
    TF1 *F_Des3 = new TF1("F_Des3", "[0]*exp(-0.5*((x-[1])/[2])**2)", 320, 375);
    F_Des3->SetParameters(1000, 340, 10);
    F_Des3->SetParNames("C","#mu", "#sigma");
    F_Des3->SetLineColor(kBlue);
    F_Des3->SetLineWidth(3);
    G_Am.Fit("F_Des3","","",320,375);
    F_Des3->Draw("same C");
    
    TF1 *F_Des7 = new TF1("F_Des7", "[0]*exp(-0.5*((x-[1])/[2])**2)", 922, 1014);
    F_Des7->SetParameters(10, 1000, 5);
    F_Des7->SetParNames("C","#mu", "#sigma");
    F_Des7->SetLineColor(kBlue);
    F_Des7->SetLineWidth(3);
    G_Am.Fit("F_Des7","","",922, 1014);
    F_Des7->Draw("same C");
    
    TF1 *F_Des8 = new TF1("F_Des8", "[0]*exp(-0.5*((x-[1])/[2])**2)", 1035, 1145);
    F_Des8->SetParameters(10, 1100, 10);
    F_Des8->SetParNames("C","#mu", "#sigma");
    F_Des8->SetLineColor(kBlue);
    F_Des8->SetLineWidth(3);
    G_Am.Fit("F_Des8","","",1035, 1145);
    F_Des8->Draw("same C");
    
    TF1 *F_Des9 = new TF1("F_Des9", "[0]*exp(-0.5*((x-[1])/[2])**2)", 745, 820);
    F_Des9->SetParameters(10, 800, 10);
    F_Des9->SetParNames("C","#mu", "#sigma");
    F_Des9->SetLineColor(kBlue);
    F_Des9->SetLineWidth(3);
    G_Am.Fit("F_Des9","","",745, 820);
    F_Des9->Draw("same C");
    
    TF1 *F_Des10 = new TF1("F_Des10", "[0]*exp(-0.5*((x-[1])/[2])**2)", 1370, 1440);
    F_Des10->SetParameters(10, 1400, 10);
    F_Des10->SetParNames("C","#mu", "#sigma");
    F_Des10->SetLineColor(kBlue);
    F_Des10->SetLineWidth(3);
    G_Am.Fit("F_Des10","","",1370, 1440);
    F_Des10->Draw("same C");

    // Create Legend
    TLegend *leg = new TLegend(0.65, 0.75, 0.85, 0.85);
    leg->AddEntry(&G_Am, "Signal", "l");
    leg->AddEntry(&G_Am_Smoothed, "Clear Signal", "l");
    leg->AddEntry(F_Des1, "Fit", "l");
    leg->Draw();
    

    c1.Update();
    c1.SaveAs("Graphs/Espetro_Fonte_Desconhecida.png");
    c1.WaitPrimitive();
    gSystem->ProcessEvents();
    gStyle->SetOptFit(kTRUE);
    
//////////////////////////////////// Atenuação na Matéria  ////////////////////////////////////
    // Calculo do Coeficiente na Atenuação do Chumbo
    double counts_grosso = 0;
    double counts_fino = 0;


    // Espetro de Radiação do Césio com placa de Chumbo Espesso
    TGraph G_Cs_Pb;
    vector<pair<double, double>> rad_cs_pb;
    ReadFile("Data_Files/Chumbo_Grosso_Energy.dat", rad_cs_pb);
    for (int i = 0; i < rad_cs_pb.size(); i++){
        if(rad_cs_pb[i].first < 700){
        G_Cs_Pb.AddPoint(rad_cs_pb[i].first, rad_cs_pb[i].second);
        counts_grosso += rad_cs_pb[i].second;
        }
    }
    G_Cs_Pb.SetLineColor(kGray+1);
    G_Cs_Pb.SetMarkerStyle(20);
    G_Cs_Pb.SetMarkerSize(0.5);

    // Espetro de Radiação do Césio com placa de Chumbo Espesso Smoothed
    TGraph G_Cs_Pb_Smoothed;
    vector<pair<double, double>> rad_cs_pb_smoothed;
    ReadFile("Data_Files/Chumbo_Grosso_Energy_Smoothed.dat", rad_cs_pb_smoothed);
    for (int i = 0; i < rad_cs_pb_smoothed.size(); i++){
        G_Cs_Pb_Smoothed.AddPoint(rad_cs_pb_smoothed[i].first, rad_cs_pb_smoothed[i].second);
    }
    G_Cs_Pb_Smoothed.SetLineColor(kRed);
    G_Cs_Pb_Smoothed.SetLineWidth(3);
    G_Cs_Pb_Smoothed.SetMarkerStyle(20);
    G_Cs_Pb_Smoothed.SetMarkerSize(0.5);
    

    // Espetro de Radiação do Césio com placa de Chumbo Fino
    TGraph G_Cs_Pb_Thin;
    vector<pair<double, double>> rad_cs_pb_thin;
    ReadFile("Data_Files/Chumbo_Fino_Energy.dat", rad_cs_pb_thin);
    for (int i = 0; i < rad_cs_pb_thin.size(); i++){
        if(rad_cs_pb_thin[i].first < 700){
        G_Cs_Pb_Thin.AddPoint(rad_cs_pb_thin[i].first, rad_cs_pb_thin[i].second);
        counts_fino += rad_cs_pb_thin[i].second;
        }
    }   
    G_Cs_Pb_Thin.SetLineColor(kGray+1);
    G_Cs_Pb_Thin.SetMarkerStyle(20);
    G_Cs_Pb_Thin.SetMarkerSize(0.5);


    // Espetro de Radiação do Césio com placa de Chumbo Fino Smoothed
    TGraph G_Cs_Pb_Thin_Smoothed;
    vector<pair<double, double>> rad_cs_pb_thin_smoothed;
    ReadFile("Data_Files/Chumbo_Fino_Energy_Smoothed.dat", rad_cs_pb_thin_smoothed);
    for (int i = 0; i < rad_cs_pb_thin_smoothed.size(); i++){
        G_Cs_Pb_Thin_Smoothed.AddPoint(rad_cs_pb_thin_smoothed[i].first, rad_cs_pb_thin_smoothed[i].second);
    }
    G_Cs_Pb_Thin_Smoothed.SetLineColor(kBlue);
    G_Cs_Pb_Thin_Smoothed.SetLineWidth(3);
    G_Cs_Pb_Thin_Smoothed.SetMarkerStyle(20);
    G_Cs_Pb_Thin_Smoothed.SetMarkerSize(0.5);

    TLegend *leg2 = new TLegend(0.55, 0.75, 0.75, 0.85);
    leg2->AddEntry(&G_Cs_Pb, "Thick Plate Signal", "l");
    leg2->AddEntry(&G_Cs_Pb_Smoothed, "Thick Plate Clear Signal", "l");
    leg2->AddEntry(&G_Cs_Pb_Thin, "Thin Plate Signal", "l");
    leg2->AddEntry(&G_Cs_Pb_Thin_Smoothed, "Thin Plate Clear Signal", "l");

    c1.Clear();
    G_Cs_Pb_Thin.SetTitle("Espetro de Radiacao do Cs-137 com Placas de Chumbo; E [keV]; Counts");
    G_Cs_Pb_Thin.GetXaxis()->CenterTitle();
    G_Cs_Pb_Thin.GetYaxis()->CenterTitle();
    G_Cs_Pb_Thin.Draw("AC");
    G_Cs_Pb.Draw("same C");
    G_Cs_Pb_Smoothed.Draw("same C");
    G_Cs_Pb_Thin_Smoothed.Draw("same C");
    leg2->Draw();
    c1.SetLogy();
    c1.Update();
    c1.SaveAs("Graphs/Atenuacao_Materia.png");
    c1.WaitPrimitive();
    gSystem->ProcessEvents();


    // Calculo do Coeficiente na Atenuação do Chumbo
    double espessura_fino = 1800;
    double espessura_grosso = 7200;
    TGraph G_Coeficiente_Atenuacao;
    TF1 *co = new TF1("co", "[0]*x+[1]", 0, 1024);

    //G_Coeficiente_Atenuacao.AddPoint(espessura_fino, log(rad_cs_pb_thin_smoothed[434].second));
    //G_Coeficiente_Atenuacao.AddPoint(espessura_grosso, log(rad_cs_pb_smoothed[434].second));
    G_Coeficiente_Atenuacao.AddPoint(espessura_fino, log(33958));
    G_Coeficiente_Atenuacao.AddPoint(espessura_grosso, log(19023));
    G_Coeficiente_Atenuacao.SetLineColor(kRed);
    G_Coeficiente_Atenuacao.SetMarkerStyle(20);
    G_Coeficiente_Atenuacao.SetMarkerSize(0.5);
    G_Coeficiente_Atenuacao.SetTitle("Coeficiente de Atenuac#tilde{a}o do Chumbo; Espessura [mg/cm^{2}]; log(Counts)");
    G_Coeficiente_Atenuacao.GetXaxis()->CenterTitle();
    G_Coeficiente_Atenuacao.GetYaxis()->CenterTitle();
    co->SetParNames("declive","y_{0}");
    G_Coeficiente_Atenuacao.Fit("co", "");
    c1.Clear();
    c1.SetLogy(0);
    gStyle->SetOptFit(kTRUE);
    G_Coeficiente_Atenuacao.Draw("AP");
    c1.Update();
    c1.SaveAs("Graphs/Coeficiente_Atenuacao.png");
    c1.WaitPrimitive();
    gSystem->ProcessEvents();

//////////////////////////////////// Resolução da Energia  ////////////////////////////////////
    // Resolução da Energia
    //TGraphErrors G_Resolucao_Energia;
    double x[5] = {29.28, 665.87, 1772.57, 1330.72};
    double y[5] = {0.19, 0.06, 0.04, 0.04};
    double ex[5] = {0.006 * x[0] + 3.6, 0.006 * x[1] + 3.6, 0.006 * x[2] + 3.6, 0.006 * x[3] + 3.6};
    double ey[5] = {0.001, 0.01, 0.01, 0.01};
    TGraphErrors* G_Resolucao_Energia = new TGraphErrors(5, x, y, ex, ey);
    TF1 *res = new TF1("res", "[0]/sqrt(x)+[1]", 0, 1024);
    res->SetParNames("a","b");
    G_Resolucao_Energia->SetLineColor(kRed);
    G_Resolucao_Energia->SetMarkerStyle(20);
    G_Resolucao_Energia->SetMarkerSize(0.5);
    G_Resolucao_Energia->SetTitle("Dependencia de R com E; E [keV]; FWHM [keV]");
    G_Resolucao_Energia->GetXaxis()->CenterTitle();
    G_Resolucao_Energia->GetYaxis()->CenterTitle();
    G_Resolucao_Energia->Fit("res", "");



    gStyle->SetOptFit(kTRUE);
    c1.Clear();
    c1.SetLogy(0);
    G_Resolucao_Energia->Draw("AP");
    c1.Update();
    c1.SaveAs("Graphs/Resolucao_Energia.png");
    c1.WaitPrimitive();
    gSystem->ProcessEvents();

    /*
    vector <double> dist = {0.00635, 0.0127, 0.019, 0.0254, 0.0318, 0.0381};   // em m
    vector <double> inc_dist = {0,0,0,0,0,0};
    vector <double> counts_semdisco = {42280, 26555, 11002, 5650, 3525, 2537};
    vector <double> inc_cnt_semdisco = {291, 230, 148, 106, 84, 42};
    vector <double> counts_comdisco = {4004, 2482, 1339, 831, 668, 487};
    vector <double> inc_cnt_comdisco = {89, 70, 52, 41, 37, 31};

    TCanvas b("b", "b", 1200, 900);
    TGraphErrors Ab;                             // grafico sem disco
    TF1 f("f", "[0]*( 1 - [1]/sqrt( 1 + ([2]/(x + [3]) )**2) )", 0.006, 0.04);

    f.SetParameter(0, 42280); // parameter 0
    f.SetParameter(1, 1); // parameter 1
    f.SetParameter(2, 1); // parameter 2
    f.SetParameter(3, 1); // parameter 3

    //f.SetParLimits(3, 0.00001, 1000000); // parameter 0 lower and upper limits

    for(int i = 0; i < dist.size(); i++){
        Ab.SetPoint(i, dist[i], counts_semdisco[i]);
        Ab.SetPointError(i, inc_dist[i], inc_cnt_semdisco[i]);
    }
    Ab.SetTitle("; d [m]; Counts");
    Ab.SetMarkerSize(0.5);
    Ab.Fit("f", "");
   
    Ab.Draw("AP");
    b.Update();
    b.WaitPrimitive();
    gSystem->ProcessEvents();
    */
}