#pragma once
#include <string>

class Transaction {
	public:
		//Constructors
		Transaction();
		Transaction(std::string type, int amount);
		
		//Mutators
		void setTransType(char type);
		void setTransAmount(int amount);

		//Accessors
		std::string getTransType();
		int getTransAmount();

	protected:
		std::string transType;
		int transAmount;
};
