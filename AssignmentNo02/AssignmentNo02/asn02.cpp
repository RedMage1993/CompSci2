//  Fritz Ammon
//  Section 1002
//  Assignment #2

#include <cstdlib>
#include <iomanip> // For setprecision
#include <iostream>
#include <string>
#include <cmath>

using namespace std;


// ****************************************************************
//  Program specific constants.

enum allowedTypes {INTEGER, FLOAT, DOUBLE, STRING, NONE};

#define MIN_LENGTH 10
#define MAX_LENGTH 250
#define NUMSPERLINE 5
#define MAXVALUE 1000


// ****************************************************************

allowedTypes getOperation();
int getLength();

void generateList(int arr[], int n);
void generateList(float arr[], int n);
void generateList(double arr[], int n);
void generateList(string arr[], int n);

int maximum(int list[],int size);
float maximum(float list[], int size);
double maximum(double list[], int size);
string maximum(string list[], int size);

int minimum(int list[],int size);
float minimum(float list[], int size);
double minimum(double list[], int size);
string minimum(string list[], int size);

void displayResults(int arr[], int max, int min, int n);
void displayResults(float arr[], float max, float min, int n);
void displayResults(double arr[], double max, double min, int n);
void displayResults(string arr[], string max, string min, int n);

void combSort(int arr[], int size);
void combSort(float arr[], int size);
void combSort(double arr[], int size);
void combSort(string arr[], int size);


// ****************************************************************

int main()
{
// --------------------------------------------
//  Data declarations
//	includes arrays for each of the various types.
	bool done = false;

	int	iNums[MAX_LENGTH];
	int	imin, imax;

	float	fNums[MAX_LENGTH];
	float	fmin, fmax;

	double	dNums[MAX_LENGTH];
	double	dmin, dmax;

	string	sWords[] = {"hat", "tree", "window", "Door", "house", "flower",
				"pencil", "desk", "cup", "coffee", "tea",
				"sugar", "salt", "pepper", "ring", "number",
				"computer", "day", "Year", "Day", "Month",
				"key", "dog", "Fred", "Air", "Coat", "shoe",
				"television", "candle", "rock", "Paper", "Lizard"};
	string	smin, smax;

	allowedTypes	myType;
	int	length;

// --------------------------------------------
//  Main processing loop
//	get type from user and
//	if needed, get length
//	if needed, generate data
//	get min and max
//	sort numbers
//	display data

	cout << fixed << showpoint;
	cout << setprecision(2);

	while (!done) { // SENTINELLLL

		myType = getOperation();

		if ( myType == INTEGER || myType == FLOAT || myType == DOUBLE )
			length = getLength();

		if (myType == NONE) {
			cout << endl << "Game over." << endl <<
				"Thanks for playing." << endl;
			done = true;
			continue;
		}

		switch (myType) {
			case INTEGER:
				generateList(iNums, length);
				imax = maximum(iNums, length);
				imin = minimum(iNums, length);
				combSort(iNums, length);
				displayResults(iNums, imax, imin, length);
				break;
			case FLOAT:
				generateList(fNums, length);
				fmax = maximum(fNums, length);
				fmin = minimum(fNums, length);
				combSort(fNums, length);
				displayResults(fNums, fmax, fmin, length);
				break;
			case DOUBLE:
				generateList(dNums, length);
				dmax = maximum(dNums, length); // Uh-oh! The template was using floats!
				dmin = minimum(dNums, length);
				combSort(dNums, length);
				displayResults(dNums, dmax, dmin, length);
				break;
			case STRING:
				smax = maximum(sWords, sizeof(sWords)/sizeof(sWords[0]));
				smin = minimum(sWords, sizeof(sWords)/sizeof(sWords[0]));
				combSort(sWords, sizeof(sWords)/sizeof(sWords[0]));
				displayResults(sWords, smax, smin,
					sizeof(sWords)/sizeof(sWords[0]));
				break;
		}
	}

	return EXIT_SUCCESS;
}


// ****************************************************************
//  Ask user for data type of the operation.
//	Must be integer, float, double, string, or quit

allowedTypes getOperation()
{
	char answer;
	allowedTypes myType = static_cast<allowedTypes> (0); // Potentionally left uninitialized
	bool	goodInput = false;

	while (!goodInput) {
		cout << "-------------------------------" << endl;
		cout << "Select data type for operations" << endl;
		cout << "     Integers (I/i)" << endl;
		cout << "     Floats (F/f)" << endl;
		cout << "     Doubles (D/d)" << endl;
		cout << "     Strings (S/s)" << endl;
		cout << "     Exit (Q/q)" << endl;
		cout << "Selection (I/i/F/f/D/d/S/s/Q/q): ";
		cin.clear(); // Aw, no ignore? :P
		cin >> answer;

		switch (answer) {
			case 'I':
			case 'i':
				myType = INTEGER;
				goodInput = true;
				break;
			case 'F':
			case 'f':
				myType = FLOAT;
				goodInput = true;
				break;
			case 'D':
			case 'd':
				myType = DOUBLE;
				goodInput = true;
				break;
			case 'S':
			case 's':
				myType = STRING;
				goodInput = true;
				break;
			case 'Q':
			case 'q':
				myType = NONE;
				goodInput = true;
				break;
			default:
				cout << "Error, must be I/i/F/f/D/d/S/s/Q/q " << endl;
				cout << "Please re-enter." << endl;
		}
	}

	return myType;
}


// ****************************************************************
//  Read and verify length from user.
//	Must be bewteen MIN_LENGTH and MAX_LENGTH (inclusive).
//	Routine shoud be efficient (which includes not performing
//		repeated, un-necessary work).

int	getLength()
{
	bool done = false;
	int length = 0; // Potentionally left uninitialized

	while (!done) // Because I dislike warnings (!using a sentinel)
	{
		cout << "\n\nEnter Length: ";
		cin >> length;

		if (length >= MIN_LENGTH && length <= MAX_LENGTH)
		{
			done = true;
			continue;
		}

		cout << "Error, invalid length. Must be between "
			 << MIN_LENGTH << " and " << MAX_LENGTH
			 << " inclusive.\n";
		cout << "Please re-enter.";
	}

	return length;
}


// ****************************************************************
//  Generate a list of random values.
//	uses rand() function (NO seed)
//	limits size to MAXVALUE

void generateList (int arr[], int n)
{
	for (int j = 0; j < n; j++)
		arr[j] = rand() % MAXVALUE + 1;
}

void generateList (float arr[], int n)
{
	for (int j = 0; j < n; j++)
		arr[j] = static_cast<float> (rand() % MAXVALUE + 1);
}

void generateList (double arr[], int n)
{
	for (int j = 0; j < n; j++)
		arr[j] = rand() % MAXVALUE + 1; // static_cast not necessary here
}


// ****************************************************************
//  Determine maximum.
//	Note, routines do NOT require data to be sorted

int maximum (int lst[], int size)
{
	int max = lst[0];

	for (int j = 0; j < size; j++)
	{
		if (lst[j] > max)
			max = lst[j];
	}

	return max;
}

float maximum (float lst[], int size)
{
	float max = lst[0];

	for (int j = 0; j < size; j++)
	{
		if (lst[j] > max)
			max = lst[j];
	}

	return max;
}

double maximum (double lst[], int size)
{
	double max = lst[0];

	for (int j = 0; j < size; j++)
	{
		if (lst[j] > max)
			max = lst[j];
	}

	return max;
}

string maximum (string lst[], int size)
{
	string max = lst[0];

	for (int j = 0; j < size; j++)
	{
		if (lst[j] > max)
			max = lst[j];
	}

	return max;
}

// ****************************************************************
//  Determine minimum.
//	Note, routines do NOT require data to be sorted

int minimum (int lst[], int size)
{
	int min = lst[0];

	for (int j = 0; j < size; j++)
	{
		if (lst[j] < min)
			min = lst[j];
	}

	return min;
}

float minimum (float lst[], int size)
{
	float min = lst[0];

	for (int j = 0; j < size; j++)
	{
		if (lst[j] < min)
			min = lst[j];
	}

	return min;
}

double minimum (double lst[], int size)
{
	double min = lst[0];

	for (int j = 0; j < size; j++)
	{
		if (lst[j] < min)
			min = lst[j];
	}

	return min;
}

string minimum (string lst[], int size)
{
	string min = lst[0];

	for (int j = 0; j < size; j++)
	{
		if (lst[j] < min)
			min = lst[j];
	}

	return min;
}


// ****************************************************************
//  Display formatted results -> integer.
//	formatting as per assignment specifications
//	displays NUMSPERLINE items per line

void displayResults (int lst[], int max, int min, int aSize)
{
	cout << endl << endl;
	cout << "------------------------------------------------\n";
	cout << "Integer Input Data (sorted):\n";

	// It's a good thing we are only allowing 250 elements in this example
	// (no need for nested loops)
	for (int j = 0; j < aSize; j++)
		cout << (j % NUMSPERLINE == 0 ? "\n  " : "  ")
			 << lst[j]; // Omg what is this nonsense

	cout << "\n\nThe smallest integer value is " << min << ".\n";
	cout << "The largest integer value is " << max << ".\n\n\n";
}


// ****************************************************************
//  Display formatted results -> float.
//	formatting as per assignment specifications
//	displays NUMSPERLINE items per line

void displayResults (float lst[], float max, float min, int size)
{
	cout << endl << endl;
	cout << "------------------------------------------------\n";
	cout << "Integer Input Data (sorted):\n";

	// It's a good thing we are only allowing 250 elements in this example
	// (no need for nested loops)
	for (int j = 0; j < size; j++)
		cout << (j % NUMSPERLINE == 0 ? "\n  " : "  ")
			 << lst[j]; // Omg what is this nonsense

	cout << "\n\nThe smallest float value is " << min << ".\n";
	cout << "The largest float value is " << max << ".\n\n\n";
}


// ****************************************************************
//  Display formatted results -> double.
//	formatting as per assignment specifications
//	displays NUMSPERLINE items per line

void displayResults (double lst[], double max, double min, int size)
{
	cout << endl << endl;
	cout << "------------------------------------------------\n";
	cout << "Integer Input Data (sorted):\n";

	// It's a good thing we are only allowing 250 elements in this example
	// (no need for nested loops)
	for (int j = 0; j < size; j++)
		cout << (j % NUMSPERLINE == 0 ? "\n  " : "  ")
			 << lst[j]; // Omg what is this nonsense

	cout << "\n\nThe smallest double value is " << min << ".\n";
	cout << "The largest double value is " << max << ".\n\n\n";

}


// ****************************************************************
//  Display formatted results -> string.
//	formatting as per assignment specifications
//	displays NUMSPERLINE items per line

void displayResults (string lst[], string max, string min, int size)
{
	cout << endl << endl;
	cout << "------------------------------------------------\n";
	cout << "Integer Input Data (sorted):\n";

	// It's a good thing we are only allowing 250 elements in this example
	// (no need for nested loops)
	for (int j = 0; j < size; j++)
		cout << (j % NUMSPERLINE == 0 ? "\n  " : "  ")
			 << lst[j]; // Omg what is this nonsense

	cout << "\n\nThe smallest string value is " << min << ".\n";
	cout << "The largest string value is " << max << ".\n\n\n";
}


// ****************************************************************
//  Sort data using comb sort.

void combSort(int arr[], int size) // These ints should be unsigned (size_t) >_>
{
	int gap = size;
	bool swapped = false;
	int temp;

	while (gap != 1 || swapped)
	{
		// update the gap value for a next comb
		if ((gap = static_cast<int> (gap / 1.247330950103979)) < 1) // sneaky shrink factor and stuff
			gap = 1; // minimum gap is 1

		for (int i = 0; i + gap < size; i++)
		{
			if (arr[i] > arr[i + gap])
			{
				temp = arr[i];
				arr[i] = arr[i + gap];
				arr[i + gap] = temp;
				swapped = true;
			}
		}

		swapped = false;
	}
}

void combSort(float arr[], int size)
{
	int gap = size;
	bool swapped = false;
	float temp;

	while (gap != 1 || swapped)
	{
		// update the gap value for a next comb
		if ((gap = static_cast<int> (gap / 1.247330950103979)) < 1) // sneaky shrink factor and stuff
			gap = 1; // minimum gap is 1

		for (int i = 0; i + gap < size; i++)
		{
			if (arr[i] > arr[i + gap])
			{
				temp = arr[i];
				arr[i] = arr[i + gap];
				arr[i + gap] = temp;
				swapped = true;
			}
		}

		swapped = false;
	}

}

void combSort(double arr[], int size)
{
	int gap = size;
	bool swapped = false;
	double temp;

	while (gap != 1 || swapped)
	{
		// update the gap value for a next comb
		if ((gap = static_cast<int> (gap / 1.247330950103979)) < 1) // sneaky shrink factor and stuff
			gap = 1; // minimum gap is 1

		for (int i = 0; i + gap < size; i++)
		{
			if (arr[i] > arr[i + gap])
			{
				temp = arr[i];
				arr[i] = arr[i + gap];
				arr[i + gap] = temp;
				swapped = true;
			}
		}

		swapped = false;
	}
}


void combSort(string arr[], int size)
{
	int gap = size;
	bool swapped = false;
	string temp;

	while (gap != 1 || swapped)
	{
		// update the gap value for a next comb
		if ((gap = static_cast<int> (gap / 1.247330950103979)) < 1) // sneaky shrink factor and stuff
			gap = 1; // minimum gap is 1

		for (int i = 0; i + gap < size; i++)
		{
			if (arr[i] > arr[i + gap])
			{
				temp = arr[i];
				arr[i] = arr[i + gap];
				arr[i + gap] = temp;
				swapped = true;
			}
		}

		swapped = false;
	}
}

