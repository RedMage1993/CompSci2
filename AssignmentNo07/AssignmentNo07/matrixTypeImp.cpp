// Fritz Ammon
// Section 1002
// Hw 07
// File: maxtrixTypeImp.cpp
// Description: class matrixType definition

#include "matrixType.h"

matrixType::matrixType(int rows, int cols, string iniTitle)
	: grid(rows, cols)
{
	title = iniTitle;
}

matrixType::~matrixType()
{
	// TODO: Nope. Nada.
}

string matrixType::getTitle() const
{
	return title;
}

void matrixType::setTitle(string setTitle)
{
	title = setTitle;
}

void matrixType::printMatrix() const
{
	string bars;

	if (getRows() == 0 || getCols() == 0)
	{
		cout << "Error, invalid matrix. Print operation can not be performed.\n";
		return;
	}

	bars.append(65, '-');

	cout << bars << endl;
	cout << "Title: " << title << endl << endl;

	// Prints enough spaces to cover all of matrix
	cout << "  ---" << setw(5 * getCols() - 1) << "---" << endl;
	printGrid();
	cout << "  ---" << setw(5 * getCols() - 1) << "---" << endl;
	cout << endl;
}

void matrixType::readMatrix()
{
	int value;

	if (getRows() == 0 || getCols() == 0)
	{
		cout << "Error, invalid matrix. Read operation can not be performed.\n";
		return;
	}

	cout << "Enter Matrix Title: ";
	cin >> title;

	cout << " Matrix Values (" << getRows() << 'x' << getCols() << ")\n";
	for (int row = 0; row < getRows(); row++)
	{
		for (int col = 0; col < getCols(); col++)
		{
			cin >> value;
			setCell(row, col, value); // Sets matrices cell values
		}
	}

	cout << endl;
}

void matrixType::scalerMultiply(int value)
{
	for (int row = 0; row < getRows(); row++)
	{
		for (int col = 0; col < getCols(); col++)
			setCell(row, col, getCell(row, col) * value); // Multiply current values by value
	}
}

void matrixType::matrixAddition(matrixType &m1, matrixType &m2)
{
	if (m1.getRows() != m2.getRows())
	{
		cout << "Error, " << m1.getRows() << " does not equal "
			 << m2.getRows() << endl;
		cout << "Undefined operation.\n\n";
		return;
	}

	if (m1.getCols() != m2.getCols())
	{
		cout << "Error, " << m1.getCols() << " does not equal "
			 << m2.getCols() << endl;
		cout << "Undefined operation.\n\n";
		return;
	}

	if (getRows() != m1.getRows() || getCols() != m1.getCols())
		setSize(m1.getRows(), m1.getCols()); // Resize if needed

	for (int row = 0; row < getRows(); row++)
	{ // Set grid cells to sum of both passed in cells
		for (int col = 0; col < getCols(); col++)
			setCell(row, col, m1.getCell(row, col) + m2.getCell(row, col));
	}
}

void matrixType::matrixSubtraction(matrixType &m1, matrixType &m2)
{
	if (m1.getRows() != m2.getRows())
	{
		cout << "Error, " << m1.getRows() << " does not equal "
			 << m2.getRows() << endl;
		cout << "Undefined operation.\n\n";
		return;
	}

	if (m1.getCols() != m2.getCols())
	{
		cout << "Error, " << m1.getCols() << " does not equal "
			 << m2.getCols() << endl;
		cout << "Undefined operation.\n\n";
		return;
	}

	if (getRows() != m1.getRows() || getCols() != m1.getCols())
		setSize(m1.getRows(), m1.getCols()); // Resize if needed

	for (int row = 0; row < getRows(); row++)
	{ // Set grid cells to difference of both passed in cells
		for (int col = 0; col < getCols(); col++)
			setCell(row, col, m1.getCell(row, col) - m2.getCell(row, col));
	}
}

void matrixType::matrixMultiply(matrixType &m1, matrixType &m2)
{
	int sum;

	if (m1.getCols() != m2.getRows())
	{
		cout << "Error, " << m1.getCols() << " does not equal "
			 << m2.getRows() << endl;
		cout << "Undefined operation.\n";
		return;
	}

	if (getRows() != m1.getRows() || getCols() != m2.getCols())
		setSize(m1.getRows(), m2.getCols());

	for (int m1Row = 0; m1Row < m1.getRows(); m1Row++)
	{ // Go through each row of matrix 1
		for (int m2Col = 0; m2Col < m2.getCols(); m2Col++)
		{ // Go through each column of matrix 2
			sum = 0;
			// For each column of m2, multiply the corresponding col of
			// row in m1 and keep sum
			for (int m1Col = 0; m1Col < m1.getCols(); m1Col++)
				sum += m1.getCell(m1Row, m1Col) * m2.getCell(m1Col, m2Col);

			// Save sum
			setCell(m1Row, m2Col, sum);
		}
	}
}