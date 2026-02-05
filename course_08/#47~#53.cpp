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

int DayOfWeekOrder(datetime::stDate date) {
	return datetime::GetDayOrderInWeek(date.day, date.month, date.year);
}

string PrintDateLong(datetime::stDate date) {
	return "Today is " + datetime::GetDayName(DayOfWeekOrder(date)) + " , " + datetime::PrintDate(date, "/");
}

bool IsEndOfWeek(datetime::stDate date) {
	return DayOfWeekOrder(date) == 6;
}

bool IsItWeekend(datetime::stDate date) {
	int day_order = DayOfWeekOrder(date);
	return (day_order == 6 || day_order == 5);
}

bool IsBusinessDay(datetime::stDate date) {
	return !IsItWeekend(date);
}

int DaysUntilTheEndOfWeek(datetime::stDate date) {
	return (6 - DayOfWeekOrder(date));
}

int DaysUntilTheEndOfMonth(datetime::stDate date) {
	datetime::stDate last_day_date;

	last_day_date.day = datetime::GetDaysInMonth(date.month, date.year);
	last_day_date.month = date.month;
	last_day_date.year = date.year;

	return datetime::DifferentBtwDatesInDays(date, last_day_date, true);
}

int DaysUntilTheEndOfYear(datetime::stDate date) {
	return (datetime::NumberOfDaysInYear(date.year) - datetime::NumberOfDayInYear(date.day, date.month, date.year));
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
		datetime::stDate date1;
		date1.day = readers::ReadNumber("Enter the day: ");
		date1.month = readers::ReadNumber("Enter the month: ");
		date1.year = readers::ReadNumber("Enter the year: ");

		cout << datetime::PrintDate(date1, "/") << "\n\n\n";

		cout << PrintDateLong(date1) << "\n\n";

		cout << "Is it end of week?" << "\n";
		cout << (IsEndOfWeek(date1) ? "Yes it is end of week." : "No it is not end of week.");
		cout << "\n\n";

		cout << "Is it weekend?" << "\n";
		cout << (IsItWeekend(date1) ? "Yes it is weekend." : "No it is not weekend.");
		cout << "\n\n";

		cout << "Is it a business day?" << "\n";
		cout << (IsBusinessDay(date1) ? "Yes it is a business day." : "No it is not a business day.");
		cout << "\n\n";

		cout << "Days until end of week: " << DaysUntilTheEndOfWeek(date1) << " Day(s)" << "\n";
		cout << "Days until end of month: " << DaysUntilTheEndOfMonth(date1) << " Day(s)" << "\n";
		cout << "Days until end of year: " << DaysUntilTheEndOfYear(date1) << " Day(s)" << "\n";




		/* --------------------------------- MAIN WORK --------------------------------- */

		/* --------------------------------- DELETE --------------------------------- */
		/* --------------------------------- DELETE --------------------------------- */

		/* --------------------------------- CODE --------------------------------- */
		//break;
	}

	return 0;
}