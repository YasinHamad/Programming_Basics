#include <iostream>
#include <cmath>
#include <string>
using namespace std;
float ReadNum(string str) {
	float N;
	cout << str;
	cin >> N;
	return N;
}
float ReadPositiveNum(string str) {
	float N;
	do {
		cout << str;
		cin >> N;
	} while (N <= 0);
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
void PrintResult(int num) {
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
/************************************************/

void NumberPattern(int N) {

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) cout << i;
		cout << endl;
	}
}




int main()
{
	system("color 0b");
	while (1)
	{

		NumberPattern(ReadPositiveNum("Enter the your number: "));




		cout << endl << endl;
	}
	return 0;
}