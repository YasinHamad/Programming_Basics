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
/* --------------------------------- FUNCTIONS --------------------------------- */
string ReversStringWords(string source, string separator) {
	vector<string> strings = manipulators::string_utilities::SplitString(source, separator);
	string result = "";

	vector<string>::iterator itor = strings.end();

	while (itor != strings.begin()) {
		itor--;
		result += *itor;
		result += separator;
	 }

	return result.substr(0, result.length() - separator.length());
}

















/* --------------------------------- FUNCTIONS --------------------------------- */


int main()
{
	while (true) {
		srand((unsigned)time(NULL));
		/* -------------------------------- CODE --------------------------------- */


		/* --------------------------------- VARIABLES --------------------------------- */
		string test_str = readers::ReadASentence("Enter a message please: ");
		//string test_str = "   yasin   ";
		//char c = readers::ReadChar("Enter your char: ");
		//char* arr = NULL;
		//int arr_size = 0;
		/* --------------------------------- VARIABLES --------------------------------- */

		/* --------------------------------- MAIN WORK --------------------------------- */
		
		//vector<string> strings = { "word1", "word2", "word3" };

		//string* strs = new string[4];
		//strs[0] = "ww0";
		//strs[1] = "ww1";
		//strs[2] = "ww2";
		//strs[3] = "ww3";


		cout << ReversStringWords(test_str, " ");

				
		/* --------------------------------- MAIN WORK --------------------------------- */


		/* --------------------------------- PRINT --------------------------------- */

						
						
		/* --------------------------------- PRINT --------------------------------- */


		/* --------------------------------- DELETE --------------------------------- */
		/* --------------------------------- DELETE --------------------------------- */
		//delete[] strs;

		/* --------------------------------- CODE --------------------------------- */
		break;
	}

	return 0;
}