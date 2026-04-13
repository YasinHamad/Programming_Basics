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



int DigitFrequency(int N, int d) {

	int res = 0;


	while (N != 0) {
		if ((N % 10) == d) res++;
		N /= 10;
	}

	return res;
}

int RemoveDigit(int main_number, int digit) {
	int res = 0;
	int remainder = 0;

	while (main_number != 0) {
		remainder = main_number % 10;
		main_number /= 10;
		if (digit != remainder) {
			res *= 10;
			res += remainder;
		}
	}
	return res;
}

void DigitsFrequency(int main_number) {

	int res = 0;
	int remainder = 0;

	while (main_number != 0) {
		int remainder = main_number % 10;
		cout << "There is " << DigitFrequency(main_number, remainder) << " numbers of number " << remainder << endl;
		main_number = RemoveDigit(main_number, remainder);
	}
}
void DigitsFrequency2(int main_number) {
	int digit_freq = 0;

	for (int i = 0; i < 10; i++) {

		digit_freq = DigitFrequency(main_number, i);

		if (digit_freq > 0)
			cout << "There is " << digit_freq << " numbers of number " << i << endl;
	}
}



int main()
{
	system("color 0b");
	while (1)
	{
		// method one
		//DigitsFrequency(ReadPositiveNum("Enter the main number: "));

		// method two
		DigitsFrequency2(ReadPositiveNum("Enter the main number: "));


		cout << endl << endl;
	}
	return 0;
}