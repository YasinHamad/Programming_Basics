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
bool IsArrayPalindrom(int* source, int size) {
	if (size == 0) return false;

	for (int s = 0, e = size - 1; s < e; s++, e--) {
		if (*(source + s) != *(source + e)) return false;
	}
	return true;
}

bool IsMatrixPalindrom(int** matrix, int rows, int columns) {
	for (int i = 0; i < rows; i++) {
		if (!IsArrayPalindrom(*(matrix + i), columns)) return false;
	}
	return true;
}

void FillPalindromMatrix(int** matrix, int rows, int columns, int random_numbers_start, int random_numbers_end) {
	int temp = 0;
	for (int i = 0; i < rows; i++) {
		for (int s = 0, e=columns-1; s<=e; s++,e--) {
			temp = generators::RandomNumber(random_numbers_start, random_numbers_end);
			*(*(matrix + i) + s) = *(*(matrix + i) + e) = temp;
		}
	}
}










/* --------------------------------- FUNCTIONS --------------------------------- */


int main()
{
	while (true) {
		srand((unsigned)time(NULL));
		/* -------------------------------- CODE --------------------------------- */


		/* --------------------------------- VARIABLES --------------------------------- */
		int rows = 5;
		int col = 7;

		//int** matrix_01 = NULL;
		int** matrix_02 = NULL;
		/* --------------------------------- VARIABLES --------------------------------- */

		/* --------------------------------- MAIN WORK --------------------------------- */
		//matrix_01 = allocators::two_dim_array::AllocateTwoDirArray(rows, col);
		matrix_02 = allocators::two_dim_array::AllocateTwoDirArray(rows, col);
		//fillers::two_dim_array::FillTwoDimArrayWithRandomNumbers(matrix_01, rows, col, 1, 9);
		FillPalindromMatrix(matrix_02, rows, col, 1, 90);

		//*(*(matrix_02 + 1) + 4) = 3;

		/* --------------------------------- MAIN WORK --------------------------------- */


		/* --------------------------------- PRINT --------------------------------- */
		//printers::two_dim_array::PrintTwoDimArray(matrix_01, rows, col, 2);

		//cout << endl;

		printers::two_dim_array::PrintTwoDimArray(matrix_02, rows, col, 2);

		cout << endl;

		//printers::vector_utilities::PrintVector(result);

		//printf("%d", math::two_dim_array::MinNumberInMatrix(matrix_01, rows, col));
		printf("%d", IsMatrixPalindrom(matrix_02, rows, col));
		
		/* --------------------------------- PRINT --------------------------------- */


		/* --------------------------------- DELETE --------------------------------- */
		//allocators::two_dim_array::DeleteTwoDimArray(matrix_01, rows);
		allocators::two_dim_array::DeleteTwoDimArray(matrix_02, rows);
		/* --------------------------------- DELETE --------------------------------- */


		/* --------------------------------- CODE --------------------------------- */
		break;
	}

	return 0;
}