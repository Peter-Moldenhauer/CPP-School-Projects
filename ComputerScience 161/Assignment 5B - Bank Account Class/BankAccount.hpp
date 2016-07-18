/**************************************************************************************
** Name: Peter Moldenhauer
** Date: 4/23/16
** Description: Project 5b This program is the header file for the class BankAccount.
**This program demonstrates a bank account that keeps track of a customers name, ID,
**balance, withdraws and deposits.
**
**Note: Per the assignment description, a main.cpp file/function is not included.
**************************************************************************************/

#ifndef BANKACCOUNT_HPP  //include guard
#define BANKACCOUNT_HPP  //include guard
#include <string>
#include <iostream>
using namespace std;

//Bank Account Class declaration
class BankAccount
{
	private:  //make variables private! Use setter and getter functions to access them!
		string customerName;
		string customerID;
		double customerBalance;

	public:
		BankAccount(string cN, string cI, double cB); //constructor with three parameters
        //The three getter functions below for the variables...
		string getCustomerName();
		string getCustomerID();
		double getCustomerBalance();
        //These functions below don't return anything but just calculate the customer balance based on withdraws and deposits
		void withdraw(double w);
		void deposit(double d);

};  //Remember semi-colon here!

#endif  //include guard

