# include <iostream>
# include <cmath>
# include <vector>
# include <string>
#include <cmath>
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


    // Directory to Save Graphs
    string directory = "graphs/";

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
    //A.Run("True");
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
    c1.SetLogy();
    c1.Update();
    c1.SaveAs("Graphs/Espetro_Ambiente.png");
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
    c1.SetLogy();
    c1.Update();
    c1.SaveAs("Graphs/Espetro_Ambiente_Smoothed.png");
    c1.WaitPrimitive();
    gSystem->ProcessEvents();
        
    
    // Espetro de Radiação do Cs-137 
    TGraphErrors G_Cs;
    n=0;
    vector<pair<double, double>> rad_cs;
    ReadFile("Data_Files/Cesio_Energy.dat", rad_cs);
    for (int i = 0; i < rad_cs.size(); i++){
        n = G_Cs.GetN();
        G_Cs.SetPoint(n, rad_cs[i].first, rad_cs[i].second);
        G_Cs.SetPointError(n,0.006*rad_cs[i].first+3.6,sqrt(rad_cs[i].second));
    }
    G_Cs.SetLineColor(kBlack);
    G_Cs.SetMarkerStyle(20);
    G_Cs.SetMarkerSize(0.5);
    G_Cs.SetTitle("Espetro de Radiacao do Cs-137; E [keV]; Counts");
    G_Cs.GetXaxis()->CenterTitle();
    G_Cs.GetYaxis()->CenterTitle();

    c1.Clear();
    G_Cs.Draw("AP");

    /*
    TF1 *F_Cs1 = new TF1("F_Cs1", "[0]*exp(-0.5*((x-[1])/[2])**2)", 21, 37);
    F_Cs1->SetParameters(2000, 27, 2);
    F_Cs1->SetLineColor(kRed);
    G_Cs.Fit("F_Cs1","","",21,37);
    F_Cs1->Draw("same C");
    */
    /*
    TF1 *F_Cs2 = new TF1("F_Cs2", "[0]*exp(-0.5*((x-[1])/[2])**2)", 175, 220);
    F_Cs2->SetParNames("C","#mu", "#sigma");
    F_Cs2->SetParameters(200, 184, 20);
    F_Cs2->SetLineColor(kRed);
    G_Cs.Fit("F_Cs2","","",175,220);
    F_Cs2->Draw("same C");
    */
    
    TF1 *F_Cs3 = new TF1("F_Cs3", "[0]*exp(-0.5*((x-[1])/[2])**2)", 620, 725);
    F_Cs3->SetParameters(1000, 650, 50);
    F_Cs3->SetLineColor(kRed);
    G_Cs.Fit("F_Cs3","","",610,725);
    F_Cs3->Draw("same C");
    

    c1.SetLogy();
    c1.Update();
    c1.SaveAs("Graphs/Espetro_Cs.png");
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
    c1.SetLogy();
    c1.Update();
    c1.SaveAs("Graphs/Espetro_Cs_Smoothed.png");
    c1.WaitPrimitive();
    gSystem->ProcessEvents();

    // Find the Compton Edge for Cs-137
    double x_1 = 434, x_2 = 490;
    double medium_x = (x_1 + x_2) / 2;
    for (int i = 0; i < rad_cs.size(); i++){
        if (rad_cs[i].first > medium_x){
            cout << "Compton Edge: " << rad_cs[i].first << endl;
            break;
        }
    }
        

    // Espetro de Radiação do Co-60
    TGraphErrors G_Co;
    vector<pair<double, double>> rad_co;
    n=0;
    ReadFile("Data_Files/Cobalto_Energy.dat", rad_co);
    for (int i = 0; i < rad_co.size(); i++){
        n = G_Co.GetN();
        G_Co.SetPoint(n, rad_co[i].first, rad_co[i].second);
        G_Co.SetPointError(n,0.006*rad_co[i].first+3.6,sqrt(rad_co[i].second));
    }
    G_Co.SetLineColor(kBlack);
    G_Co.SetMarkerStyle(20);
    G_Co.SetMarkerSize(0.5);
    G_Co.SetTitle("Espetro de Radiacao do Co-60; E [keV]; Counts");
    G_Co.GetXaxis()->CenterTitle();
    G_Co.GetYaxis()->CenterTitle();

    c1.Clear();
    G_Co.Draw("AP");
    /*
    TF1 *F_Co1 = new TF1("F_Co1", "[0]*exp(-0.5*((x-[1])/[2])**2)", 1110, 1230);
    F_Co1->SetParameters(100, 1160, 50);
    F_Co1->SetLineColor(kRed);
    G_Co.Fit("F_Co1","","",1110,1230);
    F_Co1->Draw("same C");

    TF1 *F_Co2 = new TF1("F_Co2", "[0]*exp(-0.5*((x-[1])/[2])**2)", 1270, 1390);
    F_Co2->SetParameters(100, 1320, 50);
    F_Co2->SetLineColor(kRed);
    G_Co.Fit("F_Co2","","",1270, 1390);
    F_Co2->Draw("same C");
    */

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
        if(rad_co_smoothed[i].first < 225 || rad_co_smoothed[i].first > 256)
        {
        G_Co_Smoothed.AddPoint(rad_co_smoothed[i].first, rad_co_smoothed[i].second);
        }
        else{
            G_Co_Smoothed.AddPoint(rad_co_smoothed[i].first, F_Co3->Eval(rad_co_smoothed[i].first));
        }
    }
    G_Co_Smoothed.SetLineColor(kOrange+7);
    G_Co_Smoothed.SetMarkerStyle(20);
    G_Co_Smoothed.SetMarkerSize(0.5);
    G_Co_Smoothed.SetLineWidth(3);

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
    TLegend* legend = new TLegend(0.65, 0.75, 0.85, 0.85); // Specify the position of the legend
    
    // Add an entry to the legend
    legend->AddEntry(&G_Co_Smoothed, "Clear Signal", "l"); // "l" for a solid line
    legend->AddEntry(F_Co3, "Back Scattering", "l"); // "l" for a solid line
    legend->AddEntry(&Point, "Compton Edge", "p"); // "p" for a point
    // Draw
    legend->Draw();
    G_Co_Smoothed.Draw("same C");
    F_Co3->Draw("same C");
    Point.Draw("same P");

    c1.SetLogy();
    c1.Update();
    c1.SaveAs("Graphs/Espetro_Co_Smoothed.png");
    c1.WaitPrimitive();
    gSystem->ProcessEvents();

    c1.SetLogy();
    c1.Update();
    c1.SaveAs("Graphs/Espetro_Co.png");
    c1.WaitPrimitive();
    gSystem->ProcessEvents();
    

    // Espetro de Radiação da Fonte Desconhecida
    TGraphErrors G_Am;
    vector<pair<double, double>> rad_am;
    ReadFile("Data_Files/Fonte_Desconhecida_Energy.dat", rad_am);
    n = 0;
    for (int i = 0; i < rad_am.size(); i++){
        n = G_Am.GetN();
        G_Am.SetPoint(n, rad_am[i].first, rad_am[i].second - rad_ambiente_smoothed[i].second/4);
        G_Am.SetPointError(n,0.006*rad_am[i].first+3.6,sqrt(rad_am[i].second));
    }
    G_Am.SetLineColor(kBlack);
    G_Am.SetMarkerStyle(20);
    G_Am.SetMarkerSize(0.5);
    G_Am.SetTitle("Espetro de Radiacao da Fonte Desconhecida; E [keV]; Counts");
    G_Am.GetXaxis()->CenterTitle();
    G_Am.GetYaxis()->CenterTitle();

    c1.Clear();
    c1.SetLogy();
    G_Am.Draw("AP");
    
    TF1 *F_Des1 = new TF1("F_Des1", "[0]*exp(-0.5*((x-[1])/[2])**2)", 3.4, 9.2);
    F_Des1->SetParameters(300, 6, 1);
    F_Des1->SetParNames("C","#mu", "#sigma");
    F_Des1->SetLineColor(kRed);
    G_Am.Fit("F_Des1","","",3.4,9.2);
    F_Des1->Draw("same C");
    
    TF1 *F_Des4 = new TF1("F_Des4", "[0]*exp(-0.5*((x-[1])/[2])**2)", 27, 50);
    F_Des4->SetParameters(800, 39, 3);
    F_Des4->SetParNames("C","#mu", "#sigma");
    F_Des4->SetLineColor(kRed);
    G_Am.Fit("F_Des4","","",27, 50);
    F_Des4->Draw("same C");
    
    TF1 *F_Des5 = new TF1("F_Des5", "[0]*exp(-0.5*((x-[1])/[2])**2)", 74, 106);
    F_Des5->SetParameters(500, 90, 3);
    F_Des5->SetParNames("C","#mu", "#sigma");
    F_Des5->SetLineColor(kRed);
    G_Am.Fit("F_Des5","","",74, 106);
    F_Des5->Draw("same C");
    
    TF1 *F_Des6 = new TF1("F_Des6", "[0]*exp(-0.5*((x-[1])/[2])**2)", 114, 136);
    F_Des6->SetParameters(100, 125, 1);
    F_Des6->SetParNames("C","#mu", "#sigma");
    F_Des6->SetLineColor(kRed);
    G_Am.Fit("F_Des6","","",114, 136);
    F_Des6->Draw("same C");
    
    TF1 *F_Des2 = new TF1("F_Des2", "[0]*exp(-0.5*((x-[1])/[2])**2)", 228, 268);
    F_Des2->SetParameters(1000, 235, 10);
    F_Des2->SetParNames("C","#mu", "#sigma");
    F_Des2->SetLineColor(kRed);
    G_Am.Fit("F_Des2","","",228,268);
    F_Des2->Draw("same C");
    
    TF1 *F_Des3 = new TF1("F_Des3", "[0]*exp(-0.5*((x-[1])/[2])**2)", 320, 375);
    F_Des3->SetParameters(1000, 340, 10);
    F_Des3->SetParNames("C","#mu", "#sigma");
    F_Des3->SetLineColor(kRed);
    G_Am.Fit("F_Des3","","",320,375);
    F_Des3->Draw("same C");
    
    TF1 *F_Des7 = new TF1("F_Des7", "[0]*exp(-0.5*((x-[1])/[2])**2)", 922, 1014);
    F_Des7->SetParameters(10, 1000, 5);
    F_Des7->SetParNames("C","#mu", "#sigma");
    F_Des7->SetLineColor(kRed);
    G_Am.Fit("F_Des7","","",922, 1014);
    F_Des7->Draw("same C");
    
    TF1 *F_Des8 = new TF1("F_Des8", "[0]*exp(-0.5*((x-[1])/[2])**2)", 1035, 1145);
    F_Des8->SetParameters(10, 1100, 10);
    F_Des8->SetParNames("C","#mu", "#sigma");
    F_Des8->SetLineColor(kRed);
    G_Am.Fit("F_Des8","","",1035, 1145);
    F_Des8->Draw("same C");
    
    TF1 *F_Des9 = new TF1("F_Des9", "[0]*exp(-0.5*((x-[1])/[2])**2)", 745, 826);
    F_Des9->SetParameters(10, 800, 10);
    F_Des9->SetParNames("C","#mu", "#sigma");
    F_Des9->SetLineColor(kRed);
    G_Am.Fit("F_Des9","","",745, 826);
    F_Des9->Draw("same C");
    
    TF1 *F_Des10 = new TF1("F_Des10", "[0]*exp(-0.5*((x-[1])/[2])**2)", 1370, 1440);
    F_Des10->SetParameters(10, 1400, 10);
    F_Des10->SetParNames("C","#mu", "#sigma");
    F_Des10->SetLineColor(kRed);
    G_Am.Fit("F_Des10","","",1370, 1440);
    F_Des10->Draw("same C");
    

    c1.SetLogy();
    c1.Update();
    c1.SaveAs("Graphs/Espetro_Fonte_Desconhecida.png");
    c1.WaitPrimitive();
    gSystem->ProcessEvents();

    // Espetro de Radiação da Fonte Desconhecida Smoothed
    
    TGraph G_Am_Smoothed;
    vector<pair<double, double>> rad_am_smoothed;
    ReadFile("Data_Files/Fonte_Desconhecida_Energy_Smoothed.dat", rad_am_smoothed);
    for (int i = 0; i < rad_am_smoothed.size(); i++){
        G_Am_Smoothed.AddPoint(rad_am_smoothed[i].first, rad_am_smoothed[i].second);
    }
    G_Am_Smoothed.SetLineColor(kOrange+0);
    G_Am_Smoothed.SetMarkerStyle(20);
    G_Am_Smoothed.SetMarkerSize(0.5);
    G_Am_Smoothed.SetLineWidth(3);
    c1.Clear();
    G_Am_Smoothed.Draw("AC");
    //G_Am_Smoothed.SetTitle("Espetro de Radiacao da Fonte Desconhecida Smoothed; E [keV]; Counts");
    //G_Am_Smoothed.GetXaxis()->CenterTitle();
    //G_Am_Smoothed.GetYaxis()->CenterTitle();

    //c1.Clear();
    
    //c1.SetLogy();
    //c1.Update();
    //c1.SaveAs("Graphs/Espetro_Fonte_Desconhecida_Smoothed.png");
    //c1.WaitPrimitive();
    //gSystem->ProcessEvents();
    
    
    // Calculo do Coeficiente na Atenuação do Chumbo
    double counts_grosso = 0;
    double counts_fino = 0;


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
    c1.SetLogy();
    c1.Update();
    c1.SaveAs("Graphs/Espetro_Cs_Pb.png");
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
    c1.SetLogy();
    c1.Update();
    c1.SaveAs("Graphs/Espetro_Cs_Pb_Smoothed.png");
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
    c1.SetLogy();
    c1.Update();
    c1.SaveAs("Graphs/Espetro_Cs_Pb_Thin.png");
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
    c1.SetLogy();
    c1.Update();
    c1.SaveAs("Graphs/Espetro_Cs_Pb_Thin_Smoothed.png");
    c1.WaitPrimitive();
    gSystem->ProcessEvents();
    

}