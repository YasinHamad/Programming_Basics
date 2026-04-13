#include <iostream>
#include <cmath>
#include <string>
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

bool FindPassword(string pass) {
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

string ReadThreeLettersWord() {
	string N;
	do {
		cout << "Enter three letters word: ";
		cin >> N;
	} while (N.length() != 3);
	return N;
}




int main()
{
	system("color 0b");
	while (1)
	{

		FindPassword(ReadThreeLettersWord());



		cout << endl << endl;
		//break;
	}
	return 0;
}