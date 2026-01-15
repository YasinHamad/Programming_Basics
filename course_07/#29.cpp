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
enum enLetterType {LowerLetter,CapitalLetter};

int CountCapitalLetters(string source) {
	int count = 0;
	for (int i = 0; i < source.length(); i++) if (isupper(source[i])) count++;
	return count;
}

int CountLowerLetters(string source) {
	int count = 0;
	for (int i = 0; i < source.length(); i++) if (islower(source[i])) count++;
	return count;
}

int CountLetters(string source, enLetterType letter_type) {
	int count = 0;

	if (enLetterType::CapitalLetter == letter_type) {
		for (int i = 0; i < source.length(); i++) if (isupper(source[i])) count++;
	}
	else {
		for (int i = 0; i < source.length(); i++) if (islower(source[i])) count++;
	}

	return count;
}















/* --------------------------------- FUNCTIONS --------------------------------- */


int main()
{
	while (true) {
		srand((unsigned)time(NULL));
		/* -------------------------------- CODE --------------------------------- */


		/* --------------------------------- VARIABLES --------------------------------- */
		string test_str = readers::ReadASentence("Enter a message please: ");
		//char c = readers::ReadChar("Enter your char: ");
		//char* arr = NULL;
		//int arr_size = 0;
		/* --------------------------------- VARIABLES --------------------------------- */

		/* --------------------------------- MAIN WORK --------------------------------- */
		//vector<char> test_vec = manipulators::string_utilities::FirstLetterOfEachWord(test_str);

		//printers::vector_utilities::PrintVectorOfChars(test_vec);
		//LowerString(test_str);
		//InvertStringChars(test_str);
		//manipulators::string_utilities::InvertStringChars(test_str);
		
		/* --------------------------------- MAIN WORK --------------------------------- */


		/* --------------------------------- PRINT --------------------------------- */
		//cout << test_str;
		//cout << c;
				
		cout << "String length: " << test_str.length() << "\n";
		cout << "String capital letters number: " << CountLetters(test_str, enLetterType::CapitalLetter) << "\n";
		cout << "String lower letters number: " << CountLetters(test_str, enLetterType::LowerLetter) << "\n";

		/* --------------------------------- PRINT --------------------------------- */


		/* --------------------------------- DELETE --------------------------------- */
		//delete[] arr;
		/* --------------------------------- DELETE --------------------------------- */


		/* --------------------------------- CODE --------------------------------- */
		break;
	}

	return 0;
}