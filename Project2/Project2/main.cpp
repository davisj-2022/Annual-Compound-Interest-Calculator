// Info Header
/*
Jeremy Davis
Project 2
SNHU CS-210
June 5, 2022

Annual Compound Interest Calculator
Takes user input and produces a balance sheet based on input

Report 1 - balance sheet without monthly deposits
Report 2 - balance sheet with monthly deposits

Program will produce different reports until user press Q

*/

#include "InterestCalculator.h"

using namespace std;

double initAmount;
double depositMonthly;
double annualInterest;
double years;

InterestCalculator case1;

// function to get initial values from user with error detection
void setValues() {

	// sets initial amount
	cout << "Enter your initial investment amount: $ ";
	while (true)
	{
		cin >> initAmount;
		if (!cin) {
			cout << "Invalid Entry. Enter numbers only." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}
		else break;
	}
	case1.SetInvestmentAmount(initAmount);
	system("CLS");

	// sets monthly deposity amount
	cout << "Enter your monthly deposit: $ ";
	while (true)
	{
		cin >> depositMonthly;
		if (!cin) {
			cout << "Invalid Entry. Enter numbers only." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}
		else break;
	}
	case1.SetMontlhyDeposit(depositMonthly);
	system("CLS");

	// sets annual interest rate
	cout << "Enter the annual interest rate: % ";
	while (true)
	{
		cin >> annualInterest;
		if (!cin) {
			cout << "Invalid Entry. Enter numbers only." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}
		else break;
	}
	case1.SetAnnualInterest(annualInterest);
	system("CLS");

	// sets number of investment years
	cout << "Enter the number of investment years: ";
	while (true)
	{
		cin >> years;
		if (!cin) {
			cout << "Invalid Entry. Enter numbers only." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}
		else break;
	}
	case1.SetYears(years);
}																			

int main() {																						// main driver of program

	string userEntry;

	while (userEntry != "q") {

		case1.PrintOpenTitle();																		// prints app opening message
		system("pause");														system("CLS");
		case1.PrintBanner(NULL, NULL, NULL, NULL); 								system("CLS");		// prints items that will need user input
		setValues();															system("CLS");		// function call to get the inputs
		case1.PrintBanner(initAmount, depositMonthly, annualInterest, years); 	system("CLS");		// prints input from user onto the banner
		case1.PrintOpenTitle();																		// prints app opening message
		case1.PrintReport1(initAmount, annualInterest, years);										// prints report with no monthly deposits
		case1.PrintReport2(initAmount, depositMonthly, annualInterest, years);						// prints report with monthly deposits 
		
		cout << "\n\n\nPress any key to run another report" << endl;								// run another report press any key
		cout << "Press Q to quit" << endl;															// quit program.. press Q

		userEntry = _getch();													system("CLS");
	}
	return 0;
}