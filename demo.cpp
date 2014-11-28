// demo.cpp

#include <iostream>     // to be compiled with two file2.cpp
#include "luhn.h"
#include <vector>

int main() {
    using namespace std;

	unsigned int check_digit = Luhn::get_checkdigit(7992739871ll);
	cout << "Checkdigit is: " << check_digit;
	
}

