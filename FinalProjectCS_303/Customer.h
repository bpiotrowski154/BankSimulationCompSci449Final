#pragma once
#include <string>
#include "Transaction.h"

class Customer : public Transaction {
	//Inherits the Transaction class to allow the transaction information to 
	//be stored with the specific customers information


	public:	
		//Constructors
		Customer();
		Customer(std::string name, int currBalance, std::string transType, int transAmount);

		//Mutators
		void setName(std::string name);
		void setCurrBalance(int currBalance);

		//Accessors
		std::string getName();
		int getCurrBalance();

	private:
		std::string name;
		int currBalance;
};