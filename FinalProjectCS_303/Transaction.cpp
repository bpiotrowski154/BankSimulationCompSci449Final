#include "Transaction.h"

Transaction::Transaction() {
	transType = 'N';
	transAmount = 0;
}

Transaction::Transaction(std::string type, int amount) {
	this->transType = type;
	this->transAmount = amount;
}

void Transaction::setTransType(char type)		{ this->transType = type; }
void Transaction::setTransAmount(int amount)	{ this->transAmount = amount; }

std::string Transaction::getTransType()			{ return transType; }
int Transaction::getTransAmount()				{ return transAmount; }