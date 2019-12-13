/**
* Program:    fractionUtility.cpp
* Written by: Tony H.
* Date:       2017/11/08
**/

#include <iostream>
#include "fractionUtility.h"
#include "fraction.h"
using namespace std;

void displayInfo()
{
	cout << "Extracting an Uncommon Digit\n"
        << "  Written by:         Tony Hernandez\n"
		<< "  Date:               2017/10/31" << endl;
}

void menuMain(void)
{
	int option;
	int updateOption;
	int numerator = 0;
	int denominator = 1;

	Fraction* fracPointer = 0;

	do
    {
		cout <<
        "\n*************************************"
        "\n*             MENU                  *"
        "\n* (1) Creating/Updating Fraction    *"
        "\n* (2) Displaying the Fraction       *"
        "\n* (3) Displaying Uncommon Digit(s)  *"
        "\n* (4) Quit                          *"
        "\n*************************************"
        "\nEnter your option (1 through 4): ";
		cin >> option;

		switch (option)
		{
        case 1:
            if (fracPointer == 0)
            {
                cout << "\nEnter the numerator: ";
                cin >> numerator;
                cout << "Enter the denominator: ";
                cin >> denominator;

                if (denominator == 0)
                {
                    do
                    {
                        cout <<
                        "\nZero is invalid "
                        "for the denominator."
                        "\nRe-enter a valid integer: ";
                        cin >> denominator;
                    } while (denominator == 0);
                }
                fracPointer = new Fraction(numerator, denominator);
            }
            else
            {
                fracPointer->print();
                cout
                << "\nAn update menu is provided next!"
                << endl;

                do
                {
                    cout <<
                    "\n  ****************************"
                    "\n  *       Updating MENU      *"
                    "\n  * (1) Updating num         *"
                    "\n  * (2) Updating denom       *"
                    "\n  * (3) Updating num & denom *"
                    "\n  * (4) Return               *"
                    "\n  ****************************"
                    "\n  Enter your option (1 through 4): ";
                    cin >> updateOption;

                    switch (updateOption)
                    {
                    case 1:
                        cout <<
                        "\n  Enter the numerator: ";
                        cin >> numerator;

                        fracPointer->setNum(numerator);

                        cout <<
                        "\n  Displaying updated fraction..."
                        "\n    num : " << fracPointer->getNum() <<
                        "\n    denom : " << fracPointer->getDenom()
                        << endl;
                        break;

                    case 2:
                        cout << "\n  Enter the denominator: ";
                        cin >> denominator;

                        fracPointer->setDenom(denominator);

                        cout <<
                        "\n  Displaying updated fraction..."
                        "\n    num : " << fracPointer->getNum() <<
                        "\n    denom : " << fracPointer->getDenom()
                        << endl;
                        break;

                    case 3:
                        cout << "\n  Enter the numerator: ";
                        cin >> numerator;

                        fracPointer->setNum(numerator);

                        cout <<
                        "\n  Enter the denominator: ";
                        cin >> denominator;

                        fracPointer->setDenom(denominator);

                        cout <<
                        "\n  Displaying updated fraction..."
                        "\n    num : " << fracPointer->getNum() <<
                        "\n    denom : " << fracPointer->getDenom()
                        << endl;
                        break;

                    case 4:
                        cout << "\n  Returning to previous menu!"
                        << endl << endl;
                        break;
                    }
                } while (updateOption != 4);
            }
            break;

            case 2:
                if (fracPointer == 0)
                {
                    cout << "\nNo Fraction available!\n" << endl;
                }
                else
                {
                    fracPointer->print();
                }
                break;

            case 3:
                if (fracPointer == 0)
                {
                    cout << "\nNo Fraction available!\n" << endl;
                }
                else
                {
                    fracPointer -> extractUncommonDigit(numerator, denominator);
                }
                break;

            case 4:
                cout << "\nGoodbye!\n" << endl;
                delete fracPointer;
                fracPointer = 0;
                break;
		}
    } while (option != 4);
}
