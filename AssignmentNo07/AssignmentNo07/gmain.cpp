// CS 202 Provided Main

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

#include "grid.h"

using namespace std;

int main()
{
// ----------------------------------------------------------------------
//  Initial declarations and display simple header...

	string	bars;
	bars.append(65,'-');
	string	stars;
	stars.append(65,'*');

	cout << endl << bars << endl;
	cout << "CS 202 - Assignment #6" << endl;
	cout << "Grid Class -> Test Program." << endl << endl;

// ---------------------------------------
//  Some invalid declarations

	cout << endl << "*** Invalid declarations -> should show 5 errors. *************" << endl;
	cout << endl;

	grid	grdErr1(0, 10);					// error
	grid	grdErr2(10, 0);					// error
	grid	grdErr3(60000, 60);				// error
	grid	grdErr4(60, 60000);				// error
	grid	grdErr5(1,1);					// error

// ---------------------------------------
//  first grid

	grid	grd1(10, 10);

	cout << endl;
	cout << "*** Grid #1 ***************************************************" << endl;
	cout << "Grid -> " << grd1.getRows() << "x" << grd1.getCols() << endl;
	cout << "First = all 0's" << endl;
	cout << "Second = 1's in diagonal." << endl;
	cout << endl;

	{
		grd1.printGrid();

		for (int i=0; i<10; i++)
			grd1.setCell(i,i,1);

		cout << endl;
		cout << "Cell (0,1) is :" << grd1.getCell(0,1) << endl;
		cout << "Cell (1,1) is :" << grd1.getCell(1,1) << endl;
		cout << "Cell (1,0) is :" << grd1.getCell(1,0) << endl << endl;

		grd1.printGrid();
	}

// ---------------------------------------
//  second grid

	grid	grd2(0, 0);				// valid
	int	tmpNum;

	cout << endl;
	cout << "*** Grid #2 -> primtGrid() Error Testing (1 error) ******************" << endl;
	cout << endl;

	grd2.printGrid();				// error, no grid yet...

	cout << endl;
	cout << "*** Grid #2 -> setSize() Error Testing (6 errors) ******************" << endl;
	cout << endl;

	grd2.setSize(0,0);				// error 1
	grd2.setSize(8,8000);				// error 2
	grd2.setSize(8000,8);				// error 3
	grd2.setSize(-8,8);				// error 4
	grd2.setSize(8,-8);				// error 5
	grd2.setSize(1,1);				// error 6
	grd2.setSize(10,10);				// valid
	grd2.setSize(8,8);				// valid

	cout << endl;
	cout << "*** Grid #2 -> set/get Error Testing (10 errors) ******************" << endl;
	cout << endl;
	grd2.setCell(10,10,2);				// error 1
	grd2.setCell(1,10,2);				// error 2
	grd2.setCell(8,1,2);				// error 3
	grd2.setCell(5,-1,2);				// error 4
	grd2.setCell(-5,1,2);				// error 5
	tmpNum = grd2.getCell(10,10);			// error 6
	tmpNum = grd2.getCell(1,10);			// error 7
	tmpNum = grd2.getCell(10,1);			// error 8
	tmpNum = grd2.getCell(5,-1);			// error 9
	tmpNum = grd2.getCell(-5,1);			// error 10
	tmpNum++;

	cout << endl;

	cout << endl;
	cout << "*** Grid #2 ***************************************************" << endl;
	cout << "Grid -> " << grd2.getRows() << "x" << grd2.getCols() <<
		" with 3's in diagonal and 4's in back diagonal." << endl;
	cout << endl;

	for (int i=0; i<8; i++)
		grd2.setCell(i,i,3);

	for (int i=0, j=7; i<8; i++, j--)
		grd2.setCell(i,j,4);

	grd2.printGrid();

// ---------------------------------------
//  third grid

	grid	grd3(17, 10);

	cout << endl;
	cout << "*** Grid #3 ***************************************************" << endl;
	cout << "Grid -> " << grd3.getRows() << "x" << grd3.getCols() <<
			" with all 9s." << endl;
	cout << endl;

	for (int i=0; i<17; i++)
		for (int j=0; j<10; j++)
			grd3.setCell(i,j,9);

	grd3.printGrid();

// ---------------------------------------
//  fourth grid

	grid	grd4(20, 11);

	cout << endl;
	cout << "*** Grid #4 ***************************************************" << endl;
	cout << "Grid -> " << grd4.getRows() << "x" << grd4.getCols() <<
			" with random numbers..." << endl;
	cout << endl;

	for (int i=0; i<20; i++)
		for (int j=0; j<11; j++)
			grd4.setCell(i,j,(rand()%1000));

	grd4.printGrid();

	cout << endl;
	cout << stars << endl;
	cout << endl;

// ---------------------------------------

	return 0;
}

