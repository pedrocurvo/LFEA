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
#include "TGraphErrors.h"
#include "TStyle.h"
#include "TLatex.h"
#include "Read_Geiger.h"

using namespace std;

int main(){
    // Create Application
    TApplication A("A", nullptr, nullptr);
    // Create Canvas
    TCanvas c1("c1", "c1", 1200, 800); 

/////////////////////////////////////// Plateau //////////////////////////////////////////////////////////////////////
vector<vector<double>> plateau;
ReadFile("data/plateau.dat", plateau);

TGraphErrors graph_plateau(plateau.size(), &plateau[0][0], &plateau[0][9], nullptr, &plateau[0][10]);

// Set Graph Style
graph_plateau.SetMarkerStyle(20);
graph_plateau.SetMarkerColor(kRed);
graph_plateau.SetLineColor(kRed);
graph_plateau.SetTitle("Plateau");
graph_plateau.GetXaxis()->SetTitle("Tensao [V]");
graph_plateau.GetYaxis()->SetTitle("Contagem de Particulas");
graph_plateau.GetXaxis()->CenterTitle();
graph_plateau.GetYaxis()->CenterTitle();

// Create Legend
TLegend legend_plateau(0.7, 0.7, 0.9, 0.9);

// Fit
TF1 fit_plateau("fit", "[0]*x + [1]", 0, 0.04);
fit_plateau.SetParameter(0, 1);
fit_plateau.SetParameter(1, 1);

// Draw
graph_plateau.Draw("AP");
graph_plateau.Fit(&fit_plateau, "R");
legend_plateau.AddEntry(&graph_plateau, "Dados Experimentais", "lep");
legend_plateau.AddEntry(&fit_plateau, "Ajuste Linear", "l");
legend_plateau.Draw();

// Save
c1.Update();
c1.SaveAs("plateau.png");
c1.WaitPrimitive();
gSystem->ProcessEvents();





////////////////////////////////////// Contagem de Particulas em funcao da distancia //////////////////////////////////////

    vector<double> distances = { 0.0127, 0.0190, 0.0254, 0.0318, 0.0381};
    vector<double> counts_al = { 2489, 1160, 852, 612, 509};
    vector<double> counts_al_uncertain = { 50, 34, 29, 25, 23};
    vector<double> counts_without_al = {83388, 36599, 13334, 4711, 3747};
    vector<double> counts_without_al_uncertain = {289, 191, 115, 69, 61};

    // Create Graph
    TGraphErrors graph_al(distances.size(), &distances[0], &counts_al[0], nullptr, &counts_al_uncertain[0]);
    TGraphErrors graph_without_al(distances.size(), &distances[0], &counts_without_al[0], nullptr, &counts_without_al_uncertain[0]);

    // Set Graph Style
    graph_al.SetMarkerStyle(20);
    graph_al.SetMarkerColor(kRed);
    graph_al.SetLineColor(kRed);
    graph_al.SetTitle("Contagem de Particulas em funcao da distancia c/Al");
    graph_al.GetXaxis()->SetTitle("Distancia [m]");
    graph_al.GetYaxis()->SetTitle("Contagem de Particulas");
    graph_al.GetXaxis()->CenterTitle();
    graph_al.GetYaxis()->CenterTitle();
    
    graph_without_al.SetMarkerStyle(20);
    graph_without_al.SetMarkerColor(kBlue);
    graph_without_al.SetLineColor(kBlue);
    graph_without_al.SetTitle("Contagem de Particulas em funcao da distancia s/Al");
    graph_without_al.GetXaxis()->SetTitle("Distancia [m]");
    graph_without_al.GetYaxis()->SetTitle("Contagem de Particulas");
    graph_without_al.GetXaxis()->CenterTitle();
    graph_without_al.GetYaxis()->CenterTitle();

    // Create Legend
    TLegend legend(0.7, 0.7, 0.9, 0.9);

    TLegend legend2(0.7, 0.7, 0.9, 0.9);

    // Fit
    TF1 fit("fit", "[0]/(x**2) + [1]", 0, 0.04);
    fit.SetParameter(0, 1);
    fit.SetParameter(1, 1);
    fit.SetParName(0, "A");
    fit.SetParName(1, "B");
    fit.SetLineColor(kRed);
    fit.SetLineStyle(2);
    fit.SetLineWidth(3);

    // Fit with C
    TF1 fit2("fit2", "[0]/((x+[2])**2) + [1]", 0, 0.04);
    fit2.SetParameter(0, 1);
    fit2.SetParameter(1, 1);
    fit2.SetParameter(2, 0.0238);
    fit2.SetParName(0, "A");
    fit2.SetParName(1, "B");
    fit2.SetParName(2, "C");
    fit2.SetLineColor(kBlack);
    fit2.SetLineStyle(2);
    fit2.SetLineWidth(3);




    // Draw Graph
    c1.Clear();
    graph_al.Fit(&fit, "R");
    legend.AddEntry(&graph_al, "Com Aluminio", "lep");
    legend.AddEntry(&fit, "A/x^{2} + B", "l");
    graph_al.Draw("AP");
    legend.Draw();
    c1.Update();
    c1.WaitPrimitive();
    gSystem->ProcessEvents();

    // Draw Graph
    c1.Clear();
    legend.Clear();
    graph_al.Fit(&fit2, "R");
    legend.AddEntry(&graph_al, "Com Aluminio", "lep");
    legend.AddEntry(&fit2, "A/(x+C)^{2} + B", "l");
    graph_al.Draw("AP");
    legend.Draw();
    c1.Update();
    c1.WaitPrimitive();
    gSystem->ProcessEvents();

    // Draw Graph
    c1.Clear();
    legend.Clear();
    graph_without_al.Fit(&fit, "R");
    legend.AddEntry(&graph_without_al, "Sem Aluminio", "lep");
    legend.AddEntry(&fit, "A/x^{2} + B", "l");
    graph_without_al.Draw("AP");
    legend.Draw();
    c1.Update();
    c1.WaitPrimitive();

    // Draw Graph
    c1.Clear();
    legend.Clear();
    graph_without_al.Fit(&fit2, "R");
    legend.AddEntry(&graph_without_al, "Sem Aluminio", "lep");
    legend.AddEntry(&fit2, "A/(x+C)^{2} + B", "l");
    graph_without_al.Draw("AP");
    legend.Draw();
    c1.Update();
    c1.WaitPrimitive();





}