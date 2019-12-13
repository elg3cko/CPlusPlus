/**
* Program:    fraction.cpp
* Written by: Tony H.
* Date:       2017/11/08
**/

#include <iostream>
#include "fraction.h"
#include "fractionUtility.h"
using namespace std;

Fraction::Fraction(int numerator, int denominator)
{
	num = numerator;
    denom = denominator;

	if(denom < 0)
    {
		num = -num;
		denom = -denom;
	}
	else
	{
	    denominator = denom;
	}
        cout << "\nA fraction was made!"
             << "\n   num: " << num
             << "\n   denom: " << denom
             << endl << endl;
}

int* Fraction::extractUncommonDigit(int numerator, int denominator)
{
	int tempA = 0;
	int tempB = 0;
	int tempC = 0;
	int tempD = 0;
	int tempE = 0;
	int tempF = 0;

	int totalUncommonCount = 0;

	int* countDigitArray = new int[10]();
	int* holdDigitArray = new int[10]();

	int* tempUncommonArray1 = new int[10]();
	int* tempUncommonArray2 = new int[10]();

	int* uncommonCountArray = new int[10]();
	int* uncommonDisplayArray = new int[10]();

	for (int i = 0; i < 10; i++)
    {
		holdDigitArray[i] = i;
	}

	tempA = (num < 0) ? -num : num;

	do
	{
		countDigitArray[tempA % 10] ++;
		tempA /= 10;
	} while (tempA != 0);

	tempB = denom;

	do
    {
		countDigitArray[tempB % 10] ++;
		tempB /= 10;
	} while (tempB != 0);

    tempC = (num < 0) ? -num : num;

	do
    {
		tempUncommonArray1[tempC % 10] = 1;
		tempC /= 10;
	} while (tempC != 0);

	tempD = denom;

	do
    {
		tempUncommonArray2[tempD % 10] = 1;
		tempD /= 10;
	} while (tempD != 0);

	for (int j = 0; j < 10; j++)
	{
		(tempUncommonArray1[j] == tempUncommonArray2[j]) ?
			uncommonCountArray[j] = 0 :
			uncommonCountArray[j] = 1;
	}

	for (int i = 0; i < 10; i++)
    {
		if (uncommonCountArray[i] == 1)
			totalUncommonCount++;
	}

	uncommonDisplayArray = new int[3 * totalUncommonCount];

	for (int i = 0, j = 0; i < 10; i++)
    {
		if ((countDigitArray[i] != 0) &&
			(uncommonCountArray[i] == 1))
        {
			uncommonDisplayArray[j] = holdDigitArray[i];
			uncommonDisplayArray[j + 1] = countDigitArray[i];
			uncommonDisplayArray[j + 2] = 0;
			j += 3;
		}
	}

	tempE = (num < 0) ? -num : num;
	tempF = denom;

	do
    {
		if ((countDigitArray[tempE % 10] != 0) &&
			(uncommonCountArray[tempE % 10] == 1))
        {
			for (int j = 0; j < 3 * totalUncommonCount; j += 3)
			{
				if
					(holdDigitArray[tempE % 10] ==
						uncommonDisplayArray[j])
					uncommonDisplayArray[j + 2] = 3;
			}
		}
		tempE /= 10;
	} while (tempE != 0);

    do
    {
		if ((countDigitArray[tempF % 10] != 0) &&
			(uncommonCountArray[tempF % 10] == 1))
        {
			for (int j = 0; j < 3 * totalUncommonCount; j += 3)
			{
				if
					(holdDigitArray[tempF % 10] ==
						uncommonDisplayArray[j])
					uncommonDisplayArray[j + 2] = 4;
			}
		}
		tempF /= 10;
	} while (tempF != 0);

	cout <<
		"\nDisplaying current fraction..."
		"\n   num : "
		<< num << "\n   denom : "
		<< denom << endl
		<<
		"\nDisplaying extraction..."
		"\n  The uncommon digit array has "
		<< totalUncommonCount
		<<
		" uncommon digit(s) of "
		"\n    From num:" << endl;

	for (int i = 0; i < 3 * totalUncommonCount; i += 3)
    {
		if (uncommonDisplayArray[i + 2] == 3)
			cout
			<< "      "
			<< uncommonDisplayArray[i]
			<< " occurred "
			<< uncommonDisplayArray[i + 1]
			<< " time(s)" << endl;
	}

	cout <<
		"\n    From denom:" << endl;
		for (int i = 0; i < 3 * totalUncommonCount; i += 3)
		{
			if (uncommonDisplayArray[i + 2] == 4)
				cout
				<< "      "
				<< uncommonDisplayArray[i]
				<< " occurred "
				<< uncommonDisplayArray[i + 1]
				<< " time(s)" << endl;
		}

	cout << endl;

	delete[] countDigitArray;
    delete[] holdDigitArray;
	delete[] tempUncommonArray1;
	delete[] tempUncommonArray2;
	delete[] uncommonCountArray;
	delete[] uncommonDisplayArray;

	return uncommonDisplayArray;
}

void Fraction::setNum(int numerator)
{
	num = numerator;
}

void Fraction::setDenom(int denominator)
{
	if (denominator > 0)
    {
		denom = denominator;
	}
	if (denominator < 0)
	{
		num = -num;
		denom = -denominator;
	}
}

void Fraction::print() const
{
	cout << "\nDisplaying current fraction..."
		    "\n  num : " << num
		 << "\n  denom : " << denom
		 << endl << endl;
}

int Fraction::getNum() const
{
	return num;
}


int Fraction::getDenom() const
{
	return denom;
}
