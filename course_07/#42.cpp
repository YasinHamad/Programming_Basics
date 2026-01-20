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
string ReplaceWordInString(string source, string old_word, string new_word) {
	vector<string> strings = manipulators::string_utilities::SplitString(source, " ");

	for (string& str : strings) {
		if (str == old_word) {
			str = new_word;
		}
	}

	return manipulators::string_utilities::JoinString(strings, " ");
}

string ReplaceWordInStringWithBuiltInFunction(string source, string old_word, string new_word) {
	int pos = 0;

	pos = source.find(old_word);

	while (pos != std::string::npos) {
		source.replace(pos, old_word.length(), new_word);
		pos = source.find(old_word);
	}

	return source;
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


		cout << ReplaceWordInStringWithBuiltInFunction(test_str, "yasin", "abu-ibrahim") << endl;


				
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