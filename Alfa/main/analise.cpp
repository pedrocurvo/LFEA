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


    /////////////////////////////// Areas for Each Gaussian //////////////////////////////
    /*
    cout << "Areas found with Brute Integration" << endl;
    TF1 *Area_1 = new TF1("Area_1", "[0]*exp(-0.5*((x-[1])/[2])*((x-[1])/[2]))");
    Area_1->SetParameters(F_Cal3->GetParameters()[0], F_Cal3->GetParameters()[1], F_Cal3->GetParameters()[2]);
    double area_one = 0;
    for(int i=0; i<cal3.size(); i++){
        area_one += Area_1->Eval(cal3[i].first);
    }
    cout << "Area 1: " << area_one << endl;

    TF1 *Area_2 = new TF1("Area_2", "[0]*exp(-0.5*((x-[1])/[2])*((x-[1])/[2]))");   
    Area_2->SetParameters(F_Cal3->GetParameters()[3], F_Cal3->GetParameters()[4], F_Cal3->GetParameters()[5]);
    double area_two = 0;
    for(int i=0; i<cal3.size(); i++){
        area_two += Area_2->Eval(cal3[i].first);
    }
    cout << "Area 2: " << area_two << endl;

    TF1 *Area_3 = new TF1("Area_3", "[0]*exp(-0.5*((x-[1])/[2])*((x-[1])/[2]))");
    Area_3->SetParameters(F_Cal3->GetParameters()[6], F_Cal3->GetParameters()[7], F_Cal3->GetParameters()[8]);
    double area_three = 0;
    for(int i=0; i<cal3.size(); i++){
        area_three += Area_3->Eval(cal3[i].first);
    }

    cout << "Area 3: " << area_three << endl;
    */
    cout << "Areas" << endl;
    double area_one = F_Cal3->GetParameter(0)*sqrt(2*TMath::Pi())*F_Cal3->GetParameter(2);
    double area_two = F_Cal3->GetParameter(3)*sqrt(2*TMath::Pi())*F_Cal3->GetParameter(5);
    double area_three = F_Cal3->GetParameter(6)*sqrt(2*TMath::Pi())*F_Cal3->GetParameter(8);
    cout << "Area 1: " << area_one << endl;
    cout << "Area 2: " << area_two << endl;
    cout << "Area 3: " << area_three << endl << endl;
    double sum = area_one + area_two + area_three;

    double per_one = area_one/sum*100;
    double per_two = area_two/sum*100;
    double per_three = area_three/sum*100;
    cout << "per100 of first " << per_one << endl;
    cout << "per100 of second " << per_two << endl;
    cout << "per100 of third " << per_three << endl << endl;

    double teorico_one = 1.6;
    double teorico_two = 13;
    double teorico_three = 84.5;

    cout << "err per100 of first " << abs(per_one - teorico_one)/teorico_one * 100 << endl;
    cout << "err per100 of second " << abs(per_two - teorico_two)/teorico_two * 100 << endl;
    cout << "err per100 of third " << abs(per_three - teorico_three)/teorico_three * 100 << endl << endl;

    //////////////////////////////////////////////////////////////////////////////////////
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

    /////////////////////////// Atenuacao da Materia ////////////////////////////////////
    /////////Prateleira 8/////////
    vector<pair<double, double>> aten_8;
    ReadFile("Data_Files/Prateleira_8_c_vacuo.dat", aten_8);

    double counts_8_one = 0;
    double counts_8_two = 0;

    TGraphErrors G_aten_8;
    for (int i = 100; i < aten_8.size(); i++){
        n = G_aten_8.GetN();
        G_aten_8.SetPoint(n, aten_8[i].first, aten_8[i].second);
        G_aten_8.SetPointError(n,0,sqrt(aten_8[i].second));
        counts_8_one += aten_8[i].second;
    }

    vector<pair<double, double>> aten_8_s;
    ReadFile("Data_Files/Prateleira_8_s_vacuo.dat", aten_8_s);

    TGraphErrors G_aten_8_s;
    for (int i = 100; i < aten_8_s.size(); i++){
        n = G_aten_8_s.GetN();
        G_aten_8_s.SetPoint(n, aten_8_s[i].first, aten_8_s[i].second);
        G_aten_8_s.SetPointError(n,0,sqrt(aten_8_s[i].second));
        counts_8_two += aten_8_s[i].second;
    }

    G_aten_8.SetLineColor(kBlue);
    G_aten_8.SetTitle("Atenuacao Prateleira 8; Channels; Energy [Pulser Units] ");
    G_aten_8.GetXaxis()->CenterTitle();
    G_aten_8.GetYaxis()->CenterTitle();


    G_aten_8_s.SetLineColor(kRed);
    G_aten_8_s.SetTitle("Atenuacao Prateleira 8; Channels; Energy [Pulser Units] ");
    G_aten_8_s.GetXaxis()->CenterTitle();
    G_aten_8_s.GetYaxis()->CenterTitle();


    TLegend leg(0.7,0.7,0.85,0.85);
    leg.AddEntry(&G_aten_8, "Com Vacuo", "l");
    leg.AddEntry(&G_aten_8_s, "Sem Vacuo", "l");

    c1.Clear();
    G_aten_8.Draw("AP");
    G_aten_8_s.Draw("same P");
    leg.Draw();
    c1.Update();
    c1.SaveAs("graphs/Atenuacao_8.png");
    c1.WaitPrimitive();
    gSystem->ProcessEvents();

    cout << "Atenuacao da prateleira 8: " << endl;
    cout << "Counts com vacuo: " << counts_8_one << endl;
    cout << "Counts sem vacuo: " << counts_8_two << endl;
    cout << "Centroide com vácuo: 710.60 " <<  endl;
    cout << "Centroide sem vácuo: 224.74 "  << endl;
    cout << "FWHM com vacuo:   4.36 " << endl;
    cout << "FWHM sem vacuo:  25.98 " << endl << endl;

    /////////Prateleira 4/////////
    vector<pair<double, double>> aten_4;
    ReadFile("Data_Files/4Cal.dat", aten_4);

    double counts_4_one = 0;
    double counts_4_two = 0;

    TGraphErrors G_aten_4;
    for (int i = 0; i < aten_4.size(); i++){
        n = G_aten_4.GetN();
        G_aten_4.SetPoint(n, aten_4[i].first, aten_4[i].second);
        G_aten_4.SetPointError(n,0,sqrt(aten_4[i].second));
        counts_4_one += aten_4[i].second;
    }

    vector<pair<double, double>> aten_4_s;
    ReadFile("Data_Files/Prateleira_4_s_vacuo.dat", aten_4_s);

    TGraphErrors G_aten_4_s;
    for (int i = 100; i < aten_4_s.size(); i++){
        n = G_aten_4_s.GetN();
        G_aten_4_s.SetPoint(n, aten_4_s[i].first, aten_4_s[i].second);
        G_aten_4_s.SetPointError(n,0,sqrt(aten_4_s[i].second));
        counts_4_two += aten_4_s[i].second;
    }

    G_aten_4.SetLineColor(kBlue);
    G_aten_4.SetTitle("Atenuacao Prateleira 4; Channels; Energy [Pulser Units] ");
    G_aten_4.GetXaxis()->CenterTitle();
    G_aten_4.GetYaxis()->CenterTitle();


    G_aten_4_s.SetLineColor(kRed);
    G_aten_4_s.SetTitle("Atenuacao Prateleira 4; Channels; Energy [Pulser Units] ");
    G_aten_4_s.GetXaxis()->CenterTitle();
    G_aten_4_s.GetYaxis()->CenterTitle();


    TLegend leg2(0.7,0.7,0.85,0.85);
    leg2.AddEntry(&G_aten_4, "Com Vacuo", "l");
    leg2.AddEntry(&G_aten_4_s, "Sem Vacuo", "l");

    c1.Clear();
    G_aten_4.Draw("AP");
    G_aten_4_s.Draw("same P");
    leg2.Draw();
    c1.Update();
    c1.SaveAs("graphs/Atenuacao_4.png");
    c1.WaitPrimitive();
    gSystem->ProcessEvents();

    cout << "Atenuacao da prateleira 4: " << endl;
    cout << "Counts com vacuo: " << counts_4_one << endl;
    cout << "Counts sem vacuo: " << counts_4_two << endl;
    cout << "Centroide com vácuo: 709.78 " <<  endl;
    cout << "Centroide sem vácuo: -- "  << endl;
    cout << "FWHM com vácuo:   4.21 " << endl;
    cout << "FWHM sem vácuo:  -- " << endl;




}