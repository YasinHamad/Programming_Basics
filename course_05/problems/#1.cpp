#include <iostream>
#include <cmath>
using namespace std;



float ReadNum(string str) {
    float N;
    cout << str;
    cin >> N;
    return N;
}
float ReadNumInRange(string str, float from, float to) {
	float N;
	do {
		cout << str;
		cin >> N;
	} while (N < from || N > to);
	
	return N;
}
void PrintResult(float num) {
    cout << "*** " << num << " ***" << endl;
}
void PrintResult(float num, string unit) {
	cout << "*** " << num << " " << unit << " ***" << endl;
}
void PrintResult(string result, string unit) {
	cout << "*** " << result << " " << unit << " ***" << endl;
}
void PrintResult(string result) {
	cout << "*** " << result << " ***" << endl;
}

void PrintHeader() {
	cout << "\n\n\t\t\tMultiplication Table From 1 to 10\n\n";
	for (int i = 1; i <= 10; i++) {
		cout << "\t" << i;
	}
	cout << endl;
	for (int i = 0; i < 83; i++) {
		cout << "_";
	}
	cout << endl;
}

string ColumnSeperator(int i) {
	if (i < 10) { return "   |"; }
	else return "  |";
}


void PrintTableBody() {
	for (int i = 1; i <= 10; i++) {
		cout << " " << i << ColumnSeperator(i) << "\t";
		for (int j = 1; j <= 10; j++) {
			cout << i * j << "\t";
		}
		cout << endl;
	}
}

void PrintMultiplicationTable() {
	PrintHeader();
	PrintTableBody();
}



int main()
{
	system("color 0b");

	PrintMultiplicationTable();

	


	

    return 0;
}