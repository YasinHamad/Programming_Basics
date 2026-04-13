#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
#include "readers.h"
using namespace std;
#define SIZE 50

string CheckNumber(int number) {
	return (number >= 0) ?
		((number == 0) ? "Zero\n" : "Positive\n") :
		"Negative\n";
}

int main()
{

	while (true) {
		cout << CheckNumber(readers::ReadNum("Enter a number to check: "));

		//break;
	}

	return 0;
}