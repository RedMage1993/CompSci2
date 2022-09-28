// Fritz Ammon
// CS202 Section 1002
// HW #5
// compoundInterest.h
// act is used in place of acct for account.

#ifndef COMPOUNDINT_H
#define COMPOUNDINT_H

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

class compoundInterest
{
public:
	// Initializes the members.
    compoundInterest(const string& = "", int = 0, int = 0, double = 0.0, int = 0);
        
	// Reads data into members via c-in.
	// Repeats prompt until valid data entered.
    void readActInfo();
    
	// Directly sets data for private members.
    void setActInfo(const string&, int, int, double, int);
        
	// Returns by reference all private data.
    void getActInfo(string&, int&, int&, double&, int&) const;
        
	// Summarizes the account's current
	// details based on data provided.
    void summarizeRoi();
    
	// Displays a chart showing the future progression
	// of the account during the terms listed.
    void chartRoi();

private:
	// Verify values and, if invalid, show error.
	// The function is designed so that only one error
	// need be displayed each time the function is called.
	// Returns false if any one of the member variables has an
	// invalid value, true otherwise.
    bool actVerification();

    static const int MAX_VALUE = 100000;
    static const int MAX_ANNUAL = 10000;
    static const double MIN_INT, MAX_INT;
    static const int MIN_TERM = 1, MAX_TERM = 40;

    string m_actName;
    int m_iniVal, m_annContrib, m_termLen;
    double m_annIntRate; // Annual interest rate.
};

#endif // COMPOUNDINT_H