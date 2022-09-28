//  CS 202 Assignment #11
//  Recursion Set - Provided Main.

// ------------------------------------------------------------------------------

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <limits>

#include "recursionSet.h"

using namespace std;

int main()
{

// ------------------------------------------------------------------------------
//  Display simple headers.

	string	bars;
	bars.append(60, '-');

	cout << endl;
	cout << "CS 202 – Recursion Program" << endl << endl;

// ------------------------------------------------------------------------------
//  Test recursive ackerman() function.

	cout << bars << endl;
	cout << "Ackerman Function:" << endl;

	recursionSet <int> tst1;

	cout << "Ackermann(0,0): " << tst1.ackermann(0,0) << endl;
	cout << "Ackermann(0,1): " << tst1.ackermann(0,1) << endl;
	cout << "Ackermann(1,1): " << tst1.ackermann(1,1) << endl;
	cout << "Ackermann(3,2): " << tst1.ackermann(3,2) << endl;

	// Note, these will take a while...
	cout << "Ackermann(4,1): " << tst1.ackermann(4,1) << endl;
	cout << "Ackermann(3,4): " << tst1.ackermann(3,4) << endl;
	cout << "Ackermann(3,13): " << tst1.ackermann(3,13) << endl;

// ------------------------------------------------------------------------------
//  Test recursive gcd() function.

	cout << endl << endl;
	cout << bars << endl;
	cout << "Greatest Common Denominator Function:" << endl << endl;

	unsigned int	firstNum;
	unsigned int	secondNum;
	recursionSet <unsigned int> tst2;

	string	pmt1 = "Enter first number: ";
	string	pmt2 = "Enter second number: ";

	firstNum = tst2.readNumber(pmt1, numeric_limits<unsigned int>::max());
	secondNum = tst2.readNumber(pmt2, numeric_limits<unsigned int>::max());

	cout << "The gcd of " << firstNum << " and " << secondNum
		<< " = " << tst2.gcd(firstNum, secondNum) << endl;

// ------------------------------------------------------------------------------
//  Test recursive binarySearch() function.

	cout << endl << endl;
	cout << bars << endl;
	cout << "Binary Search Function:" << endl;
	cout << "List contains numbers between 1 and 100" << endl;

	recursionSet <int> tst3;
	bool	isFound, doMore=true;
	int	item;
	int	location;
	char	ch;
	string	nPmt = "Enter Search Number (1-100): ";

	tst3.generateList(15);
	tst3.mergeSort();
	tst3.printList();

	while (doMore) {
		cout << endl << "Search the list (Y/y/N/n): ";
		cin >> ch;
		cout << endl;

		switch (ch) {
			case 'N':
			case 'n':
				doMore=false;
				break;

			case 'Y':
			case 'y':
				item = tst3.readNumber(nPmt,100);

				isFound = false;
				location = tst3.binarySearch(item);

				if (location != -1)
					cout << item << " found at position: "
						<< location << endl;
				else
					cout << item << " not in the list" << endl;
				break;

			default:
				cout << "Error, must enter (Y/y/N/n)." << endl;
				break;
		}
	}

// ------------------------------------------------------------------------------
//  Test copy constructor.
//	copy previous tst3 object into tst4 object.

	cout << endl << endl;
	cout << bars << endl;
	cout << "Copy Constructor Test:" << endl;

	recursionSet <int> tst4(tst3);

	cout << endl;
	if (tst3 == tst4)
		cout << "Copy Constructor Succeeded." << endl;
	else
		cout << "Copy Constructor Failed." << endl;

	cout << endl;
	tst4.setDatum(73, 0);					// error
	tst4.setDatum(42, 1);					// error
	tst4.setDatum(3, 2);					// modify the copy
	tst4.mergeSort();

	cout << endl << "Modified List (16 replaced with 2):" << endl;
	tst4.printList();

	cout << endl;
	if (tst3 == tst4)
		cout << "Copy of set not modified." << endl;
	else
		cout << "Copy of set modified." << endl;	// it should be modified

// ------------------------------------------------------------------------------
//  Test recursive collatz() function.
//  Uses unsigned long long, the largest type we can easily get...

	cout << endl << endl;
	cout << bars << endl;
	cout << "Collatz Function:" << endl;

	recursionSet <unsigned long long> tst5;
	unsigned long long	nValue;
	string ePmt = "Enter N value: ";

	nValue = tst5.readNumber(ePmt, numeric_limits<unsigned long long>::max());

	if (nValue > 0)
		cout << nValue << " takes " << tst5.collatz(nValue)
			<< " iterations before reaching 1";

// ------------------------------------------------------------------------------
//  Various error tests...

	cout << endl << endl;
	cout << bars << endl;
	cout << "Error Testing:" << endl;

	recursionSet <short> tst6;
	short	tstNum;
	short	sArray[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	short	sArrayLen = sizeof(sArray) / sizeof(short);

	tst6.generateList(10);
	tst6.mergeSort();

	cout << endl << "Original List:" << endl;
	tst6.printList();

	cout << endl << endl << "Copy of Original List:" << endl;
	recursionSet <short> tst6copy(tst6);
	tst6copy.printList();

	cout << endl << endl << "Set/Get Tests:" << endl;
	tst6.setDatum(-1, 3);					// error
	tst6.setDatum(10, 3);					// error
	tstNum = tst6.getDatum(11);				// error
	tstNum = tst6.getDatum(-9);				// error

	cout << endl << "Constructor Tests (errors):" << endl;
	recursionSet <short> tst6err1(sArrayLen, NULL);		// error
	recursionSet <short> tst6err2(-3, sArray);		// error

	cout << endl << "Constructor Test (good, 0-9):" << endl;
	recursionSet <short> tst6good(sArrayLen, sArray);	// good
	tst6good.printList();

// ------------------------------------------------------------------------------
//  Test recursive countWays() function.

	cout << endl << endl;
	cout << bars << endl;
	cout << "Count Ways Function:" << endl;

	recursionSet <long long> tst7;
	long long	stairSteps, cnt;
	string stPmt = "Enter size: ";

	stairSteps = tst7.readNumber(stPmt, 1000);

	if (stairSteps > 0) {
		cnt = tst7.countWays(stairSteps);

		cout << "For a staircase with " << stairSteps << " steps, there is " <<
			cnt << " different" << endl << " ways to climb the staircase." << endl;
	}

// ------------------------------------------------------------------------------
//  Test recursive printDuedecimal() function.

	cout << endl << endl;
	cout << bars << endl;
	cout << "Duodecimal Function:" << endl;

	recursionSet <int> tst8;
	int	num8;
	string dPmt = "Enter Integer Number: ";

	num8 = tst8.readNumber(dPmt, numeric_limits<int>::max());

	if (num8 > 0) {
		cout << "Duodecimal value of " << num8 << ": ";
		tst8.printDuodecimal(num8);
	}

// ------------------------------------------------------------------------------
//  Done...

	cout << endl << endl;
	cout << bars << endl;

	return 0;

}

