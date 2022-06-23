// Info Header
/*
Jeremy Davis
Project 2
SNHU CS-210
June 5, 2022

Annual Compound Interest Calculator
Takes user input and produces a balance sheet

*/

#ifndef INTERESTCALCULATOR_H
#define INTERESTCALCULATOR_H

#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <conio.h> 

using namespace std;

class InterestCalculator {
public:
	InterestCalculator();
	InterestCalculator(double initInvestmentAmount, double initMontlhyDeposit, double initAnnualInterest, double initYears, InterestCalculator* nextLoc = 0);
	void InsertAfter(InterestCalculator* nodePtr);

	// mutators
	void SetInvestmentAmount(double investmentAmount);
	void SetMontlhyDeposit(double monthlyDeposit);
	void SetAnnualInterest(double annualInterest);
	void SetYears(double years);

	// accessors
	double GetInvestmentAmount() const;
	double GetMonthlyDeposit() const;
	double GetAnnualInterest() const;
	double GetYears() const;
	vector<double>CalYearlyTotalDepositNo(double initAmount, double annualInterest, double years);
	vector<double>CalYearlyInterestDepositNo(double initAmount, double annualInterest, double years);
	vector<double>CalculateYearlyTotal(double initAmount, double depositMonthly, double annualInterest, double years);
	vector<double>CalculateYearlyInterest(double initAmount, double depositMonthly, double annualInterest, double years);
	void PrintOpenTitle();
	void PrintBanner(double initInvestmentAmount, double initMontlhyDeposit, double initAnnualInterest, double initYears);
	void PrintReport1(double initInvestmentAmount, double initAnnualInterest, double initYears);
	void PrintReport2(double initInvestmentAmount, double initMontlhyDeposit, double initAnnualInterest, double initYears);

	InterestCalculator* GetNext();

private:
	double investmentAmount;
	double monthlyDeposit;
	double annualInterest;
	double years;

	InterestCalculator* nextNodePtr;
};

#endif