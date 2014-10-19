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

	static vector<int> string_to_int_vector(string value);
	static int summarize_int_vector(vector<int> numbers);
}; 

#endif
