// Fritz Ammon
// Section 1002
// Assignment #9
// File: complexType.h
// Description: The complexType class declaration.
// Handles real and imaginary numbers and can perform
// various complex operations.

#ifndef COMPLEXTYPE_H
#define COMPLEXTYPE_H

#include <iostream>
#include <cmath>

using std::istream;
using std::ostream;
using std::pow;
using std::abs;
using std::atan2;
using std::sqrt;
using std::sin;
using std::cosh;
using std::cos;
using std::sinh;

class complexType
{
	// External non-member functions.
	friend ostream& operator << (ostream&, const complexType&);
	friend istream& operator >> (istream&, complexType&);

public:
	// Constructor
	complexType(double=0.0, double=0.0); // Initializes private members.

	complexType operator + (const complexType& rhs); // Complex addition.
	complexType operator - (const complexType& rhs); // Complex subtraction.
	complexType operator * (const complexType& rhs); // Complex multiplication.
	complexType operator / (const complexType& rhs); // Complex division.

	// Determines if two complex numbers are equal.
	bool operator == (const complexType& rhs);

	double angle(); // The angle necessary in creating the complex image.
	double abs(); // Another value necessary in creating the complex image. (The c-lines.)

	complexType sine(); // Complex sine.
	complexType cose(); // Complex cosine.

	complexType cSqrt(); // Complex square root function.

	void setComplex(const double&, const double&); // Sets members.
	void getComplex(double&, double&) const; // Gets members by reference.

private:
	double realPart;
	double imaginaryPart;
};

#endif // COMPLEXTYPE_H
