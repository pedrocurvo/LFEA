#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <utility>
using namespace std;

void ReadFile(const std::string& filename, vector<vector<double>>& data)
{
    //vector<pair<double, double>> data;

    ifstream file(filename);
    if (file.is_open())
    {
        std::string line;
        while (getline(file, line))
        {
            istringstream iss(line);
            double value1, value2, value3, value4, value5, value6, value7, value8, value9, value10, value11;

            if (iss >> value1 >> value2 >> value3 >> value4 >> value5 >> value6 >> value7 >> value8 >> value9 >> value10 >> value11 )
            {
                data.emplace_back(std::vector<double>{value1, value2, value3, value4, value5, value6, value7, value8, value9, value10, value11});
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
