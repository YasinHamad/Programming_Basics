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
enum enMatrixSum
{
	rows, columns
};
// Goal: sum the ints in some row in a two dim array
// Inputs: 
//    - the two dim array in heap
//    - number of row you want to add
//    - number of columns in the array	
// Outputs: the summation
int SumRows(int** source, int row_number, int columns) {
	int sum = 0;

	for (int j = 0; j < columns; j++) {
		sum += *(*(source + row_number) + j);
	}

	return sum;
}

// Goal: sum the ints in some column in a two dim array
// Inputs: 
//    - the two dim array in heap
//    - number of rows in the array
//    - number of column you want to add	
// Outputs: the summation
int SumColumns(int** source, int rows, int column_number) {
	int sum = 0;

	for (int i = 0; i < rows; i++) {
		sum += *(*(source + i) + column_number);
	}

	return sum;
}

// Goal: some rows/columns of a two dim array
// Inputs: 
//    - the two dim array in heap
//    - number of rows in the array
//    - number of columns in the array
//    - direction: horizontally or vertically
//    - pointer to an array of ints, to put the results in
//    - int variable to put in the size of the resultant array
// Outputs: the summation
void SumMatrix(int** source, int rows, int columns, enMatrixSum directoin, int*& result, int& result_size) {
	if (enMatrixSum::rows == directoin) {
		result = new int[rows];
		result_size = rows;

		for (int i = 0; i < rows; i++) {
			*(result + i) = SumRows(source, i, columns);
		}
	}
	else {
		result = new int[columns];
		result_size = columns;

		for (int i = 0; i < columns; i++) {
			*(result + i) = SumColumns(source, rows, i);
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
		int rows = 2;
		int col = 2;
		int* result_horizontally = NULL;
		int* result_vertically = NULL;
		int result_horizontally_size = 0;
		int result_vertically_size = 0;
		int** arr = NULL;
		/* --------------------------------- VARIABLES --------------------------------- */

		/* --------------------------------- HEAP ALLOCATION --------------------------------- */
		/* --------------------------------- HEAP ALLOCATION --------------------------------- */


		/* --------------------------------- MAIN WORK --------------------------------- */
		arr = allocators::two_dim_array::AllocateTwoDirArray(rows, col);
		fillers::two_dim_array::FillTwoDimArrayWithRandomNumbers(arr, rows, col, 1, 10);

		SumMatrix(arr, rows, col, enMatrixSum::rows, result_horizontally, result_horizontally_size);
		SumMatrix(arr, rows, col, enMatrixSum::columns, result_vertically, result_vertically_size);
		/* --------------------------------- MAIN WORK --------------------------------- */


		/* --------------------------------- PRINT --------------------------------- */
		printf("Your matrix %d x %d\n", rows, col);
		printers::two_dim_array::PrintTwoDimArray(arr, rows, col, 3, printers::enPosition::left);

		printf("Result horizontally: \n");
		for (int i = 0; i < result_horizontally_size; i++) printf("%d\t", *(result_horizontally + i));
		cout << endl;

		printf("Result vertically: \n");
		for (int i = 0; i < result_vertically_size; i++) printf("%d\t", *(result_vertically + i));
		cout << endl;
		/* --------------------------------- PRINT --------------------------------- */


		/* --------------------------------- DELETE --------------------------------- */
		allocators::two_dim_array::DeleteTwoDimArray(arr, rows);
		delete[] result_horizontally;
		delete[] result_vertically;
		/* --------------------------------- DELETE --------------------------------- */


		/* --------------------------------- CODE --------------------------------- */
		break;
	}

	return 0;
}