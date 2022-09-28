// Fritz Ammon
// CS 202
// Provided Main Program
// Assignment #5

#include <iostream>
#include <iomanip>
#include <string>

#include "compoundInterest.h"

using namespace std;

int main()
{
	cout << fixed << showpoint;
	cout << setprecision(2);

// ------------------------------------------------------------
//  Declartions and headers.

	string	stars = "";
	stars.append(70, '*');

	cout << endl;
	cout << "CS 202 Assignment #5" << endl;
	cout << "Compounded Interest" << endl;
	cout << endl;

// ------------------------------------------------------------
// Account One -> constructor data entry
//	provide data via constructor
//	show payment schedule

	cout << stars << endl;
	cout << "Accout One:" << endl << endl;

	compoundInterest acctOne ("Example One", 1000, 0, 2.0, 10);

	acctOne.chartRoi();

	cout << endl;

// ------------------------------------------------------------
// Account Two -> function data entry
//	provide data via function
//	show summary (only)

	cout << stars << endl;
	cout << "Account Two:" << endl << endl;

	compoundInterest acctTwo;

	acctTwo.setActInfo("Example Two", 10000, 0, 2.0, 10);
	acctTwo.summarizeRoi();

	cout << endl;

// ------------------------------------------------------------
// Account Three -> data transfer...

	cout << stars << endl;
	cout << "Account Three:" << endl << endl;

	compoundInterest acctThree;
	int	initBal, annCnt, yrs;
	double	intRt;
	string	acctNm;

	acctTwo.getActInfo(acctNm, initBal, annCnt, intRt, yrs);
	acctThree.setActInfo(acctNm, initBal, annCnt, intRt, yrs);

	acctThree.chartRoi();

	cout << endl;

// ------------------------------------------------------------
// Account Four -> interactive data entry

	compoundInterest acctFour;

	cout << stars << endl;
	cout << "Account Four:" << endl << endl;

	acctFour.readActInfo();
	acctFour.chartRoi();

	cout << endl;

// ------------------------------------------------------------
// Account Five
//	error checking for constructor

	cout << stars << endl;
	cout << "Account Five - testing" << endl << endl;

	compoundInterest acctFiveA("test 5 A bad", -1000, 0, 2.0, 10);		// invalid initial balance
	compoundInterest acctFiveB("test 5 B bad", 1000, -100, 2.0, 10);	// invalid annual contribution
	compoundInterest acctFiveC("test 5 C bad", 1000, 100, -2.0, 10);	// invalid interest rate
	compoundInterest acctFiveD("test 5 D bad", 1000, 100, 2.0, 100);	// invalid term
	compoundInterest acctFiveE("test 5 E bad", 0, 0, 2.0, 100);		// invalid balances
	compoundInterest acctFiveF("test 5 good", 1000, 100, 2.0, 10);		// good

	acctFiveA.summarizeRoi();
	acctFiveB.summarizeRoi();
	acctFiveC.summarizeRoi();
	acctFiveD.summarizeRoi();
	acctFiveE.summarizeRoi();
	acctFiveF.summarizeRoi();

	cout << endl;

// ------------------------------------------------------------
// Account Six
//	error checking for set function

	cout << stars << endl;
	cout << "Account Six - testing" << endl << endl;

	compoundInterest acctSix;

	acctSix.setActInfo("test 6 A bad", -1000, 0, 2.0, 10);			// invalid initial balance
	acctSix.setActInfo("test 6 B bad", 1000, -100, 2.0, 10);		// invalid annual contribution
	acctSix.setActInfo("test 6 C bad", 1000, 100, -2.0, 10);		// invalid interest rate
	acctSix.setActInfo("test 6 D bad", 1000, 100, 2.0, 100);		// invalid term
	acctSix.setActInfo("test 6 E bad", 0, 0, 2.0, 100);			// invalid balances
	acctSix.setActInfo("test 6 good", 1000, 100, 2.0, 10);			// good

	acctSix.summarizeRoi();

	cout << endl;

// ------------------------------------------------------------

	return 0;
}
