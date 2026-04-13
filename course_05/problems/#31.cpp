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

void ShuffleArrayElements(int arr[], int size) {
	int aux[SIZE];
	int rnum = 0;
	for (int i = 0; i < size; i++) {
		aux[i] = -1;
	}
	for (int i = 0; i < size; i++) {
		do {
			rnum = RandomNumber(0, size - 1);
		} while (aux[rnum] != -1);
		aux[rnum] = arr[i];
	}
	CopyArray(aux, size, arr);
}

void Swap(int& num1, int& num2) {
	int aux = num1;
	num1 = num2;
	num2 = aux;
}

void ShuffleArrayElements2(int arr[], int size) {
	int rand_index_1 = 0;
	int rand_index_2 = 0;

	for (int i = 0; i < size; i++) {
		rand_index_1 = RandomNumber(0, size - 1);
		rand_index_2 = RandomNumber(0, size - 1);
		Swap(arr[rand_index_1], arr[rand_index_2]);
	}

}






int main()
{
	system("color 0b");
	while (1)
	{
		srand((unsigned)time(NULL));

		int arr[SIZE], size;

		FillArrayWithOrderInts(arr, size);
		//FillArrayWithRandomValues(arr, size);

		PrintArray(arr, size);

		// method one
		//ShuffleArrayElements(arr, size);

		// method two
		ShuffleArrayElements2(arr, size);

		cout << "After suffling : " << endl;

		PrintArray(arr, size);





		cout << endl << endl;
		break;
	}
	return 0;
}