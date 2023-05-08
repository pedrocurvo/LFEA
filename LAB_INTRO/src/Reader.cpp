#include "Reader.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

Reader::Reader(string filename, int N){
    ifstream F(filename);
    string s;
    for (int i = 0; i < 2; i++){
        getline(F, s);
    }
    int col = 0;
    int row = 0;
    vector<double> row0(N);
    Data.push_back(row0);
    while (F >> Data[row][col]) {
        col++;
        if(col == N){
            col = 0;
            row++;
            vector<double> rowi(N);
            Data.push_back(rowi);
        }
    }
    Data.pop_back();
}

vector<vector<double>> Reader::GetData(){
    return Data;
}