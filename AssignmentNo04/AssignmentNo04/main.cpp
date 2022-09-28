// Name: Fritz Ammon
// Section: 1002
// Assignment: 4

//	CS 202
//	Provided Main Program
//	Assignment #4 - Vending Machine

// -----------------------------------------------------------------------
//	C++ program to implement a virtual vending machine.
//	The vending machine has two main elements;
//		a built-in cash register
//		product inventory (dispensing and tracking)
//	The main() program will show the products, allow product
//	selection, and handle termination.

//	Additionally, the main will support an non-displayed option
//	for machine inventory.

//	The program uses two classes; cashRegister and dispenserType

//	The function prototypes are in vendingMachine.h and the code
//	is in file vendingMachineImp.cpp

// ***********************************************************************

#include <cstdlib>
#include <iostream>

#include "vendingMachine.h"

using namespace std;

void showSelection();
void sellProduct(dispenserType& product, 
			cashRegister& pCounter);

// ***********************************************************************

int main()
{

// ----------
//	Initializations and declarations

	// initialize cash register
	cashRegister counter;

	// create object for each virtual product in machine
	dispenserType coke(10, 150);			// 10 coke's at 150 cents each
	dispenserType pepsi(3, 150);			// 3 peipsi's at 150 cents each
	dispenserType redBull(5, 250);			// 5 Red Bull's at 250 cents each
	dispenserType lemonade(5, 125);			// 5 lemonade's at 125 cents each
	dispenserType water(5, 100);			// 5 water's at 100 cents each

	int	choice;					// customer selection

// ----------
//	Start interactive session

	system("clear");
	showSelection();
	cin >> choice;

	while (choice != 9)
	{
		switch (choice) {
		case 1:
			sellProduct(coke, counter);
			break;
		case 2:
			sellProduct(pepsi, counter);
			break;
		case 3:
			sellProduct(redBull, counter);
			break;
		case 4:
			sellProduct(lemonade, counter);
			break;
		case 5:
			sellProduct(water, counter);
			break;
		case 8:
			cout << "Inventory:" << endl;
			cout << "  Coke: " << coke.getNoOfItems() << endl;
			cout << "  Pepsi: " << pepsi.getNoOfItems() << endl;
			cout << "  RedBull: " << redBull.getNoOfItems() << endl;
			cout << "  Lemonade: " << lemonade.getNoOfItems() << endl;
			cout << "  Water: " << water.getNoOfItems() << endl;
			cout << "  Machine Funds: " << counter.getCurrentBalance() << endl;
			break;
		default:
			cout << "Invalid selection." << endl;
		} //end switch

		showSelection();

		cin >> choice;
	} //end while

	return 0;

} //end main


// ***********************************************************************
//	Show virtual machine selection options.
//	Note, does not show option 8 (inventory) to users.

void showSelection()
{
	cout << endl;
	cout << "*************************************************" << endl;
	cout << "Welcome to the CS 202 Virtual Candy Machine" << endl << endl;
	cout << "To select an item, enter " << endl;
	cout << "   1 for Coke" << endl;
	cout << "   2 for Pepsi" << endl;
	cout << "   3 for Red Bull" << endl;
	cout << "   4 for Lemonade" << endl;
	cout << "   5 for Water" << endl;
	cout << "   9 to exit" << endl;

} //end showSelection


// ***********************************************************************

void sellProduct(dispenserType& product, cashRegister& pCounter)
{
	int	amount;			// amount entered
	int	amount2;		// extra amount needed (if any)
	int	maxDeposit = 1000;	// max amount accepted

	// ensure dispenser is not empty
	if (product.getNoOfItems() > 0) {

		amount = 0;
		while (amount <= 0 || amount > maxDeposit) {
			cout << "Cost is " << product.getCost()
				<< " cents" << endl;
			cout << "Deposit: ";
			cin >> amount;
			if (amount > maxDeposit)
				cout << "Sorry, more than " << maxDeposit <<
					" is not accepted by this machine." << endl;
		}

		while (amount < product.getCost()) {
			cout << "Please deposit another "
				 << product.getCost()- amount
				 << " cents." << endl;
			cin >> amount2;
			amount = amount + amount2;
		}

		pCounter.acceptAmount(product.getCost(), amount);
		product.makeSale();

		cout << "Thank you, enjoy your virtual item." << endl;

	} else
		cout << "Sorry, this item is sold out." << endl
			<< "Please make another choice." << endl;

} //end sellProduct

// ***********************************************************************
