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

void FillCurrentMonth(datetime::stDate& date, int& days_to_add) {
	int current_month_days = datetime::GetDaysInMonth(date.month, date.year);
	int remaining_days_to_fill_month = current_month_days - date.day;

	if (days_to_add == 0) return;
	else if (days_to_add <= remaining_days_to_fill_month) {
		date.day += days_to_add;
		days_to_add = 0;
		return;
	}
	else {
		if (remaining_days_to_fill_month == 0) {
			if (date.month == 12) {
				date.month = 1;
				date.year++;
			}
			else {
				date.month++;
			}
			date.day = 0;
			FillCurrentMonth(date, days_to_add);
			return;
		}
		date.day += remaining_days_to_fill_month;
		days_to_add -= remaining_days_to_fill_month;
	}
}

void AddDaysToDate(datetime::stDate& date, int days_to_add) {
	while (days_to_add != 0) {
		FillCurrentMonth(date, days_to_add);
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
		datetime::stDate date;
		date.day = readers::ReadNumber("Enter the day: ");
		date.month = readers::ReadNumber("Enter the month: ");
		date.year = readers::ReadNumber("Enter the year: ");
		int days_to_add = readers::ReadNumber("Enter days to add: ");

		AddDaysToDate(date, days_to_add);

		cout << datetime::PrintDate(date, "/");

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