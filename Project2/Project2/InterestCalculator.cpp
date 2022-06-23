// Info Header
/*
Jeremy Davis
Project 2
SNHU CS-210
June 5, 2022

Annual Compound Interest Calculator
Takes user input and produces a balance sheet

*/

#include "InterestCalculator.h"

InterestCalculator::InterestCalculator() {}

// constructor
InterestCalculator::InterestCalculator(double initInvestmentAmount, double initMontlhyDeposit, double initAnnualInterest, double initYears, InterestCalculator* nextLoc) {
	this->investmentAmount = initInvestmentAmount;
	this->monthlyDeposit = initMontlhyDeposit;
	this->annualInterest = initAnnualInterest;
	this->years = initYears;
	this->nextNodePtr = nextLoc;
	return;
}

// (linked list code)
void InterestCalculator::InsertAfter(InterestCalculator* nodeLoc) {

	InterestCalculator* tmpNext = 0;

	tmpNext = this->nextNodePtr;
	this->nextNodePtr = nodeLoc;
	if (nodeLoc != nullptr) {
		nodeLoc->nextNodePtr = tmpNext;
	}
	else {
		return;
	}
	return;
}

// grab location pointed by nextNodePtr (linked list code)
InterestCalculator* InterestCalculator::GetNext() {
	return this->nextNodePtr;
}

// mutators
void InterestCalculator::SetInvestmentAmount(double userInvestmentAmount) {
	investmentAmount = userInvestmentAmount;
}
void InterestCalculator::SetMontlhyDeposit(double userMonthlyDeposit) {
	monthlyDeposit = userMonthlyDeposit;
}
void InterestCalculator::SetAnnualInterest(double userAnnualInterest) {
	annualInterest = userAnnualInterest;
}
void InterestCalculator::SetYears(double userYears) {
	years = userYears;
}

// accessors
double InterestCalculator::GetInvestmentAmount() const {
	return investmentAmount;
}
double InterestCalculator::GetMonthlyDeposit() const {
	return monthlyDeposit;
}
double InterestCalculator::GetAnnualInterest() const {
	return annualInterest;
}
double InterestCalculator::GetYears() const {
	return years;
}

// calculates year end total including the additional monthly deposits and compounded monthly interest
vector<double> InterestCalculator::CalculateYearlyTotal(double initAmount, double depositMonthly, double annualInterest, double years) {
	vector<double> eoyBalanceMonthlyDeposit(0);
	double monthlyInterestAccrued;
	double monthlyTotal = initAmount;
	int i;
	int j;

	for (i = 1; i <= years; ++i) {
		for (j = 1; j <= 12; ++j) {
			//calculate the new monthly total with monthly deposits and interest added
			monthlyInterestAccrued = (monthlyTotal + depositMonthly) * ((annualInterest / 100) / 12);
			monthlyTotal = monthlyTotal + depositMonthly + monthlyInterestAccrued;
		}
		eoyBalanceMonthlyDeposit.push_back(monthlyTotal);
	}
	return eoyBalanceMonthlyDeposit;
}

// calculates year end interest made on additional monthly deposits and compounded monthly interest
vector<double> InterestCalculator::CalculateYearlyInterest(double initAmount, double depositMonthly, double annualInterest, double years) {
	vector<double> eoyInterestMonthlyDeposit(0);
	double monthlyInterestAccrued;
	double monthlyTotal = initAmount;
	double yearlyInterest = 0;
	int i;
	int j;

	for (i = 1; i <= years; ++i) {
		for (j = 1; j <= 12; ++j) {
			//calculate the new monthly total with monthly deposits and interest added
			monthlyInterestAccrued = (initAmount + depositMonthly) * ((annualInterest / 100) / 12);		// calculation for interested earned monthly
			yearlyInterest = yearlyInterest + monthlyInterestAccrued;									// calculaton for annual interested earned
			initAmount = initAmount + depositMonthly + monthlyInterestAccrued;                          // calculation for total monthly amount
		}
		eoyInterestMonthlyDeposit.push_back(yearlyInterest);
		yearlyInterest = 0;
	}
	return eoyInterestMonthlyDeposit;
}

// < NO MONTHLY DEPOSIT >   calculates year end total including the compounded monthly interest   < NO MONTHLY DEPOSIT >
vector<double> InterestCalculator::CalYearlyTotalDepositNo(double initAmount, double annualInterest, double years) {
	vector<double> eoyBalanceDepositNo(0);
	double monthlyInterestAccrued;
	double monthlyTotal = initAmount;
	int i;
	int j;

	for (i = 1; i <= years; ++i) {
		for (j = 1; j <= 12; ++j) {
			//calculate the new monthly total with monthly deposits and interest added
			monthlyInterestAccrued = (monthlyTotal) * ((annualInterest / 100) / 12);
			monthlyTotal = monthlyTotal + monthlyInterestAccrued;
		}
		eoyBalanceDepositNo.push_back(monthlyTotal);
	}
	return eoyBalanceDepositNo;
}

// < NO MONTHLY DEPOSIT >   calculates year end interest made on compounded monthly interest   < NO MONTHLY DEPOSIT >
vector<double> InterestCalculator::CalYearlyInterestDepositNo(double initAmount, double annualInterest, double years) {
	vector<double> eoyInterestDepositNo(0);
	double monthlyInterestAccrued;
	double monthlyTotal = initAmount;
	double yearlyInterest = 0;
	int i;
	int j;

	for (i = 1; i <= years; ++i) {
		for (j = 1; j <= 12; ++j) {
			//calculate the new monthly total with monthly deposits and interest added
			monthlyInterestAccrued = (initAmount) * ((annualInterest / 100) / 12);		// calculation for interested earned monthly
			yearlyInterest = yearlyInterest + monthlyInterestAccrued;				   // calculaton for annual interested earned
			initAmount = initAmount + monthlyInterestAccrued;                          // calculation for total monthly amount
		}
		eoyInterestDepositNo.push_back(yearlyInterest);
		yearlyInterest = 0;
	}
	return eoyInterestDepositNo;
}

// prints application opening message
void InterestCalculator::PrintOpenTitle() {

	cout << "================================================================" << endl;
	cout << "=                                                              =" << endl;
	cout << "================================================================" << endl;
	cout << "------ > > > > > > >   AIRGEAD BANKING   < < < < < < < <  ------" << endl;
	cout << "================================================================" << endl;
	cout << "=                                                              =" << endl;
	cout << "=                                                              =" << endl;
	cout << "================================================================" << endl;
	cout << "- - - - - - - -   COMPOUND   INTEREST   RATE  - - - - - - - - - " << endl;
	cout << "-------------------    REPORT   GENERATOR   --------------------" << endl;
	cout << "================================================================" << endl;
	cout << "=                                                              =" << endl;
	cout << "=                                                              =" << endl;
	cout << "=                                                              =" << endl;
	cout << "-/-/-/-/-/-/-/-         Jeremy   Davis         -/-/-/-/-/-/-/-/-" << endl;
	cout << "-------------------      SNHU CS-210        --------------------" << endl;
	cout << "=                                                              =" << endl;
	cout << "================================================================" << endl;

}

// prints inital banner with & without values
void InterestCalculator::PrintBanner(double initAmount, double depositMonthly, double annualInterest, double years) {

	cout << fixed << setprecision(0);
	if (initAmount == NULL) {
		cout << "================================================================" << endl;
		cout << "===               Required   Data    Input                   ===" << endl;
		cout << "================================================================" << endl;
		cout << "=                                                              =" << endl;
		cout << "=  " << left << setw(27) << "Initial Investment Amount:   $________" << right << setw(24) << " = " << endl;
		cout << "=                                                              =" << endl;
		cout << "=  " << left << setw(16) << "Monthly Deposit:             $_______" << right << setw(24) << "=" << endl;
		cout << "=                                                              =" << endl;
		cout << "=  " << left << setw(16) << "Annual Interest Rate <ex. 5>: _______%" << right << setw(23) << "=" << endl;
		cout << "=                                                              =" << endl;
		cout << "=  " << left << setw(16) << "Number of years:              _______" << right << setw(24) << "=" << endl;
		cout << "=                                                              =" << endl;
		cout << "================================================================" << endl;
		system("pause");
	}
	else {
		cout << "================================================================" << endl;
		cout << "===                 Your   Data    Input                     ===" << endl;
		cout << "================================================================" << endl;
		cout << "=                                                              =" << endl;
		cout << "=  " << left << setw(27) << "Initial Investment Amount: $" << initAmount << right << setw(33) << " = " << endl;
		cout << "=                                                              =" << endl;
		cout << "=  " << left << setw(16) << "Monthly Deposit: $" << depositMonthly << right << setw(41) << "=" << endl;
		cout << "=                                                              =" << endl;
		cout << "=  " << left << setw(16) << "Annual Interest: %" << annualInterest << right << setw(42) << "=" << endl;
		cout << "=                                                              =" << endl;
		cout << "=  " << left << setw(16) << "Number of years: " << years << right << setw(43) << "=" << endl;
		cout << "=                                                              =" << endl;
		cout << "================================================================" << endl;
		system("pause");
	}

}

// prints report without additional monthly deposits report
void InterestCalculator::PrintReport1(double initAmount, double annualInterest, double years) {
	vector<double> eoyBalanceDepositNo = CalYearlyTotalDepositNo(initAmount, annualInterest, years);
	vector<double> eoyInterestDepositNo = CalYearlyInterestDepositNo(initAmount, annualInterest, years);
	int i;

	cout << fixed << setprecision(2);
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "================================================================" << endl;
	cout << "    Balance and Interest Without Additional Monthly Deposits    " << endl;
	cout << "================================================================" << endl;
	cout << left << setw(10) << "  Year" << right << setw(20) << "Year End Balance" << right << setw(30) << "Year End Earned Interest" << endl;
	cout << "----------------------------------------------------------------" << endl;
	for (i = 0; i < eoyBalanceDepositNo.size(); i++) {
		cout << endl;
		cout << setw(5) << i + 1 << right << setw(18) << "$" << right << setw(8) << eoyBalanceDepositNo[i] << right << setw(23) << "$" << right << setw(8) << eoyInterestDepositNo[i] << endl;
	}
}

// prints report with additional monthly deposits report
void InterestCalculator::PrintReport2(double initAmount, double depositMonthly, double annualInterest, double years) {
	vector<double> eoyBalanceMonthlyDeposit = CalculateYearlyTotal(initAmount, depositMonthly, annualInterest, years);
	vector<double> eoyInterestMonthlyDeposit = CalculateYearlyInterest(initAmount, depositMonthly, annualInterest, years);
	int i;

	cout << fixed << setprecision(2);
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "================================================================" << endl;
	cout << "      Balance and Interest With Additional Monthly Deposits     " << endl;
	cout << "================================================================" << endl;
	cout << left << setw(10) << "  Year" << right << setw(20) << "Year End Balance" << right << setw(30) << "Year End Earned Interest" << endl;
	cout << "----------------------------------------------------------------" << endl;
	for (i = 0; i < eoyBalanceMonthlyDeposit.size(); i++) {
		cout << endl;
		cout << setw(5) << i+1 << right << setw(18) << "$" << right << setw(8) << eoyBalanceMonthlyDeposit[i] << right << setw(23) << "$" << right << setw(8) << eoyInterestMonthlyDeposit[i] << endl;
	}
}