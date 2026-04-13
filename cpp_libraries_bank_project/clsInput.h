#pragma once

#include <vector>
#include <iostream>
#include "clsDate.h"
#include "clsValidate.h"
#include "clsString.h"

class clsInput
{
public:
	static int ReadIntNumber(string message, string error_message = "Invalid Number, enter a valid one: ") {
		int number;
		cout << message;
		cin >> number;
		while (cin.fail()) {
			// user didn't input a number    
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << error_message;
			cin >> number;
		}
		return number;
	}
	static int ReadIntNumberInRange(int from, int to, string message, string error_message = "Number not in range, enter another one: ") {
		int number = ReadIntNumber(message, error_message);

		while (!clsValidate::IsNumberBetween(number, from, to)) {
			cout << error_message;
			number = ReadIntNumber("", error_message);
		}
		return number;
	}
	static double ReadDbNumber(string message, string error_message = "Invalid Number, enter a valid one: ") {
		double number;
		cout << message;
		cin >> number;
		while (cin.fail()) {
			// user didn't input a number    
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << error_message;
			cin >> number;
		}
		return number;
	}
	static double ReadDbNumberInRange(double from, double to, string message, string error_message = "Number not in range, enter another one: ") {
		double number = ReadDbNumber(message, error_message);

		while (!clsValidate::IsNumberBetween(number, from, to)) {
			cout << error_message;
			number = ReadDbNumber("", error_message);
		}
		return number;
	}
	static float ReadFlNumber(string message, string error_message = "Invalid Number, enter a valid one: ") {
		float number;
		cout << message;
		cin >> number;
		while (cin.fail()) {
			// user didn't input a number    
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << error_message;
			cin >> number;
		}
		return number;
	}
	static float ReadFlNumberInRange(float from, float to, string message, string error_message = "Number not in range, enter another one: ") {
		float number = ReadDbNumber(message, error_message);

		while (!clsValidate::IsNumberBetween(number, from, to)) {
			cout << error_message;
			number = ReadDbNumber("", error_message);
		}
		return number;
	}

	static string ReadAWord(string message) {
		string W;
		cout << message;
		cin >> W;
		return W;
	}
	static string ReadASentence(string message) {
		string W;
		cout << message;
		getline(cin >> std::ws, W);
		return W;
	}
	static string ReadASentence(string message, string error_message) {
		string W;
		cout << message;
		getline(cin >> std::ws, W);

		clsOutput::ColorString(error_message, clsOutput::enColorString::en_error);

		W = clsString::Trim(W);

		while (W == "") {
			cout << error_message;
			getline(cin >> std::ws, W);
			W = clsString::Trim(W);
		}
		return W;
	}
	static char ReadChar(string message) {
		char c = 'x';
		cout << message;
		cin >> c;
		return c;
	}	
	static char ReadBool(string message) {
		char check = 'a';
		string error_message = "Invalid input, enter [y/n]: ";
		clsOutput::ColorString(error_message, clsOutput::enColorString::en_error);
		cout << message;
		while (true) {
			cin >> check;
			if (tolower(check) != 'y' && tolower(check) != 'n') {
				cout << error_message;
				continue;
			}
			if (tolower(check) == 'y') return true;
			break;
		}
		return false;
	}

	static void ReadArrayElements(int arr[], int& size) {
		size = ReadIntNumberInRange(1, INT_MAX, "Enter array size: ", "The size should be positive, enter another one: ");
		for (int i = 0; i < size; i++) {
			arr[i] = ReadIntNumber("Element [" + to_string(i + 1) + "] : ");
		}
	}
	static void ReadVectorElements(vector <int>& vector) {
		char check = 'y';
		int new_element = 0;

		while (check == 'y' || check == 'Y') {
			new_element = ReadIntNumber("Enter an element: ");
			vector.push_back(new_element);

			cout << "Do you want to add more elements [y/n]: ";
			cin >> check;
		}
	}

};

