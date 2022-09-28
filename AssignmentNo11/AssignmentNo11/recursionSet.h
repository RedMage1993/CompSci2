// Fritz Ammon
// Section 1002
// Assignment #11
// Provides practice with recursive functions
// and algorithms used on arrays (search, sort, etc.)

#ifndef RECURSIONSET_H
#define RECURSIONSET_H

#include <iostream>
#include <iomanip>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::showpoint;
using std::setprecision;
using std::right;
using std::setw;

template <class myType>
class recursionSet
{
public:
	recursionSet(); // Constructor, initialize all to 0
	recursionSet(int, myType*); // Constructor, intialize to passed if valid
	recursionSet(const recursionSet &); // Copy construtor
	~recursionSet(); // Deconstructor, deletes array (frees memory)

	bool operator==(const recursionSet &); // Compares arrays

	void generateList(int); // Generates random array from 1 to 100

	myType getDatum(int); // Returns element from array
	void setDatum(int, myType); // Sets element in array

	void printList(); // Prints formatted view of array

	myType gcd(myType, myType); // Uses Euclid's algorithm to find GCD

	myType readNumber(string, myType); // Prompts user for number

	int getLength() const; // Returns length of array

	void mergeSort(); // Performs merge sort algorithm on array

	int binarySearch(myType); // Searches for value in sorted array

	myType collatz(myType); // Counts steps taken to reach 1 with collatz algorithm

	myType ackermann(myType, myType); // Performs ackermann's algorithm

	myType countWays(myType); // Counts different ways to climb staircase with n steps

	void printDuodecimal(myType); // Prints converted number from base10 to base12

private:
	// Forwarded calls
	void mSort(int, int);
	void merge(int, int, int);
	int bSearch(myType, int, int);

	static const int MAX_SIZE = 50000;

	int length;
	myType *mySet;
};

template <class myType>
recursionSet<myType>::recursionSet()
{
	length = 0;

	mySet = static_cast<myType> (NULL);
}

template <class myType>
recursionSet<myType>::recursionSet(int len, myType* set)
{
	if (set == static_cast<myType> (NULL))
		cout << "(init constructor) Invalid array.\n";
	else if (!(len > 0 && len < MAX_SIZE))
		cout << "(init constructor) Array size not valid.\n";
	else
	{
		length = len;
		mySet = new myType[length];
		for (int i = 0; i < length; i++)
			mySet[i] = set[i];
		return;
	}

	length = 0;

	mySet = static_cast<myType> (NULL);
}

template <class myType>
recursionSet<myType>::recursionSet(const recursionSet &recSet)
{	
	if (recSet.mySet == static_cast<myType> (NULL))        // Check if passed set's
		cout << "(copy constructor) Invalid array.\n"; // array is valid (not NULL).
	else if (!(recSet.length > 0 && recSet.length < MAX_SIZE))    // Check if passed set's length
		cout << "(copy constructor) Array size not valid.\n"; // is valid (in range).
	else
	{ // Valid case
		length = recSet.length; 	 // Make (this) set length equal passed set length.
		mySet = new myType[length];	 // Make (this) mySet be an array of same length
		for (int i = 0; i < length; i++)      // so that we can store all of the elements of
			mySet[i] = recSet.mySet[i];   // the passed set's mySet into (this) mySet.
		return; // Exit early so that the following doesn't execute:
	}

	// These will execute to initialize the private members if valid case does not
	// run (so that return is executed).
	length = 0;

	mySet = static_cast<myType> (NULL);
}

template <class myType>
recursionSet<myType>::~recursionSet()
{
	if (mySet != static_cast<myType> (NULL))
	{
		length = 0;

		delete [] mySet;
		mySet = static_cast<myType> (NULL);
	}
}

template <class myType>
bool recursionSet<myType>::operator==(const recursionSet &recSet)
{
	if (recSet.mySet == static_cast<myType> (NULL)) // Check if passed set's
		cout << "(==) Invalid passed array.\n"; // array is valid (not NULL).
	else if (mySet == static_cast<myType> (NULL))
		cout << "(==) Invalid array.\n";
	else if (length == recSet.length)
	{
		for (int i = 0; i < length; i++)
		{
			if (mySet[i] != recSet.mySet[i])
				return false;
		}

		return true;
	}

	return false;
}

template <class myType>
void recursionSet<myType>::generateList(int len)
{
	if (!(len > 0 && len < MAX_SIZE))
		cout << "Error (generateList), invalid set length.\n";
	else
	{
		if (mySet != static_cast<myType> (NULL))
			delete [] mySet;

		mySet = new myType[len];
		length = len;

		for (int i = 0; i < length; i++)
			mySet[i] = static_cast<myType> ((myType)(rand() % 100+1));
	}
}

template <class myType>
myType recursionSet<myType>::getDatum(int index)
{
	if (mySet == static_cast<myType> (NULL))
		cout << "(getDatum) No array exists.\n";
	else if (index < 0 || index >= length)
		cout << "(getDatum) Index out of bounds.\n";
	else
		return mySet[index];

	return static_cast<myType> (0);
}

template <class myType>
void recursionSet<myType>::setDatum(int index, myType datum)
{
	if (mySet == static_cast<myType> (NULL))
		cout << "(setDatum) No array exists.\n";
	else if (index < 0 || index >= length)
		cout << "(setDatum) Index out of bounds.\n";
	else
		mySet[index] = datum;
}

template <class myType>
void recursionSet<myType>::printList()
{
	if (mySet == static_cast<myType> (NULL))
		cout << "(printList) No array exists.\n";
	else
	{
		cout << showpoint;
		cout << setprecision(6);

		for (int i = 0; i < length;)
		{
			cout << " Set[" <<  right << setw(2) << i << "] = "
				 << setw(8) << mySet[i] << "     ";
			if (++i % 3 == 0)
				cout << endl;
		}
	}
}

template <class myType>
myType recursionSet<myType>::gcd(myType m, myType n)
{
	if (n == 0)
		return m;

	return gcd(n, m % n);
}

template <class myType>
myType recursionSet<myType>::readNumber(string prompt, myType max)
{
	myType number = static_cast<myType> (0);
	int attempts = 0;
	bool done = false;

	while (!done)
	{
		if (attempts++ == 4)
		{ // Do not let them try more than 4 times.
			cout << "\nSorry, too many errors.\n";
			return 0;
		}

		cout << prompt;
		cin >> number;
		cout << endl;

		if (!cin)
		{
			cin.clear();
			cin.ignore(std::numeric_limits<int>::max(), '\n');

			cout << "Error, out of range.\n";
		}
		else if (number < static_cast<myType> (1) || number >= max)
		{
			cout << "Error, not between " << 1 << " and "
			     << max << ".\n";
		}
		else
			done = true;
	}

	return number;
}

template <class myType>
int recursionSet<myType>::getLength() const
{
	return length;
}

template <class myType>
void recursionSet<myType>::mergeSort()
{
	mSort(0, length - 1);
}

template <class myType>
int recursionSet<myType>::binarySearch(myType v)
{
	return bSearch(v, 0, length - 1);
}

template <class myType>
myType recursionSet<myType>::collatz(myType n)
{
	if (n == static_cast<myType> (1))
		return n;
	else if (n % static_cast<myType> (2) == static_cast<myType> (0))
		return collatz(n / static_cast<myType> (2)) + static_cast<myType> (1);

	return collatz(static_cast<myType> (3) * n + static_cast<myType> (1)) +
		static_cast<myType> (1);
}

template <class myType>
myType recursionSet<myType>::ackermann(myType m, myType n)
{
	if (m == static_cast<myType> (0))
		return n + static_cast<myType> (1);
	else if (n == static_cast<myType> (0))
	{
		return ackermann(m - static_cast<myType> (1),
			static_cast<myType> (1));
	}
	
	return ackermann(m - static_cast<myType> (1),
		ackermann(m, n - static_cast<myType> (1)));
}

template <class myType>
myType recursionSet<myType>::countWays(myType steps)
{
	if (steps < static_cast<myType> (0))
		return static_cast<myType> (0);
	else if (steps == 0)
		return static_cast<myType> (1);
	else
	{
		// Counting if taking 1 step and 2 steps
		return countWays(steps - static_cast<myType> (1)) +
			countWays(steps - static_cast<myType> (2));
	}
}

template <class myType>
void recursionSet<myType>::printDuodecimal(myType n)
{
	if (n / static_cast<myType> (12) != static_cast<myType> (0))
		printDuodecimal(n / static_cast<myType> (12));

	if (n % static_cast<myType> (12) == static_cast<myType> (10))
		cout << 'X';
	else if (n % static_cast<myType> (12) == static_cast<myType> (11))
		cout << 'E';
	else
		cout << n % static_cast<myType> (12);
}

template <class myType>
void recursionSet<myType>::mSort(int lo, int hi)
{
	int mid;

	if (lo < hi)
	{
		mid = (lo + hi) / 2;
		mSort(lo, mid);
		mSort(mid + 1, hi);
		merge(lo, mid, hi);
	}
}

template <class myType>
void recursionSet<myType>::merge(int lo, int mid, int hi)
{
	int h, i, j;
	myType* set;

	if (mySet == static_cast<myType> (NULL))
		cout << "(merge) Array is invalid.\n";
	else
	{
		set = new myType[length];

		h = i = lo;
		j = mid + 1;

		while ((h <= mid) && (j <= hi))
		{
			if (mySet[h] <= mySet[j])
				set[i++] = mySet[h++];
			else
				set[i++] = mySet[j++];
		}

		if (h > mid)
		{
			for (int k = j; k <= hi; k++)
				set[i++] = mySet[k];
		}
		else
		{
			for (int k = h; k <= mid; k++)
				set[i++] = mySet[k];
		}

		for (int k = lo; k <= hi; k++)
			mySet[k] = set[k];
	}
}

template <class myType>
int recursionSet<myType>::bSearch(myType v, int l, int r)
{
	int m;

	if (mySet == static_cast<myType> (NULL))
		cout << "(bSearch) Array is invalid.\n";
	else
	{
		if (r < l) // Does not exist.
			return -1;

		m = (l + r) / 2;

		if (v < mySet[m])
			return bSearch(v, l, m - 1);
		else if (v > mySet[m])
			return bSearch(v, m + 1, r);
		else if (v == mySet[m])
			return m;
	}
}

#endif // RECURSIONSET_H
