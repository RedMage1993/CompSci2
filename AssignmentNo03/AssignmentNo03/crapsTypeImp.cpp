//******************************************
// Computer Science II -- Assignment No. 03
// Description: Create a craps game.
// File: crapsTypeImp.cpp
// Definition for crapsType class.
//******************************************

#include "crapsType.h"

const char* crapsType::NAME_TABLE[6][6] =
	{{"Snake Eyes", "Ace Deuce", "Easy Four", "Fever Five", "Easy Six", "Seven Out"},
	{"Ace Deuce", "Hard Four", "Fever Five", "Easy Six", "Seven Out", "Easy Eight"},
	{"Easy Four", "Fever Five", "Hard Six", "Seven Out", "Easy Eight", "Nina"},
	{"Fever Five", "Easy Six", "Seven Out", "Hard Eight", "Nina", " Easy Ten"},
	{"Easy Six", "Seven Out", "Easy Eight", "Nina", "Hard Ten", "Yo-leven"},
	{"Seven Out", "Easy Eight", "Nina", "Easy Ten", "Yo-leven", "Boxcars"}};

crapsType::crapsType()
{
	int originalStake = 0;
	int cashOnHand = 0;
	bool display = false; // Doesn't matter, but why true, false == 0.
}

void crapsType::readStake()
{
	bool valid = false;

	while (!valid)
	{
		cout << "Enter Stake Amount: ";
		cin >> originalStake;

		if (originalStake >= MINSTAKE && originalStake <= MAXSTAKE)
			valid = true;
		else
		{
			cout << "Error, invalid entry. Must be between " << MINSTAKE
				 << " and " << MAXSTAKE << " inclusive.\nPlease re-enter.\n\n";
		}
	};

	cashOnHand = originalStake;
}

void crapsType::setStake(int stake)
{
	if (stake < MINSTAKE || stake > MAXSTAKE)
		cout << "Error, invalid stake amount.\n";
	else
		cashOnHand = originalStake = stake;
}

int crapsType::getStake() const
{
	return originalStake;
}

int crapsType::getCurrentBalance() const
{
	return cashOnHand;
}

void crapsType::setDisplay(bool disp)
{
	display = disp;
}

bool crapsType::playCraps(int bet)
{
	int die1, die2;
	int point;

	if (bet < MINBET || bet > MAXBET)
	{
		cout << "Error, invalid bet.\n";
		return false;
	}

	die1 = rand() % 6 + 1;
	die2 = rand() % 6 + 1;

	if (display)
	{
		cout << setfill('-') << setw(26) << '\n';
		displayRoll(die1, die2);
	}

	switch (die1 + die2)
	{
	case 7:
	case 11:
		break;

	case 2: // ... is not very portable >.>
	case 3:
	case 12:
lose:
		cashOnHand -= bet;

		if (display)
		{
			cout << "Lost\n";
			cout << "Current Balance: $" << cashOnHand << endl << endl;
		}

		return false;

	case 4:
	case 5:
	case 6:
	case 8:
	case 9:
	case 10: // point
		point = die1 + die2;

		if (display)
			cout << "Point: " << point;
		
		do
		{
			die1 = rand() % 6 + 1;
			die2 = rand() % 6 + 1;

			if (display)
			{
				cout << endl;
				displayRoll(die1, die2);
			}

			if (die1 + die2 == 7)
				goto lose;
		} while (die1 + die2 != point);
		
		break;
	}

	cashOnHand += bet;

	if (display)
	{
		cout << "Won\n";
		cout << "Current Balance: $" << cashOnHand << endl << endl;
	}

	return true;
}

void crapsType::displayRoll(int first, int second)
{
	cout << "Die 1: " << first << "\tDie 2: " << second;
	cout << "\tSum: " << first + second << "\t\t" << NAME_TABLE[first - 1][second - 1]
		 << endl;
}