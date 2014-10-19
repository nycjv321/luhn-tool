// number_utilities.cpp -- implement Number Utilities class
// version 00

#include <string> 
#include <vector>
#include "number_utilities.h"

vector<int> NumberUtilities::string_to_int_vector(string value) {
	std::vector<int> integers(value.size());   
	
	for (int i = 0 ; i < value.size(); ++i) {
		integers[i] = value[i] -'0'; 
	}
	return integers;
}

int NumberUtilities::summarize_int_vector(vector<int> numbers) {
	int total = 0;
	
	for (int i = 0; i < numbers.size(); ++i) {
		total += numbers[i];
	}
	return total;
}

