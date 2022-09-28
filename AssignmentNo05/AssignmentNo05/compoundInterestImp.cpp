// Fritz Ammon
// CS202 Section 1002
// HW #5
// compoundInterest.cpp

#include "compoundInterest.h"

const double compoundInterest::MIN_INT = 1.0;
const double compoundInterest::MAX_INT = 75.0;

bool compoundInterest::actVerification()
{
	return m_iniVal && m_annIntRate && m_termLen;
}

compoundInterest::compoundInterest(const string& actName, int iniVal,
        int annContrib, double annIntRate, int termLen)
{
	m_actName = actName;

	if (iniVal < 0 || iniVal > MAX_VALUE)
	{
		cout << "   Error, invalid initial balance.\n";
		m_iniVal = 0;
	}
	else
		m_iniVal = iniVal;

	if (annContrib < 0 || annContrib > MAX_ANNUAL)
	{
		cout << "   Error, invalid annual contribution.\n";
		m_annContrib = 0;
	}
	else
		m_annContrib = annContrib;

	if (annIntRate != 0.0 && (annIntRate < MIN_INT || annIntRate > MAX_INT))
	{
		cout << "   Error, invalid interest rate.\n";
		m_annIntRate = 0;
	}
	else
		m_annIntRate = annIntRate;

    if (termLen != 0 && (termLen < MIN_TERM || termLen > MAX_TERM))
	{
		cout << "   Error, invalid term length.\n";
		m_termLen = 0;
	}
	else
		m_termLen = termLen;
}

void compoundInterest::readActInfo()
{
    bool valid;

    cout << setfill('-') << setw(72) << " \n";
	cout << setfill(' ');

	cout << "Account Information" << endl;

	cout << "   Enter Account Name: ";
	getline(cin, m_actName);

	do
	{
	    valid = true;
		cout << "   Enter Initial Balance: ";
		cin >> m_iniVal;

		if (m_iniVal < 0 || m_iniVal > MAX_VALUE)
        {
            valid = false;
            cout << "   Error, invalid initial balance.  Please re-enter." << endl;
        }
	} while (!valid);

	do
	{
	    valid = true;
		cout << "   Enter Annual Contribution Amount: ";
		cin >> m_annContrib;

        if (m_annContrib < 0 || m_annContrib > MAX_ANNUAL)
        {
            valid = false;
            cout << "   Error, invalid annual contribution.  Please re-enter." << endl;
        }
	} while (!valid);

	do
	{
	    valid = true;
		cout << "   Enter Annual Interest Rate: ";
		cin >> m_annIntRate;

        if (m_annIntRate < MIN_INT || m_annIntRate > MAX_INT)
        {
            valid = false;
            cout << "   Error, invalid interest rate.  Please re-enter." << endl;
        }
	} while (!valid);

	do
	{
	    valid = true;
		cout << "   Enter Term (years): ";
		cin >> m_termLen;

        if (m_termLen < MIN_TERM || m_termLen > MAX_TERM)
        {
            valid = false;
            cout << "   Error, invalid term.  Please re-enter." << endl;
        }
	} while (!valid);

	cout << endl << "Account Information Accepted" << endl;

    cout << setfill('-') << setw(72) << " \n";
	cout << setfill(' ');

	cout << endl;
}

void compoundInterest::setActInfo(const string& actName, int iniVal,
        int annContrib, double annIntRate, int termLen)
{
	m_actName = actName;

	if (iniVal < 0 || iniVal > MAX_VALUE)
		cout << "   Error, invalid initial balance.\n";
	else
		m_iniVal = iniVal;

	if (annContrib < 0 || annContrib > MAX_ANNUAL)
		cout << "   Error, invalid annual contribution.\n";
	else
		m_annContrib = annContrib;

	if (annIntRate < MIN_INT || annIntRate > MAX_INT)
		cout << "   Error, invalid interest rate.\n";
	else
		m_annIntRate = annIntRate;

    if (termLen < MIN_TERM || termLen > MAX_TERM)
		cout << "   Error, invalid term.\n";
	else
		m_termLen = termLen;
}

void compoundInterest::getActInfo(string& actName, int& iniVal,
        int& annContrib, double& annIntRate, int& termLen) const
{
	// We edit the data held at the addresses of each
	// variable passed by reference.
	actName = m_actName;
	iniVal = m_iniVal;
	annContrib = m_annContrib;
	annIntRate = m_annIntRate;
	termLen = m_termLen;
}

void compoundInterest::summarizeRoi()
{
	double actIntRate, actIntRateTerm;

	if (!actVerification())
	{
		cout << "Account information not complete." << endl;
		return;
	}

	cout << right << setfill('-') << setw(72) << " \n";
	cout << setfill(' ');

	cout << "Account Summary" << endl;
	cout << right << setw(24) << "   Account Name: " << m_actName << endl;
	cout << setw(24) << "   Initial Balance: " << '$' << static_cast<double> (m_iniVal) << endl;
	cout << setw(24) << "   Annual Contribution: " << '$' << static_cast<double> (m_annContrib) << endl;
	cout << setw(24) << "   Interest (annual): " << m_annIntRate << endl;
	cout << setw(24) << "   Term (years): " << m_termLen << endl << endl;
	cout << left;

	actIntRate = m_annIntRate / 100.0 + 1.0; // Variable used in formula.
	actIntRateTerm = pow(actIntRate, static_cast<double> (m_termLen));

	cout << "   Final Balance (" << m_termLen << " years): $" << m_iniVal * actIntRateTerm
		+ m_annContrib * (actIntRateTerm * actIntRate - actIntRate)
		/ (actIntRate - 1.0);

	cout << endl << endl;
}

void compoundInterest::chartRoi()
{
	double actIntRate, endingBal, intAmt;

	summarizeRoi();

	cout << "   Annual Return on Investment Schedule" << endl << endl;

	cout << right << setw(24) << "Starting" << setw(14) << "Annual"
		 << setw(14) << "Interest" << setw(14) << "Ending" << endl;
	cout << setw(10) << "Year" << setw(14) << "Balance" << setw(14)
		 << "Contrib" << setw(14) << "Amount" << setw(14) << "Balance" << endl;

	cout << setw(10) << "----" << setw(14) << "----------" << setw(14)
		 << "----------" << setw(14) << "----------" << setw(14)
		 << "----------" << endl;

	actIntRate = m_annIntRate / 100.0;
	endingBal = m_iniVal;

	// Display progress and expected balance through the terms.
	cout << setw(24) << endingBal << setw(42) << endingBal << endl;
	for (int term = 1; term <= m_termLen; term++)
	{
		cout << setw(9) << term << setw(15) << endingBal
			 << setw(14) << m_annContrib;

		intAmt = (endingBal + m_annContrib) * actIntRate;
		endingBal += (intAmt + m_annContrib); // This is our sum.

		cout << setw(14) << intAmt << setw(14) << endingBal
			 << endl;
	}

	cout << endl << setw(21) << "Final Balance (" << m_termLen << " years): $"
		 << endingBal << endl;

	cout << setfill('-') << setw(72) << " \n";
	cout << setfill(' ');
}
