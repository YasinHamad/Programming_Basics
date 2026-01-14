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

using namespace std;

#define SIZE 50
/* --------------------------------- FUNCTIONS --------------------------------- */
vector<char> FirstLetterOfEachWord(string source) {
	vector<char> result;

	bool is_first_letter = true;

	for (int i = 0; i < source.length(); i++) {
		if (source[i] != ' ' && is_first_letter) result.push_back(source[i]);
		is_first_letter = source[i] == ' ' ? true : false;
	}

	return result;
}













/* --------------------------------- FUNCTIONS --------------------------------- */


int main()
{
	while (true) {
		srand((unsigned)time(NULL));
		/* -------------------------------- CODE --------------------------------- */


		/* --------------------------------- VARIABLES --------------------------------- */
		string test_str = readers::ReadASentence("Enter a message please: ");
		//char* arr = NULL;
		//int arr_size = 0;
		/* --------------------------------- VARIABLES --------------------------------- */

		/* --------------------------------- MAIN WORK --------------------------------- */
		vector<char> test_vec = FirstLetterOfEachWord(test_str);

		printers::vector_utilities::PrintVectorOfChars(test_vec);
		
		/* --------------------------------- MAIN WORK --------------------------------- */


		/* --------------------------------- PRINT --------------------------------- */

				
		/* --------------------------------- PRINT --------------------------------- */


		/* --------------------------------- DELETE --------------------------------- */
		//delete[] arr;
		/* --------------------------------- DELETE --------------------------------- */


		/* --------------------------------- CODE --------------------------------- */
		break;
	}

	return 0;
}