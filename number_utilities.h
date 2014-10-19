// number_utilities.h
// version 00
#ifndef NUMBER_UTILITIES_H
#define NUMBER_UTILITIES_H
#include <string>
#include <vector>

using namespace std;

class NumberUtilities  // class declaration
{

public:

	static vector<int> convertStringToIntVector(string value);
	static int summarizeIntVector(vector<int> numbers);
}; 

#endif
