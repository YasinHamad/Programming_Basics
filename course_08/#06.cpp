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
int GetDaysInMonth(int month, int year) {
	if (month <= 0 || month >= 13) return 0;
	int NumberOfDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	return (month == 2) ? (datetime::IsLeapYear(year) ? 29 : 28) : NumberOfDays[month - 1];
}

int GetHoursInMonth(int month, int year) {
	return GetDaysInMonth(month, year) * 24;
}

int GetMinutesInMonth(int month, int year) {
	return GetHoursInMonth(month, year) * 60;
}

int GetSecondsInMonth(int month, int year) {
	return GetMinutesInMonth(month, year) * 60;
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
		int test_num1 = readers::ReadNumber("Enter a number: ");
		int test_num2 = readers::ReadNumber("Enter a number: ");
		/* --------------------------------- VARIABLES --------------------------------- */

		/* --------------------------------- MAIN WORK --------------------------------- */
		cout << "Number of Days in Month ["<< test_num1 <<"]       " << "is " << GetDaysInMonth(test_num1, test_num2) << "\n";
		cout << "Number of Hours in Month ["<< test_num1 <<"]      " << "is " << GetHoursInMonth(test_num1, test_num2) << "\n";
		cout << "Number of Minutes in Month ["<< test_num1 <<"]    " << "is " << GetMinutesInMonth(test_num1, test_num2) << "\n";
		cout << "Number of Seconds in Month ["<< test_num1 <<"]    " << "is " << GetSecondsInMonth(test_num1, test_num2) << "\n";
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