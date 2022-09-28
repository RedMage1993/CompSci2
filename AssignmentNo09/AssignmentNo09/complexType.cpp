// Fritz Ammon
// Section 1002
// Assignment #9
// File: complexType.cpp
// Description: The complexType class defintion.
// Handles real and imaginary numbers and can perform
// various complex operations.

#include "complexType.h"

ostream& operator << (ostream& os, const complexType& rhs)
{
	return os << '(' << rhs.realPart << ", " << rhs.imaginaryPart << ")\n";
}

istream& operator >> (istream& is, complexType& rhs)
{
	return is >> rhs.realPart >> rhs.imaginaryPart;
}

complexType::complexType(double real, double imaginary)
{
	realPart = real;
	imaginaryPart = imaginary;
}

complexType complexType::operator + (const complexType& rhs)
{
	complexType result;

	result.realPart = realPart + rhs.realPart;
	result.imaginaryPart = imaginaryPart + rhs.imaginaryPart;

	return result;
}

complexType complexType::operator - (const complexType& rhs)
{
	complexType result;

	result.realPart = realPart - rhs.realPart;
	result.imaginaryPart = imaginaryPart - rhs.imaginaryPart;

	return result;
}

complexType complexType::operator * (const complexType& rhs)
{
	complexType result;

	result.realPart = realPart * rhs.realPart -
		imaginaryPart * rhs.imaginaryPart;

	result.imaginaryPart = realPart * rhs.imaginaryPart +
		imaginaryPart * rhs.realPart;

	return result;
}

complexType complexType::operator / (const complexType& rhs)
{
	complexType result;
	double hypSq;

	if (rhs.realPart == 0 && rhs.imaginaryPart == 0)
		return result;

	hypSq = pow(rhs.realPart, 2.0) + pow(rhs.imaginaryPart, 2.0);

	result.realPart = (realPart * rhs.realPart +
		imaginaryPart * rhs.imaginaryPart) / hypSq;

	result.imaginaryPart = (-realPart * rhs.imaginaryPart +
		imaginaryPart * rhs.realPart) / hypSq;

	return result;
}

bool complexType::operator == (const complexType& rhs)
{
	return realPart == rhs.realPart && // Can only be equal if both members equal.
		imaginaryPart == rhs.imaginaryPart;
}

double complexType::angle()
{
	return atan2(imaginaryPart, realPart); // Same as atan(i/r).
}

double complexType::abs()
{
	return sqrt(pow(realPart, 2.0) + pow(imaginaryPart, 2.0));
}

complexType complexType::sine()
{
	complexType result;

	result.realPart = sin(realPart) * cosh(imaginaryPart);
	result.imaginaryPart = cos(realPart) * sinh(imaginaryPart);

	return result; // Return newly created complexType.
}

complexType complexType::cose()
{
	complexType result;

	result.realPart = cos(realPart) * cosh(imaginaryPart);
	result.imaginaryPart = sin(realPart) * sinh(imaginaryPart);

	return result;
}

complexType complexType::cSqrt()
{
	complexType result;
	double hyp = sqrt(pow(realPart, 2.0) + pow(imaginaryPart, 2.0)); // Save calculation time.

	result.realPart = sqrt((realPart + hyp) / 2.0);
	result.imaginaryPart = (imaginaryPart / ::abs(imaginaryPart)) *
		sqrt((-realPart + hyp) / 2.0);

	return result;
}

void complexType::setComplex(const double& real, const double& imaginary)
{
	realPart = real;
	imaginaryPart = imaginary;
}

void complexType::getComplex(double& real, double& imaginary) const
{
	real = realPart;
	imaginary = imaginaryPart;
}
