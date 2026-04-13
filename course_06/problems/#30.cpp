#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
#include <vector>
#include <iomanip> // for setw()

#include "readers.h"
#include "printers.h"

using namespace std;

#define SIZE 50

struct stEmployee {
	string first_name;
	string last_name;
	int salary;
};

void ReadEmployees(vector <stEmployee>& vector) {
	char check = 'y';
	stEmployee tmpEmployee;

	while (check == 'y' || check == 'Y') {
		cout << "Enter empoyee's first name: ";
		cin >> tmpEmployee.first_name;

		cout << "Enter empoyee's last name: ";
		cin >> tmpEmployee.last_name;

		cout << "Enter empoyee's salary: ";
		cin >> tmpEmployee.salary;

		vector.push_back(tmpEmployee);

		cout << "Do you want to add more elements [y/n]: ";
		cin >> check;
	}
}

void PrintEmployees(vector <stEmployee>& vector) {
	for (stEmployee& element : vector) {
		cout << "First name: " << element.first_name << endl;
		cout << "Last name: " << element.last_name << endl;
		cout << "Salary: " << element.salary << endl << endl;
	}
	cout << endl;
}


int main()
{

	while (true) {

		vector <stEmployee> vEmployees;

		ReadEmployees(vEmployees);
		PrintEmployees(vEmployees);






		break;
	}

	return 0;
}