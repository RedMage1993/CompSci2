// File: student.h
// Description: student class declaration

#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

class student
{
public:
	// Constructor. Initializes class variables to the passed
	// arguments (if any) or default vlaues (if not or error).
	// Parameters: last name, first name, student ID, majorCode,
	// gpa, charges, and financial aid.
	// Includes error-checking.
	student(string="", string="", string="", string="",
		double=0.0, double=0.0, double=0.0);

	// Returns student last name.
	string getLastName() const;

	// Returns student first name.
	string getFirstName() const;

	// Returns student ID.
	string getID() const;

	// Returns charges.
	// Parameters: charges and finanacial aid.
	void getCharges(double &, double &) const;

	// Returns student balance.
	double getBalance() const;

	// Returns student major.
	string getMajor() const;

	// Returns student GPA.
	double getGPA() const;

	// Sets the student name.
	// Parameters: last name and first name.
	void setName(string, string);

	// Sets student ID.
	// Includes error-checking same as constructor.
	void setID(string);

	// Sets student major.
	// Includes error-checking same as constructor.
	void setMajor(string);

	// Set student charges.
	// Parameters: charges and financial aid.
	// Includes error-checking same as constructor.
	void setCharges(double, double);

	// Sets student ID.
	// Includes error-checking same as constructor.
	void setGPA(double);

	// Displays student summary in an organized manner.
	// Monetary values displayed in standard format.
	void showStudent();

private:
	string lastName, firstName;
	string studentID, major; // Major is expanded from major code.
	double gpa;
	double charges, financialAid, balance;
	static const double MAX_CHARGES;
	static const double MAX_GPA;
	static const string mCodes[];

	// Checks that an ID has a valid format.
	// L followed by 9 digits ('0' to '9' [inclusive]).
	// Returns true if valid format.
	bool checkID(string) const;

	// Checks code of 2-4 characters and finds the
	// appropriate major name. If not found, returns "Error."
	string expandMajorCode(string);
};

#endif // STUDENT_H