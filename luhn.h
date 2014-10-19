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
	static long get_checksum(unsigned long long account_number, bool contains_check_digit);
	
public:
    static bool isValid(unsigned long long account_number);
  	static long get_checkdigit(unsigned long long account_number, bool contains_check_digit);
  	static long get_checkdigit(unsigned long long account_number);
	static vector<int> string_to_int_vector(string value);
	static int summarize_int_vector(vector<int> numbers);
}; 

#endif


