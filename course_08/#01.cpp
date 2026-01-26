#include <iostream>
#include <cmath>
#include <string> // to use the string object
#include <cstdlib>
#include <vector>
#include <cctype> // isupper(), isdigit()
#include <iomanip> // for setw()
//#include <fstream> // for files
//#include <ctime> // for time
#include <print>


//#include <sstream> // for ostringstream oss;

#include "readers.h"
#include "printers.h"
#include "converters.h"
#include "files.h"
#include "datetime.h"
#include "generators.h"
#include "allocators.h"
#include "fillers.h"
#include "manipulators.h"

using namespace std;

#define SIZE 50
const string ACCOUNTS_FILE = "accounts.txt";
/* --------------------------------- FUNCTIONS --------------------------------- */
string NumberToText(int number) {
	if (number >= 0 && number <= 19) {
		string numbers[] = {
			"",
			"One", "Two", "Three", "Four", "Five",
			"Six", "Seven", "Eight", "Nine", "Ten",
			"Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen",
			"Sixteen", "Seventeen", "Eighteen", "Nineteen"
		};
		return numbers[number];
	}

	else if (number >= 20 && number <= 99) {
		string numbers[] = {
			"", "", "Twenty", "Thirty", "Forty",
			"Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
		};
		return numbers[number / 10] + " " + NumberToText(number % 10);
	}

	else if (number <= 999) {
		if(number / 100 == 1) return NumberToText(number / 100) + " Hundred " + NumberToText(number % 100);
		return NumberToText(number / 100) + " Hundreds " + NumberToText(number % 100);
	}

	else if (number <= 999999) {
		if (number / 1000 == 1) return NumberToText(number / 1000) + " Thousand " + NumberToText(number % 1000);
		return NumberToText(number / 1000) + " Thousands " + NumberToText(number % 1000);
	}

	else if (number <= 999999999) {
		if (number / 1000000 == 1) return NumberToText(number / 1000000) + " Million " + NumberToText(number % 1000000);
		return NumberToText(number / 1000000) + " Millions " + NumberToText(number % 1000000);
	}

	else {
		if (number / 1000000000 == 1) return NumberToText(number / 1000000000) + " Billion " + NumberToText(number % 1000000000);
		return NumberToText(number / 1000000000) + " Billions " + NumberToText(number % 1000000000);
	}

	return "null";
}













/* --------------------------------- FUNCTIONS --------------------------------- */


int main()
{
	while (true) {
		srand((unsigned)time(NULL));
		/* -------------------------------- CODE --------------------------------- */
		

		/* --------------------------------- VARIABLES --------------------------------- */
		//string test_str = readers::ReadASentence("Enter a message please: ");
		//string test_str = "my name is actaully yasin, yasin is my first name, yes yasin";
		//char c = readers::ReadChar("Enter your char: ");
		//char* arr = NULL;
		//int arr_size = 0;
		int test_num = readers::ReadNumber("Enter a number: ");
		/* --------------------------------- VARIABLES --------------------------------- */

		/* --------------------------------- MAIN WORK --------------------------------- */
		cout << NumberToText(test_num) << endl;

		/* --------------------------------- MAIN WORK --------------------------------- */


		/* --------------------------------- PRINT --------------------------------- */

						
						
		/* --------------------------------- PRINT --------------------------------- */


		/* --------------------------------- DELETE --------------------------------- */
		/* --------------------------------- DELETE --------------------------------- */

		/* --------------------------------- CODE --------------------------------- */
		//break;
	}

	return 0;
}