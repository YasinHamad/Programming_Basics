#pragma once

#include <vector>
#include <iostream>
#include "clsUtil.h"
#include "clsDate.h"
//#include "clsOutput.h"

class clsValidate
{
public:
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

	static bool IsElementInVector(vector<int> vec, int looking_for) {
		return -1 != clsUtil::SearchInVector(vec, looking_for);
	}
	static bool IsElementInVector(vector<double> vec, double looking_for) {
		return -1 != clsUtil::SearchInVector(vec, looking_for);
	}
	static bool IsElementInVector(vector<char> vec, char looking_for) {
		return -1 != clsUtil::SearchInVector(vec, looking_for);
	}
	static bool IsElementInVector(vector<string> vec, string looking_for) {
		return -1 != clsUtil::SearchInVector(vec, looking_for);
	}

	// not tested
	static bool IsPalindromeArray(int arr[], int size) {
		for (int i = 0, j = size - 1; i < j; i++, j--) {
			if (arr[i] != arr[j]) return false;
		}
		return true;
	}

	static bool IsPrime(int num) {
		if (num < 2) return false;
		int M = round(num / 2);
		for (int i = 2; i <= M; i++) {
			if (num % i == 0) return false;
		}
		return true;
	}
	static bool IsEven(int number) {
		return (number % 2) == 0;
	}
	static bool IsPalindrome(int N) {
		return N == clsUtil::ReverseNumber(N);
	}
		
	// not tested
	static bool IsPerfect(int num) {
		int sum = 0;

		for (int i = 1; i < num; i++) {
			if (num % i == 0) sum += i;
		}
		return sum == num;
	}

	static bool IsNumberBetween(short number, short first_number, short second_number) {
		return (number >= first_number) && (number <= second_number);
	}
	static bool IsNumberBetween(float number, float first_number, float second_number) {
		return (number >= first_number) && (number <= second_number);
	}
	static bool IsNumberBetween(int number, int first_number, int second_number) {
		return (number >= first_number) && (number <= second_number);
	}
	static bool IsNumberBetween(double number, double first_number, double second_number) {
		return (number >= first_number) && (number <= second_number);
	}

	static bool IsDateBetween(clsDate date, clsDate first_date, clsDate second_date) {
		return (
			((date.IsAfterDate(first_date) || date.IsEqualToDate(first_date)) && (date.IsBeforeDate(second_date) || date.IsEqualToDate(second_date))) ||
			((date.IsAfterDate(second_date) || date.IsEqualToDate(second_date)) && (date.IsBeforeDate(first_date)) || date.IsEqualToDate(first_date)));
	}
	static bool IsValidDate(clsDate date) {
		return date.ValidateDate();
	}


};

