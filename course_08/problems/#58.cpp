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
struct stPeriod {
	datetime::stDate starDate;
	datetime::stDate endDate;
};

bool IsOverlapedPeriods(stPeriod period1, stPeriod period2) {
	return !(datetime::IsDate1BeforeDate2(period1.endDate, period2.starDate) || 
		datetime::IsDate1BeforeDate2(period2.endDate, period1.starDate));
}

stPeriod ReadPeriod() {
	stPeriod period;
	cout << "Filling a period:" << "\n";
	cout << "Filling start date:" << "\n\n";

	cout << "Enter a date: ";
	cin >> period.starDate.day;

	cout << "Enter a month: ";
	cin >> period.starDate.month;

	cout << "Enter a year: ";
	cin >> period.starDate.year;
	cout << "\n";

	cout << "Filling end date:" << "\n\n";

	cout << "Enter a date: ";
	cin >> period.endDate.day;

	cout << "Enter a month: ";
	cin >> period.endDate.month;

	cout << "Enter a year: ";
	cin >> period.endDate.year;
	cout << "\n";

	return period;
}

string PrintPeriod(stPeriod period) {
	return datetime::PrintDate(period.starDate, "/") + " ~~ " + datetime::PrintDate(period.endDate, "/");
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
		//datetime::stDate date1, date2;
		//date1.day = readers::ReadNumber("Enter the day: ");
		//date1.month = readers::ReadNumber("Enter the month: ");
		//date1.year = readers::ReadNumber("Enter the year: ");

		//date2.day = readers::ReadNumber("Enter the day: ");
		//date2.month = readers::ReadNumber("Enter the month: ");
		//date2.year = readers::ReadNumber("Enter the year: ");
		//cout << "\n";

		stPeriod period1 = ReadPeriod();
		stPeriod period2 = ReadPeriod();

		cout << IsOverlapedPeriods(period1, period2) << "\n";

		/* --------------------------------- MAIN WORK --------------------------------- */

		/* --------------------------------- DELETE --------------------------------- */
		/* --------------------------------- DELETE --------------------------------- */

		/* --------------------------------- CODE --------------------------------- */
		//break;
	}

	return 0;
}