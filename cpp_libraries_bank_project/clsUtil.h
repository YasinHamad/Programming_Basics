#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>

#include "clsDate.h"

using namespace std;

class clsUtil
{
private:
	static bool IsElementInArray(int arr[], int size, int looking_for) {
		return -1 != clsUtil::SearchInArray(arr, size, looking_for);
	}
	static bool IsElementInArray(double arr[], int size, double looking_for) {
		return -1 != clsUtil::SearchInArray(arr, size, looking_for);
	}
	static bool IsElementInArray(char arr[], int size, char looking_for) {
		return -1 != clsUtil::SearchInArray(arr, size, looking_for);
	}
	static bool IsElementInArray(string arr[], int size, string looking_for) {
		return -1 != clsUtil::SearchInArray(arr, size, looking_for);
	}

	static bool IsPrime(int num) {
		if (num < 2) return false;
		int M = round(num / 2);
		for (int i = 2; i <= M; i++) {
			if (num % i == 0) return false;
		}
		return true;
	}

public:
	enum en_char_type
	{
		en_small_letter, en_capital_letter, en_special_char, en_digit, en_mix_char
	};

	// this function allocate two dim int array in the heap
	// you should use `DeleteTwoDimArray` after using this function
	static int** AllocateTwoDimIntArray(int rows, int columns) {
		int** arr = new int* [rows];

		for (int i = 0; i < rows; i++) {
			*(arr + i) = new int[columns];
		}

		return arr;
	}
	static double** AllocateTwoDimDbArray(int rows, int columns) {
		double** arr = new double* [rows];

		for (int i = 0; i < rows; i++) {
			*(arr + i) = new double[columns];
		}

		return arr;
	}
	static char** AllocateTwoDimCharArray(int rows, int columns) {
		char** arr = new char* [rows];

		for (int i = 0; i < rows; i++) {
			*(arr + i) = new char[columns];
		}

		return arr;
	}
	static string** AllocateTwoDimStringArray(int rows, int columns) {
		string** arr = new string * [rows];

		for (int i = 0; i < rows; i++) {
			*(arr + i) = new string[columns];
		}

		return arr;
	}

	// this function delete/free a two dim array from the heap
	static void DeleteTwoDimArray(int** arr, int rows) {
		for (int i = 0; i < rows; i++) {
			delete[] * (arr + i);
		}

		delete[] arr;
	}
	static void DeleteTwoDimArray(double** arr, int rows) {
		for (int i = 0; i < rows; i++) {
			delete[] * (arr + i);
		}

		delete[] arr;
	}
	static void DeleteTwoDimArray(char** arr, int rows) {
		for (int i = 0; i < rows; i++) {
			delete[] * (arr + i);
		}

		delete[] arr;
	}
	static void DeleteTwoDimArray(string** arr, int rows) {
		for (int i = 0; i < rows; i++) {
			delete[] * (arr + i);
		}

		delete[] arr;
	}

	static string ConvertAddressToString(void* address) {
		ostringstream oss;
		string address_st = "";

		oss << address;
		address_st += oss.str();
		oss.str("");
		oss.clear();

		return address_st;
	}

	static string NumberToText(int number) {
		if (number >= 0 && number <= 19) {
			string numbers[] = {
				"",
				"One", "Two", "Three", "Four", "Five",
				"Six", "Seven", "Eight", "Nine", "Ten",
				"Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen",
				"Sixteen", "Seventeen", "Eighteen", "Nineteen"
			};
			return numbers[number];
		}

		else if (number >= 20 && number <= 99) {
			string numbers[] = {
				"", "", "Twenty", "Thirty", "Forty",
				"Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
			};
			return numbers[number / 10] + " " + NumberToText(number % 10);
		}

		else if (number <= 999) {
			if (number / 100 == 1) return NumberToText(number / 100) + " Hundred " + NumberToText(number % 100);
			return NumberToText(number / 100) + " Hundreds " + NumberToText(number % 100);
		}

		else if (number <= 999999) {
			if (number / 1000 == 1) return NumberToText(number / 1000) + " Thousand " + NumberToText(number % 1000);
			return NumberToText(number / 1000) + " Thousands " + NumberToText(number % 1000);
		}

		else if (number <= 999999999) {
			if (number / 1000000 == 1) return NumberToText(number / 1000000) + " Million " + NumberToText(number % 1000000);
			return NumberToText(number / 1000000) + " Millions " + NumberToText(number % 1000000);
		}

		else {
			if (number / 1000000000 == 1) return NumberToText(number / 1000000000) + " Billion " + NumberToText(number % 1000000000);
			return NumberToText(number / 1000000000) + " Billions " + NumberToText(number % 1000000000);
		}

		return "null";
	}

	//static string NumberToText(double number) {
	//	// this is the left part
	//	int int_part = int(number);

	//	// this is the right part with dot, like 0.2210009
	//	double zero_part_fraction_part = number - int_part;

	//	// this is the right part with dot as string, like "0.2210009"
	//	string fraction_part_str = to_string(zero_part_fraction_part);

	//	// this is the right part without the dot zero, like "2210009"
	//	fraction_part_str = fraction_part_str.erase(0, 2);

	//	// this is the right part without the unnecessarily zeros, like "221"
	//	for (int i = 0; i < fraction_part_str.size(); i++) {
	//		if (fraction_part_str[i] == '0') {
	//			fraction_part_str.replace(i, INT_MAX, "");
	//			break;
	//		}
	//	}

	//	// if the number is 2.0, so it will end up ""
	//	if (fraction_part_str.empty()) {
	//		return NumberToText(int_part);
	//	}
	//	// if the number is 2.300, so it will end up 3
	//	else {
	//		int fraction_part = stoi(fraction_part_str.substr());
	//		return NumberToText(int_part) + " Point " + NumberToText(fraction_part);
	//	}
	//}

	// this function return a random number
	static int RandomNumber(int From, int To)
	{
		int randNum = rand() % (To - From + 1) + From;
		return randNum;
	}
	// initialize the the random number generator
	static void Srand() {
		srand((unsigned)time(NULL));
	}

	// this function fills two dim array(in heap) with random numbers
	static void FillTwoDimArrayWithRandomIntNumbers(int** arr, int rows, int columns, int from, int to) {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				*(*(arr + i) + j) = RandomNumber(from, to);
			}
		}
	}
	// this fills two dim array(in heap) with orderd number
	static void FillTwoDimArrayWithOrderdIntNumbers(int** arr, int rows, int columns, int first_number = 1) {
		int counter = first_number;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				*(*(arr + i) + j) = counter++;
			}
		}
	}

	// -1 means does not exist
	static int SearchInArray(int arr[], int size, int looking_for) {
		for (int i = 0; i < size; i++) {
			if (arr[i] == looking_for) {
				return i;
			}
		}
		return -1;
	}
	static int SearchInArray(double arr[], int size, double looking_for) {
		for (int i = 0; i < size; i++) {
			if (arr[i] == looking_for) {
				return i;
			}
		}
		return -1;
	}
	static int SearchInArray(char arr[], int size, char looking_for) {
		for (int i = 0; i < size; i++) {
			if (arr[i] == looking_for) {
				return i;
			}
		}
		return -1;
	}
	static int SearchInArray(string arr[], int size, string looking_for) {
		for (int i = 0; i < size; i++) {
			if (arr[i] == looking_for) {
				return i;
			}
		}
		return -1;
	}

	 //-1 means does not exist
	static int SearchInVector(vector<int> vec, int looking_for) {
		int counter = 0;
		for (const int& i : vec) {
			if (i == looking_for) {
				return counter;
			}
			counter++;
		}
		return -1;
	}
	static int SearchInVector(vector<double> vec, double looking_for) {
		int counter = 0;
		for (const double& i : vec) {
			if (i == looking_for) {
				return counter;
			}
			counter++;
		}
		return -1;
	}
	static int SearchInVector(vector<char> vec, char looking_for) {
		int counter = 0;
		for (const char& i : vec) {
			if (i == looking_for) {
				return counter;
			}
			counter++;
		}
		return -1;
	}
	static int SearchInVector(vector<string> vec, string looking_for) {
		int counter = 0;
		for (const string& i : vec) {
			if (i == looking_for) {
				return counter;
			}
			counter++;
		}
		return -1;
	}

	static void AddElementToArray(int element, int arr[], int& size) {
		arr[size++] = element;
	}
	static void AddElementToArray(double element, double arr[], int& size) {
		arr[size++] = element;
	}
	static void AddElementToArray(char element, char arr[], int& size) {
		arr[size++] = element;
	}
	static void AddElementToArray(string element, string arr[], int& size) {
		arr[size++] = element;
	}

	static void CopyDistinctElementsToArray(int arr1[], int arr2[], int size1, int& size2) {
		for (int i = 0; i < size1; i++) {
			if (!IsElementInArray(arr2, size2, arr1[i]))
				AddElementToArray(arr1[i], arr2, size2);
		}
	}
	static void CopyDistinctElementsToArray(double arr1[], double arr2[], int size1, int& size2) {
		for (int i = 0; i < size1; i++) {
			if (!IsElementInArray(arr2, size2, arr1[i]))
				AddElementToArray(arr1[i], arr2, size2);
		}
	}
	static void CopyDistinctElementsToArray(char arr1[], char arr2[], int size1, int& size2) {
		for (int i = 0; i < size1; i++) {
			if (!IsElementInArray(arr2, size2, arr1[i]))
				AddElementToArray(arr1[i], arr2, size2);
		}
	}
	static void CopyDistinctElementsToArray(string arr1[], string arr2[], int size1, int& size2) {
		for (int i = 0; i < size1; i++) {
			if (!IsElementInArray(arr2, size2, arr1[i]))
				AddElementToArray(arr1[i], arr2, size2);
		}
	}

	static void Swap(int& num1, int& num2) {
		int aux = num1;
		num1 = num2;
		num2 = aux;
	}
	static void Swap(double& num1, double& num2) {
		double aux = num1;
		num1 = num2;
		num2 = aux;
	}
	static void Swap(char& num1, char& num2) {
		char aux = num1;
		num1 = num2;
		num2 = aux;
	}
	static void Swap(string& num1, string& num2) {
		string aux = num1;
		num1 = num2;
		num2 = aux;
	}
	static void Swap(clsDate& date1, clsDate& date2) {
		clsDate aux = date1;
		date1 = date2;
		date2 = aux;
	}

	static void ReverseArray(int arr[], int size) {
		int new_size = size / 2;
		for (int i = 0; i < new_size; i++) {
			Swap(arr[i], arr[size - (1 + i)]);
		}
	}
	static void ReverseArray(double arr[], int size) {
		int new_size = size / 2;
		for (int i = 0; i < new_size; i++) {
			Swap(arr[i], arr[size - (1 + i)]);
		}
	}
	static void ReverseArray(char arr[], int size) {
		int new_size = size / 2;
		for (int i = 0; i < new_size; i++) {
			Swap(arr[i], arr[size - (1 + i)]);
		}
	}
	static void ReverseArray(string arr[], int size) {
		int new_size = size / 2;
		for (int i = 0; i < new_size; i++) {
			Swap(arr[i], arr[size - (1 + i)]);
		}
	}

	static void CopyReversedArray(int original[], int arr2[], int size) {
		for (int i = 0; i < size; i++) {
			arr2[size - i - 1] = original[i];
		}
	}
	static void CopyReversedArray(double original[], double arr2[], int size) {
		for (int i = 0; i < size; i++) {
			arr2[size - i - 1] = original[i];
		}
	}
	static void CopyReversedArray(char original[], char arr2[], int size) {
		for (int i = 0; i < size; i++) {
			arr2[size - i - 1] = original[i];
		}
	}
	static void CopyReversedArray(string original[], string arr2[], int size) {
		for (int i = 0; i < size; i++) {
			arr2[size - i - 1] = original[i];
		}
	}

	static void CopyArray(int arr[], int size, int c_arr[]) {
		for (int i = 0; i < size; i++) {
			c_arr[i] = arr[i];
		}
	}
	static void CopyArray(double arr[], int size, double c_arr[]) {
		for (int i = 0; i < size; i++) {
			c_arr[i] = arr[i];
		}
	}
	static void CopyArray(char arr[], int size, char c_arr[]) {
		for (int i = 0; i < size; i++) {
			c_arr[i] = arr[i];
		}
	}
	static void CopyArray(string arr[], int size, string c_arr[]) {
		for (int i = 0; i < size; i++) {
			c_arr[i] = arr[i];
		}
	}
	
	static void FillArrayWithOrderInts(int arr[], int size, int first_number) {
		for (int i = 0; i < size; i++) {
			arr[i] = first_number++;
		}
	}
	static void FillArrayWithRandomValues(int arr[], int size, int from = 0, int to = 100) {
		for (int i = 0; i < size; i++) {
			arr[i] = RandomNumber(from, to);
		}
	}
	static void FillArrayWithRnadomWords(string arr[], int size, en_char_type char_type, short word_length) {
		for (int i = 0; i < size; i++) {
			arr[i] = GenerateWord(char_type, word_length);
		}
	}
	static void FillArrayWithRnadomKeys(string arr[], int size, en_char_type char_type, short word_length, 
		int number_of_words, string separator = "-") {
		for (int i = 0; i < size; i++) {
			arr[i] = GenerateKey(number_of_words, char_type, word_length, separator);
		}
	}

	static char GetRandomChar(en_char_type char_type) {
		switch (char_type)
		{
		case en_small_letter:
			return char(RandomNumber(97, 122));
		case en_capital_letter:
			return char(RandomNumber(65, 90));
		case en_special_char:
			return char(RandomNumber(33, 47));
		case en_digit:
			return char(RandomNumber(48, 57));
		case en_mix_char:
			return GetRandomChar((en_char_type)RandomNumber(0, 3));
		default:
			return '\0';
		}
	}

	static int CountOddNumbers(int arr[], int size) {
		int counter = 0;
		for (int i = 0; i < size; i++) {
			if (arr[i] % 2 != 0) counter++;
		}
		return counter;
	}
	static int CountEvenNumbers(int arr[], int size) {
		int counter = 0;
		for (int i = 0; i < size; i++) {
			if (arr[i] % 2 == 0) counter++;
		}
		return counter;
	}
	static int CountPositiveNumbers(int arr[], int size) {
		int counter = 0;
		for (int i = 0; i < size; i++) {
			if (arr[i] >= 0) counter++;
		}
		return counter;
	}
	static int CountNegativeNumbers(int arr[], int size) {
		return size - CountPositiveNumbers(arr, size);
	}

	static float GetFractionPart(float num) {
		return num - int(num);
	}

	static void CopyPrimeElementsToArray(int original_arr[], int c_arr[], int size1, int& size2) {
		for (int i = 0; i < size1; i++) {
			if (IsPrime(original_arr[i]))
				AddElementToArray(original_arr[i], c_arr, size2);
		}
	}
	static void CopyOddElementsToArray(int original_arr[], int c_arr[], int size1, int& size2) {
		for (int i = 0; i < size1; i++) {
			if ((original_arr[i] % 2) != 0)
				AddElementToArray(original_arr[i], c_arr, size2);
		}
	}

	static string GenerateWord(en_char_type type, short length) {
		string word = "";
		for (int i = 0; i < length; i++) word += GetRandomChar(type);
		return word;
	}
	static string GenerateKey(int number_of_words, en_char_type char_type, int words_length, string separator = "-") {
		string key = "";
		for (int i = 0; i < number_of_words; i++) {
			key += GenerateWord(char_type, words_length);
			if (i != number_of_words - 1) key += separator;
		}
		return key;
	}

	static void ShuffleArrayElements(int arr[], int size) {
		int rand_index_1 = 0;
		int rand_index_2 = 0;

		for (int i = 0; i < size; i++) {
			rand_index_1 = RandomNumber(0, size - 1);
			rand_index_2 = RandomNumber(0, size - 1);
			Swap(arr[rand_index_1], arr[rand_index_2]);
		}

	}

	static void SumTwoArray(int arr1[], int arr2[], int size, int arr_result[], int& size_result) {
		for (int i = 0; i < size; i++) {
			AddElementToArray(arr1[i] + arr2[i], arr_result, size_result);
		}
	}

	static int SumArray(int arr[], int size) {
		int sum = 0;
		for (int i = 0; i < size; i++) {
			sum += arr[i];
		}
		return sum;
	}

	static float AverageOfArrayElements(int arr[], int size) {
		return SumArray(arr, size) * 1.0 / size;
	}

	static int GetMaxNumberInArray(int arr[], int size) {
		int max = arr[0];
		for (int i = 1; i < size; i++) {
			max = arr[i] > max ? arr[i] : max;
		}
		return max;
	}
	static int GetMinNumberInArray(int arr[], int size) {
		int min = arr[0];
		for (int i = 1; i < size; i++) {
			min = arr[i] < min ? arr[i] : min;
		}
		return min;
	}

	static int CountFrequency(int arr[], int numberToCheck, int size) {

		int counter = 0;
		for (int i = 0; i < size; i++) {
			if (numberToCheck == arr[i]) counter++;
		}
		return counter;
	}

	static string Encrypt(string word, short encryption_key = 2) {
		for (int i = 0; i < word.length(); i++) {
			word[i] = word[i] + encryption_key;
		}

		return word;
	}
	static string Decrypt(string word, short decryption_key = 2) {
		for (int i = 0; i < word.length(); i++) {
			word[i] = word[i] - decryption_key;
		}

		return word;
	}

	// I really don't know the purpose of this
	static bool FindPassword(string pass) {
		string word = "";
		int counter = 1;

		for (int i = 65; i <= 90; i++) {
			for (int j = 65; j <= 90; j++) {
				for (int k = 65; k <= 90; k++) {
					word += char(i);
					word += char(j);
					word += char(k);

					cout << "Trail[" << counter << "]:" << word << endl;

					if (pass == word) {
						cout << "Password is " << word << endl;
						cout << "Found after " << counter << " trail(s)" << endl;
						return true;
					}
					counter++;

					word = "";
				}

			}

		}
		return false;
	}

	// I guess that I need to rewrite this, convert to string, then to int, and pay ettention to the int size
	static int ReverseNumber(int N) {
		int res = 0;

		while (N != 0) {
			res *= 10;
			res += N % 10;
			N /= 10;
		}

		return res;
	}

	static int CountDigitFrequency(int N, int d) {

		int res = 0;

		while (N != 0) {
			if ((N % 10) == d) res++;
			N /= 10;
		}

		return res;
	}
	static int RemoveDigit(int main_number, int digit) {
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
	static int SumOfDigits(int N) {

		int sum = 0;


		while (N != 0) {
			sum += N % 10;
			N /= 10;
		}

		return sum;
	}
};

