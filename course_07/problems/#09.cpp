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










/* --------------------------------- FUNCTIONS --------------------------------- */


int main()
{
	while (true) {
		srand((unsigned)time(NULL));
		/* -------------------------------- CODE --------------------------------- */


		/* --------------------------------- VARIABLES --------------------------------- */
		int rows = 3;
		int col = 3;

		int** matrix_01 = NULL;
		//int** matrix_02 = NULL;

		//int** multiplication_result = NULL;
		/* --------------------------------- VARIABLES --------------------------------- */

		/* --------------------------------- HEAP ALLOCATION --------------------------------- */
		/* --------------------------------- HEAP ALLOCATION --------------------------------- */


		/* --------------------------------- MAIN WORK --------------------------------- */
		matrix_01 = allocators::two_dim_array::AllocateTwoDirArray(rows, col);
		//matrix_02 = allocators::two_dim_array::AllocateTwoDirArray(rows, col);

		//fillers::two_dim_array::FillTwoDimArrayWithOrderdNumbers(arr, rows, col);
		fillers::two_dim_array::FillTwoDimArrayWithRandomNumbers(matrix_01, rows, col, 1, 9);
		//fillers::two_dim_array::FillTwoDimArrayWithRandomNumbers(matrix_02, rows, col, 1, 9);

		int* middleRow = math::two_dim_array::GetRow(matrix_01, rows, col, rows / 2);
		int* middleColumn = math::two_dim_array::GetColumn(matrix_01, rows, col, col / 2);

		//multiplication_result = math::two_dim_array::MuliplyTwoMatrices(matrix_01, rows, col, matrix_02);

		//math::two_dim_array::SumMatrix(arr, rows, col, math::two_dim_array::enMatrixSum::rows, result_horizontally, result_horizontally_size);
		//math::two_dim_array::SumMatrix(arr, rows, col, math::two_dim_array::enMatrixSum::columns, result_vertically, result_vertically_size);
		/* --------------------------------- MAIN WORK --------------------------------- */


		/* --------------------------------- PRINT --------------------------------- */
		printf("Your matrix %d x %d\n", rows, col);
		//printers::two_dim_array::PrintTwoDimArray(matrix_01, rows, col, 3, printers::enPosition::left);

		printers::two_dim_array::PrintTwoDimArray(matrix_01, rows, col, 2);
		
		printers::PrintArray(middleRow, col, "Middle Row:");
		printers::PrintArray(middleColumn, rows, "Middle Column:");
		
		//printf("Your matrix %d x %d\n", rows, col);
		//printers::two_dim_array::PrintTwoDimArray(matrix_02, rows, col, 3, printers::enPosition::left);

		//printf("Your matrix %d x %d\n", rows, col);
		//printers::two_dim_array::PrintTwoDimArray(multiplication_result, rows, col, 3, printers::enPosition::left);



		//printf("Your transposed matrix %d x %d\n", col, rows);
		//printers::two_dim_array::PrintTwoDimArray(transposed_arr, col, rows, 3, printers::enPosition::left);


		//printf("Result horizontally: \n");
		//for (int i = 0; i < result_horizontally_size; i++) printf("%d\t", *(result_horizontally + i));
		//cout << endl;

		//printf("Result vertically: \n");
		//for (int i = 0; i < result_vertically_size; i++) printf("%d\t", *(result_vertically + i));
		//cout << endl;
		/* --------------------------------- PRINT --------------------------------- */


		/* --------------------------------- DELETE --------------------------------- */
		allocators::two_dim_array::DeleteTwoDimArray(matrix_01, rows);
		delete[] middleColumn;
		delete[] middleRow;
		//allocators::two_dim_array::DeleteTwoDimArray(matrix_02, rows);
		//allocators::two_dim_array::DeleteTwoDimArray(multiplication_result, rows);

		//delete[] result_horizontally;
		//delete[] result_vertically;
		/* --------------------------------- DELETE --------------------------------- */


		/* --------------------------------- CODE --------------------------------- */
		break;
	}

	return 0;
}