// File: underGrad.h
// Description: underGrad class declaration

#ifndef UNDERGRAD_H
#define UNDERGRAD_H

#include "student.h"

enum sStat{PROBATION, GOOD, SPECIAL, NONE};

class underGrad : public student
{
public:
	// Constructor. Initializes class variables.
	// Parameters: last name, first name, student ID,
	// major code, gpa, charges, financial aid, advisor,
	// and status.
	underGrad(string="", string="", string="",
		string="", double=0.0, double=0.0,
		double=0.0, string="", sStat=NONE);

	// Returns the advisor's name.
	string getAdvisor() const;

	// Returns the student's status.
	sStat getStatus();

	// Sets advisor name.
	void setAdvisor(string);

	// Sets student status.
	void setStatus(sStat);

	// Extends base showStudent.
	void showStudent();

private:
	string advisor;
	sStat sStatus;
};

#endif // UNDERGRAD_H