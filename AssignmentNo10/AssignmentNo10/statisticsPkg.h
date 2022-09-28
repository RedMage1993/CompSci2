// Fritz Ammon
// Assignment #10
// Section 1002
// File: statisticsPkg.h
// Description: Template class declaration and definition for statisticsPkg.
// Handles arrays of various types and calculates informatoin about the
// data they hold.

#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <cstdlib>
#include <cmath>

using namespace std;

template <class myType>
class statisticsPkg
{
public:
	statisticsPkg() : setLength(0), mySet(NULL) {} // Initialize members.
	statisticsPkg(int, myType*);
	~statisticsPkg() { freeMemory(); } // Destructor, free array memory.

	myType getDatum(int) const; // Return element at index.
	void setDatum(int, myType); // Set element at index to passed value.

	int readCount(); // Prompt user for array size.

	void generateNewSet(int); // Create array of passed size with random data.

	void printSet() const; // Display the elements of the array.

	myType minimum() const; // The smallest value in the array.

	myType maximum() const; // The biggest value in the array.

	myType median() const; // The element at the middle of the array.

	myType sum() const; // The summation of all of the elements.

	myType average() const; // The average of the array's values.

	myType standardDeviation() const; // The array's standard deviation of values.

	void shellSort(); // Sorts the values in the array from smallest to biggest.

	myType coVariance(const statisticsPkg&) const; // The covariance is found.

	myType pearsonsCoefficient(const statisticsPkg&) const; // Pearsons coefficient is found.

	myType linearCorrelationCoefficient(const statisticsPkg&) const; // LCC is found.

	static const int CNT_MIN = 5, CNT_MAX = 9999;
	static const int RND_LIMIT = 999;
private:
	void freeMemory(); // Deletes array and resets length of array.

	int setLength; // Length of array.
	myType *mySet; // The array.
};

template <class myType>
statisticsPkg<myType>::statisticsPkg(int n, myType* a)
{
	if (a == NULL) // Check that it isn't a null pointer.
		cout << "Error (constructor), invalid input array.\n";
	else if (n < CNT_MIN || n > CNT_MAX)
		cout << "Error (constructor), invalid set length.\n";
	else
	{
		mySet = new myType[n];
		setLength = n;

		for (int i = 0; i < n; i++)
			mySet[i] = a[i];

		return;
	}

	mySet = static_cast<myType*> (NULL);
	setLength = 0;
}

template <class myType>
myType statisticsPkg<myType>::getDatum(int i) const
{
	if (i < 0 || i >= setLength)
	{ // Index is bounds.
		cout << "Error (getDatum), index out of bounds.\n";
		return static_cast<myType> (0);
	}
	else
		return mySet[i];
}

template <class myType>
void statisticsPkg<myType>::setDatum(int i, myType y)
{
	if (i < 0 || i >= setLength)
		cout << "Error (setDatum), index out of bounds.\n";
	else
		mySet[i] = y; // Set element at i to y.
}

template <class myType>
int statisticsPkg<myType>::readCount()
{
	int count = 0;
	int attempts = 0;
	bool done = false;

	while (!done)
	{
		if (attempts++ == 4)
		{ // Do not let them try more than 4 times.
			cout << "\nSorry, too many errors.\n";
			return 0;
		}

		cout << "Enter Count (" << CNT_MIN << '-' << CNT_MAX << "): ";
		cin >> count;
		cout << endl;

		if (!cin)
		{
			cin.clear();
			cin.ignore(std::numeric_limits<int>::max(), '\n');

			cout << "Error, count out of range.\n";
		}
		else if (count < CNT_MIN || count > CNT_MAX)
			cout << "Error, not between " << CNT_MIN << " and " << CNT_MAX << ".\n";
		else
			done = true;
	}

	return count;
}

template <class myType>
void statisticsPkg<myType>::generateNewSet(int n)
{
	if (n < CNT_MIN || n > CNT_MAX)
		cout << "Error (generateNewSet), invalid set length.\n";
	else
	{
		if (mySet)
			freeMemory();
		
		mySet = new myType[n];
		setLength = n;
		for (int i = 0; i < n; i++)
			mySet[i] = static_cast<myType> (rand() % RND_LIMIT);
		
	}
}

template <class myType>
void statisticsPkg<myType>::printSet() const
{
	if (!mySet)
		cout << "Error (printSet), no set to display.\n";
	else
	{
		cout << showpoint;
		cout << setprecision(6);
		for (int i = 0; i < setLength;)
		{
			cout << " Set[" << i << "] = "
				 << right << setw(8) << mySet[i] << "     ";
			if (++i % 3 == 0)
				cout << endl;
		}
	}
}

template <class myType>
myType statisticsPkg<myType>::minimum() const
{
	myType min;

	if (!mySet)
	{
		cout << "Error (minimum), no set to look in.\n";
		return static_cast<myType> (0);
	}
	else
	{
		min = mySet[0];

		for (int i = 1; i < setLength; i++)
		{
			if (mySet[i] < min)
				min = mySet[i];
		}

		return min;
	}
}

template <class myType>
myType statisticsPkg<myType>::maximum() const
{
	myType max;

	if (!mySet)
	{
		cout << "Error (maximum), no set to look in.\n";
		return static_cast<myType> (0);
	}
	else
	{
		max = mySet[0];

		for (int i = 1; i < setLength; i++)
		{
			if (mySet[i] > max)
				max = mySet[i];
		}
		
		return max;
	}
}

template <class myType>
myType statisticsPkg<myType>::median() const
{
	myType med = static_cast<myType> (0);

	if (!mySet)
		cout << "Error (median), no set to look in.\n";
	else
	{
		if (setLength % 2 == 0) // If size is even, average two middle.
			med = (mySet[setLength / 2] + mySet[setLength / 2 - 1]) / 2;
		else
			med = mySet[setLength / 2];
	}

	return med;
}

template <class myType>
myType statisticsPkg<myType>::sum() const
{
	myType sum = static_cast<myType> (0);

	if (!mySet)
		cout << "Error (sum), no set to look in.\n";
	else
	{
		for (int i = 0; i < setLength; i++)
			sum += mySet[i];
	}

	return sum;
}

template <class myType>
myType statisticsPkg<myType>::average() const
{
	myType avg = static_cast<myType> (0);

	if (!mySet)
		cout << "Error (average), no set to look in.\n";
	else
		avg = sum() / setLength;

	return avg;
}

template <class myType>
myType statisticsPkg<myType>::standardDeviation() const
{
	myType dev = static_cast<myType> (0);
	myType avg, sum = static_cast<myType> (0);

	if (!mySet)
		cout << "Error (standardDeviation), no set to look in.\n";
	else
	{
		avg = average();
		for (int i = 0; i < setLength; i++)
			sum += static_cast<myType> (pow(static_cast<double> (mySet[i] - avg), 2));
		dev = static_cast<myType> (sqrt(static_cast<double> (sum / (setLength - 1))));
	}

	return dev;
}

template <class myType>
void statisticsPkg<myType>::shellSort()
{
	int h = 1;
	myType tmp;

	while ( (h*3+1) < setLength ) {
		h = 3 * h + 1;
	}

	while ( h>0 ) {
		for (int i = h-1, j; i < setLength; i++) {
			tmp = mySet[i];
			for (j=i; (j>=h) && (mySet[j-h]>tmp); j = j-h)
				mySet[j] = mySet[j-h];
			mySet[j] = tmp;
		}
		h = h / 3;
	}
}

template <class myType>
myType statisticsPkg<myType>::coVariance(const statisticsPkg& urSet) const
{
	myType cov = static_cast<myType> (0);
	myType xAvg, yAvg;
	myType sum = static_cast<myType> (0);

	if (!mySet)
		cout << "Error (coVariance), no set to look in.\n";
	else if (!urSet.mySet)
		cout << "Error (coVariance), invalid set passed.\n";
	else
	{
		xAvg = average();
		yAvg = urSet.average();

		for(int i = 0; i < setLength; i++)
			sum += ((mySet[i] - xAvg) * (mySet[i] - yAvg));

		cov = sum / (setLength - 1);
	}

	return cov;
}

template <class myType>
myType statisticsPkg<myType>::pearsonsCoefficient(const statisticsPkg& urSet) const
{
	myType pea = static_cast<myType> (0);
	myType xAvg, yAvg;
	myType sum = static_cast<myType> (0);

	if (!mySet)
		cout << "Error (pearsonsCoefficient), no set to look in.\n";
	else if (!urSet.mySet)
		cout << "Error (pearsonsCoefficient), invalid set passed.\n";
	else
	{
		xAvg = average();
		yAvg = urSet.average();

		for(int i = 0; i < setLength; i++)
			sum += (mySet[i] * urSet.mySet[i]);

		pea = (sum - setLength * xAvg * yAvg) / ((setLength - 1) *
			standardDeviation() * urSet.standardDeviation());
	}

	return pea;
}

template <class myType>
myType statisticsPkg<myType>::linearCorrelationCoefficient(const statisticsPkg& urSet) const
{
	myType lcc = static_cast<myType> (0);

	if (!mySet)
		cout << "Error (linearCorrelationCoefficient), no set to look in.\n";
	else if (!urSet.mySet)
		cout << "Error (linearCorrelationCoefficient), invalid set passed.\n";
	else
		lcc = coVariance(urSet) / (standardDeviation() * urSet.standardDeviation());

	return lcc;
}

template <class myType>
void statisticsPkg<myType>::freeMemory()
{
	if (mySet)
	{
		delete [] mySet;
		mySet = static_cast<myType*> (NULL);
		
		setLength = 0;
	}
}