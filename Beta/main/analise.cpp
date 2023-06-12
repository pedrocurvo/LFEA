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

    //////////////////////////////// Talium ////////////////////////////////
    vector<pair<double, double>> talium;
    ReadFile("data/talium.dat", talium);
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
    ReadFile("data/taliumAl.dat", taliumAl);
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










}