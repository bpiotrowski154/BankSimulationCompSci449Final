#pragma once
#include <stack>
#include "Customer.h"
using namespace std;

int startMenu();
//Expects nothing

//Outputs the main menu and returns the users choice of 
//simulation type 1, simulation type 2, or manual input

void readCustomers(stack<Customer> &customers, string fileName);
//Expects the stack containing each customers information as well as the 
//the name of which file is being opened

//Reads through the text file that was passed and parses through each line
//to get the customers name, current account balance, transaction type, and
//transaction amount then passes that customer onto the stack of customers

void manualInputCustomers(stack<Customer>& customers);
//Expects the stack containing each customers information

//Allows the user to manually input each customers name, current account
//balance, transaction type, and transaction amount, to allow the user to 
//performa a simulation of their own. Passes each customer onto the stack
//after the user inputs the four items each customer requires

void simulateBankTeller(stack<Customer>& customers);
//Expects the stack containing each customers information

//Outputs the simulation results. Processes five customers on the stack and
//then outputs the current size of the stack, the next customers name, current 
//account balance, transaction type, and transaction amount 

