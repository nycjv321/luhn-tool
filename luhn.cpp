// luhn.cpp -- implement Luhn class
// version 00

#include <iostream>
#include "luhn.h"
#include "number_utilities.h"
#include <string> 
#include <vector>
#include <sstream>

using namespace std;

// Checks to see if a provided account number is 
// valid based on the suffix checksum digit
bool Luhn::is_valid(unsigned long long account_number) {
        return checksum(account_number, false) == 0;
    }

// Generates the checksum associated with the provided account number
unsigned int Luhn::checksum(unsigned long long account_number, bool contains_check_digit) {
	
	stringstream streamLong;
	string string_number;
	streamLong  << account_number;
	streamLong >> string_number;
	if (contains_check_digit) {
		string_number = string_number.substr(0, (string_number.size() - 1));
	}
	
	vector<int> numbers = NumberUtilities::string_to_int_vector(string_number);
	
	for (int i = numbers.size() - 2; i >= 0; i -= 2) {
		int operation = numbers[i] * 2;
		if (operation > 9 ) {
			numbers[i] = 0;
			string string_operation = to_string(operation);
			for (int j = 0; j < string_operation.size(); ++j) {
				numbers[i] += atoi(string_operation.substr(j, j + 1).c_str());
			}
		} else {
			numbers[i] = operation;
		}	 
	}
	
	unsigned int total = NumberUtilities::summarize_int_vector(numbers);
	return total % 10;
}

// Generates the check digit associated with the provided account number
unsigned int Luhn::checkdigit(unsigned long long account_number, bool contains_check_digit) {
	unsigned int checkDigit = checksum(account_number * 10, contains_check_digit);
	if (checkDigit == 0) {
		return checkDigit;
	}else {
		return 10 - checkDigit;
	}
}

unsigned int Luhn::checkdigit(unsigned long long account_number) {
	return checkdigit(account_number, false);
}

unsigned int Luhn::checkdigit(string account_number) {
	return checkdigit(std::stoull(account_number.c_str()), false);
}
