// File: underGradImp.cpp
// Description: underGradImp class definition

#include "underGrad.h"

underGrad::underGrad(string last, string first, string id, string majorCode,
	double gradePtAvg, double charge, double aid,
	string adv, sStat status)
	: student(last, first, id, majorCode, // Call base constructor.
	gradePtAvg, charge, aid)
{
	advisor = adv;
	sStatus = status;
}

string underGrad::getAdvisor() const
{
	return advisor;
}

sStat underGrad::getStatus()
{
	return sStatus;
}

void underGrad::setAdvisor(string adv)
{
	advisor = adv;
}

void underGrad::setStatus(sStat status)
{
	sStatus = status;
}

void underGrad::showStudent()
{
	string sStatNames[] = {"PROBATION", "GOOD", "SPECIAL", "NONE"};
	double charge, aid;
	string	bars;
	bars.append(70,'-');
	streamsize ssize = cout.precision(2); // Save and set new precision.

	cout << fixed << showpoint;

	cout << endl << bars << endl;

	cout << "Student Summary\n";
	cout << setw(14) << "Name: " << getLastName() << ", " << getFirstName() << endl;
	cout << setw(14) << "ID: " << getID() << endl;
	cout << setw(14) << "Major: " << getMajor() << endl;
	cout << setw(14) << "GPA: " << getGPA() << endl;

	getCharges(charge, aid); // Get values from base.

	cout << setw(14) << "Charges: " << left << setw(24) << charge << right;
	cout << "Financial Aid: " << aid << endl;
	cout << setw(14) << "Balance: " << getBalance() << endl;

	// Set the appropriate status.
	if (sStatus == NONE)
	{
		if (getGPA() <= 1.7)
			sStatus = PROBATION;
		else
			sStatus = GOOD;
	}

	cout << setw(14) << "Advisor: " << left << setw(24) << advisor << right
		 << "Status: " << sStatNames[sStatus]; // Print status.
	cout << endl << endl;

	// Reset flags.
	cout.unsetf(ios::fixed | ios::showpoint);
	cout << setprecision(ssize);
}