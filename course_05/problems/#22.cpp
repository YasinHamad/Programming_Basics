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

void ReadArrayElements(int arr[], int& size) {
	size = ReadPositiveNum("Enter array size: ");

	for (int i = 0; i < size; i++) {
		arr[i] = ReadNum("Element [" + to_string(i + 1) + "] : ");
	}
}
void PrintArray(int arr[], int size) {
	cout << "Original Array : ";
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int CheckFrequency(int arr[], int numberToCheck, int size) {

	int counter = 0;
	for (int i = 0; i < size; i++) {
		if (numberToCheck == arr[i]) counter++;
	}
	return counter;
}






int main()
{
	system("color 0b");
	while (1)
	{
		srand((unsigned)time(NULL));

		int arr[SIZE], size;

		ReadArrayElements(arr, size);

		int number_to_check = ReadNum("Enter the number you want to check : ");

		PrintArray(arr, size);

		int rep = CheckFrequency(arr, number_to_check, size);

		cout << "\n" << number_to_check << " is repeated " << rep << " times(s)" << endl;



		cout << endl << endl;
		break;
	}
	return 0;
}