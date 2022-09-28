// File: grad.h
// Description: grad class declaration

#ifndef GRAD_H
#define GRAD_H

#include "underGrad.h"

class grad : public underGrad
{
public:
	// Constructor. Initializes class variables.
	// Parameters: last name, first name, student ID,
	// major code, gpa, charges, aid, advisor, status,
	// ga flag, grad fees.
	grad(string="", string="", string="",
		string="", double=0.0, double=0.0,
		double=0.0, string="", sStat=NONE,
		bool=false, double=0.0);

	// Returns GA flag.
	bool getGAstatus() const;

	// Returns graduate fees.
	double getGradFees() const;

	// Sets GA flag.
	void setGAstatus(bool);

	// Sets graduate fees.
	void setGradFees(double);

	// Prints student summary, calls base's func.
	void showStudent();

private:
	bool isGA; // True if student is graduate assistant.
	double gradFees;

	static const double MAX_FEES;
};

#endif // GRAD_H