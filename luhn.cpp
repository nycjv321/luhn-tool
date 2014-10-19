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
bool Luhn::isValid(unsigned long long accountNumber) {
        return getCheckSum(accountNumber, false) == 0;
    }

// Generates the checksum associated with the provided account number
long Luhn::getCheckSum(unsigned long long accountNumber, bool hasCheckDigit) {
	
	stringstream streamLong;
	string numberAsString;
	streamLong  << accountNumber;
	streamLong >> numberAsString;
	if (hasCheckDigit) {
		numberAsString = numberAsString.substr(0, (numberAsString.size() - 1));
	}
	
	vector<int> numbers = NumberUtilities::convertStringToIntVector(numberAsString);
	
	for (int i = numbers.size() - 2; i >= 0; i -= 2) {
		int operation = numbers[i] * 2;
		if (operation > 9 ) {
			numbers[i] = 0;
			string operationAsString = to_string(operation);
			for (int j = 0; j < operationAsString.size(); ++j) {
				numbers[i] += atoi(operationAsString.substr(j, j + 1).c_str());
			}
		} else {
			numbers[i] = operation;
		}	 
	}
	
	int total = NumberUtilities::summarizeIntVector(numbers);
	return total % 10;
}

// Generates the check digit associated with the provided account number
long Luhn::getCheckDigit(unsigned long long accountNumber, bool hasCheckDigit) {
	long checkDigit = getCheckSum(accountNumber * 10, hasCheckDigit);
	if (checkDigit == 0) {
		return checkDigit;
	}else {
		return 10 - checkDigit;
	}
}

long Luhn::getCheckDigit(unsigned long long accountNumber) {
	return getCheckDigit(accountNumber, false);
}
