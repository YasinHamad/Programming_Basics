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
bool IsMatrixIdentity(int** matrix, int rows, int columns) {
	int temp = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			temp = *(*(matrix + i) + j);
			if (i == j) {
				if (temp != 1) return false;
			} 
			else if (temp != 0) return false;
			temp = 0;
		}
	}
	return true;
}

void FillIdentityMatrix(int** matrix, int rows, int columns) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if (i == j) *(*(matrix + i) + j) = 1;
			else *(*(matrix + i) + j) = 0;
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
		int rows = 3;
		int col = 5;

		int** matrix_01 = NULL;
		int** matrix_02 = NULL;
		/* --------------------------------- VARIABLES --------------------------------- */

		/* --------------------------------- MAIN WORK --------------------------------- */
		matrix_01 = allocators::two_dim_array::AllocateTwoDirArray(rows, col);
		matrix_02 = allocators::two_dim_array::AllocateTwoDirArray(rows, col);
		FillIdentityMatrix(matrix_01, rows, col);
		fillers::two_dim_array::FillTwoDimArrayWithOrderdNumbers(matrix_02, rows, col);
		/* --------------------------------- MAIN WORK --------------------------------- */


		/* --------------------------------- PRINT --------------------------------- */
		//printf("Your matrix %d x %d\n", rows, col);
		
		printers::two_dim_array::PrintTwoDimArray(matrix_01, rows, col, 2);
		printers::two_dim_array::PrintTwoDimArray(matrix_02, rows, col, 2);

		printf("%d", IsMatrixIdentity(matrix_01, rows, col));
		printf("%d", IsMatrixIdentity(matrix_02, rows, col));
		
		/* --------------------------------- PRINT --------------------------------- */


		/* --------------------------------- DELETE --------------------------------- */
		allocators::two_dim_array::DeleteTwoDimArray(matrix_01, rows);
		allocators::two_dim_array::DeleteTwoDimArray(matrix_02, rows);
		/* --------------------------------- DELETE --------------------------------- */


		/* --------------------------------- CODE --------------------------------- */
		break;
	}

	return 0;
}