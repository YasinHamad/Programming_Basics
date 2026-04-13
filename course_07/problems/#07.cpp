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
int** TransposedMatrix(int** source, int rows, int columns) {
	if (rows == 0 || columns == 0) return NULL;
	int** result;

	result = allocators::two_dim_array::AllocateTwoDirArray(columns, rows);

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			*(*(result + j) + i) = *(*(source + i) + j);
		}
	}

	return result;
}



/* --------------------------------- FUNCTIONS --------------------------------- */


int main()
{
	while (true) {
		//srand((unsigned)time(NULL));
		/* -------------------------------- CODE --------------------------------- */


		/* --------------------------------- VARIABLES --------------------------------- */
		int rows = 5;
		int col = 7;
		//int* result_horizontally = NULL;
		//int* result_vertically = NULL;
		//int result_horizontally_size = 0;
		//int result_vertically_size = 0;
		int** arr = NULL;
		int** transposed_arr = NULL;
		/* --------------------------------- VARIABLES --------------------------------- */

		/* --------------------------------- HEAP ALLOCATION --------------------------------- */
		/* --------------------------------- HEAP ALLOCATION --------------------------------- */


		/* --------------------------------- MAIN WORK --------------------------------- */
		arr = allocators::two_dim_array::AllocateTwoDirArray(rows, col);
		fillers::two_dim_array::FillTwoDimArrayWithOrderdNumbers(arr, rows, col);
		//fillers::two_dim_array::FillTwoDimArrayWithRandomNumbers(arr, rows, col, 1, 10);

		transposed_arr = TransposedMatrix(arr, rows, col);

		//math::two_dim_array::SumMatrix(arr, rows, col, math::two_dim_array::enMatrixSum::rows, result_horizontally, result_horizontally_size);
		//math::two_dim_array::SumMatrix(arr, rows, col, math::two_dim_array::enMatrixSum::columns, result_vertically, result_vertically_size);
		/* --------------------------------- MAIN WORK --------------------------------- */


		/* --------------------------------- PRINT --------------------------------- */
		printf("Your matrix %d x %d\n", rows, col);
		printers::two_dim_array::PrintTwoDimArray(arr, rows, col, 3, printers::enPosition::left);

		printf("Your transposed matrix %d x %d\n", col, rows);
		printers::two_dim_array::PrintTwoDimArray(transposed_arr, col, rows, 3, printers::enPosition::left);


		//printf("Result horizontally: \n");
		//for (int i = 0; i < result_horizontally_size; i++) printf("%d\t", *(result_horizontally + i));
		//cout << endl;

		//printf("Result vertically: \n");
		//for (int i = 0; i < result_vertically_size; i++) printf("%d\t", *(result_vertically + i));
		//cout << endl;
		/* --------------------------------- PRINT --------------------------------- */


		/* --------------------------------- DELETE --------------------------------- */
		allocators::two_dim_array::DeleteTwoDimArray(arr, rows);
		allocators::two_dim_array::DeleteTwoDimArray(transposed_arr, col);
		//delete[] result_horizontally;
		//delete[] result_vertically;
		/* --------------------------------- DELETE --------------------------------- */


		/* --------------------------------- CODE --------------------------------- */
		break;
	}

	return 0;
}