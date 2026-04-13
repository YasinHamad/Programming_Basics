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

void ReadVectorElements(vector <int>& vector) {
	char check = 'y';
	int new_element = 0;

	while (check == 'y' || check == 'Y') {
		cout << "Enter the new element: ";
		cin >> new_element;

		vector.push_back(new_element);

		cout << "Do you want to add more elements [y/n]: ";
		cin >> check;
	}
}

void PrintVectorElements(vector <int>& vector) {
	for (int element : vector) {
		cout << element << " ";
	}
	cout << endl;
}




int main()
{

	while (true) {

		vector <int> vNumbers;

		ReadVectorElements(vNumbers);

		PrintVectorElements(vNumbers);
		PrintVectorElements(vNumbers);









		break;
	}

	return 0;
}