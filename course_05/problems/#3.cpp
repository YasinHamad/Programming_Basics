#include <iostream>
#include <cmath>
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
void PrintResult(float num, string unit) {
	cout << "*** " << num << " " << unit << " ***" << endl;
}
void PrintResult(string result, string unit) {
	cout << "*** " << result << " " << unit << " ***" << endl;
}
void PrintResult(string result) {
	cout << "*** " << result << " ***" << endl;
}



bool IsPerfect(int num) {
	int sum = 0;

	for (int i = 1; i < num; i++) {
		if (num % i == 0) sum += i;
	}
	return sum == num;
}

void PrintResultsForPerfectNumber(int N) {

	if (IsPerfect(N)) cout << N << " is perfect number.";
	else cout << N << " is not perfect number.";
}



int main()
{
	system("color 0b");
	while (1) 
	{

		PrintResultsForPerfectNumber(ReadPositiveNum("Enter a positive number: "));

		cout << endl << endl;
	}
    return 0;
}