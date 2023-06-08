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
    int n = 0;
    TApplication A("A", nullptr, nullptr);
    TCanvas c1("c1", "c1", 1200, 800); 

    vector<pair<double, double>> cal1;
    ReadFile("Data_Files/1Cal.dat", cal1);

    TGraphErrors G_Cal1;
    for (int i = 0; i < cal1.size(); i++){
        n = G_Cal1.GetN();
        G_Cal1.SetPoint(n, cal1[i].first, cal1[i].second);
        G_Cal1.SetPointError(n,0,sqrt(cal1[i].second));
    }
    G_Cal1.SetMarkerStyle(20);
    G_Cal1.SetMarkerSize(0.5);
    G_Cal1.SetLineColor(kGray+1);
    G_Cal1.SetTitle("Cenas; Counts");
    G_Cal1.GetXaxis()->CenterTitle();
    G_Cal1.GetYaxis()->CenterTitle();

    G_Cal1.Draw("AP");
    c1.Update();
    c1.SaveAs("Graphs/Cal1.png");
    c1.WaitPrimitive();
    gSystem->ProcessEvents();

    vector<pair<double, double>> cal2;
    ReadFile("Data_Files/2Cal.dat", cal2);

    TGraphErrors G_Cal2;
    for (int i = 0; i < cal2.size(); i++){
        n = G_Cal2.GetN();
        G_Cal2.SetPoint(n, cal2[i].first, cal2[i].second);
        G_Cal2.SetPointError(n,0,sqrt(cal2[i].second));
        cout << cal2[i].first << cal2[i].second << endl;
    }
    G_Cal2.SetMarkerStyle(20);
    G_Cal2.SetMarkerSize(0.5);
    G_Cal2.SetLineColor(kGray+1);
    G_Cal2.SetTitle("Cenas; Counts");
    G_Cal2.GetXaxis()->CenterTitle();
    G_Cal2.GetYaxis()->CenterTitle();

    c1.Clear();
    G_Cal2.Draw("AP");
    c1.Update();
    c1.SaveAs("Graphs/Cal2.png");
    c1.WaitPrimitive();
    gSystem->ProcessEvents();

    gStyle->SetOptFit(kTRUE);
    vector<pair<double, double>> cal3;
    ReadFile("Data_Files/3Cal.dat",  cal3);

    TGraphErrors G_Cal3;
    for (int i = 0; i <  cal3.size(); i++){
        n = G_Cal3.GetN();
        G_Cal3.SetPoint(n,  cal3[i].first,  cal3[i].second);
        G_Cal3.SetPointError(n,0,sqrt( cal3[i].second));
    }
    G_Cal3.SetMarkerStyle(20);
    G_Cal3.SetMarkerSize(1);
    G_Cal3.SetMarkerColor(kViolet+2);
    G_Cal3.SetLineColor(kGray+1);
    G_Cal3.SetTitle("Espetro do ^{241}Am; Channels; Counts");
    G_Cal3.GetXaxis()->CenterTitle();
    G_Cal3.GetYaxis()->CenterTitle();

    TF1 *F_Cal3 = new TF1("F_Cal3", "[0]*exp(-0.5*((x-[1])/[2])*((x-[1])/[2])) + [3]*exp(-0.5*((x-[4])/[5])*((x-[4])/[5])) + [6]*exp(-0.5*((x-[7])/[8])*((x-[7])/[8]))", 1370, 1440);
    //F_Cal3->SetParLimits(1,410,430);
    F_Cal3->SetParLimits(1,417,417.9);
    F_Cal3->SetParLimits(2,0,8.39);
    F_Cal3->SetParameters(80, 418, 8, 500, 450, 9, 3000, 475, 6);
    F_Cal3->SetParNames("C1","#mu1", "#sigma1","C2","#mu2", "#sigma2","C3","#mu3", "#sigma3");
    F_Cal3->SetLineColor(kBlue);
    F_Cal3->SetLineWidth(3);

    c1.Clear();
    G_Cal3.Draw("AP");
    c1.Update();
    c1.SaveAs("Graphs/Cal3-points.png");
    c1.WaitPrimitive();
    gSystem->ProcessEvents();

    c1.Clear();
    G_Cal3.SetMarkerColor(kBlack);
    G_Cal3.Fit("F_Cal3","","",375, 525);
    G_Cal3.SetMarkerSize(0.5);
    G_Cal3.Draw("AP");
    F_Cal3->Draw("same C");
    c1.Update();
    c1.SaveAs("Graphs/Cal3.png");
    c1.WaitPrimitive();
    gSystem->ProcessEvents();

    vector<pair<double, double>> cal4;
    ReadFile("Data_Files/4Cal.dat", cal4);

    TGraphErrors G_Cal4;
    for (int i = 0; i < cal4.size(); i++){
        n = G_Cal4.GetN();
        G_Cal4.SetPoint(n, cal4[i].first, cal4[i].second);
        G_Cal4.SetPointError(n,0,sqrt(cal4[i].second));
    }
    G_Cal4.SetMarkerStyle(20);
    G_Cal4.SetMarkerSize(0.5);
    G_Cal4.SetLineColor(kGray+1);
    G_Cal4.SetTitle("Cenas; Counts");
    G_Cal4.GetXaxis()->CenterTitle();
    G_Cal4.GetYaxis()->CenterTitle();

    c1.Clear();
    G_Cal4.Draw("AP");
    c1.Update();
    c1.SaveAs("Graphs/Cal4.png");
    c1.WaitPrimitive();
    gSystem->ProcessEvents();

    vector<pair<double, double>> cal5;
    ReadFile("Data_Files/Prateleira_4_c_vacuo.dat", cal5);

    TGraphErrors G_Cal5;
    for (int i = 0; i < cal5.size(); i++){
        n = G_Cal5.GetN();
        G_Cal5.SetPoint(n, cal5[i].first, cal5[i].second);
        G_Cal5.SetPointError(n,0,sqrt(cal5[i].second));
    }
    G_Cal5.SetMarkerStyle(20);
    G_Cal5.SetMarkerSize(0.5);
    G_Cal5.SetLineColor(kGray+1);
    G_Cal5.SetTitle("Cenas; Counts");
    G_Cal5.GetXaxis()->CenterTitle();
    G_Cal5.GetYaxis()->CenterTitle();

    c1.Clear();
    G_Cal5.Draw("AP");
    c1.Update();
    c1.SaveAs("Graphs/Prateleira_4_c_vacuo.png");
    c1.WaitPrimitive();
    gSystem->ProcessEvents();

    vector<pair<double, double>> cal6;
    ReadFile("Data_Files/Prateleira_4_s_vacuo.dat", cal6);

    TGraphErrors G_Cal6;
    for (int i = 0; i < cal6.size(); i++){
        n = G_Cal6.GetN();
        G_Cal6.SetPoint(n, cal6[i].first, cal6[i].second);
        G_Cal6.SetPointError(n,0,sqrt(cal6[i].second));
    }
    G_Cal6.SetMarkerStyle(20);
    G_Cal6.SetMarkerSize(0.5);
    G_Cal6.SetLineColor(kGray+1);
    G_Cal6.SetTitle("Cenas; Counts");
    G_Cal6.GetXaxis()->CenterTitle();
    G_Cal6.GetYaxis()->CenterTitle();

    c1.Clear();
    G_Cal6.Draw("AP");
    c1.Update();
    c1.SaveAs("Graphs/Prateleira_4_s_vacuo.png");
    c1.WaitPrimitive();
    gSystem->ProcessEvents();

    vector<pair<double, double>> cal7;
    ReadFile("Data_Files/Prateleira_8_c_vacuo.dat", cal7);

    TGraphErrors G_Cal7;
    for (int i = 0; i < cal7.size(); i++){
        n = G_Cal7.GetN();
        G_Cal7.SetPoint(n, cal7[i].first, cal7[i].second);
        G_Cal7.SetPointError(n,0,sqrt(cal7[i].second));
    }
    G_Cal7.SetMarkerStyle(20);
    G_Cal7.SetMarkerSize(0.5);
    G_Cal7.SetLineColor(kGray+1);
    G_Cal7.SetTitle("Cenas; Counts");
    G_Cal7.GetXaxis()->CenterTitle();
    G_Cal7.GetYaxis()->CenterTitle();

    c1.Clear();
    G_Cal7.Draw("AP");
    c1.Update();
    c1.SaveAs("Graphs/Prateleira_8_c_vacuo.png");
    c1.WaitPrimitive();
    gSystem->ProcessEvents();

    vector<pair<double, double>> cal8;
    ReadFile("Data_Files/Prateleira_8_s_vacuo.dat", cal8);

    TGraphErrors G_Cal8;
    for (int i = 0; i < cal8.size(); i++){
        n = G_Cal8.GetN();
        G_Cal8.SetPoint(n, cal8[i].first, cal8[i].second);
        G_Cal8.SetPointError(n,0,sqrt(cal8[i].second));
    }
    G_Cal8.SetMarkerStyle(20);
    G_Cal8.SetMarkerSize(0.5);
    G_Cal8.SetLineColor(kGray+1);
    G_Cal8.SetTitle("Cenas; Counts");
    G_Cal8.GetXaxis()->CenterTitle();
    G_Cal8.GetYaxis()->CenterTitle();

    c1.Clear();
    G_Cal8.Draw("AP");
    c1.Update();
    c1.SaveAs("Graphs/Prateleira_8_s_vacuo.png");
    c1.WaitPrimitive();
    gSystem->ProcessEvents();
}