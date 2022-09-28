// Name: Fritz Ammon
// Section: 1002
// Assignment: 4

// ***********************************************************************
// Class: cashRegister
// Description:
//     The cashRegister class handles the inventory functions of a
// vending machine. It will be able to manage sales and update accordingly
// its own inventory, managing its funds at all times.

#include "vendingMachine.h"

cashRegister::cashRegister(int iniFunds)
{
    cashOnHand = iniFunds;
}

int cashRegister::getCurrentBalance() const
{
    return cashOnHand;
}

void cashRegister::acceptAmount(int costAmt, int tendAmt)
{
    int change = tendAmt - costAmt; // Change is difference in cost and tendered.
    int rem;
    int cValue = 0; // Value of the coin/bill.
    char* name = 0; // Name of the coin/bill.
   
	cout << "\nSale Summary:\n";
	cout << "  Product Cost: " << costAmt << endl;
	cout << "  Amount Tendered: " << tendAmt << endl;

	if (costAmt == tendAmt)
		cout << "  Exact change, thank you.\n";
	else
	{
		cout << "  Change is: " << change << endl;
    
		for (unsigned int c = 0; c < 6; c++)
		{
			switch (c)
			{
			case 0:
				cValue = 500;
				name = "Five";
				break;
			case 1:
				cValue = 100;
				name = "Dollar";
				break;
			case 2:
				cValue = 25;
				name = "Quarter";
				break;
			case 3:
				cValue = 10;
				name = "Dime";
				break;
			case 4:
				cValue = 5;
				name = "Nickel";
				break;
			case 5:
				cValue = 1;
				name = "Penny"; // Shows up as "Pennys" in PDF (pennies, pence).
				break;
			}
    
			if (change >= cValue)
			{ // Coin/bill fits into change.
				cout << "  " << (rem = change / cValue);
				change %= cValue; // Update change.

				cout << "  " << name;
       
				if (rem > 1)
					cout << 's';
                
				cout << endl;
			}
		}
	}

	cashOnHand += costAmt;

	cout << "Sale Completed\n\n";
}

dispenserType::dispenserType(int proCount, int proCost)
{
	pCount = proCount;
	pCost = proCost;
}

int dispenserType::getNoOfItems() const
{
	return pCount;
}

int dispenserType::getCost() const
{
	return pCost;
}

void dispenserType::makeSale()
{
	pCount--;
}