#include "wordLadder.h"

wordLadder::wordLadder()
{
	count = 0;

	first = ladderEnd = NULL;
}

wordLadder::~wordLadder()
{
	wordNode *temp;

	temp = first; // delete dict. list
	while (temp)
	{
		temp = temp->link; // go up list
		delete first;
		first = temp;
	}
}

bool wordLadder::readDictionary(const char *fName)
{
	string buffer;
	ifstream inFile;

	inFile.open(fName);

	if (!inFile) // could not open file
		return false;

	// first is the starting word; a queue
	while (inFile)
	{
		getline(inFile, buffer); // whitespace exist

		// only keep first 5 characters
		insertWord(buffer.substr(0, 5));
	}

	inFile.close();

	// because we used ladderEnd to save time
	ladderEnd = NULL;

	return true;
}

bool wordLadder::findLadder(const string& top, const string& target)
{
	wordNode *current = first;
	wordNode *prev = searchPtr(top);

	prev->prev = prev;

	while (current)
	{
		if (current->prev) // has already been used
			continue;

		if (isOneApart(prev->info, current->info))
		{
			ladderEnd = current;
			ladderEnd->prev = prev;
			prev = ladderEnd;

			if (prev->info == target)
				return true;
		}

		current = current->link;
	}

	return false;
}

bool wordLadder::validWord(const string& word) const
{
	return searchPtr(word) != NULL;
}

void wordLadder::printLadder() const
{
	linkedStack<string> theCherry;
	wordNode *theHand = ladderEnd;

	while (theHand)
	{
		theCherry.push(theHand->info);

		if (theHand->prev == theHand)
			break;

		theHand = theHand->prev;
	}

	while (!theCherry.isStackEmpty())
		cout << theCherry.pop() << endl; // yeah buddy
}

void wordLadder::resetLadder()
{
	// set prev member of wordNode's in ladder to NULL
	wordNode *start = first;

	while (start)
	{
		start->prev = NULL;
		start = start->link;
	}
}

bool wordLadder::isOneApart(const string& a, const string& b) const
{
	size_t len = a.size();
	unsigned int diff = 0;

	for (size_t i = 0; i < len; i++)
	{
		if (a[i] != b[i])
			++diff;
	}

	return diff == 1;
}

void wordLadder::insertWord(const string& word)
{
	// insert into dictinoary--first pointer
	wordNode *newRear = new wordNode;

	newRear->info = word;
	newRear->link = newRear->prev = NULL; // prev should be NULL

	if (first == NULL)				 // last rear points to new rear
		first = ladderEnd = newRear; // we'll use ladderEnd as the last node of the dict. for now
	else
	{
		ladderEnd->link = newRear;
		ladderEnd = newRear;
	}

	count++;
}

wordNode* wordLadder::searchPtr(const string& word) const
{
	wordNode *traverser = first;

	while (traverser)
	{
		if (traverser->info == word)
			return traverser;
		traverser = traverser->link;
	}

	return NULL;
}