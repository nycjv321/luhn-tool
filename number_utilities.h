// number_utilities.h
// version 00
#ifndef NUMBER_UTILITIES_H
#define NUMBER_UTILITIES_H
#include <string>
#include <vector>
#include <chrono>
#include <random>

using namespace std;

class NumberUtilities {
	private:
	public:
	
		static vector<int> string_to_int_vector(string value);
		static int summarize_int_vector(vector<int> numbers);
		static int length(unsigned long long number);
		static unsigned long long random_numeric(int length);
}; 

#endif
