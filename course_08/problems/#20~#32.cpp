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

// 01 - Adding one day
// already implemented

// 02 - Adding 10 days
void IncreaseDateByXDays(int X, datetime::stDate& date) {
	while (X > 0) {
		datetime::IncreaseDateByOne(date);
		X--;
	}
}

// 03 - Adding one week
void IncreaseDateByOneWeek(datetime::stDate& date) {
	IncreaseDateByXDays(7, date);
}

// 04 - Adding 10 weeks
void IncreaseDateByXWeeks(int X, datetime::stDate& date) {
	while (X > 0) {
		IncreaseDateByOneWeek(date);
		X--;
	}
}

// 05 - Adding one month
void IncreaseDateByOneMonth(datetime::stDate& date) {
	if (datetime::IsLastMonthInYear(date)) {
		date.year++;
		date.month = 1;
	}
	else {
		date.month++;
	}

	int current_month_days = datetime::GetDaysInMonth(date.month, date.year);
	if (date.day > current_month_days) {
		date.day = current_month_days;
	}
}

// 06 - Adding 5 months
void IncreaseDateByXMonths(int X, datetime::stDate& date) {
	while (X > 0) {
		IncreaseDateByOneMonth(date);
		X--;
	}
}

// 07 - Adding one year
void IncreaseDateByOneYear(datetime::stDate& date) {
	IncreaseDateByXMonths(12, date);
}

// 08 - Adding 10 years
void IncreaseDateByXYears(int X, datetime::stDate& date) {
	while (X > 0) {
		IncreaseDateByOneYear(date);
		X--;
	}
}

// 09 - Adding 10 years (faster)
void IncreaseDateByXYearsFaster(int X, datetime::stDate& date) {
	while (X > 0) {
		if (datetime::IsLeapYear(date.year + 1)) datetime::IncreaseDateByOne(date);
		date.year++;
		X--;
	}
}

// 10 - Adding one decade
void IncreaseDateByOneDecade(datetime::stDate& date) {
	IncreaseDateByXYears(10, date);
}

// 11 - Adding 10 decades
void IncreaseDateByXDecades(int X, datetime::stDate& date) {
	while (X > 0) {
		IncreaseDateByOneDecade(date);
		X--;
	}
}

// 12 - Adding 10 decades (faster)
void IncreaseDateByXDecadesFaster(int X, datetime::stDate& date) {
	IncreaseDateByXYearsFaster(X * 10, date);
}

// 13 - Adding one century
void IncreaseDateByOneCentury(datetime::stDate& date) {
	IncreaseDateByXDecadesFaster(10, date);
}

// 14 - Adding one millennium
void IncreaseDateByOneMillennuim(datetime::stDate& date) {
	for(int i = 1; i<=10; i++) IncreaseDateByOneCentury(date);
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

		// 01 - Adding one day
		datetime::IncreaseDateByOne(date1);
		cout << "01-Adding one day is: " << datetime::PrintDate(date1, "/") << "\n";

		// 02 - Adding 10 days
		IncreaseDateByXDays(10, date1);
		cout << "02-Adding 10 days is: " << datetime::PrintDate(date1, "/") << "\n";

		// 03 - Adding one week
		IncreaseDateByOneWeek(date1);
		cout << "03-Adding one week is: " << datetime::PrintDate(date1, "/") << "\n";

		// 04 - Adding 10 weeks
		IncreaseDateByXWeeks(10, date1);
		cout << "04 - Adding 10 weeks is: " << datetime::PrintDate(date1, "/") << "\n";

		// 05 - Adding one month
		IncreaseDateByOneMonth(date1);
		cout << "05 - Adding one month is: " << datetime::PrintDate(date1, "/") << "\n";

		// 06 - Adding 5 months
		IncreaseDateByXMonths(5, date1);
		cout << "06 - Adding 5 months is: " << datetime::PrintDate(date1, "/") << "\n";

		// 07 - Adding one year
		IncreaseDateByOneYear(date1);
		cout << "07 - Adding one year is: " << datetime::PrintDate(date1, "/") << "\n";

		// 08 - Adding 10 years
		IncreaseDateByXYears(10, date1);
		cout << "08 - Adding 10 years is: " << datetime::PrintDate(date1, "/") << "\n";

		// 09 - Adding 10 years (faster)
		IncreaseDateByXYearsFaster(10, date1);
		cout << "09 - Adding 10 years (faster) is: " << datetime::PrintDate(date1, "/") << "\n";

		// 10 - Adding one decade
		IncreaseDateByOneDecade(date1);
		cout << "10 - Adding one decade is: " << datetime::PrintDate(date1, "/") << "\n";

		// 11 - Adding 10 decades
		IncreaseDateByXDecades(10, date1);
		cout << "11 - Adding 10 decades is: " << datetime::PrintDate(date1, "/") << "\n";

		// 12 - Adding 10 decades (faster)
		IncreaseDateByXDecadesFaster(10, date1);
		cout << "12 - Adding 10 decades (faster) is: " << datetime::PrintDate(date1, "/") << "\n";

		// 13 - Adding one century
		IncreaseDateByOneCentury(date1);
		cout << "13 - Adding one century is: " << datetime::PrintDate(date1, "/") << "\n";

		// 14 - Adding one millennium
		IncreaseDateByOneMillennuim(date1);
		cout << "14 - Adding one millennium is: " << datetime::PrintDate(date1, "/") << "\n";

		/* --------------------------------- MAIN WORK --------------------------------- */

		/* --------------------------------- DELETE --------------------------------- */
		/* --------------------------------- DELETE --------------------------------- */

		/* --------------------------------- CODE --------------------------------- */
		//break;
	}

	return 0;
}