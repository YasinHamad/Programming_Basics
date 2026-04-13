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

// 01 - Subtracting one day
void DecreaseDateByOne(datetime::stDate& date) {
	if (date.day == 1) {
		if (date.month == 1) {
			date.year--;
			date.month = 12;
			date.day = datetime::GetDaysInMonth(date.month, date.year);
		}
		else {
			date.month--;
			date.day = datetime::GetDaysInMonth(date.month, date.year);
		}
	}
	else {
		date.day--;
	}
}

// 02 - Subtracting 10 days
void DecreaseDateByXDays(int X, datetime::stDate& date) {
	while (X > 0) {
		DecreaseDateByOne(date);
		X--;
	}
}

// 03 - Subtracting one week
void DecreaseDateByOneWeek(datetime::stDate& date) {
	DecreaseDateByXDays(7, date);
}

// 04 - Subtracting 10 weeks
void DecreaseDateByXWeeks(int X, datetime::stDate& date) {
	while (X > 0) {
		DecreaseDateByOneWeek(date);
		X--;
	}
}

// 05 - Subtracting one month
void DecreaseDateByOneMonth(datetime::stDate& date) {
	if (date.month == 1) {
		date.year--;
		date.month = 12;
	}
	else {
		date.month--;
	}

	int current_month_days = datetime::GetDaysInMonth(date.month, date.year);
	if (date.day > current_month_days) {
		date.day = current_month_days;
	}
}

// 06 - Subtracting 5 months
void DecreaseDateByXMonths(int X, datetime::stDate& date) {
	while (X > 0) {
		DecreaseDateByOneMonth(date);
		X--;
	}
}

// 07 - Subtracting one year
void DecreaseDateByOneYear(datetime::stDate& date) {
	DecreaseDateByXMonths(12, date);
}

// 08 - Subtracting 10 years
void DecreaseDateByXYears(int X, datetime::stDate& date) {
	while (X > 0) {
		DecreaseDateByOneYear(date);
		X--;
	}
}

// 09 - Subtracting 10 years (faster)
void DecreaseDateByXYearsFaster(int X, datetime::stDate& date) {
	while (X > 0) {
		if (datetime::IsLeapYear(date.year - 1)) DecreaseDateByOne(date);
		date.year--;
		X--;
	}
}

// 10 - Subtracting one decade
void DecreaseDateByOneDecade(datetime::stDate& date) {
	DecreaseDateByXYears(10, date);
}

// 11 - Subtracting 10 decades
void DecreaseDateByXDecades(int X, datetime::stDate& date) {
	while (X > 0) {
		DecreaseDateByOneDecade(date);
		X--;
	}
}

// 12 - Subtracting 10 decades (faster)
void DecreaseDateByXDecadesFaster(int X, datetime::stDate& date) {
	DecreaseDateByXYearsFaster(X * 10, date);
}

// 13 - Subtracting one century
void DecreaseDateByOneCentury(datetime::stDate& date) {
	DecreaseDateByXDecadesFaster(10, date);
}

// 14 - Subtracting one millennium
void DecreaseDateByOneMillennuim(datetime::stDate& date) {
	for(int i = 1; i<=10; i++) DecreaseDateByOneCentury(date);
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

		// 01 - Subtracting one day
		DecreaseDateByOne(date1);
		cout << "01-Subtracting one day is: " << datetime::PrintDate(date1, "/") << "\n";

		// 02 - Subtracting 10 days
		DecreaseDateByXDays(10, date1);
		cout << "02-Subtracting 10 days is: " << datetime::PrintDate(date1, "/") << "\n";

		// 03 - Subtracting one week
		DecreaseDateByOneWeek(date1);
		cout << "03-Subtracting one week is: " << datetime::PrintDate(date1, "/") << "\n";

		// 04 - Subtracting 10 weeks
		DecreaseDateByXWeeks(10, date1);
		cout << "04 - Subtracting 10 weeks is: " << datetime::PrintDate(date1, "/") << "\n";

		// 05 - Subtracting one month
		DecreaseDateByOneMonth(date1);
		cout << "05 - Subtracting one month is: " << datetime::PrintDate(date1, "/") << "\n";

		// 06 - Subtracting 5 months
		DecreaseDateByXMonths(5, date1);
		cout << "06 - Subtracting 5 months is: " << datetime::PrintDate(date1, "/") << "\n";

		// 07 - Subtracting one year
		DecreaseDateByOneYear(date1);
		cout << "07 - Subtracting one year is: " << datetime::PrintDate(date1, "/") << "\n";

		// 08 - Subtracting 10 years
		DecreaseDateByXYears(10, date1);
		cout << "08 - Subtracting 10 years is: " << datetime::PrintDate(date1, "/") << "\n";

		// 09 - Subtracting 10 years (faster)
		DecreaseDateByXYearsFaster(10, date1);
		cout << "09 - Subtracting 10 years (faster) is: " << datetime::PrintDate(date1, "/") << "\n";

		// 10 - Subtracting one decade
		DecreaseDateByOneDecade(date1);
		cout << "10 - Subtracting one decade is: " << datetime::PrintDate(date1, "/") << "\n";

		// 11 - Subtracting 10 decades
		DecreaseDateByXDecades(10, date1);
		cout << "11 - Subtracting 10 decades is: " << datetime::PrintDate(date1, "/") << "\n";

		// 12 - Subtracting 10 decades (faster)
		DecreaseDateByXDecadesFaster(10, date1);
		cout << "12 - Subtracting 10 decades (faster) is: " << datetime::PrintDate(date1, "/") << "\n";

		// 13 - Subtracting one century
		DecreaseDateByOneCentury(date1);
		cout << "13 - Subtracting one century is: " << datetime::PrintDate(date1, "/") << "\n";

		// 14 - Subtracting one millennium
		DecreaseDateByOneMillennuim(date1);
		cout << "14 - Subtracting one millennium is: " << datetime::PrintDate(date1, "/") << "\n";

		/* --------------------------------- MAIN WORK --------------------------------- */

		/* --------------------------------- DELETE --------------------------------- */
		/* --------------------------------- DELETE --------------------------------- */

		/* --------------------------------- CODE --------------------------------- */
		//break;
	}

	return 0;
}