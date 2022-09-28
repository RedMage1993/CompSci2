//******************************************
// Computer Science II -- Assignment No. 03
// Description: Create a craps game.
// File: crapsType.h
// Declarations for crapsType class.
//******************************************

#ifndef CRAPSTYPE_H
#define CRAPSTYPE_H

#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

class crapsType
{
public:
	// Constructor. Initialize class variables.
	crapsType();

	// Function to read stake amount from player.
	// Verifies range, re-prompts until correct input.
	void readStake();

	// Function to set the stake amount (from argument).
	void setStake(int stake);

	// Function to return the current stake.
	int getStake() const;

	// Function to get the current balance.
	int getCurrentBalance() const;

	// Function to set the display flag.
	void setDisplay(bool disp);

	// Play a single game of craps (simplified version).
	// If display is true, calls displayGame().
	bool playCraps(int bet);

private:
	// Private function to display roll details.
	// Includes roll name.
	void displayRoll(int first, int second);

	int originalStake; // Original stake amount.
	int cashOnHand; // Current cash amount.
	bool display; // Dislpay game details if true.

	static const int MINSTAKE = 50;
	static const int MAXSTAKE = 10000;
	static const int MINBET = 10;
	static const int MAXBET = 1000;

	// To make name selection easier.
	static const char* NAME_TABLE[6][6];
};

#endif // CRAPSTYPE_H