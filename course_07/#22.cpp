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

void CalculateFibonacciRecHelper(int size, int prev01, int prev02, int* cell) {
	if (size == 0) return;
	*cell = prev01 + prev02;
	CalculateFibonacciRecHelper(size-1, prev02, *cell, cell + 1);
}

int* CalculateFibonacciRec(int size) {
	int* result = new int[size];
	CalculateFibonacciRecHelper(size, 1, 0, result);
	return result;
}












/* --------------------------------- FUNCTIONS --------------------------------- */


int main()
{
	while (true) {
		srand((unsigned)time(NULL));
		/* -------------------------------- CODE --------------------------------- */


		/* --------------------------------- VARIABLES --------------------------------- */
		//int rows = 5;
		//int col = 7;
		int size = readers::ReadPositiveNumber("Enter a positive number: ");
		//int size = 11;

		int* arr = NULL;

		//int** matrix_01 = NULL;
		//int** matrix_02 = NULL;
		/* --------------------------------- VARIABLES --------------------------------- */

		/* --------------------------------- MAIN WORK --------------------------------- */
		//matrix_01 = allocators::two_dim_array::AllocateTwoDirArray(rows, col);
		//matrix_02 = allocators::two_dim_array::AllocateTwoDirArray(rows, col);
		//fillers::two_dim_array::FillTwoDimArrayWithRandomNumbers(matrix_01, rows, col, 1, 9);
		//fillers::two_dim_array::FillPalindromMatrix(matrix_02, rows, col, 1, 90);

		//*(*(matrix_02 + 1) + 4) = 3;

		//arr = CalculateFibonacciRec(size);

		arr = CalculateFibonacciRec(size);

		/* --------------------------------- MAIN WORK --------------------------------- */


		/* --------------------------------- PRINT --------------------------------- */
		//printers::two_dim_array::PrintTwoDimArray(matrix_01, rows, col, 2);

		printers::PrintArray(arr, size, "Your Fibonacci");

		cout << endl;

		//printers::two_dim_array::PrintTwoDimArray(matrix_02, rows, col, 2);

		//cout << endl;

		//printers::vector_utilities::PrintVector(result);

		//printf("%d", math::two_dim_array::MinNumberInMatrix(matrix_01, rows, col));
		//printf("%d", math::two_dim_array::IsMatrixPalindrom(matrix_02, rows, col));
		
		/* --------------------------------- PRINT --------------------------------- */


		/* --------------------------------- DELETE --------------------------------- */
		//allocators::two_dim_array::DeleteTwoDimArray(matrix_01, rows);
		//allocators::two_dim_array::DeleteTwoDimArray(matrix_02, rows);
		delete[] arr;
		/* --------------------------------- DELETE --------------------------------- */


		/* --------------------------------- CODE --------------------------------- */
		break;
	}

	return 0;
}