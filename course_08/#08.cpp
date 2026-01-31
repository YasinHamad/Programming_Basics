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

string GetMonthName(int month) {
	if (month <= 0 || month >= 13) return "";
	string months[12] = {
	"January", "February", "March", "April", "May", "June",
	"July", "August", "September", "October", "November", "December"
	};

	return months[month - 1];
}

void PrintMonthCalender(short year, short month) {
	string month_name = GetMonthName(month);
	int month_days = datetime::GetDaysInMonth(month, year);
	int break_line = 1;

	cout << printers::PrintNameInMiddleOfDashes(40, month_name, "_");
	cout << "\n\n";

	string Days[7]{ "Sun", "Mon", "Tue", "Wed", "Thu", "Fir", "Sat" };
	for (int i = 0; i < 7; i++) {
		cout << Days[i] << "  ";
	}
	cout << "\n";

	break_line = datetime::GetDayOrderInWeek(1, month, year);

	for (int i = 0; i < break_line; i++) {
		cout << printers::FormatedCout(3, "", printers::enPosition::left) << "  ";
	}

	for (int i = 1; i <= month_days; i++) {
		cout << printers::FormatedCout(3, to_string(i), printers::enPosition::left) << "  ";
		break_line++;
		if (break_line % 7 == 0) {
			cout << "\n";
			break_line = 0;
		}
	}



	cout << "\n";
	cout << printers::PrintDashes(40 , "_");
	cout << "\n";
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
		//int test_num3 = readers::ReadNumber("Enter a number: ");
		/* --------------------------------- VARIABLES --------------------------------- */

		/* --------------------------------- MAIN WORK --------------------------------- */
		PrintMonthCalender(test_num1, test_num2);
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