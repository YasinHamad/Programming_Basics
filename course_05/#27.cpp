#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
using namespace std;
#define SIZE 50

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
string ReadAWord(string str) {
	string W;
	cout << str;
	cin >> W;
	return W;
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
enum en_char_type
{
	small_letter, capital_letter, special_char, digit
};

int RandomNumber(int From, int To)
{
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}
/************************************************/

void FillArrayWithRandomValues(int arr[], int& size) {
	size = ReadPositiveNum("Enter array size: ");

	for (int i = 0; i < size; i++) {
		arr[i] = RandomNumber(1, 100);
	}
}
void PrintArray(int arr[], int size) {
	cout << "Original Array : ";
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

float AverageArray(int arr[], int size) {
	int sum = 0;
	for (int i = 1; i < size; i++) {
		sum += arr[i];
	}
	return sum * 1.0 / size;
}






int main()
{
	system("color 0b");
	while (1)
	{
		srand((unsigned)time(NULL));

		int arr[SIZE], size;

		FillArrayWithRandomValues(arr, size);

		PrintArray(arr, size);

		cout << "Sumation is : " << AverageArray(arr, size) << endl;





		cout << endl << endl;
		break;
	}
	return 0;
}