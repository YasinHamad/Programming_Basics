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
enum enYearTime {Days, Hours, Minutes, Seconds};

int GetYearTime(int year, enYearTime time) {
	int year_days = datetime::IsLeapYear(year) ? 366 : 365;

	switch (time) {
	case enYearTime::Days: return year_days;
	case enYearTime::Hours: return year_days * 24;
	case enYearTime::Minutes: return year_days * 24 * 60;
	case enYearTime::Seconds: return year_days * 24 * 60 * 60;
	default: return -1;
	}
}

int NumberOfDaysInYear(int year) {
	return datetime::IsLeapYear(year) ? 366 : 365;
}
int NumberOfHoursInYear(int year) {
	return NumberOfDaysInYear(year) * 24;
}
int NumberOfMinutesInYear(int year) {
	return NumberOfHoursInYear(year) * 60;
}
int NumberOfSecondsInYear(int year) {
	return NumberOfMinutesInYear(year) * 60;
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
		cout << "Number of Days in Year ["<< test_num <<"]    " << "is " << NumberOfDaysInYear(test_num) << "\n";
		cout << "Number of Hours in Year [" << test_num << "]   " << "is " << NumberOfHoursInYear(test_num) << "\n";
		cout << "Number of Minutes in Year [" << test_num << "] " << "is " << NumberOfMinutesInYear(test_num) << "\n";
		cout << "Number of Seconds in Year [" << test_num << "] " << "is " << NumberOfSecondsInYear(test_num) << "\n";
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