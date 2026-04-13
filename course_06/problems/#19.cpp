#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
#include "readers.h"
using namespace std;
#define SIZE 50

void PrintNumbers(int start, int end) {
	if (start <= end) {
		cout << start << endl;
		PrintNumbers(start + 1, end);
	}
}
int Power(int a, int b) {
	if (b == 0) return 1;
	return a * Power(a, b - 1);
}

int main()
{

	while (true) {

		PrintNumbers(1, 5);
		cout << Power(5, 5) << endl;

		break;
	}

	return 0;
}