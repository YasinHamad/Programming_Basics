bool IsPrime(int num) {
	if (num < 2) return false;
	int M = round(num / 2);
	for (int i = 2; i <= M; i++) {
		if (num % i == 0) return false;
	}
	return true;
}

int SearchInArray(int arr[], int size, int looking_for) {
	for (int i = 0; i < size; i++) {
		if (arr[i] == looking_for) {
			return i;
		}
	}
	return -1;
}
bool IsNumberInArray(int arr[], int size, int looking_for) {
	return -1 != SearchInArray(arr, size, looking_for);
}

void AddElementToArray(int element, int arr[], int& size) {
	arr[size++] = element;
}

void CopyDistinctElementsToArray(int arr1[], int arr2[], int size1, int& size2) {
	for (int i = 0; i < size1; i++) {
		if (!IsNumberInArray(arr2, size2, arr1[i]))
			AddElementToArray(arr1[i], arr2, size2);
	}
}

bool IsPalindromeArray(int arr[], int size) {
	int new_size = size / 2;
	for (int i = 0; i < new_size; i++) {
		if (arr[i] != arr[size - i - 1]) return false;
	}
	return true;
}
bool IsPalindromeArray2(int arr[], int size) {
	for (int i = 0, j = size - 1; i < j; i++, j--) {
		if (arr[i] != arr[j]) return false;
	}
	return true;
}

void ReverseArray(int arr[], int size) {
	int new_size = size / 2;
	for (int i = 0; i < new_size; i++) {
		Swap(arr[i], arr[size - (1 + i)]);
	}
}
void CopyReversedArray(int arr[], int arr2[], int size) {
	for (int i = 0; i < size; i++) {
		arr2[size - i - 1] = arr[i];
	}
}

void CopyArray(int arr[], int size, int c_arr[]) {
	for (int i = 0; i < size; i++) {
		c_arr[i] = arr[i];
	}
}
void Swap(int& num1, int& num2) {
	int aux = num1;
	num1 = num2;
	num2 = aux;
}

void FillArrayWithOrderInts(int arr[], int& size) {
	size = ReadPositiveNum("Enter array size: ");
	for (int i = 0; i < size; i++) {
		arr[i] = i + 1;
	}
}

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

int CountOddNumbers(int arr[], int size) {
	int counter = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i] % 2 != 0) counter++;
	}
	return counter;
}

int CountEvenNumbers(int arr[], int size) {
	int counter = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i] % 2 == 0) counter++;
	}
	return counter;
}

int CountPositiveNumbers(int arr[], int size) {
	int counter = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i] >= 0) counter++;
	}
	return counter;
}

int CountNegativeNumbers(int arr[], int size) {
	int counter = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i] < 0) counter++;
	}
	return counter;
}

int CountNegativeNumbers2(int arr[], int size) {
	return size - CountPositiveNumbers(arr, size);
}

void FillArray(int arr[], int& size) {
	arr[0] = 10;
	arr[1] = 20;
	arr[2] = 30;
	arr[3] = 30;
	arr[4] = 20;
	arr[5] = 10;
	size = 6;
}

float MyABS(float num) {
	if (num >= 0) return num;
	return num * (-1);
}

int MyRound(float num) {
	int new_num = num;
	if (num >= 0) {
		if (num - new_num >= 0.5) return new_num + 1;
		return new_num;
	}
	if ((num - new_num) * (-1) >= 0.5) return new_num - 1;
	return new_num;
}

float GetFractionPart(float num) {
	return num - int(num);
}

int MyRound(float num) {
	int IntPart = int(num);
	float FractionPart = GetFractionPart(num);

	if (abs(FractionPart) >= .5) {
		if (num >= 0) return ++IntPart;
		return --IntPart;
	}
	return IntPart;
}

int MyFloor(float num) {
	if (GetFractionPart(num) == 0) return num;

	int IntPart = int(num);
	if (num >= 0) return IntPart;
	return --IntPart;
}

int MyCeil(float num) {
	if (GetFractionPart(num) == 0) return num;

	int IntPart = int(num);
	if (num >= 0) return ++IntPart;
	return IntPart;
}

float MySQRT(float num) {
	if (num < 0) return -1;

	return pow(num, 0.5);
}

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

void FillArrayWithRandomValues(int arr[], int& size) {

	size = ReadPositiveNum("Enter array size: ");
	for (int i = 0; i < size; i++) {
		arr[i] = RandomNumber(-100, 100);
	}
}

void PrintArray(int arr[], int size) {
	cout << "Original Array : ";
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void CopyPrimeElementsToArray(int arr1[], int arr2[], int size1, int& size2) {
	for (int i = 0; i < size1; i++) {
		if (IsPrime(arr1[i]))
			AddElementToArray(arr1[i], arr2, size2);
	}
}

void CopyOddElementsToArray(int arr1[], int arr2[], int size1, int& size2) {
	for (int i = 0; i < size1; i++) {
		if ((arr1[i] % 2) != 0)
			AddElementToArray(arr1[i], arr2, size2);
	}
}

void ReadArraySemiDynamic(int arr[], int& size) {
	int flag = 0;

	do {
		AddElementToArray(ReadNum("\nEnter a number: "), arr, size);
		flag = ReadNum("Do you want to add more numbers? [0]:NO | [1]:YES ");
	} while (flag == 1);
}

string GenerateWord(en_char_type type, short length) {
	string word = "";
	for (int i = 0; i < length; i++) word += GetRandomChar(type);
	return word;
}

string GenerateKey(int number_of_words, en_char_type char_type, int word_digit_number) {
	string key = "";
	for (int i = 0; i < number_of_words; i++) {
		key += GenerateWord(char_type, word_digit_number);
		if (i != number_of_words - 1) key += "-";
	}
	return key;
}

void FillArrayWithKeys(string arr[], int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = GenerateKey(5, en_char_type::capital_letter, 3);
	}
}

void PrintArrayOfKeys(string arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << "Array[" << i << "] : " << arr[i] << endl;
	}
}

void ShuffleArrayElements2(int arr[], int size) {
	int rand_index_1 = 0;
	int rand_index_2 = 0;

	for (int i = 0; i < size; i++) {
		rand_index_1 = RandomNumber(0, size - 1);
		rand_index_2 = RandomNumber(0, size - 1);
		Swap(arr[rand_index_1], arr[rand_index_2]);
	}

}

void SumTwoArray(int arr1[], int arr2[], int size, int arr3[]) {
	for (int i = 0; i < size; i++) {
		arr3[i] = arr1[i] + arr2[i];
	}
}

void CopyPrimeNumbersToArray(int arr[], int size, int c_arr[], int& c_size) {
	int counter = 0;
	for (int i = 0; i < size; i++) {
		if (IsPrime(arr[i])) {
			c_arr[counter] = arr[i];
			counter++;
		}
	}
	c_size = counter;
}

float AverageOfArrayElements(int arr[], int size) {
	int sum = 0;
	for (int i = 1; i < size; i++) {
		sum += arr[i];
	}
	return sum * 1.0 / size;
}

int SumArray(int arr[], int size) {
	int sum = 0;
	for (int i = 1; i < size; i++) {
		sum += arr[i];
	}
	return sum;
}

int GetMaxNumberInArray(int arr[], int size) {
	int max = arr[0];
	for (int i = 1; i < size; i++) {
		max = arr[i] > max ? arr[i] : max;
	}
	return max;
}
int GetMinNumberInArray(int arr[], int size) {
	int min = arr[0];
	for (int i = 1; i < size; i++) {
		min = arr[i] < min ? arr[i] : min;
	}
	return min;
}

void ReadArrayElements(int arr[], int& size) {
	size = ReadPositiveNum("Enter array size: ");

	for (int i = 0; i < size; i++) {
		arr[i] = ReadNum("Element [" + to_string(i + 1) + "] : ");
	}
}

int CheckFrequency(int arr[], int numberToCheck, int size) {

	int counter = 0;
	for (int i = 0; i < size; i++) {
		if (numberToCheck == arr[i]) counter++;
	}
	return counter;
}

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

void LetterPattern(int N) {

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			char c = i + 64;
			cout << c;
		}
		cout << endl;
	}
}

void InvertedLetterPattern(int N) {

	for (int i = N; i >= 1; i--) {
		for (int j = 1; j <= i; j++) {
			char c = i + 64;
			cout << c;
		}
		cout << endl;
	}
}

void NumberPattern(int N) {

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) cout << i;
		cout << endl;
	}
}

void InvertedNumberPattern(int N) {

	for (int i = N; i > 0; i--) {
		for (int j = 1; j <= i; j++) cout << i;
		cout << endl;
	}
}

int ReverseNumber(int N) {

	int res = 0;


	while (N != 0) {
		res *= 10;
		res += N % 10;
		N /= 10;
	}

	return res;
}
bool IsPalindrome(int N) {
	return N == ReverseNumber(N);
}

int DigitFrequency(int N, int d) {

	int res = 0;


	while (N != 0) {
		if ((N % 10) == d) res++;
		N /= 10;
	}

	return res;
}

int RemoveDigit(int main_number, int digit) {
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

int SumOfDigits(int N) {

	int sum = 0;


	while (N != 0) {
		sum += N % 10;
		N /= 10;
	}

	return sum;
}

bool IsPerfect(int num) {
	int sum = 0;

	for (int i = 1; i < num; i++) {
		if (num % i == 0) sum += i;
	}
	return sum == num;
}