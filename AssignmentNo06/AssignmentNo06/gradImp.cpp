#include "grad.h"

const double grad::MAX_FEES = 1000.0;

grad::grad(string last, string first, string id, string majorCode,
	double gradePtAvg, double charge, double aid,
	string adv, sStat status,
	bool ga, double fees)
	: underGrad(last, first, id, majorCode,
	gradePtAvg, charge, aid,
	adv, status)

{
	isGA = ga;

	if (fees < 0.0 || fees > MAX_FEES)
	{
		cout << "Error, invalid fees amount." << endl;
		gradFees = 0.0;
	}
	else
		gradFees = fees;
}

bool grad::getGAstatus() const
{
	return isGA;
}

double grad::getGradFees() const
{
	return gradFees;
}

void grad::setGAstatus(bool ga)
{
	isGA = ga;
}

void grad::setGradFees(double fees)
{
	if (fees < 0.0 || fees > MAX_FEES)
		cout << "Error, invalid fees amount." << endl;
	else
		gradFees = fees;
}

void grad::showStudent()
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
	if (getStatus() == NONE)
	{
		if (getGPA() <= 1.7)
			setStatus(PROBATION);
		else
			setStatus(GOOD);
	}

	cout << setw(14) << "Advisor: " << left << setw(24) << getAdvisor() << right
		 << "Status: " << sStatNames[getStatus()] << endl; // Print status.

	// Show correct grad info.
	cout << setw(14) << "Grad Fees: " << left << setw(24) <<  gradFees << right
		 << "Graduate Assistant: " << ((isGA) ? "Yes" : "No");
	cout << endl << endl;

	// Reset flags.
	cout.unsetf(ios::fixed | ios::showpoint);
	cout << setprecision(ssize);
}