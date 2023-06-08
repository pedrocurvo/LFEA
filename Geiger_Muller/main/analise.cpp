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

    int numPoints = plateau.size();

    std::vector<double> xValues(numPoints);
    std::vector<double> yValues(numPoints);
    std::vector<double> exValues(numPoints);
    std::vector<double> eyValues(numPoints);

    for (int i = 0; i < numPoints; i++) {
        cout << plateau[i][0] << " " << plateau[i][9] << endl;
        xValues[i] = plateau[i][0];     // x values are stored in plateau[i][0]
        yValues[i] = plateau[i][7];     // y values are stored in plateau[i][1]
        exValues[i] = 0;    // error in x values are stored in plateau[i][2]
        eyValues[i] = plateau[i][8];    // error in y values are stored in plateau[i][3]
    }

    TGraphErrors graph_plateau(numPoints, &xValues[0], &yValues[0], &exValues[0], &eyValues[0]);
    gStyle->SetOptFit(111);
    // Set Graph Style
    graph_plateau.SetMarkerStyle(20);
    graph_plateau.SetMarkerColor(kRed);
    graph_plateau.SetLineColor(kRed);
    graph_plateau.SetTitle("Plateau");
    graph_plateau.GetXaxis()->SetTitle("Tensao [V]");
    graph_plateau.GetYaxis()->SetTitle("Taxa [counts/s]");
    graph_plateau.GetXaxis()->CenterTitle();
    graph_plateau.GetYaxis()->CenterTitle();

    // Create Legend
    TLegend legend_plateau(0.65, 0.35, 0.85, 0.5);

    // Fit
    TF1 fit_plateau("fit", "[0]*x + [1]", 775, 1200);
    fit_plateau.SetParameter(0, 1);
    fit_plateau.SetParameter(1, 1);
    fit_plateau.SetLineColor(kBlue);
    fit_plateau.SetParName(0, "A");
    fit_plateau.SetParName(1, "B");

    // Draw
    graph_plateau.Draw("AP");
    graph_plateau.Fit(&fit_plateau, "R");
    legend_plateau.AddEntry(&graph_plateau, "Dados Experimentais", "lep");
    legend_plateau.AddEntry(&fit_plateau, "Fit Plateau de Geiger", "l");
    legend_plateau.Draw();

    // Save
    c1.Update();
    c1.SaveAs("graphs/plateau.png");
    c1.WaitPrimitive();
    gSystem->ProcessEvents();





////////////////////////////////////// Contagem de Particulas em funcao da distancia //////////////////////////////////////

    vector<double> distances = { 0.0127, 0.0190, 0.0254, 0.0318, 0.0381};
    vector<double> counts_al = { 2489, 1160, 852, 612, 509};
    vector<double> counts_al_uncertain = { 50, 34, 29, 25, 23};
    vector<double> counts_without_al = {83388, 36599, 13334, 4711, 3747};
    vector<double> counts_without_al_uncertain = {289, 191, 115, 69, 61};
    vector<double> uncertainty_distance = {0.0005, 0.0005, 0.0005, 0.0005, 0.0005};
    vector<double> counts_subtracted(counts_al.size());
    vector<double> counts_subtracted_uncertain(counts_al.size());
    for(int i = 0; i < counts_subtracted.size(); i++){
        counts_subtracted[i] = counts_without_al[i] - counts_al[i];
        counts_subtracted_uncertain[i] = sqrt(counts_without_al_uncertain[i]*counts_without_al_uncertain[i] + counts_al_uncertain[i]*counts_al_uncertain[i]);
    }

    // Create Graph
    TGraphErrors graph_al(distances.size(), &distances[0], &counts_al[0], &uncertainty_distance[0], &counts_al_uncertain[0]);
    TGraphErrors graph_without_al(distances.size(), &distances[0], &counts_without_al[0], &uncertainty_distance[0], &counts_without_al_uncertain[0]);
    TGraphErrors graph_subtracted(distances.size(), &distances[0], &counts_subtracted[0], &uncertainty_distance[0], &counts_subtracted_uncertain[0]);

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

    graph_subtracted.SetMarkerStyle(20);
    graph_subtracted.SetMarkerColor(kGreen);
    graph_subtracted.SetLineColor(kGreen);
    graph_subtracted.SetTitle("Contagem de Particulas em funcao da distancia s/Al - c/Al");
    graph_subtracted.GetXaxis()->SetTitle("Distancia [m]");
    graph_subtracted.GetYaxis()->SetTitle("Contagem de Particulas");
    graph_subtracted.GetXaxis()->CenterTitle();
    graph_subtracted.GetYaxis()->CenterTitle();

    // Create Legend
    TLegend legend(0.65, 0.55, 0.85, 0.65);
    legend.SetTextSize(0.03);

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
    fit2.SetParameter(2, 0);
    fit2.SetParLimits(2, -0.005, 0.005);
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
    c1.SaveAs("graphs/contagem_al.png");
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
    c1.SaveAs("graphs/contagem_al_c.png");
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
    c1.SaveAs("graphs/contagem_without_al.png");
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
    c1.SaveAs("graphs/contagem_without_al_c.png");
    c1.WaitPrimitive();

    // Draw Graph
    c1.Clear();
    legend.Clear();
    graph_subtracted.Fit(&fit, "R");
    legend.AddEntry(&graph_subtracted, "Subtraido", "lep");
    legend.AddEntry(&fit, "A/x^{2} + B", "l");
    graph_subtracted.Draw("AP");
    legend.Draw();
    c1.Update();
    c1.SaveAs("graphs/contagem_subtracted.png");
    c1.WaitPrimitive();

    // Draw Graph
    c1.Clear();
    legend.Clear();
    graph_subtracted.Fit(&fit2, "R");
    legend.AddEntry(&graph_subtracted, "Subtraido", "lep");
    legend.AddEntry(&fit2, "A/(x+C)^{2} + B", "l");
    graph_subtracted.Draw("AP");
    legend.Draw();
    c1.Update();
    c1.SaveAs("graphs/contagem_subtracted_c.png");
    c1.WaitPrimitive();
    







}