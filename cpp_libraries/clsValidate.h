#pragma once

#include <vector>
#include <iostream>
#include "clsUtil.h"
#include "clsDate.h"
//#include "clsOutput.h"

class clsValidate
{
public:
	template <typename element_type>
	static bool IsElementInArray(element_type arr[], int size, element_type looking_for) {
		return -1 != clsUtil::SearchInArray<element_type>(arr, size, looking_for);
	}

	template <typename element_type>
	static bool IsElementInVector(vector<element_type> vec, element_type looking_for) {
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

	template <typename element_type>
	static bool IsNumberBetween(element_type number, element_type first_number, element_type second_number) {
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

