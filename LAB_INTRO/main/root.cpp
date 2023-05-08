#include <iostream>
#include <cmath>
#include "TF1.h"
#include "TH1D.h"
#include "TApplication.h"
#include <fstream>

using namespace std;

int main(){

	TApplication app("app", NULL, NULL);

	ifstream ifile;
	ifile.open("nome_ficheiro.txt");
	
	int n_bin=100; //INSERIR
	double minimo=0; //inserir canal minimo
	double maximo=100; // inserir o canal maximo 

	TH1D h("h","h", n_bin, minimo, maximo);

	double channel, contagem;

	while(ifile >> channel >> contagem){

	for(int i=0; i<contagem; i++){
		h.Fill(channel);
	  }

	}

	h.Draw("E");

	TF1 f("f","[0]*x+1",minimo, maximo); //Inserir formula para fazer o fit 

	h.Fit("f");

	f.Draw("same");

	app.Run("true");
	
	return 0;
}
