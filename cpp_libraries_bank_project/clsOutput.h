#pragma once

#include <iostream>

#include "clsValidate.h"

using namespace std;

static const string C_RESET = "\033[0m";
static const string C_NOT_IMP = "\033[90m";
static const string C_BLACK = "\033[30m";
static const string C_INVERT = "\033[7m";
static const string C_UNDERLINE = "\033[4m";
static const string C_WHITE = "\033[97m";

static const string C_DARK_RED = "\033[31m";
static const string C_DARK_GREEN = "\033[32m";
static const string C_DARK_YELLOW = "\033[33m";
static const string C_DARK_BLUE = "\033[34m";
static const string C_DARK_PINK = "\033[35m";
static const string C_DARK_SKY = "\033[36m";

static const string C_DARK_RED_B = "\033[41m";
static const string C_DARK_GREEN_B = "\033[42m";
static const string C_DARK_YELLOW_B = "\033[43m";
static const string C_DARK_BLUE_B = "\033[44m";
static const string C_DARK_PINK_B = "\033[45m";
static const string C_DARK_SKY_B = "\033[46m";
static const string C_DARK_GRAY_B = "\033[100m";

static const string C_LIGHT_RED = "\033[91m";
static const string C_LIGHT_GREEN = "\033[92m";
static const string C_LIGHT_YELLOW = "\033[93m";
static const string C_LIGHT_BLUE = "\033[94m";
static const string C_LIGHT_PINK = "\033[95m";
static const string C_LIGHT_SKY = "\033[96m";

static const string C_LIGHT_RED_B = "\033[101m";
static const string C_LIGHT_GREEN_B = "\033[102m";
static const string C_LIGHT_YELLOW_B = "\033[103m";
static const string C_LIGHT_BLUE_B = "\033[104m";
static const string C_LIGHT_PINK_B = "\033[105m";
static const string C_LIGHT_SKY_B = "\033[106m";

class clsOutput
{
public:
	enum enPosition { left, center, right };
	enum enColorString { en_error = 0, en_sucess = 1, en_attention = 2, en_invert = 3 };

private:
	static void _PrintTableBorder(vector<int>& _cell_widths, int padding) {
		string result = "";

		for (int& item : _cell_widths) {
			for (int j = 0; j < item + (padding * 2); j++) {
				result += "-";
			}
			result += "|";
		}

		cout << result << endl;
	}

	static void _PrintTableRow(vector<string>& row, vector<int>& widths, int padding, enPosition _position) {
		int iterator = 0;
		for (string& item : row) {
			cout <<
				FormatString(widths[iterator] + padding * 2, item, _position) <<
				"|";
			iterator++;
		}
		cout << endl;
	}

	static void _ConvertHeaderToCapital(vector<vector<string>>& _data) {
		for (string& item : _data[0]) {
			for (char& ch : item) {
				ch = toupper(ch);
			}
		}
	}

	static string _GetStringColor(enColorString color) {
		switch (color) {
		case enColorString::en_error: {
			string resutl = C_WHITE;
			resutl += C_DARK_RED_B;
			return resutl;
		}
		case enColorString::en_sucess: {
			string resutl = C_WHITE;
			resutl += C_DARK_GREEN_B;
			return resutl;
		}
		case enColorString::en_attention: {
			string resutl = C_WHITE;
			resutl += C_DARK_YELLOW_B;
			return resutl;
		}
		case enColorString::en_invert: {
			string resutl = "";
			resutl += C_INVERT;
			return resutl;
		}
		}
	}

public:
	static void PrintArray(int arr[], int size) {
		cout << "{";
		for (int i = 0; i < size; i++) {
			cout << arr[i] << ", ";
		}
		cout << "\b\b}\n";
	}
	static void PrintArray(double arr[], int size) {
		cout << "{";
		for (int i = 0; i < size; i++) {
			cout << arr[i] << ", ";
		}
		cout << "\b\b}\n";
	}
	static void PrintArray(char arr[], int size) {
		cout << "{";
		for (int i = 0; i < size; i++) {
			cout << arr[i] << ", ";
		}
		cout << "\b\b}\n";
	}
	static void PrintArray(string arr[], int size) {
		cout << "{";
		for (int i = 0; i < size; i++) {
			cout << arr[i] << ", ";
		}
		cout << "\b\b}\n";
	}

	static void PrintVector(vector<int> vec) {
		cout << "{";
		for (int i = 0; i < vec.size(); i++) {
			cout << vec[i] << ", ";
		}
		cout << "\b\b}\n";
	}
	static void PrintVector(vector<double> vec) {
		cout << "{";
		for (int i = 0; i < vec.size(); i++) {
			cout << vec[i] << ", ";
		}
		cout << "\b\b}\n";
	}
	static void PrintVector(vector<char> vec) {
		cout << "{";
		for (int i = 0; i < vec.size(); i++) {
			cout << vec[i] << ", ";
		}
		cout << "\b\b}\n";
	}
	static void PrintVector(vector<string> vec) {
		cout << "{";
		for (int i = 0; i < vec.size(); i++) {
			cout << vec[i] << ", ";
		}
		cout << "\b\b}\n";
	}

	static string GetChar(int number, string char_to_print) {
		string result = char_to_print;
		for (int i = 1; i < number; i++) result += char_to_print;
		return result;
	}

	static string FormatString(int number, string sentence, enPosition position, string empy_space_char = " ") {
		int length = sentence.length();
		int padding_summation = length - number;

		string result = "";

		int left_padding = 0;
		int right_padding = 0;

		switch (position)
		{
		case(enPosition::center):
		{
			if ((clsValidate::IsEven(length) && clsValidate::IsEven(number)) || (!clsValidate::IsEven(length) && !clsValidate::IsEven(number))) {
				left_padding = right_padding = (number - length) / 2;
			}
			else {
				left_padding = (number - length) / 2;
				right_padding = (number - length) / 2;
				right_padding++;
			}

			result += GetChar(left_padding, empy_space_char);
			result += sentence;
			result += GetChar(right_padding, empy_space_char);
			break;
		}
		case(enPosition::left):
		{
			result += sentence;
			result += GetChar(number - length, empy_space_char);
			break;
		}
		default:
		{
			result += GetChar(number - length, empy_space_char);
			result += sentence;
			break;
		}
		}
		return result;
	}

	static void Println(string ms) {
		cout << ms << endl;
	}

	static void MakeTable(vector<vector<string>>& _data, enPosition _position, bool line_btw) {
		int number_of_columns = _data[0].size();
		int number_of_rows = _data.size();
		int iterator = 0;
		int padding = 5;

		vector<int> num_of_spaces_for_each_column;

		// initialize the vector num_of_spaces_for_each_column
		for (int i = 0; i < number_of_columns; i++) num_of_spaces_for_each_column.push_back(0);

		for (vector<string>& vec : _data) {
			for (string& item : vec) {
				num_of_spaces_for_each_column[iterator] =
					(item.length() > num_of_spaces_for_each_column[iterator]) ? item.length() : num_of_spaces_for_each_column[iterator];
				iterator++;
			}
			iterator = 0;
		}

		_PrintTableBorder(num_of_spaces_for_each_column, padding);

		_ConvertHeaderToCapital(_data);

		iterator = 0;
		for (vector<string>& vec : _data) {
			_PrintTableRow(vec, num_of_spaces_for_each_column, padding, _position);

			if (iterator == 0) _PrintTableBorder(num_of_spaces_for_each_column, padding);

			if (line_btw && iterator != 0) _PrintTableBorder(num_of_spaces_for_each_column, padding);

			iterator++;
		}

		if (!line_btw) _PrintTableBorder(num_of_spaces_for_each_column, padding);
	}

	// this function prints two dim array(in heap) to the screen
	static void PrintTwoDimArray(int** arr, int rows, int columns, int cell_width, enPosition position) {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				string cell_data = to_string(*(*(arr + i) + j));
				cout << FormatString(cell_width, cell_data, position) << "\t";
			}
			cout << endl;
		}
	}
	// this function is similar to the above function, but it prints zeros in the spaces
	// for example if you say the cell_width is 3, you gonna see 001 002 etc
	static void PrintTwoDimArray(int** arr, int rows, int columns, int cell_width) {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				int cell_data = *(*(arr + i) + j);

				printf("%0*d ", cell_width, cell_data);

			}
			cout << endl;
		}
	}

	static int ColorString(string& str, enColorString color) {
		string result = "";
		int length = 0;

		result += _GetStringColor(color);
		result += str;
		result += C_RESET;

		length = result.length() - str.length();

		str = result;
		return length;
	}

	static int ColorString(string& str, string color) {
		string result = "";
		int length = 0;

		result += color;
		result += str;
		result += C_RESET;

		length = result.length() - str.length();

		str = result;
		return length;
	}

	static string FormatNumber(int number, int digits = 1) {
		if (digits == 1 || number <= 0) return to_string(number);

		string result = to_string(number);
		int length = result.length();
		for (int i = 1; i <= digits - length ; i++) {
			result = "0" + result;
		}

		return result;
	}

};

