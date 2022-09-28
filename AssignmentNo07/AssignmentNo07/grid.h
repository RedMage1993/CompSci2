// Fritz Ammon
// Section 1002
// Hw 07
// File: grid.h
// Description: class grid declaration

#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <iomanip>
#include <cstring>

using std::cout;
using std::setw;
using std::memset;

class grid
{
public:
	// Grid constructor
	// Initializes member rows and columns and intGrid
	// iff valid dimensions
	grid(int, int);

	// Deconstructor
	// Deallocates memory from intGrid
	~grid();

	// Sets a cell to value passed at given position
	void setCell(int, int, int);

	// Gets a cell value from given position
	int getCell(int, int) const;

	// Prints the 2-dimensional array in, formatted
	void printGrid() const;

	// Sets the dimensions of the 2d array
	void setSize(int, int);

	// Gets the rows or height of the 2d array
	int getRows() const;

	// Gets the columns or width of the 2d array
	int getCols() const;

private:
	int rows;
	int cols;
	int **intGrid; // 2d array rows * cols

	static const int ROW_MAX = 500;
	static const int COL_MAX = 500;
};

#endif // GRID_H