#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <utility>
using namespace std;

vector<pair<double, double>> ReadFile(const std::string& filename)
{
    vector<pair<double, double>> data;

    ifstream file(filename);
    if (file.is_open())
    {
        std::string line;
        while (getline(file, line))
        {
            istringstream iss(line);
            double value1, value2;

            if (iss >> value1 >> value2)
            {
                data.emplace_back(value1, value2);
            }
        }

        file.close();
    }
    else
    {
        cout << "Failed to open the file." << endl;
    }

    return data;
}
