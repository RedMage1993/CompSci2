// CS 202 Provided Main

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

#include "matrixType.h"

using namespace std;

int main()
{
// --------------------------------------------------
//  Initial declarations and headers...

	string	stars;
	string	dashs;

	stars.append(65,'*');
	dashs.append(65,'-');

	cout << stars << endl;
	cout << "CS 202 - Assignment #7" << endl;
	cout << "Matrix Testing" << endl << endl;

// --------------------------------------------------
//  Testing, declarations

	cout << stars << endl;
	cout << "Matrix Declaration Testing (5 errors)." << endl << endl;

	matrixType	matrixErr1(-1,1);			// error
	matrixType	matrixErr2(1,-1);			// error
	matrixType	matrixErr3(1,1);			// error
	matrixType	matrixErr4(10,10000);			// error
	matrixType	matrixErr5(10000,10);			// error

	cout << endl << endl;

// --------------------------------------------------
//  Testing, misc. fucntions

	cout << stars << endl;
	cout << "Matrix I/O Testing (2 errors)." << endl << endl;

	matrixType	matrixTeser;

	matrixTeser.readMatrix();				// error
	matrixTeser.printMatrix();				// error

	cout << endl << endl;

// --------------------------------------------------
//  Testing
//	simple 3x3 matrix
//	user entered data

	matrixType matrix1(3,3);

	cout << stars << endl;
	cout << "Matrix Testing (3x3), user entered data" << endl << endl;

	matrix1.readMatrix();
	matrix1.printMatrix();

	matrix1.setTitle(matrix1.getTitle()+" -> Scaler Multiply *2");
	matrix1.scalerMultiply(2);
	matrix1.printMatrix();

	cout << endl << endl;

// --------------------------------------------------
//  Testing
//	randomly created data
//	scaler multuiply

	int	rows=10, cols=12;
	matrixType matrix2a(0,0,"Original Values"), matrix2b;

	cout << stars << endl;
	cout << "Matrix Testing Random Data" << endl << endl;

	matrix2a.setSize(rows, cols);
	matrix2b.setSize(rows, cols);

	for (int i=0; i<rows; i++)
		for (int j=0; j<cols; j++) {
			matrix2a.setCell(i,j,rand()%100);
			matrix2b.setCell(i,j,matrix2a.getCell(i,j));
		}

	matrix2a.printMatrix();

	matrix2a.setTitle("Original Matrix * 2");
	matrix2a.scalerMultiply(2);
	matrix2a.printMatrix();

	cout << endl << endl;

// --------------------------------------------------
//  Testing, matrix addition

	cout << stars << endl;
	cout << "Matrix Addition Testing, 1 Error" << endl << endl;
	cout << "Matrix Addition Testing, Random Data" << endl << endl;

	matrixType matrix3;

	matrix3.matrixAddition(matrix1, matrix2b);		// error

	matrix3.matrixAddition(matrix2a, matrix2b);
	matrix3.setTitle("Matrix 3 = OriginalMatrix + (OriginalMatrix * 2)");
	matrix3.printMatrix();

	cout << endl << endl;

// --------------------------------------------------
//  Testing, matrix subtraction

	cout << stars << endl;
	cout << "Matrix Subtraction Testing, 1 Error" << endl << endl;
	cout << "Matrix Subtraction Testing, Random Data" << endl << endl;

	matrix3.matrixSubtraction(matrix2a, matrix1);		// error

	matrix3.matrixSubtraction(matrix2a, matrix2b);
	matrix3.setTitle("Matrix 3 = (OriginalMatrix * 2) - (OriginalMatrix)");
	matrix3.printMatrix();

	cout << endl << endl;

// --------------------------------------------------
//  Testing
//	matrix multiple, specific test data

//	| 7 3 |                   |  73  31  78 |
//	| 2 5 |  *  | 7 4 9 |  =  |  54  13  43 |
//	| 6 8 |     | 8 1 5 |     | 106  32  94 |
//	| 9 0 |                   |  63  36  81 |

	matrixType	matrixA1(4,2);
	matrixType	matrixB1(2,3);
	matrixType	matrixC1;

	matrixA1.setCell(0, 0, 7);
	matrixA1.setCell(0, 1, 3);
	matrixA1.setCell(1, 0, 2);
	matrixA1.setCell(1, 1, 5);
	matrixA1.setCell(2, 0, 6);
	matrixA1.setCell(2, 1, 8);
	matrixA1.setCell(3, 0, 9);
	matrixA1.setCell(3, 1, 0);

	matrixB1.setCell(0, 0, 7);
	matrixB1.setCell(0, 1, 4);
	matrixB1.setCell(0, 2, 9);
	matrixB1.setCell(1, 0, 8);
	matrixB1.setCell(1, 1, 1);
	matrixB1.setCell(1, 2, 5);

	cout << stars << endl;
	cout << "Matrix Multiplication Testing" << endl << endl;

	matrixA1.setTitle("Matrix A1");
	matrixA1.printMatrix();

	matrixB1.setTitle("Matrix B1");
	matrixB1.printMatrix();

	matrixC1.setTitle("Matrix C1 = Matrix A1 * Matrix B1");
	matrixC1.matrixMultiply(matrixA1, matrixB1);
	matrixC1.printMatrix();

	cout << stars << endl;
	cout << "Matrix Multiplication Error Testing (2 errors)" << endl << endl;

	matrixC1.matrixMultiply(matrixA1, matrix2a);
	matrixC1.matrixMultiply(matrix2a, matrixB1);


	cout << endl << endl;

// --------------------------------------------------
//  Testing
//	matrix multiply, random test data

	matrixType	matrixA2(10,12);
	matrixType	matrixB2(12,14);
	matrixType	matrixC2;

	cout << stars << endl;
	cout << "Matrix Multiplication Testing" << endl << endl;

	for (int i=0; i<10; i++)
		for (int j=0; j<12; j++)
			matrixA2.setCell(i,j,rand()%10);

	for (int i=0; i<12; i++)
		for (int j=0; j<14; j++)
			matrixB2.setCell(i,j,rand()%10);

	matrixA2.setTitle("Matrix A2");
	matrixA2.printMatrix();

	matrixB2.setTitle("Matrix B2");
	matrixB2.printMatrix();

	matrixC2.setTitle("Matrix C2 = Matrix A2 * Matrix B2");
	matrixC2.matrixMultiply(matrixA2, matrixB2);
	matrixC2.printMatrix();

	cout << endl << endl;

// --------------------------------------------------
//  All done...

	return 0;
}

