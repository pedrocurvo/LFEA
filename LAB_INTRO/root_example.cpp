#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
using namespace std;

void root_example() {

    //-----------------------------------------------------------READ FILE------------------------------------------------------------//
    
    ifstream file;
    file.open("linear.csv");
    
    vector <float> x, y;
     
    // Ignore first line
    file.ignore(LLONG_MAX, '\n');
    
    
    string line, delimiter = ",";
    float val;
    int pos=0;
    
    while(getline(file, line)){
        pos = line.find(delimiter);
        
        // Parse the string and store the desired values
        x.push_back(stof(line.substr(0, pos)));
        line.erase(0, pos + delimiter.length());
        y.push_back(stof(line));
    }
    
    file.close();
    
    
    
    //--------------------------------------------------------------PLOT---------------------------------------------------------------//
    
    auto c = new TCanvas("Example", "", 0, 0, 1500, 1500);
    c-> SetGrid();
    
    // Convert vec to array to use in TGraph
    float ax [x.size()];
    float ay [x.size()];
    
    for (int i = 0; i < x.size(); i++){
        ax[i] = x[i];
        ay[i] = y[i];
    }
    
    auto g = new TGraph(x.size(), ax, ay);
    g-> SetTitle("Plot example");
    g-> SetMarkerStyle(8);
    g-> SetMarkerSize(0.8);
    
    
    
    //----------------------------------------------------------------FIT--------------------------------------------------------------//
    
    // Declaration of fit functions
    auto f1 = new TF1("Linear fit", "[0]*x+[1]", ax[0], ax[x.size()]);
    auto f2 = new TF1("Exponential fit", "[0]*exp([1]*x)", ax[0], ax[x.size()]);
    auto f3 = new TF1("Gaussian fit", "gaus", ax[0], ax[x.size()]);
    // gaus = [Constant]*exp(-0.5*((x-[Mean])/[Sigma])*((x-[Mean])/[Sigma]))
    auto f4 = new TF1("Two gaussian fit", "[0]*exp(-0.5*((x-[1])/[2])*((x-[1])/[2])) + [3]*exp(-0.5*((x-[4])/[5])*((x-[4])/[5]))", ax[0], ax[x.size()]);
    auto f5 = new TF1("Gaussian fit with linear noise", "gaus + [3]*x+[4]", ax[0], ax[x.size()]);
    auto f6 = new TF1("Gaussian fit with exponential noise", "gaus + [3]*exp([4]*x)", ax[0], ax[x.size()]);
    
    
    /* HOW TO FIT GAUSSIAN WHITH NOISE:
     - Previously select the points that do not belong to the gaussian and save them in diferent file
     - Fit the noise points with the linear/polinomial or exponential fit to find the parameters of that curve and
     set the values encountered as initial parameters of the fit function
     - Finally, fit the whole points using the respective fit function and initial parameters
    */
    
    // Give initial parameters to the fit funtions -> important for fits with noise or with more than one gaussian
    f1-> SetParameters(0.954892, 51.6898);
    f2-> SetParameters(426.103, -0.0833753);
    f3-> SetParameters(309.578, 36.8166, 6.41789);
    f4-> SetParameters(141.85, 59.2324, 3.51108, 251.659, 42.6864, 5.93927);
    f5-> SetParameters(130.928, 40.21, 9.51679, -1.17957, 128.944);
    f6-> SetParameters(507.293, 37.5508, 2.10464, 297.083, -0.0393331);
    
    
    // Fit all graph range -> Parameters will be presented in the comand line
    g->Fit(f1);
    
    // Fit in a given range ex.[0,100] ('0' is the option to not immediately draw the fit with the graph)
    //g->Fit(f3, "0", "", 0, 100);
    
    // Draw graph or graph+fit if Fit() was performed
    g-> Draw("AP");
    
    c-> SaveAs ("linear.png");
}

/* RESULTS OBTAINED FOR EXAMPLE FILES:
 - Linear (linear.csv):
    p0   =     0.954892   +/-   0.0325827
    p1   =     51.6898    +/-   1.87646
    Chi2 =     8325.81
 - Exponential (exp.csv):
    p0   =     426.103      +/-   2.63872
    p1   =     -0.0833753   +/-   0.000713181
    Chi2 =     7599.82
 - Gaussian (gaus.csv):
    Constant   =     309.578   +/-   1.50987
    Mean       =     36.8166   +/-   0.0359862
    Sigma      =     6.41789   +/-   0.0364579
    Chi2       =     6717.41
 - 2 Gaussians (gaus2.csv):
    p0   =     141.85    +/-   2.44367
    p1   =     59.2324   +/-   0.0790425
    p2   =     3.51108   +/-   0.0790563
    p3   =     251.659   +/-   1.9338
    p4   =     42.6864   +/-   0.0570686
    p5   =     5.93927   +/-   0.0630426
    Chi2 =     9543.18
 - Gaussiana + linear noise (gaus_linear.csv):
    p0   =     130.928   +/-   1.9652
    p1   =     40.21     +/-   0.160639
    p2   =     9.51679   +/-   0.187791
    p3   =     -1.16187  +/-   0.0239042
    p4   =     127.147   +/-   1.68874
    Chi2 =     14635.4
 - Gaussiana + exponential noise (gaus_exp.csv):
    p0   =     507.293    +/-   4.11175
    p1   =     37.5508    +/-   0.0194028
    p2   =     2.10464    +/-   0.0202237
    p3   =     297.089    +/-   2.63701
    p4   =     -0.0393905 +/-   0.000538963
    Chi2 =     15820.6
*/
