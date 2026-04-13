#include <iostream>
#include <cmath>
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



int ReverseNumber(int N) {

	int res = 0;


	while (N != 0) {
		res *= 10;
		res += N % 10;
		N /= 10;
	}

	return res;
}



int main()
{
	system("color 0b");
	while (1)
	{

		PrintResult(ReverseNumber(ReadPositiveNum("Enter a positive number: ")));

		cout << endl << endl;
	}
	return 0;
}