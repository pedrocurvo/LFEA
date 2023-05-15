#ifndef __READER__
#define __READER__

//Std
#include <string>
#include <vector>
using namespace std;

class Reader{


    /*
        Class containing methods to solve linear sytems

        Class attributes:

                Data -> vector containing vectors(point of the dataset)
	       		comprising the entire dataset

        Constructor arguments:

                String containing the absolute path of the file to be read
		        Integer specifying the number of line to skip before the data
                Integer specifying the number of elements in each line
    */

    public:
        Reader(string, int, int);
        vector<vector<double>> GetData(void);
        /*
	        Method to retrieve 
                Output: vector of vectors containing the data in the same
			manner as the class's vector
        */
    private:
        vector<vector<double>> Data;
};
#endif
