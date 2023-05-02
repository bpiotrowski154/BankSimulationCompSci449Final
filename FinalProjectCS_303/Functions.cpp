#include "Functions.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <iomanip>

int startMenu() {
	int userChoice;

	//Outputs main menu
	cout << setfill('-') << setw(30) << "" << endl;
	cout << setfill(' ') << setw(23) << "Simulation Menu" << endl;
	cout << setfill('-') << setw(30) << "" << endl;
	cout << "1 - Simulation 25 Customers" << endl;
	cout << "2 - Simulation 31 Customers" << endl;
	cout << "3 - Manual Input of Customers" << endl;
	cout << "0 - Quit" << endl;
	cout << "Choice >> ";
	
	//Input validation
	if (cin >> userChoice) {
		//Validates the users menu choice
		if (userChoice != 1 && userChoice != 2 && userChoice != 3 && userChoice != 0)
			throw userChoice;
	}
	else if (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid Input" << endl << endl;
		return -1;
	}

	cout << endl << endl;

	return userChoice;
}





void readCustomers(stack<Customer> &customers, string fileName) {
	ifstream inFile;
	string name, inLine, testChar, tempStr, transType;
	vector<string> row;
	int currBalance, transAmount;
	
	//Opens and error handles the text file containing simulation data
	try {
		inFile.exceptions(ifstream::failbit);
		inFile.open(fileName);
	}
	catch (ifstream::failure& fail) {
		cout << "Could not open input file" << endl;
		cout << fail.what() << endl;
		cout << fail.code() << endl;
	}

	//Loop that parses and reads through the text file
	while (inFile.good()) {
		getline(inFile, inLine);
		testChar = inLine.substr(0, 1);
		if (testChar == "Q")
			break;

		row.clear();
		stringstream inSS(inLine);
		while (getline(inSS, tempStr, ','))
			//Stores the current lines information into a vector
			row.push_back(tempStr);

		//Stores the elements within the vector into the temporary variables used
		//to create a customer
		name = row[1];
		currBalance = stoi(row[2]);
		transType = row[3];
		transAmount = stoi(row[4]);

		row.erase(row.begin(), row.begin() + 5);

		//Creates a customer and pushes it onto the stack
		Customer tempCustomer(name, currBalance, transType, transAmount);
		customers.push(tempCustomer);
	}

	inFile.close();
}





void manualInputCustomers(stack<Customer>& customers) {
	bool stopInput = false, active = true;
	string name, transType, addCustChoice;
	int currBalance, transAmount;
	
	//Input handling
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	//Loop that allows the user to input as many customers as they want
	while (!stopInput) {
		//Get customers name from user
		cout << "Input Customer Name: ";
		cin.clear();
		getline(cin, name);

		//Get customers current account balance from the user
		while (true) {
			cout << "Input Customer's Account Balance: ";

			//Input validation to make sure the user entered an integer
			if (cin >> currBalance) {
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				break;
			}
			else if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid Input" << endl << endl;
			}
		}

		//Get customers transaction type from the user
		do {
			try {
				cout << "Input Transaction Type (W/D): ";
				
				getline(cin, transType);

				//Input handling that allows user to not worry about capitalization 
				if (transType == "w")
					transType = "W";
				else if (transType == "d")
					transType = "D";

				//Input validation
				if (transType != "W" && transType != "D")
					throw transType;
			}

			//Catches error caused by user inputting an invalid transaction type
			catch (string input) {
				cout << "Invalid Input" << endl << endl;
				cin.clear();
			}
		} while (transType != "W" && transType != "D");

		//Get customers transaction amount from the user
		while (true) {
			cout << "Input Transaction Amount: ";

			//Input validation to make sure user inputs an integer
			if (cin >> transAmount) {
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				//Checks to make sure the user did not input an amount that would overdraw
				//from the customers account
				if (transType == "W" && transAmount > currBalance) {
					cout << "Error: Withdrawal Amount exceeds Current Balance" << endl << endl;
				}
				else
					break;
			}
			else if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid Input" << endl << endl;
			}
		}
		
		//Pushes the customer onto the stack
		Customer tempCustomer(name, currBalance, transType, transAmount);
		customers.push(tempCustomer);


		//Asks user if they would like to continue adding customers
		do {
			try {
				cout << "Add Another Customer (Y/N): ";
				getline(cin, addCustChoice);

				//Input validation
				if (addCustChoice != "Y" && addCustChoice != "y" && addCustChoice != "n" && addCustChoice != "N")
					throw addCustChoice;
			}

			//Catches error caused by user misinput during choice of adding another customer
			catch(string input) {
				cout << "Invalid Input" << endl << endl;
				cin.clear();
			}
		} while (addCustChoice != "Y" && addCustChoice != "y" && addCustChoice != "n" && addCustChoice != "N");

		cout << endl << endl;
		if (addCustChoice == "N" || addCustChoice == "n")
			stopInput = true;
	}
}





void simulateBankTeller(stack<Customer>& customers) {
	stack<Customer> tempStack;
	int custServed = 0, origStackSize = customers.size();

	cout << "Processing Customers..." << endl << endl;	
	
	while (customers.size() != 0) {
		//Removes next customer from the stack
		customers.pop();
		custServed++;
		
		//After every 5 customers are processed in the system, outputs current stacks information
		if (custServed % 5 == 0 && custServed != origStackSize) {
			cout << setfill(' ') << right << setw(17) << "Current Stack" << endl;
			cout << setfill('-') << setw(20) << "" << endl;
			cout << "Stack Size: " << customers.size() << endl;
			cout << "Next Customer: " << customers.top().getName() << endl;
			cout << "Account Balance: $" << customers.top().getCurrBalance() << endl;
			cout << "Transaction Type: ";
			if (customers.top().getTransType() == "W")
				cout << "Withdrawal" << endl;
			else
				cout << "Deposit" << endl;
			cout << "Transaction Amount: $" << customers.top().getTransAmount() << endl << endl;
			cout << "Processing Customers..." << endl << endl;
		}
	}
}