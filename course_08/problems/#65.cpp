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
enum enFormatString {
	day_month_year_forward_slash,
	year_day_month_forward_slash,
	month_day_year_forward_slash,
	day_month_year_dash,
	year_day_month_dash,
	month_day_year_dash,
	details
};
string FormatDate(datetime::stDate date, enFormatString format) {
	switch(format) {
	case enFormatString::day_month_year_forward_slash: return to_string(date.day) + "/" + to_string(date.month) + "/" + to_string(date.year);
	case enFormatString::year_day_month_forward_slash: return to_string(date.year) + "/" + to_string(date.day) + "/" + to_string(date.month);
	case enFormatString::month_day_year_forward_slash: return to_string(date.month) + "/" + to_string(date.day) + "/" + to_string(date.year);
	case enFormatString::day_month_year_dash: return to_string(date.day) + "-" + to_string(date.month) + "-" + to_string(date.year);
	case enFormatString::year_day_month_dash: return to_string(date.year) + "-" + to_string(date.day) + "-" + to_string(date.month);
	case enFormatString::month_day_year_dash: return to_string(date.month) + "-" + to_string(date.day) + "-" + to_string(date.year);
	default: return "Day:" + to_string(date.month) + ", Month:" + to_string(date.day) + ", Year:" + to_string(date.year);
	};
}

string FormatDate(datetime::stDate date, string date_formated = "dd/mm/yyyy") {
	date_formated = manipulators::string_utilities::ReplaceWordInStringWithBuiltInFunction(date_formated, "dd", to_string(date.day));
	date_formated = manipulators::string_utilities::ReplaceWordInStringWithBuiltInFunction(date_formated, "mm", to_string(date.month));
	date_formated = manipulators::string_utilities::ReplaceWordInStringWithBuiltInFunction(date_formated, "yyyy", to_string(date.year));
	return date_formated;
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

		//date1 = datetime::ReadDate();
		date2 = datetime::ReadDateAsString();
		
		cout << FormatDate(date2, "DAY:dd - MONTH:mm - YEAR:yyyy");

		//cout << datetime::ValidateDate(date1) << "\n";

		/* --------------------------------- MAIN WORK --------------------------------- */

		/* --------------------------------- DELETE --------------------------------- */
		/* --------------------------------- DELETE --------------------------------- */

		/* --------------------------------- CODE --------------------------------- */
		//break;
	}

	return 0;
}