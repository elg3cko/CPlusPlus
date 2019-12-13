/**
* Program:    Extracting an uncommon digit.cpp
* Written by: Tony H.
* Date: 2017/10/05
**/

#include <iostream>
using namespace std;

//Function Prototypes
void displayInfo(void);
void menuMain(void);
void displayResults(int*);

int countDigitSeen(int, int);
int countDigitSeen(int[], int, int);

int* getUncommonDigitCheck(int);
int* extractUncommonDigit(int[], int);

//Application Driver
int main()
{
    displayInfo();
    menuMain();

    return 0;
}

//Function Definitions
void displayInfo()
{
	cout << "Extracting an Uncommon Digit\n"
		<< "  Written by:         Tony Hernandez\n"
		<< "  Date:               2017/10/05" << endl;
}

void menuMain()
{
    int option = 0;
    int size = 0;

    int* ary;
    int* uncommonDigitArray;

	do
	{
		cout <<
            "\n*********************************************"
            "\n*                MENU                       *"
			      "\n* 1. Extract the Uncommon Digit             *"
			      "\n* 2. Quit                                   *"
			      "\n*********************************************"
			      "\nSelect an option (1 or 2): ";
		cin >> option;

		switch (option)
		{
		case 1:
			cout << "\n  How many integers? ";
            cin >> size;

            ary = new int[size];

            for (int i = 0; i < size; i++)
            {
                cout << "    Enter integer #"
                     << i + 1
                     << ": ";
                cin  >> ary[i];
            }

            cout << "\n  The original input: ";

            for (int i = 0; i < size; i++)
            {
                cout << "\n    "
                     << ary[i];
            }

            cout << "\n\n  Extracting..."
                 << "\n"
                 << "\n  Displaying..."
                 << "\n  The Uncommon Digits:"
                 << "\n  {the digit, times seen}";

            uncommonDigitArray = extractUncommonDigit(ary, size);

            displayResults(uncommonDigitArray);

            delete[] uncommonDigitArray;
			break;
		case 2:
			cout << "\n  Goodbye!\n" << endl;
				break;
		default:
			cout << "\n  Wrong option!\n" << endl;
		}
	} while (option != 2);
}

void displayResults(int* ary)
{
    if(*(ary) > 0)
    {
      cout << "\n\n  Found "
           << *(ary)
           << " uncommon digit(s) with"
           << "\n    "
           << *(ary + 1)
           << " even uncommon digit(s):";

        for (int i = 0; i < *(ary + 1); i++)
        {
        cout << "\n      {"
             << *(ary + 2 + i * 2)
             << ", "
             << *(ary + 3 + i * 2)
             << "}";
        }

        cout << "\n\n    And "
             << *(ary + 2 + *(ary + 1) * 2)
             << " odd uncommon digit(s):";

        for (int j = 0; j < *(ary + 2 + *(ary + 1) * 2); j++)
        {
           cout << "\n      {"
            << *(ary + 3 + *(ary + 1) * 2 + j * 2)
            << ", "
            << *(ary + 4 + *(ary + 1) * 2 + j * 2)
            << "}";
        }

        cout << endl << endl;
    }
    else
    {
      cout << "\n\n  There are 0 uncommon digits";
    }
}

int countDigitSeen(int arg, int digit)
{
    int counter = 0;

    if (arg < 0)
    {
        arg = -arg;
    }

    do
    {
        if (arg % 10 == digit)
      {
          counter++;
      }
      arg /= 10;
    } while (arg != 0);

   return counter;
}

int countDigitSeen(int ary[], int size, int digit)
{
    int counter = 0;

    for (int i = 0; i < size; i++)
    {
      counter += countDigitSeen(ary[i], digit);
    }

    return counter;
}

int* getUncommonDigitCheck(int arg)
{
    int* returnDigitArray = new int[10];

    for(int i = 0; i < 10; i++)
    {
      *(returnDigitArray + i) = 0;
    }

    if(arg < 0)
    {
      arg = -arg;
    }

    do
    {
      *(returnDigitArray + (arg % 10)) = 1;
      arg /= 10;
    } while (arg != 0);

   return returnDigitArray;
}

int* extractUncommonDigit(int ary[], int size)
{
    int uncommonEvenDigitArray[10] = {0};
    int uncommonOddDigitArray[10] = {0};
    int uncommonEvenDigit = 0;
    int uncommonOddDigit = 0;

    int* uncommonDigitCheck;
    int* tempArray;

    int totalUncommonDigit = 0;

    uncommonDigitCheck = getUncommonDigitCheck(ary[0]);

    for(int i = 1; i < size; i++)
    {
      tempArray = getUncommonDigitCheck(ary[i]);

      for (int j = 0; j < 10; j++)
      {
         *(uncommonDigitCheck + j) += *(tempArray + j);
      }

      delete[] tempArray;
    }

    for(int k = 0; k < 10; k++)
    {
      if(*(uncommonDigitCheck + k) == 1)
      {
        if(k % 2 == 0)
        {
            uncommonEvenDigitArray[2 * uncommonEvenDigit] = k;
            uncommonEvenDigitArray[2 * uncommonEvenDigit + 1] = countDigitSeen(ary, size, k);
            uncommonEvenDigit++;
        }
        else if(k % 2 != 0)
        {
            uncommonOddDigitArray[2 * uncommonOddDigit] = k;
            uncommonOddDigitArray[2 * uncommonOddDigit + 1] = countDigitSeen(ary, size, k);
            uncommonOddDigit++;
        }
      }
    }

    delete[] uncommonDigitCheck;

    totalUncommonDigit = uncommonEvenDigit + uncommonOddDigit;
    tempArray = new int[2 * totalUncommonDigit + 3];

    for (int i = 0; i < totalUncommonDigit + 3; i++) \
    {
      *(tempArray + i) = 0;
    }

    *(tempArray) = totalUncommonDigit;
    *(tempArray + 1) = uncommonEvenDigit;

    for (int j = 0; j < uncommonEvenDigit * 2; j++)
    {
      *(tempArray + 2 + j) = *(uncommonEvenDigitArray + j);
    }

    *(tempArray + 2 + 2 * uncommonEvenDigit) = uncommonOddDigit;

    for (int k = 0; k < uncommonOddDigit * 2; k++)
    {
      *(tempArray + 3 + 2 * uncommonEvenDigit + k) = *(uncommonOddDigitArray + k);
    }

    return tempArray;
}