// luhn.h
// version 00
#ifndef LUHN_H
#define LUHN_H

#include <string>
#include <vector>

using namespace std;

// Checks and validates account numbers that contain Luhn checksums
class Luhn  // class declaration
{
private: 
	static long getCheckSum(unsigned long long accountNumber, bool hasCheckDigit);
	
public:
    static bool isValid(unsigned long long accountNumber);
  	static long getCheckDigit(unsigned long long accountNumber, bool hasCheckDigit);
  	static long getCheckDigit(unsigned long long accountNumber);
	static vector<int> convertStringToIntVector(string value);
	static int summarizeIntVector(vector<int> numbers);
}; 

#endif


