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
datetime::stDate StringToDate(string str_date) {
	vector<string> vec_date = manipulators::string_utilities::Split(str_date, "/");

	datetime::stDate date;
	date.day = stoi(vec_date[0]);
	date.month = stoi(vec_date[1]);
	date.year = stoi(vec_date[2]);

	return date;
}

string DateToString(datetime::stDate date) {
	return datetime::PrintDate(date, "/");
}

datetime::stDate ReadDateAsString() {
	string str_date = "";
	datetime::stDate date;

	cout << "Please enter date dd/mm/yyyy: ";
	cin >> str_date;

	date = StringToDate(str_date);
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
		//int test_num1 = readers::ReadNumber("Enter a number: ");
		//int test_num2 = readers::ReadNumber("Enter a number: ");
		//int test_num3 = readers::ReadNumber("Enter a number: ");
		/* --------------------------------- VARIABLES --------------------------------- */

		/* --------------------------------- MAIN WORK --------------------------------- */
		datetime::stDate date1, date2;

		//date1 = datetime::ReadDate();
		date2 = ReadDateAsString();

		cout << datetime::PrintDate(date2, "-") << "\n";

		cout << DateToString(date2) << "\n";
		
		//cout << datetime::ValidateDate(date1) << "\n";

		/* --------------------------------- MAIN WORK --------------------------------- */

		/* --------------------------------- DELETE --------------------------------- */
		/* --------------------------------- DELETE --------------------------------- */

		/* --------------------------------- CODE --------------------------------- */
		//break;
	}

	return 0;
}