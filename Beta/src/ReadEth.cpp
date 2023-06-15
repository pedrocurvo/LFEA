#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <utility>
using namespace std;

void ReadFile(const std::string& filename, vector<double>& K, vector<double>& Col,vector<double>& Rad,vector<double>& Total, vector<double>& Param)
{
    //vector<pair<double, double>> data;

    ifstream file(filename);
    if (file.is_open())
    {
        std::string line;
        while (getline(file, line))
        {   
            size_t pos = line.find(",");
            while(pos != std::string::npos)
            {
                line.replace(pos, 1, ".");
                pos = line.find(",", pos + 1);
            }
            istringstream iss(line);
            double value1, value2, value3, value4, value5, value6, value7;

            if (iss >> value1 >> value2 >> value3 >> value4 >> value5)
            {
                K.push_back(value1);
                Col.push_back(value2);
                Rad.push_back(value3);
                Total.push_back(value4);
                Param.push_back(value5);
                
            }
        }

        file.close();
    }
    else
    {
        cout << "Failed to open the file." << endl;
    }

    
    //return data;
}


void ReadFile(const std::string& filename, vector<double>& K, vector<double>& Col,vector<double>& Rad,vector<double>& Total, vector<double>& CSDA,vector<double>& Param)
{
    //vector<pair<double, double>> data;

    ifstream file(filename);
    if (file.is_open())
    {
        std::string line;
        while (getline(file, line))
        {   
            size_t pos = line.find(",");
            while(pos != std::string::npos)
            {
                line.replace(pos, 1, ".");
                pos = line.find(",", pos + 1);
            }
            istringstream iss(line);
            double value1, value2, value3, value4, value5, value6, value7;

            if (iss >> value1 >> value2 >> value3 >> value4 >> value5 >> value6 )
            {
                K.push_back(value1);
                Col.push_back(value2);
                Rad.push_back(value3);
                Total.push_back(value4);
                CSDA.push_back(value5);
                Param.push_back(value6);
                
            }
        }

        file.close();
    }
    else
    {
        cout << "Failed to open the file." << endl;
    }

    
    //return data;
}