// Fritz Ammon
// Section 1002
// Hw 07
// File: gridImp.cpp
// Description: class grid definition

#include "grid.h"

grid::grid(int iniRows, int iniCols)
{
	if (iniRows < 0 || iniRows > ROW_MAX ||
		iniCols < 0 || iniCols > COL_MAX ||
		(iniRows == 0 && iniCols > 0) ||
		(iniCols == 0 && iniRows > 0) ||
		(iniRows == 1 && iniCols == 1))
	{
		cout << "Error, invalid grid size, no grid created.\n";
		intGrid = 0;
		rows = cols = 0;
	}
	else
	{ // Valid values passed
		intGrid = new int*[iniRows];
		for (int row = 0; row < iniRows; row++)
		{ // Create columns for each row
			intGrid[row] = new int[iniCols];
			memset(intGrid[row], 0, iniCols * sizeof(int)); // Initialize all to 0
		}

		rows = iniRows;
		cols = iniCols;
	}
}

grid::~grid()
{
	// Deallocate all requested memory
	for (int row = 0; row < rows; row++)
		delete [] intGrid[row];

	delete [] intGrid;
}

void grid::setCell(int row, int col, int value)
{
	if (row < 0 || row >= rows ||
		col < 0 || col >= cols)
		cout << "Error, invalid grid location.\n";
	else
		intGrid[row][col] = value;
}

int grid::getCell(int row, int col) const
{
	if (row < 0 || row >= rows ||
		col < 0 || col >= cols)
	{
		cout << "Error, invalid grid location.\n";
		return 0;
	}

	return intGrid[row][col];
}

void grid::printGrid() const
{
	if (rows == 0 || cols == 0)
	{
		cout << "Error, uninitialized matrix.\n";
		return;
	}

	for (int row = 0; row < rows; row++)
	{ // Print in formatted manner
		cout << "  |";
		for (int col = 0; col < cols; col++)
			cout << setw(4) << intGrid[row][col] << ' ';
		cout << "|\n";
	}
}

void grid::setSize(int setRows, int setCols)
{
	if (setRows < 0 || setRows > ROW_MAX ||
		setCols < 0 || setCols > COL_MAX ||
		(setRows == 1 && setCols == 1) ||
		(setRows == 0 && setCols == 0))
		cout << "Error, invalid grid size, no grid created.\n"; // Don't touch members
	else
	{ // Valid values passed
		if (intGrid) // Pointer is not null
		{ // Deallocate
			for (int row = 0; row < rows; row++)
				delete [] intGrid[row];

			delete [] intGrid;
		}
	
		// Reallocate
		intGrid = new int*[setRows];
		for (int row = 0; row < setRows; row++)
		{
			intGrid[row] = new int[setCols];
			memset(intGrid[row], 0, setCols * sizeof(int));
		}

		rows = setRows;
		cols = setCols;
	}
}

int grid::getRows() const
{
	return rows;
}

int grid::getCols() const
{
	return cols;
}