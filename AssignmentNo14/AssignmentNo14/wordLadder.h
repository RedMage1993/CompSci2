// first and ladderEnd are talking about the same list
// we have a bigass dictionary and first points to the first node in it
// ladderEnd of course points to the last node created
// the nodes contain links which are used to go through the entire dictionary
// the prev member is used to go through the word ladder
// in order to tell what word is the start of the word ladder, we set the prev
// member to itself
// so we basically have two lists in one

#ifndef WORDLADDER_H
#define WORDLADDER_H

#include <string>
#include <fstream>

using std::string;
using std::ifstream;

struct wordNode
{
	string info;
	wordNode *prev;
	wordNode *link;
};

class wordLadder
{
public:
	wordLadder();
	~wordLadder();

	bool readDictionary(const char *);

	bool findLadder(const string&, const string&);

	bool validWord(const string&) const;

	void printLadder() const;

	void resetLadder();

private:
	bool isOneApart(const string&, const string&) const;
	void insertWord(const string&);
	wordNode *searchPtr(const string&) const;

	int count; // amt. of nodes in dict. list

	wordNode *first; // first node of dict. list
	wordNode *ladderEnd; // last node of ladder list
};

#endif