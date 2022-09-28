// Fritz Ammon
// Section 1002
// Hw 07
// File: matrixType.h
// Description: class matrixType declaration

#ifndef MATRIXTYPE_H
#define MATRIXTYPE_H

#include <iostream>
#include <string>
#include "grid.h"

using std::endl;
using std::string;
using std::cin;

class matrixType : public grid
{
public:
	// Constructor
	// Initializes grid class and gives it a title
	matrixType(int=0, int=0, string="");

	// Deconstructor
	~matrixType();

	// Returns the title of the 2d array
	string getTitle() const;
	
	// Sets title of 2d array to passed value
	void setTitle(string);

	// Prints grid as matrix
	void printMatrix() const;

	// Reads in matrix values from user
	void readMatrix();

	// Performs scaler multiplication on the matrix/grid
	void scalerMultiply(int);

	// Performs additions of two passed in matrices and saves it
	// into grid members
	void matrixAddition(matrixType &, matrixType &);

	// Performs subtraction of two passed in matrices and saves it
	// into grid members
	void matrixSubtraction(matrixType &, matrixType &);

	// Performs multiplication of two passed in matrices and saves it
	// into grid members
	void matrixMultiply(matrixType &, matrixType &);
	
private:
	string title; // Title of 2d array
};

#endif // MATRIXTYPE_H