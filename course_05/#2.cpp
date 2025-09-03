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




enum enPrime { prime, notPrime};

enPrime IsPrime(int num) {
	int maxNum = num / 2;
	for (int i = 2; i <= maxNum; i++) {
		if (num % i == 0) return enPrime::notPrime;
	}
	return enPrime::prime;
}

void PrintAllPrimeNumbers(int N) {

	for (int i = 1; i <= N; i++) {
		if (IsPrime(i) == enPrime::prime) cout << i << " ";
	}
}



int main()
{
	system("color 0b");

	PrintAllPrimeNumbers(ReadPositiveNum("Enter a positive number: "));

	


	

    return 0;
}