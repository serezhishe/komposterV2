﻿#include "pch.h"
#include <iostream> 
#include <math.h> 
using namespace std;
int digit_number (int number, int base) {
	int n = 1;
	for (int i = base; i <= number; i *= base) { n++; }
	return n;
}
char* convertion (int number, int base) {
	char* result = new char[number];
	int k = digit_number(number, base);
	for (int i = k; i > 0; i--) {
		result[k - i] = '0' + floor(number / pow(base, i - 1));
		if (floor (number / pow(base, i - 1)) != 0) {
			number -= pow(base, i - 1);}
	}
	result[k] = '\0';
	return result;
}
int main() {
	int base, number;
	cin >> base >> number;
	cout << convertion(number, base);
	return 0;
}
