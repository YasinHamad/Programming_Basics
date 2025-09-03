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
char GetRandomChar(en_char_type char_type) {
	switch (char_type)
	{
	case small_letter:
		return char(RandomNumber(97, 122));
	case capital_letter:
		return char(RandomNumber(65, 90));
	case special_char:
		return char(RandomNumber(33, 47));
	case digit:
		return char(RandomNumber(48, 57));
	default:
		return '\0';
	}
}
void FillArrayWithRandomValues(int arr[], int& size) {

	size = ReadPositiveNum("Enter array size: ");
	for (int i = 0; i < size; i++) {
		arr[i] = RandomNumber(1, 100);
	}
}
void FillArrayWithOrderInts(int arr[], int& size) {
	size = ReadPositiveNum("Enter array size: ");
	for (int i = 0; i < size; i++) {
		arr[i] = i + 1;
	}
}
void PrintArray(int arr[], int size) {
	cout << "Original Array : ";
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
void CopyArray(int arr[], int size, int c_arr[]) {
	for (int i = 0; i < size; i++) {
		c_arr[i] = arr[i];
	}
}
void Swap(int& num1, int& num2) {
	int aux = num1;
	num1 = num2;
	num2 = aux;
}

void ReverseArray(int arr[], int size) {
	int new_size = size / 2;
	for (int i = 0; i < new_size; i++) {
		Swap(arr[i], arr[size - (1 + i)]);
	}
}
void CopyReversedArray(int arr[], int arr2[], int size) {
	for (int i = 0; i < size; i++) {
		arr2[size - i - 1] = arr[i];
	}
}
/************************************************/

void FillArray(int arr[], int& size) {
	arr[0] = 10;
	arr[1] = 20;
	arr[2] = 30;
	arr[3] = 30;
	arr[4] = 20;
	arr[5] = 10;
	size = 6;
}


bool IsPalindromeArray(int arr[], int size) {
	int new_size = size / 2;
	for (int i = 0; i < new_size; i++) {
		if (arr[i] != arr[size - i - 1]) return false;
	}
	return true;
}
bool IsPalindromeArray2(int arr[], int size) {
	for (int i = 0, j = size - 1; i < j; i++, j--) {
		if (arr[i] != arr[j]) return false;
	}
	return true;
}



int main()
{
	system("color 0b");
	while (1)
	{
		srand((unsigned)time(NULL));

		int arr[SIZE];
		int size = 0;

		FillArray(arr, size);

		PrintArray(arr, size);

		cout << IsPalindromeArray2(arr, size);


		cout << endl << endl;
		break;
	}
	return 0;
}