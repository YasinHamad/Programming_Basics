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
datetime::stDate CompareDates(datetime::stDate date1, datetime::stDate date2) {
	int year_diff = date2.year - date1.year;

	if (year_diff > 0) return date2;
	else if (year_diff < 0) return date1;
	else {
		int days_from_beggining1 = datetime::NumberOfDayInYear(date1.day, date1.month, date1.year);
		int days_from_beggining2 = datetime::NumberOfDayInYear(date2.day, date2.month, date2.year);
		int diff = days_from_beggining2 - days_from_beggining1;
		if (diff > 0) return date2;
		return date1;
	}
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
		//int test_num1 = readers::ReadNumber("Enter a number: ");
		//int test_num2 = readers::ReadNumber("Enter a number: ");
		//int test_num3 = readers::ReadNumber("Enter a number: ");
		/* --------------------------------- VARIABLES --------------------------------- */

		/* --------------------------------- MAIN WORK --------------------------------- */
		datetime::stDate date1, date2;
		date1.day = readers::ReadNumber("Enter the day: ");
		date1.month = readers::ReadNumber("Enter the month: ");
		date1.year = readers::ReadNumber("Enter the year: ");

		date2.day = readers::ReadNumber("Enter the day: ");
		date2.month = readers::ReadNumber("Enter the month: ");
		date2.year = readers::ReadNumber("Enter the year: ");

		cout << datetime::PrintDate(CompareDates(date1, date2), "/");

		/* --------------------------------- MAIN WORK --------------------------------- */


		/* --------------------------------- PRINT --------------------------------- */



		/* --------------------------------- PRINT --------------------------------- */


		/* --------------------------------- DELETE --------------------------------- */
		/* --------------------------------- DELETE --------------------------------- */

		/* --------------------------------- CODE --------------------------------- */
		break;
	}

	return 0;
}