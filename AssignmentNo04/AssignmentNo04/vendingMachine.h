// Name: Fritz Ammon
// Section: 1002
// Assignment: 4

// ***********************************************************************
// Class: cashRegister
// Description:
//     The cashRegister class handles the inventory functions of a
// vending machine. It will be able to manage sales and update accordingly
// its own inventory, managing its funds at all times.

#include <iostream>

using namespace std;

#ifndef CASHREGISTER_H
#define CASHREGISTER_H

class cashRegister
{
public:
    // Initialize member variables and set the
    // initial funds to iniFunds.
    // If no initial funds is passed, it is set to
    // $5.00, or 500.
    cashRegister(int iniFunds = 500);
    
    // Returns the machine's current funding.
    // The cashOnHand member is returned.
    int getCurrentBalance() const;
    
    // Accepts the purchase of a product.
    // Updates the machine's funding and displays
    // the change to be returned to the user.
    // The change displayed differentiates between
    // singular and plural coins.
    void acceptAmount(int costAmt, int tendAmt);
   
private:
    int cashOnHand; // The machine's funding.
}; //end cashRegister

// ***********************************************************************
// Class: dispenserType
// Description:
//    The dispenserType class maintains record of the number of its
// particular product being sold in stock. It manages the price of the
// product as well.

class dispenserType
{
public:
    // Initialize member variables and set
    // the product count and cost.
    dispenserType(int proCount, int proCost);
    
    // Returns the number of products in stock.
    // The pCount member is returned.
    int getNoOfItems() const;
    
    // Returns the cost of the product.
    // The pCost member is returned.
    int getCost() const;
    
    // Updates the stock of the product.
    // Subtracts one from pCount.
    void makeSale();
    
private:
    int pCount; // The number of available products in stock.
    int pCost; // The cost of the product.
}; //end dispenserType

#endif // CASHREGISTER_H

// ***********************************************************************
