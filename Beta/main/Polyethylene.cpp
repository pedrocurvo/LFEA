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
    

    //////////////////////////////// Polyethylene ////////////////////////////////
    
    vector<string> filename;
    for (int i = 1; i < 8; i++){
        string name = "data/TTBET"+ to_string(i) + ".ASC";
        filename.push_back(name);
    }
    vector<pair<double, double>> vec;
    vector<pair<double, double>> integrals;
    vector<double> thicknessmm{0.1,0.2,0.51,0.76,1.57,3.18,6.35};
    vector<double> thicknessmgcm2{10,20,49,73,151,305,610};

    for (string file : filename){
        int integral = 0;
        int integralerror = 0;
        vec.clear();
        ReadFile(file, vec);
        TGraphErrors plot;
        for (int i = 0; i < vec.size(); i++){
            plot.SetPoint(i, vec[i].first, vec[i].second);
            plot.SetPointError(i, 0, sqrt(vec[i].second));
            integral += vec[i].second;
            integralerror += sqrt(vec[i].second);
        }
        integrals.push_back(make_pair(integral, integralerror));
        plot.SetMarkerStyle(1);
        plot.SetMarkerColor(kOrange);
        plot.SetLineColor(kOrange);
        string title = "Polyethylene thickness " + file.substr(10,1);
        plot.SetTitle(title.data());
        plot.GetXaxis()->SetTitle("Channels");
        plot.GetYaxis()->SetTitle("Counts");
        plot.GetXaxis()->CenterTitle();
        plot.GetYaxis()->CenterTitle();
        plot.GetXaxis()->SetRangeUser(0, 300);
        c1.Clear();
        plot.Draw("APL");
        c1.Update();
        string png = "graphs/Polyethylene" + file.substr(10,1) + ".png";
        c1.SaveAs(png.data());
        //c1.WaitPrimitive();
        gSystem->ProcessEvents();
    }

    c1.Clear();
    vec.clear();
    ReadFile("data/TTBET1.ASC", vec);
    TGraphErrors plot1;
    for (int i = 0; i < vec.size(); i++){
        plot1.SetPoint(i, vec[i].first, vec[i].second);
        plot1.SetPointError(i, 0, sqrt(vec[i].second));
    }
    plot1.SetMarkerStyle(1);
    plot1.SetMarkerColor(kRed);
    plot1.SetLineColor(kRed);
    plot1.SetTitle("All Polyethylene");
    plot1.GetXaxis()->SetTitle("Channels");
    plot1.GetYaxis()->SetTitle("Counts");
    plot1.GetXaxis()->CenterTitle();
    plot1.GetYaxis()->CenterTitle();
    plot1.GetXaxis()->SetRangeUser(0, 300);
    c1.Clear();
    plot1.Draw("APL");

    vec.clear();
    ReadFile("data/TTBET2.ASC", vec);
    TGraphErrors plot2;
    for (int i = 0; i < vec.size(); i++){
        plot2.SetPoint(i, vec[i].first, vec[i].second);
        plot2.SetPointError(i, 0, sqrt(vec[i].second));
    }
    plot2.SetMarkerStyle(1);
    plot2.SetMarkerColor(kBlue);
    plot2.SetLineColor(kBlue);
    plot2.Draw("same PL");

    vec.clear();
    ReadFile("data/TTBET3.ASC", vec);
    TGraphErrors plot3;
    for (int i = 0; i < vec.size(); i++){
        plot3.SetPoint(i, vec[i].first, vec[i].second);
        plot3.SetPointError(i, 0, sqrt(vec[i].second));
    }
    plot3.SetMarkerStyle(1);
    plot3.SetMarkerColor(kViolet);
    plot3.SetLineColor(kViolet);
    plot3.Draw("same PL");

    vec.clear();
    ReadFile("data/TTBET4.ASC", vec);
    TGraphErrors plot4;
    for (int i = 0; i < vec.size(); i++){
        plot4.SetPoint(i, vec[i].first, vec[i].second);
        plot4.SetPointError(i, 0, sqrt(vec[i].second));
    }
    plot4.SetMarkerStyle(1);
    plot4.SetMarkerColor(kGreen);
    plot4.SetLineColor(kGreen);
    plot4.Draw("same PL");

    vec.clear();
    ReadFile("data/TTBET5.ASC", vec);
    TGraphErrors plot5;
    for (int i = 0; i < vec.size(); i++){
        plot5.SetPoint(i, vec[i].first, vec[i].second);
        plot5.SetPointError(i, 0, sqrt(vec[i].second));
    }
    plot5.SetMarkerStyle(1);
    plot5.SetMarkerColor(kBlack);
    plot5.SetLineColor(kBlack);
    plot5.Draw("same PL");

    vec.clear();
    ReadFile("data/TTBET6.ASC", vec);
    TGraphErrors plot6;
    for (int i = 0; i < vec.size(); i++){
        plot6.SetPoint(i, vec[i].first, vec[i].second);
        plot6.SetPointError(i, 0, sqrt(vec[i].second));
    }
    plot6.SetMarkerStyle(1);
    plot6.SetMarkerColor(kTeal);
    plot6.SetLineColor(kTeal);
    plot6.Draw("same PL");

    vec.clear();
    ReadFile("data/TTBET7.ASC", vec);
    TGraphErrors plot7;
    for (int i = 0; i < vec.size(); i++){
        plot7.SetPoint(i, vec[i].first, vec[i].second);
        plot7.SetPointError(i, 0, sqrt(vec[i].second));
    }
    plot7.SetMarkerStyle(1);
    plot7.SetMarkerColor(kOrange);
    plot7.SetLineColor(kOrange);
    plot7.Draw("same PL");

    TLegend leg(0.7, 0.6, 0.85, .85);
    leg.AddEntry(&plot7, "Thickness = 1/4 inc", "l");
    leg.AddEntry(&plot6, "Thickness = 1/8 inc", "l");
    leg.AddEntry(&plot5, "Thickness = 1/16 inc", "l");
    leg.AddEntry(&plot4, "Thickness = 3/100 inc", "l");
    leg.AddEntry(&plot3, "Thickness = 2/100 inc", "l");
    leg.AddEntry(&plot2, "Thickness = 8/1000 inc", "l");
    leg.AddEntry(&plot1, "Thickness = 4/1000 inc", "l");
    leg.Draw();

    c1.Update();
    c1.SaveAs("graphs/AllPolyethylene.png");
    //c1.WaitPrimitive();
    gSystem->ProcessEvents();
    TF1 fit1("fit1", "gaus", 13, 17);
    fit1.SetLineColor(kBlack);
    fit1.SetLineWidth(2);
    fit1.SetLineStyle(2);
    plot1.Fit(&fit1, "R");
    plot1.SetTitle("");
    TF1 fit2("fit2", "gaus", 13, 17);
    fit2.SetLineColor(kBlack);
    fit2.SetLineWidth(2);
    fit2.SetLineStyle(2);
    plot2.Fit(&fit2, "R");
    plot2.SetTitle("");
    TF1 fit3("fit3", "gaus", 13, 17);
    fit3.SetLineColor(kBlack);
    fit3.SetLineWidth(2);
    fit3.SetLineStyle(2);
    plot3.Fit(&fit3, "R");
    plot3.SetTitle("");
    TF1 fit4("fit4", "gaus", 13, 17);
    fit4.SetLineColor(kBlack);
    fit4.SetLineWidth(2);
    fit4.SetLineStyle(2);
    plot4.Fit(&fit4, "R");
    plot4.SetTitle("");
    TF1 fit5("fit5", "gaus", 13, 17);
    fit5.SetLineColor(kBlack);
    fit5.SetLineWidth(2);
    fit5.SetLineStyle(2);
    plot5.Fit(&fit5, "R");
    plot5.SetTitle("");
    TF1 fit6("fit6", "gaus", 13, 17);
    fit6.SetLineColor(kBlack);
    fit6.SetLineWidth(2);
    fit6.SetLineStyle(2);
    plot6.Fit(&fit6, "R");
    plot6.SetTitle("");
    TF1 fit7("fit7", "gaus", 13, 17);
    fit7.SetLineColor(kBlack);
    fit7.SetLineWidth(2);
    fit7.SetLineStyle(2);
    plot7.SetTitle("");
    plot7.Fit(&fit7, "R");
    plot7.GetXaxis()->SetRangeUser(0, 50);
    plot6.GetXaxis()->SetRangeUser(0, 50);
    plot5.GetXaxis()->SetRangeUser(0, 50);
    plot4.GetXaxis()->SetRangeUser(0, 50);
    plot3.GetXaxis()->SetRangeUser(0, 50);
    plot2.GetXaxis()->SetRangeUser(0, 50);
    plot1.GetXaxis()->SetRangeUser(0, 50);
    double average_means = (fit1.GetParameter(1) + fit2.GetParameter(1) + fit3.GetParameter(1) + fit4.GetParameter(1) + fit5.GetParameter(1) + fit6.GetParameter(1) + fit7.GetParameter(1))/7;
    double error_means = (fit1.GetParError(1) + fit2.GetParError(1) + fit3.GetParError(1) + fit4.GetParError(1) + fit5.GetParError(1) + fit6.GetParError(1) + fit7.GetParError(1))/7;
    cout << "Average Mean: " << average_means << " +/- " << error_means * 4.616 + 1.499 << endl;
    cout << "Peak Energy: " << average_means * 4.616 + 1.499 << "KeV "<< endl;
    TLegend leg2(0.4, 0.4, 0.65, 0.5);
    leg2.AddEntry("graph", Form("Peak Energy: %.2f +/- 1.66 keV", average_means * 4.616 + 1.499), "l");
    leg2.Draw();
    c1.Update();
    c1.SaveAs("graphs/xrays.png");
    A.Run();



    c1.Clear();
    TGraphErrors plotmm;
    TGraphErrors plotmgcm2;
    for (int i = 0; i < integrals.size(); i++){
        plotmm.SetPoint(i, thicknessmm[i], integrals[i].first);
        plotmm.SetPointError(i, 0.1, integrals[i].second);
        plotmgcm2.SetPoint(i, thicknessmgcm2[i], integrals[i].first);
        plotmgcm2.SetPointError(i,1, integrals[i].second);
    }
    plotmm.SetMarkerStyle(1);
    plotmm.SetMarkerColor(kRed);
    plotmm.SetLineColor(kRed);
    plotmm.SetTitle("Counts relation with thickness");
    plotmm.GetXaxis()->SetTitle("Thickness [mm]");
    plotmm.GetYaxis()->SetTitle("Counts");
    plotmm.GetXaxis()->CenterTitle();
    plotmm.GetYaxis()->CenterTitle();
    plotmm.GetXaxis()->SetRangeUser(0, 300);
    plotmm.Draw("APC");

    c1.Update();
    c1.SaveAs("graphs/Counts_Thickness_mm.png");
    c1.WaitPrimitive();
    gSystem->ProcessEvents();
    
    c1.Clear();
    plotmgcm2.SetMarkerStyle(1);
    plotmgcm2.SetMarkerColor(kRed);
    plotmgcm2.SetLineColor(kRed);
    plotmgcm2.SetTitle("Counts relation with thickness");
    plotmgcm2.GetXaxis()->SetTitle("Thickness [mg/cm^{2}]");
    plotmgcm2.GetYaxis()->SetTitle("Counts");
    plotmgcm2.GetXaxis()->CenterTitle();
    plotmgcm2.GetYaxis()->CenterTitle();
    plotmgcm2.GetXaxis()->SetRangeUser(0, 620);
    plotmgcm2.Draw("APC");
    c1.Update();
    c1.SaveAs("graphs/Counts_Thickness_mgcm2.png");
    c1.WaitPrimitive();
    gSystem->ProcessEvents();
}