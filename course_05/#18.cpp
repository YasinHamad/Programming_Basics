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

string Encrypt(string word) {
	for (int i = 0; i < word.length(); i++) {
		word[i] = word[i] + 2;
	}

	return word;
}
string Decrypt(string word) {
	for (int i = 0; i < word.length(); i++) {
		word[i] = word[i] - 2;
	}

	return word;
}




int main()
{
	system("color 0b");
	while (1)
	{
		string word = ReadAWord("Enter your name: ");
		string en_word = Encrypt(word);
		string de_word = Decrypt(en_word);
		cout << "Before enc: " << word << endl;
		cout << "after enc: " << en_word << endl;
		cout << "after dec: " << de_word << endl;


		cout << endl << endl;
		break;
	}
	return 0;
}