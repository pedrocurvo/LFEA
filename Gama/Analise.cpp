# include <iostream>
# include <cmath>
# include <vector>
# include <string>
#include "TCanvas.h"
#include "TApplication.h"
#include "TSystem.h"
#include "TLegend.h"
#include "TH1F.h"
#include "TGraph.h"
#include "TF1.h"
#include "Read.cpp"
using namespace std;

int main(){
    // Create Application
    TApplication A("A", nullptr, nullptr);
    // Create Canvas
    TCanvas c1("c1", "c1", 1200, 800); 
    double acq_time = 150;
    double acq_time_amb = 1200;

    //System Command
    string command = "mkdir test";
    system(command.c_str());

    // Directory to Save Graphs
    string directory = "graphs/";

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
    CalibratioGraph.GetXaxis()->SetLimits(0, 1024);
    CalibratioGraph.GetYaxis()->SetLimits(0, 1400);
    CalibratioGraph.Draw("AP");
    TF1 *f1 = new TF1("f1", "[0]*x+[1]");
    CalibratioGraph.Fit("f1");
    double slope = f1->GetParameter(0);
    double intercept = f1->GetParameter(1);
    
    c1.Update();
    c1.SaveAs("graphs/Calibracao.png");
    c1.WaitPrimitive();
    gSystem->ProcessEvents();


    // Espetro de Radiação do Ambiente
    TGraph G_Amb; 
    vector<pair<double, double>> rad_ambiente;
    ReadFile("Data_Files/Ruido_Energy.dat", rad_ambiente);

    for (int i = 0; i < rad_ambiente.size(); i++){
        G_Amb.AddPoint(rad_ambiente[i].first, rad_ambiente[i].second);
    }
    G_Amb.SetLineColor(kBlue+1);
    G_Amb.SetMarkerStyle(20);
    G_Amb.SetMarkerSize(0.5);
    G_Amb.SetTitle("Espetro de Radiacao Ambiente; E [keV]; Counts");
    G_Amb.GetXaxis()->CenterTitle();
    G_Amb.GetYaxis()->CenterTitle();

    c1.Clear();
    G_Amb.Draw("AC");
    c1.Update();
    c1.SaveAs("graphs/Espetro_Ambiente.png");
    c1.WaitPrimitive();
    gSystem->ProcessEvents();

    // Espetro de Radiacao Ambiente Smoothed
    TGraph G_Amb_Smoothed;
    vector<pair<double, double>> rad_ambiente_smoothed;
    ReadFile("Data_Files/Ruido_Energy_Smoothed.dat", rad_ambiente_smoothed);
    for(int i=0; i<rad_ambiente_smoothed.size(); i++){
        G_Amb_Smoothed.AddPoint(rad_ambiente_smoothed[i].first, rad_ambiente_smoothed[i].second);
    }
    G_Amb_Smoothed.SetLineColor(kBlue+1);
    G_Amb_Smoothed.SetMarkerStyle(20);
    G_Amb_Smoothed.SetMarkerSize(0.5);
    G_Amb_Smoothed.SetTitle("Espetro de Radiacao Ambiente Smoothed; E [keV]; Counts");
    G_Amb_Smoothed.GetXaxis()->CenterTitle();
    G_Amb_Smoothed.GetYaxis()->CenterTitle();

    c1.Clear();
    G_Amb_Smoothed.Draw("AC");
    c1.Update();
    c1.SaveAs("graphs/Espetro_Ambiente_Smoothed.png");
    c1.WaitPrimitive();
    gSystem->ProcessEvents();

    // Espetro de Radiação do Cs-137 
    TGraph G_Cs;
    vector<pair<double, double>> rad_cs;
    ReadFile("Data_Files/Cesio_Energy.dat", rad_cs);
    for (int i = 0; i < rad_cs.size(); i++){
        G_Cs.AddPoint(rad_cs[i].first, rad_cs[i].second);
    }
    G_Cs.SetLineColor(kRed);
    G_Cs.SetMarkerStyle(20);
    G_Cs.SetMarkerSize(0.5);
    G_Cs.SetTitle("Espetro de Radiacao do Cs-137; E [keV]; Counts");
    G_Cs.GetXaxis()->CenterTitle();
    G_Cs.GetYaxis()->CenterTitle();

    c1.Clear();
    G_Cs.Draw("AC");
    c1.Update();
    c1.SaveAs("graphs/Espetro_Cs.png");
    c1.WaitPrimitive();
    gSystem->ProcessEvents();

    // Espetro de Radiaçao do Cs-137 Smoothed
    TGraph G_Cs_Smoothed;
    vector<pair<double, double>> rad_cs_smoothed;
    ReadFile("Data_Files/Cesio_Energy_Smoothed.dat", rad_cs_smoothed);
    for (int i = 0; i < rad_cs_smoothed.size(); i++){
        G_Cs_Smoothed.AddPoint(rad_cs_smoothed[i].first, rad_cs_smoothed[i].second);
    }
    G_Cs_Smoothed.SetLineColor(kRed);
    G_Cs_Smoothed.SetMarkerStyle(20);
    G_Cs_Smoothed.SetMarkerSize(0.5);
    G_Cs_Smoothed.SetTitle("Espetro de Radiacao do Cs-137 Smoothed; E [keV]; Counts");
    G_Cs_Smoothed.GetXaxis()->CenterTitle();
    G_Cs_Smoothed.GetYaxis()->CenterTitle();

    c1.Clear();
    G_Cs_Smoothed.Draw("AC");   
    c1.Update();
    c1.SaveAs("graphs/Espetro_Cs_Smoothed.png");
    c1.WaitPrimitive();
    gSystem->ProcessEvents();

    // Espetro de Radiação do Co-60
    TGraph G_Co;
    vector<pair<double, double>> rad_co;
    ReadFile("Data_Files/Cobalto_Energy.dat", rad_co);
    for (int i = 0; i < rad_co.size(); i++){
        G_Co.AddPoint(rad_co[i].first, rad_co[i].second);
    }
    G_Co.SetLineColor(kGreen+2);
    G_Co.SetMarkerStyle(20);
    G_Co.SetMarkerSize(0.5);
    G_Co.SetTitle("Espetro de Radiacao do Co-60; E [keV]; Counts");
    G_Co.GetXaxis()->CenterTitle();
    G_Co.GetYaxis()->CenterTitle();

    c1.Clear();
    G_Co.Draw("AC");
    c1.Update();
    c1.SaveAs("graphs/Espetro_Co.png");
    c1.WaitPrimitive();
    gSystem->ProcessEvents();

    // Espetro de Radiação do Co-60 Smoothed
    TGraph G_Co_Smoothed;
    vector<pair<double, double>> rad_co_smoothed;
    ReadFile("Data_Files/Cobalto_Energy_Smoothed.dat", rad_co_smoothed);
    for (int i = 0; i < rad_co_smoothed.size(); i++){
        G_Co_Smoothed.AddPoint(rad_co_smoothed[i].first, rad_co_smoothed[i].second);
    }
    G_Co_Smoothed.SetLineColor(kGreen+2);
    G_Co_Smoothed.SetMarkerStyle(20);
    G_Co_Smoothed.SetMarkerSize(0.5);
    G_Co_Smoothed.SetTitle("Espetro de Radiacao do Co-60 Smoothed; E [keV]; Counts");
    G_Co_Smoothed.GetXaxis()->CenterTitle();
    G_Co_Smoothed.GetYaxis()->CenterTitle();

    c1.Clear();
    G_Co_Smoothed.Draw("AC");
    c1.Update();
    c1.SaveAs("graphs/Espetro_Co_Smoothed.png");
    c1.WaitPrimitive();
    gSystem->ProcessEvents();

    // Espetro de Radiação da Fonte Desconhecida
    TGraph G_Am;
    vector<pair<double, double>> rad_am;
    ReadFile("Data_Files/Fonte_Desconhecida_Energy.dat", rad_am);
    for (int i = 0; i < rad_am.size(); i++){
        G_Am.AddPoint(rad_am[i].first, rad_am[i].second);
    }
    G_Am.SetLineColor(kMagenta+2);
    G_Am.SetMarkerStyle(20);
    G_Am.SetMarkerSize(0.5);
    G_Am.SetTitle("Espetro de Radiacao da Fonte Desconhecida; E [keV]; Counts");
    G_Am.GetXaxis()->CenterTitle();
    G_Am.GetYaxis()->CenterTitle();

    c1.Clear();
    //c1.SetLogy();
    G_Am.Draw("AC");
    c1.Update();
    c1.SaveAs("graphs/Espetro_Fonte_Desconhecida.png");
    c1.WaitPrimitive();
    gSystem->ProcessEvents();

    // Espetro de Radiação da Fonte Desconhecida Smoothed
    TGraph G_Am_Smoothed;
    vector<pair<double, double>> rad_am_smoothed;
    ReadFile("Data_Files/Fonte_Desconhecida_Energy_Smoothed.dat", rad_am_smoothed);
    for (int i = 0; i < rad_am_smoothed.size(); i++){
        G_Am_Smoothed.AddPoint(rad_am_smoothed[i].first, rad_am_smoothed[i].second);
    }
    G_Am_Smoothed.SetLineColor(kMagenta+2);
    G_Am_Smoothed.SetMarkerStyle(20);
    G_Am_Smoothed.SetMarkerSize(0.5);
    G_Am_Smoothed.SetTitle("Espetro de Radiacao da Fonte Desconhecida Smoothed; E [keV]; Counts");
    G_Am_Smoothed.GetXaxis()->CenterTitle();
    G_Am_Smoothed.GetYaxis()->CenterTitle();

    c1.Clear();
    G_Am_Smoothed.Draw("AC");
    
    c1.Update();
    c1.SaveAs("graphs/Espetro_Fonte_Desconhecida_Smoothed.png");
    c1.WaitPrimitive();
    gSystem->ProcessEvents();

    // Espetro de Radiação do Césio com placa de Chumbo Espesso
    TGraph G_Cs_Pb;
    vector<pair<double, double>> rad_cs_pb;
    ReadFile("Data_Files/Chumbo_Grosso_Energy.dat", rad_cs_pb);
    for (int i = 0; i < rad_cs_pb.size(); i++){
        G_Cs_Pb.AddPoint(rad_cs_pb[i].first, rad_cs_pb[i].second);
    }
    G_Cs_Pb.SetLineColor(kRed);
    G_Cs_Pb.SetMarkerStyle(20);
    G_Cs_Pb.SetMarkerSize(0.5);
    G_Cs_Pb.SetTitle("Espetro de Radiacao do Cs-137 com Placa de Chumbo Espesso; E [keV]; Counts");
    G_Cs_Pb.GetXaxis()->CenterTitle();
    G_Cs_Pb.GetYaxis()->CenterTitle();


    c1.Clear();
    G_Cs_Pb.Draw("AC");
    c1.Update();
    c1.SaveAs("graphs/Espetro_Cs_Pb.png");
    c1.WaitPrimitive();
    gSystem->ProcessEvents();

    // Espetro de Radiação do Césio com placa de Chumbo Espesso Smoothed
    TGraph G_Cs_Pb_Smoothed;
    vector<pair<double, double>> rad_cs_pb_smoothed;
    ReadFile("Data_Files/Chumbo_Grosso_Energy_Smoothed.dat", rad_cs_pb_smoothed);
    for (int i = 0; i < rad_cs_pb_smoothed.size(); i++){
        G_Cs_Pb_Smoothed.AddPoint(rad_cs_pb_smoothed[i].first, rad_cs_pb_smoothed[i].second);
    }
    G_Cs_Pb_Smoothed.SetLineColor(kRed);
    G_Cs_Pb_Smoothed.SetMarkerStyle(20);
    G_Cs_Pb_Smoothed.SetMarkerSize(0.5);
    G_Cs_Pb_Smoothed.SetTitle("Espetro de Radiacao do Cs-137 com Placa de Chumbo Espesso Smoothed; E [keV]; Counts");
    G_Cs_Pb_Smoothed.GetXaxis()->CenterTitle();
    G_Cs_Pb_Smoothed.GetYaxis()->CenterTitle();

    c1.Clear();
    G_Cs_Pb_Smoothed.Draw("AC");
    c1.Update();
    c1.SaveAs("graphs/Espetro_Cs_Pb_Smoothed.png");
    c1.WaitPrimitive();
    gSystem->ProcessEvents();

    // Espetro de Radiação do Césio com placa de Chumbo Fino
    TGraph G_Cs_Pb_Thin;
    vector<pair<double, double>> rad_cs_pb_thin;
    ReadFile("Data_Files/Chumbo_Fino_Energy.dat", rad_cs_pb_thin);
    for (int i = 0; i < rad_cs_pb_thin.size(); i++){
        G_Cs_Pb_Thin.AddPoint(rad_cs_pb_thin[i].first, rad_cs_pb_thin[i].second);
    }   
    G_Cs_Pb_Thin.SetLineColor(kRed);
    G_Cs_Pb_Thin.SetMarkerStyle(20);
    G_Cs_Pb_Thin.SetMarkerSize(0.5);
    G_Cs_Pb_Thin.SetTitle("Espetro de Radiacao do Cs-137 com Placa de Chumbo Fino; E [keV]; Counts");
    G_Cs_Pb_Thin.GetXaxis()->CenterTitle();
    G_Cs_Pb_Thin.GetYaxis()->CenterTitle();

    c1.Clear();
    G_Cs_Pb_Thin.Draw("AC");
    c1.Update();
    c1.SaveAs("graphs/Espetro_Cs_Pb_Thin.png");
    c1.WaitPrimitive();
    gSystem->ProcessEvents();

    // Espetro de Radiação do Césio com placa de Chumbo Fino Smoothed
    TGraph G_Cs_Pb_Thin_Smoothed;
    vector<pair<double, double>> rad_cs_pb_thin_smoothed;
    ReadFile("Data_Files/Chumbo_Fino_Energy_Smoothed.dat", rad_cs_pb_thin_smoothed);
    for (int i = 0; i < rad_cs_pb_thin_smoothed.size(); i++){
        G_Cs_Pb_Thin_Smoothed.AddPoint(rad_cs_pb_thin_smoothed[i].first, rad_cs_pb_thin_smoothed[i].second);
    }
    G_Cs_Pb_Thin_Smoothed.SetLineColor(kRed);
    G_Cs_Pb_Thin_Smoothed.SetMarkerStyle(20);
    G_Cs_Pb_Thin_Smoothed.SetMarkerSize(0.5);
    G_Cs_Pb_Thin_Smoothed.SetTitle("Espetro de Radiacao do Cs-137 com Placa de Chumbo Fino Smoothed; E [keV]; Counts");
    G_Cs_Pb_Thin_Smoothed.GetXaxis()->CenterTitle();
    G_Cs_Pb_Thin_Smoothed.GetYaxis()->CenterTitle();

    c1.Clear();
    G_Cs_Pb_Thin_Smoothed.Draw("AC");
    c1.Update();
    c1.SaveAs("graphs/Espetro_Cs_Pb_Thin_Smoothed.png");
    c1.WaitPrimitive();
    gSystem->ProcessEvents();

    













}