#include <iostream>
#include <cmath>
#include "TF1.h"
#include "TH1D.h"
#include "TApplication.h"
#include <fstream>
#include "Reader.h"

int main(){
    Reader RR(valoreshist_test_OneShot.txt, 1);
    vector<vector<double>> rawdata = RR.GetData();
    vector<double> data;
    for(int i=0; i < rawdata.size(); i++){
		data.push_back(rawdata[i][0]);
	}
    
    TApplication app("app", NULL, NULL);
	
	int n_bin=20; //INSERIR
	double minimo=min_element(data.begin(), data.end()); //inserir canal minimo
	double maximo=max_element(data.begin(), data.end()); // inserir o canal maximo 

	TH1D h("h","h", n_bin, minimo, maximo);

	for(int i=0; i < data.size(); i++){
		h.Fill(data[i]);
	}

	h.Draw("E");

	TF1 f("f","[0]*x+1",minimo, maximo); //Inserir formula para fazer o fit 

	h.Fit("f");

	f.Draw("same");

	app.Run("true");


    return 0;
}