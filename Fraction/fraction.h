/**
* Program:    fraction.h
* Written by: Tony H.
* Date:       2017/11/08
**/

#ifndef FRACTION_H_INCLUDED
#define FRACTION_H_INCLUDED
#include <iostream>
using namespace std;

class Fraction
{
public:
	Fraction(int, int);

	int* extractUncommonDigit(int numerator, int denominator);

	void setNum(int);
	void setDenom(int);
	void print(void) const;

	int getNum(void) const;
	int getDenom(void) const;

private:
	int num;
	int denom;
};

#endif // FRACTION_H_INCLUDED