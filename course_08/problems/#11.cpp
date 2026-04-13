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
struct stDate {
	int day;
	int month;
	int year;
};

// just returns the date to print
string PrintDate(stDate date, string separator) {
	return to_string(date.day) + separator + to_string(date.month) + separator + to_string(date.year);
}

stDate GetDate(int number_of_day_from_beginning_of_year, int year) {
	stDate date;
	int counter = 0;
	for (int i = 1; i <= 12; i++) {
		number_of_day_from_beginning_of_year -= datetime::GetDaysInMonth(i, year);
		counter++;
		if (number_of_day_from_beginning_of_year <= 31) {
			counter++;
			break;
		}
	}
	date.day = number_of_day_from_beginning_of_year;
	date.year = year;
	date.month = counter;

	return date;
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
		int test_num3 = readers::ReadNumber("Enter a number: ");
		/* --------------------------------- VARIABLES --------------------------------- */

		/* --------------------------------- MAIN WORK --------------------------------- */
	 	cout << PrintDate(GetDate(datetime::NumberOfDayInYear(test_num1, test_num2, test_num3), test_num3), "-");
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