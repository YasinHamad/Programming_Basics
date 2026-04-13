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
vector<int> IntersectedNumbers(int** matrix_01, int rows_01, int columns_01, int** matrix_02, int rows_02, int columns_02) {
	vector<int> result;
	int temp = 0;
	
	for (int i = 0; i < rows_01; i++) {
		for (int j = 0; j < columns_01; j++) {
			temp = *(*(matrix_01 + i) + j);
			if (math::two_dim_array::DoesNumberExistInMatrix(matrix_02, rows_02, columns_02, temp))
				result.push_back(temp);
		}
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
		int rows = 5;
		int col = 5;

		int** matrix_01 = NULL;
		int** matrix_02 = NULL;
		/* --------------------------------- VARIABLES --------------------------------- */

		/* --------------------------------- MAIN WORK --------------------------------- */
		matrix_01 = allocators::two_dim_array::AllocateTwoDirArray(rows, col);
		matrix_02 = allocators::two_dim_array::AllocateTwoDirArray(rows, col);
		fillers::two_dim_array::FillTwoDimArrayWithRandomNumbers(matrix_01, rows, col, 1, 90);
		fillers::two_dim_array::FillTwoDimArrayWithRandomNumbers(matrix_02, rows, col, 1, 90);
		/* --------------------------------- MAIN WORK --------------------------------- */


		/* --------------------------------- PRINT --------------------------------- */
		//printf("Your matrix %d x %d\n", rows, col);
		
		printers::two_dim_array::PrintTwoDimArray(matrix_01, rows, col, 2);

		cout << endl;

		printers::two_dim_array::PrintTwoDimArray(matrix_02, rows, col, 2);

		cout << endl;

		vector<int> result = IntersectedNumbers(matrix_01, rows, col, matrix_02, rows, col);

		printers::vector_utilities::PrintVector(result);

		//printf("%d", math::two_dim_array::DoesNumberExistInMatrix(matrix_02, rows, col, 2));
		//printf("%d", math::two_dim_array::IsSparceMatrix(matrix_02, rows, col));
		
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