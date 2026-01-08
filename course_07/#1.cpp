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
/* ---------------------------------WRITE YOUR FUNCTIONS HERE--------------------------------- */


/* ---------------------------------WRITE YOUR FUNCTIONS HERE--------------------------------- */


int main()
{
	while (true) {
		srand((unsigned)time(NULL));
		/* ---------------------------------WRITE YOUR CODE HERE--------------------------------- */

		int rows = 10;
		int col = 5;

		int** arr = allocators::two_dim_array::AllocateTwoDirArray(rows, col);

		fillers::two_dim_array::FillTwoDimArrayWithRandomNumbers(arr, rows, col, 100, 1000);

		printers::two_dim_array::PrintTwoDimArray(arr, rows, col, 10, printers::enPosition::center);

		allocators::two_dim_array::DeleteTwoDimArray(arr, rows);

		/* ---------------------------------WRITE YOUR CODE HERE--------------------------------- */
		break;
	}

	return 0;
}