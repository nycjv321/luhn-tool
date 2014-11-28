// number_utilities.cpp -- implement Number Utilities class
// version 00

#include <string> 
#include <vector>
#include "number_utilities.h"
#include <random>
#include <iostream>
#include <chrono>

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

int NumberUtilities::length(unsigned long long number) {
      int counter = 0;
      while(number) {
            number = number / 10;
            counter++;
      }
      return counter;
}

unsigned long long NumberUtilities::random_numeric(int l) {
	static mt19937_64 generator(std::chrono::system_clock::now().time_since_epoch().count());
	
	unsigned long long value = generator();
	long long number = 1;
	
	for (int i = 0; i < l - 1; ++i) {
		number *= 10;
	}
			
	while (value / 10 > number) { 
		value = value / 10;
	}
		
	return value;
}
