/*
 * employeeCommissionCalculator.cpp
 *
 *  Created on: Dec 10, 2022
 *      Author: jacobkerames
 */

#include <iostream>
#include <iomanip>
#include <conio.h>

// Standard namespace declaration
using namespace std;

// Function prototype
double calculatePay(double commissionRate, double baseSalary, double overtime);

// Main function
int main()
{
	// Declare variables
	double commissionRate;
	double baseSalary;
	double overtimeHours = 0;
	double pay;

	double* commissionRatePtr{ new double };
	double* baseSalaryPtr{ new double };
	double* overtimeHoursPtr{ new double };
	double* payPtr{ new double };

	// Get user inputs
	cout << "Enter the employee's commission rate(percent): " << endl;
	cin >> commissionRate;
	cout << "Enter the employee's base salary: " << endl;
	cin >> baseSalary;
	cout << "Enter the employee's overtime hours: " << endl;
	cin >> overtimeHours;

	// Calculate the employee's pay
	pay = calculatePay(commissionRate, baseSalary, overtimeHours);
	cout << "\nEmployee pay: $" << pay << endl;

	// Assign the variables' memory addresses to pointers
	commissionRatePtr = &commissionRate;
	baseSalaryPtr = &baseSalary;
	overtimeHoursPtr = &overtimeHours;
	payPtr = &pay;

	// Display the content of the variables and pointers
	cout << "\nCommission at " << setw(18) << commissionRatePtr << ": " << commissionRate << "%" << endl;
	cout << "Base salary at " << setw(17) << baseSalaryPtr << ": $" << baseSalary << endl;
	cout << "Overtime hours at " << overtimeHoursPtr << ": " << overtimeHours << " hours" << endl;
	cout << "Pay at " << setw(25) << payPtr << ": $" << pay << endl;

	// Deallocate memory from pointers
	commissionRatePtr = NULL;
	baseSalaryPtr = NULL;
	overtimeHoursPtr = NULL;
	payPtr = NULL;
	delete commissionRatePtr;
	delete baseSalaryPtr;
	delete overtimeHoursPtr;
	delete payPtr;

	// Wait for output screen
	getch();

	// End program
	return 0;
}

// Function to calculate the employee's pay
double calculatePay(double commission, double salary, double overtime)
{
	// Format output
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout << setprecision(2);

	// Calculate the commission amount
	double commissionAmount = salary * (commission / 100);
	cout << "\nCalculating employee pay..." << endl;
	cout << salary << " * " << setw(8) << commission << "% = " << setw(10) << commissionAmount << endl;

	// Calculate the employee's pay
	double pay = salary + commissionAmount;
	cout << salary << " + " << setw(9) << commissionAmount << " = " << setw(10) << pay << endl;

	// Return the pay value
	return pay;
}
