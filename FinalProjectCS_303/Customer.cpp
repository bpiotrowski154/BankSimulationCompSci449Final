#include "Customer.h"

Customer::Customer(): Transaction(){
	name = "";
	currBalance = 0;
}

Customer::Customer(std::string name, int currBalance, std::string transType, int transAmount) : Transaction(transType, transAmount) {
	this->name = name;
	this->currBalance = currBalance;
}

void Customer::setName(std::string name)			{ this->name = name; }
void Customer::setCurrBalance(int currBalance)		{ this->currBalance = currBalance; }

std::string Customer::getName()						{ return name; }
int Customer::getCurrBalance()						{ return currBalance; }