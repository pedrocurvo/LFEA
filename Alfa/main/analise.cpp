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
        cout << cal1[i].first << cal1[i].second << endl;
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
    ReadFile("Data_Files/1Cal.dat", cal2);

    TGraphErrors G_Cal2;
    for (int i = 0; i < cal2.size(); i++){
        n = G_Cal1.GetN();
        G_Cal1.SetPoint(n, cal2[i].first, cal2[i].second);
        G_Cal1.SetPointError(n,0,sqrt(cal1[i].second));
        cout << cal1[i].first << cal1[i].second << endl;
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

    vector<pair<double, double>> cal1;
    ReadFile("Data_Files/1Cal.dat", cal1);

    TGraphErrors G_Cal1;
    for (int i = 0; i < cal1.size(); i++){
        n = G_Cal1.GetN();
        G_Cal1.SetPoint(n, cal1[i].first, cal1[i].second);
        G_Cal1.SetPointError(n,0,sqrt(cal1[i].second));
        cout << cal1[i].first << cal1[i].second << endl;
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


    vector<pair<double, double>> cal1;
    ReadFile("Data_Files/1Cal.dat", cal1);

    TGraphErrors G_Cal1;
    for (int i = 0; i < cal1.size(); i++){
        n = G_Cal1.GetN();
        G_Cal1.SetPoint(n, cal1[i].first, cal1[i].second);
        G_Cal1.SetPointError(n,0,sqrt(cal1[i].second));
        cout << cal1[i].first << cal1[i].second << endl;
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
}