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
string ReplaceWordInString(string source, string old_word, string new_word, bool case_sensetive = true) {
	vector<string> strings = manipulators::string_utilities::SplitString(source, " ");

	string old_word_small = manipulators::string_utilities::LowerString(old_word);

	if (case_sensetive) {
		for (string& str : strings) {
			if (str == old_word) {
				str = new_word;
			}
		}
	}
	else {
		for (string& str : strings) {
			if (manipulators::string_utilities::LowerString(str) == old_word_small) str = new_word;
		}
	}



	return manipulators::string_utilities::JoinString(strings, " ");
}

















/* --------------------------------- FUNCTIONS --------------------------------- */


int main()
{
	while (true) {
		srand((unsigned)time(NULL));
		/* -------------------------------- CODE --------------------------------- */


		/* --------------------------------- VARIABLES --------------------------------- */
		string test_str = readers::ReadASentence("Enter a message please: ");
		//string test_str = "my name is actaully yasin, yasin is my first name, yes yasin";
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


		cout << ReplaceWordInString(test_str, "Yasin", "abu-ibrahim", false) << endl;


				
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