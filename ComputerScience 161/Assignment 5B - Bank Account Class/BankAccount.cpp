/************************************************************************
** Name: Peter Moldenhauer
** Date: 4/23/16
** Description: Project 5b This program is the implementation file for
**the class BankAccount. This program demonstrates a bank account that
**keeps track of a customers name, ID, balance, withdraws and deposits.
**
**Note: Per the assignment description, a main.cpp file/function is not
**included.
*************************************************************************/

#include "BankAccount.hpp"  //include the BankAccount class header file

//Constructor that takes three parameters
BankAccount::BankAccount(string cN, string cI, double cB)
{
	customerName = cN; //initialize the class variables through the constructor here
	customerID = cI;
	customerBalance = cB;
}

string BankAccount::getCustomerName()  //getter, no parameter, returns a string
{
	return customerName;
}

string BankAccount::getCustomerID()  //getter, no parameters, returns a string
{
	return customerID;
}

double BankAccount::getCustomerBalance()  //getter, no parameter, returns a double
{
	return customerBalance;
}

void BankAccount::withdraw(double w)  //this function does not return anything, just calculates customer's balance if there is a withdraw
{
	customerBalance = customerBalance - w;
}

void BankAccount::deposit(double d)  //this function does not return anything, just calculates customers balance if there is a deposit
{
	customerBalance = customerBalance + d;
}


