#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
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
/************************************************/

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





int main()
{
	system("color 0b");
	while (1)
	{
		srand((unsigned)time(NULL));

		cout << GetRandomChar(en_char_type::small_letter) << endl;
		cout << GetRandomChar(en_char_type::capital_letter) << endl;
		cout << GetRandomChar(en_char_type::special_char) << endl;
		cout << GetRandomChar(en_char_type::digit) << endl;


		cout << endl << endl;
		break;
	}
	return 0;
}