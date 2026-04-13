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
// this function calculate approximatly the diff btw the years
int PeriodLengthInYears(datetime::stPeriod period) {
	return abs(period.starDate.year - period.endDate.year);
}

void SwitchPeriods(datetime::stPeriod& period1, datetime::stPeriod& period2) {
	datetime::stPeriod aux_period = period1;
	period1 = period2;
	period2 = aux_period;
}

int CountOverlapDays(datetime::stPeriod period1, datetime::stPeriod period2) {
	if (!datetime::IsOverlapedPeriods(period1, period2)) return 0;

	int years_length1 = PeriodLengthInYears(period1);
	int years_length2 = PeriodLengthInYears(period2);

	if (years_length1 > years_length2) SwitchPeriods(period1, period2);


	datetime::stDate date = period1.starDate;
	int overlaped_days = 0;


	while (!datetime::IsEqualDates(date, period1.endDate)) {
		if (datetime::IsDateWithinPeriod(date, period2)) overlaped_days++;
		datetime::IncreaseDateByOne(date);
	}
	if (datetime::IsDateWithinPeriod(date, period2)) overlaped_days++;

	return overlaped_days;
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

		datetime::stPeriod period1 = datetime::ReadPeriod();
		datetime::stPeriod period2 = datetime::ReadPeriod();

		cout << CountOverlapDays(period1, period2) << "\n";

		/* --------------------------------- MAIN WORK --------------------------------- */

		/* --------------------------------- DELETE --------------------------------- */
		/* --------------------------------- DELETE --------------------------------- */

		/* --------------------------------- CODE --------------------------------- */
		//break;
	}

	return 0;
}