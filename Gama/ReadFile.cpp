# include <iostream>
# include <cstdlib>
# include <cmath>
# include <fstream> // permite manipular e fazer a leitura
# include <string>
# include <vector>
using namespace std;


void ReadFile(string fname, vector <double> &t, vector <double> &A, vector <double> &z) {
    ifstream F(fname);
    string s;
    for (int j=0; j<5; j++){        // taking out 2 first lines
        getline(F, s);
        //cout << s << endl;
        }
    
    int i = 0; // counter
    t.push_back(0); A.push_back(0); z.push_back(0);
    while (F >> t.at(i) >> A.at(i) >> z.at(i)){
        t.push_back(i);
        A.push_back(i);
        z.push_back(i);
        //cout << t[i] << "  |  " << A[i] << endl;
        i ++;}
    //cout << "counter: " << i << endl;
}