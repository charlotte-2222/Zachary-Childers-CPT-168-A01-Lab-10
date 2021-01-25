// Zachary-Childers-CPT-168-A01-Lab-10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//Was unable to do this on my own,
//This Sln is from Alimagham
//-- Zach Childers


#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main()
{
	system("color b0");
	ifstream labFile;
	labFile.open("labtencpt.txt");
	int cntr = 0;
	string firstName, lastName, ssn;
	double hrs, rate, grossPay, totalDeduct, netPay;

	cout << fixed << setprecision(2);
	cout << "\t\t\t*****************************\n";
	cout << "\t\t\t*      Zachary Childers     *\n";
	cout << "\t\t\t*     CPT-168-A01 or A02    *\n";
	cout << "\t\t\t*  Payroll Sequential File  *\n";
	cout << "\t\t\t*****************************\n\n";

	labFile >> firstName >> lastName >> ssn >> hrs >> rate;
	cout << "   SSN  \tName\t\tHours\tRate\tGross\tDeductions\tNetPay" << endl << endl;     //Headings
	cout << "   ____ \t____________\t_____\t____\t_____\t__________\t______" << endl << endl;   // Headings
	while (labFile.eof() == false)
	{
		if (hrs > 40)
			grossPay = (((hrs - 40) * 1.5) + 40)* rate;
		else
			grossPay = hrs * rate;

		totalDeduct = grossPay * .1;
		netPay = grossPay - totalDeduct;
		cntr++;
		cout << "   " << ssn.substr(7) << " \t" << firstName.substr(0, 1) << ". " << lastName << "    \t" << hrs << "\t" << rate << "\t" << grossPay << "\t" << totalDeduct << "\t\t" << netPay << endl;
		labFile >> firstName >> lastName >> ssn >> hrs >> rate;
	}
	cout << "\n\n\tNumber of records: " << cntr << endl << endl;
	cout << "\n\t\t\t\t T H A N K   Y O U" << endl << endl;
	labFile.close();
	system("PAUSE");
	return 0;
}