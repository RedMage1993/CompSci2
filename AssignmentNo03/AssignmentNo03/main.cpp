//******************************************
// Computer Science II -- Assignment No. 03
// Description: Create a craps game.
// File: main.cpp
// Driver for the crapsType class.
//******************************************

#define GAME_01 00
#define GAME_02 01
#define GAME_03 02

#include <iostream>
#include <iomanip>
#include <ctime>
#include "crapsType.h"

using namespace std;

struct crapsEmu
{
	crapsType emu;
	int wins, losses, rounds;
	int myBet, balance;
	int reset; // If player wins, reset bet to this.
	int change; // If player loses, increase/decreases bet by this.
	char* title;
	bool done;
	int multiplier; // Multiplier to check balance against triples, quadruples, etc.
};

void showCrapsData(const crapsEmu& data);

const unsigned int NUM_GAMES = 3;

int main()
{
	crapsEmu craps[NUM_GAMES];

	cout << setfill('-') << setw(26) << '\n';
	cout << "CS 202 Assignment #3" << endl;
	cout << "Craps Game Simulation." << endl << endl;

	//srand(static_cast<unsigned int> (time(reinterpret_cast<time_t*> (NULL))));

	memset(craps, 0, sizeof(craps));

	cout << fixed << showpoint;
	cout << setprecision(2);

	for (unsigned int game = GAME_01; game < NUM_GAMES; game++)
	{
		switch (game)
		{
		case GAME_01: // Initial game.
			//  Game strategy:
			//	- bet 100 each bet.
			//	- if run out of money, quit
			//	- if stake is quadrupled, quit

			craps[game].myBet = 100;
			craps[game].title = "Game Example A (w/display)";

			cout << setw(26) << '\n';
			cout << craps[game].title << endl << endl;

			craps[game].emu.readStake();
			craps[game].emu.setDisplay(true);

			craps[game].multiplier = 4;

			break;

		case GAME_02: // Second game.
			// ----------
			//  Start two more games.
			//  For simplicity on these games:
			//	- set stake directly (no need to read from user)
			//	- do not display each game status (i.e., set display to false)

			//  Game 1 Strategy:
			//	- set stake to 1000, and set bet 100
			//		if win, increase bet by 10
			//		if lose, set bet back to 100
			//	- if run out of money, quit
			//	- if stake is doubled, quit

			craps[game].myBet = 100;
			craps[game].title = "Game Example 1 (wo/display)";

			craps[game].emu.setStake(1); // note, invalid.
			craps[game].emu.setStake(1000);
			craps[game].emu.setDisplay(false);

			craps[game].change = 10;
			craps[game].reset = 100;

			craps[game].emu.playCraps(5); // note, invalid.

			craps[game].multiplier = 4;

			break;

		case GAME_03: // Third game.
			// ----------
			//  Game 2 Strategy:
			//	- players choice.
			//	Challenge: find a winning strategy.  :-)

			craps[game].myBet = 64;
			craps[game].title = "Game Example 2 (wo/display)";

			craps[game].emu.setStake(256);
			craps[game].emu.setDisplay(false);

			craps[game].change = 32;
			craps[game].reset = 64;

			craps[game].multiplier = 2;

			break;
		}

		// Play game.
		while (!craps[game].done)
		{
			craps[game].rounds++;

			if (craps[game].emu.playCraps(craps[game].myBet))
			{
				craps[game].wins++;
				craps[game].myBet += craps[game].change;
			}
			else
			{
				craps[game].losses++;

				if (craps[game].reset)
					craps[game].myBet = craps[game].reset;
			}

			if (craps[game].emu.getCurrentBalance() <= craps[game].myBet ||
				craps[game].emu.getCurrentBalance() >=
				craps[game].emu.getStake() * craps[game].multiplier)
			{
				craps[game].done = true;
			}
		}

		cout << endl;
		showCrapsData(craps[game]);
	}

	return 0;
}


// ************************************************************************************
//  Simple function to display game summary.

void showCrapsData(const crapsEmu& data)
{
	cout << setfill('*') << setw(51) << '\n';

	cout << "Game Results:" << endl;
	cout << "\tGame Title: " << data.title << endl;
	cout << "\tWins = " << data.wins << endl;
	cout << "\tLosses = " << data.losses << endl;
	cout << "\tRounds = " << data.rounds << endl;
	cout << "\tOriginal Stake:  $"
		 << static_cast<float> (data.emu.getStake()) << endl;
	cout << "\tFinal Balance:  $"
		 << static_cast<float> (data.emu.getCurrentBalance()) << endl;

	if (data.emu.getCurrentBalance() > data.emu.getStake())
		cout << "\tWinner!!" << endl;
	else
		cout << "\tLoser." << endl;

	cout << setfill('*') << setw(52) << "\n\n";
}
