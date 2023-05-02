#include <iostream>
#include "Functions.h"
#include "Customer.h"
#include "Transaction.h"
#include <stack>
#include <stdexcept>
#include <limits>
using namespace std;

int main() {
	stack<Customer> customers;
	int userChoice;
	bool done = false;

	while (!done) {
		try {
			//Gets the users choice from the main menu 
			userChoice = startMenu();

			switch (userChoice) {
				//Performs simulation type 1 containing 25 customers
				case 1:
					readCustomers(customers, "customers1.txt");
					simulateBankTeller(customers);
					break;

				//Performs simulation type 2 containing 31 customers
				case 2:
					readCustomers(customers, "customers2.txt");
					simulateBankTeller(customers);
					break;

				//Performs simulation containing the customers manually input by the user
				case 3:
					manualInputCustomers(customers);
					simulateBankTeller(customers);
					break;

				//Ends the program
				case 0:
					done = true;
					break;

				default:
					break;
			}
		}

		//Catches the error cause by the users misinput during the main menu
		catch (int choice) {
			cout << "Invalid Input" << endl << endl << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
}