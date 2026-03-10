# 1 
What did you learn?
```cpp
// do you have data?
// if yes, then put it in a data structure
```

What changed?
```cpp
// added the functions, in allocators::two_dim_array
int** AllocateTwoDirArray(int rows, int columns);
void DeleteTwoDimArray(int** arr, int rows);

// added the functions, in fillers::two_dim_array
void FillTwoDimArrayWithRandomNumbers(int** arr, int rows, int columns, int from, int to);

// added the functions, in printers::two_dim_array
void PrintTwoDimArray(int** arr, int rows, int columns, int cell_width, enPosition position);
```
---
# 2 
What did you learn?
```cpp
// think how you will split the work into small tasks
```

What changed?
```cpp
// added the functions, in math::two_dim_array
int SumRows(int** source, int row_number, int columns);
int SumColumns(int** source, int rows, int column_number);
void SumMatrix(int** source, int rows, int columns, enMatrixSum directoin, int*& result, int& result_size);
```
---
# 3
What did you learn?
```cpp

```

What changed?
```cpp

```
---
# 4
What did you learn?
```cpp

```

What changed?
```cpp

```
---
# 5
What did you learn?
```cpp
// Do not forget to use `short` when needed instead of `int`
```

What changed?
```cpp

```
---
# 6
What did you learn?
```cpp

```

What changed?
```cpp
// added the functions, in fillers::two_dim_array
void FillTwoDimArrayWithOrderdNumbers(int** arr, int rows, int columns);
```
---
# 7
What did you learn?
```cpp

```

What changed?
```cpp
// added the functions, in math::two_dim_array
int** TransposedMatrix(int** source, int rows, int columns);
```
---
# 8
What did you learn?
```cpp

```

What changed?
```cpp
// added the functions, in math::two_dim_array
int** MuliplyTwoMatrices(int** matrix_01, int rows, int columns, int** matrix_02);
```
---
# 9
What did you learn?
```cpp

```

What changed?
```cpp
// added this functions to math
int* GetRow(int** matrix, int rows, int columns, int row_number);
int* GetColumn(int** matrix, int rows, int columns, int column_number);

// added this functions to printers
void PrintArray(int* arr, int size, string message);
void PrintTwoDimArray(int** arr, int rows, int columns, int cell_width);

```
---
# 10
What did you learn?
```cpp

```

What changed?
```cpp
// add functions to math
int SumMatrix(int** matrix, int rows, int columns);
```
---
# 11
What did you learn?
```cpp

```

What changed?
```cpp
// Added the function
bool EqualMatrices(int** matrix_01, int** matrix_02, int rows, int columns);
```
---
# 12
What did you learn?
```cpp
// the name of the below function is better if it is AreTypicalMatrices
```

What changed?
```cpp
// added the function
bool MatricesTypicallyEqual(int** matrix_01, int** matrix_02, int rows, int columns);
```
---
# 13
What did you learn?
```cpp
// instead of: if else if else
// you can use the if(__ && __)
```

What changed?
```cpp

// added the functions
void FillIdentityMatrix(int** matrix, int rows, int columns);
bool IsMatrixIdentity(int** matrix, int rows, int columns);
```
---
# 14
What did you learn?
```cpp

```

What changed?
```cpp

// added the functions
bool IsMatrixScalar(int** matrix, int rows, int columns);
void FillScalarMatrix(int** matrix, int rows, int columns, int diagonal);
```
---
# 15
What did you learn?
```cpp

```

What changed?
```cpp
int CountNumberInMatrix(int** matrix, int rows, int columns, int number);
```
---
# 16
What did you learn?
```cpp

```

What changed?
```cpp
bool IsSparceMatrix(int** matrix, int rows, int columns);
```
---
# 17
What did you learn?
```cpp

```

What changed?
```cpp
bool DoesNumberExistInMatrix(int** matrix, int rows, int columns, int number);
```
---
# 18
What did you learn?
```cpp

```

What changed?
```cpp
void PrintVector(vector<int>& source);
vector<int> IntersectedNumbers(int** matrix_01, int rows_01, int columns_01, int** matrix_02, int rows_02, int columns_02);
```
---
# 19
What did you learn?
```cpp

```

What changed?
```cpp
int MinNumberInMatrix(int** matrix, int rows, int columns);
int MaxNumberInMatrix(int** matrix, int rows, int columns);
```
---
# 20
What did you learn?
```cpp

```

What changed?
```cpp
bool IsArrayPalindrom(int* source, int size);
bool IsMatrixPalindrom(int** matrix, int rows, int columns);
void FillPalindromMatrix(int** matrix, int rows, int columns, int random_numbers_start, int random_numbers_end);
```
---
# 21
What did you learn?
```cpp

```

What changed?
```cpp
int* CalculateFibonacci(int size);
```
---
# 22
What did you learn?
```cpp
// start small and THEN grow
// make a small version that is actaully work, then make it bigger and bigger
```

What changed?
```cpp
void CalculateFibonacciRecHelper(int size, int prev01, int prev02, int* cell);
int* CalculateFibonacciRec(int size);
```
---
# 23
What did you learn?
```cpp

```

What changed?
```cpp
void PrintVectorOfChars(vector<char>& source);
string ReadASentence(string str);
vector<char> FirstLetterOfEachWord(string source)
```
---
# 24
What did you learn?
```cpp

```

What changed?
```cpp
void UpperFirstLetterOfEachWord(string& source);
```
---
# 25
What did you learn?
```cpp

```

What changed?
```cpp
void LowerFirstLetterOfEachWord(string& source);
```
---
# 26
What did you learn?
```cpp

```

What changed?
```cpp
void LowerString(string& source);
void UpperString(string& source);
```
---
# 27
What did you learn?
```cpp

```

What changed?
```cpp
void InvertChar(char& c);
char ReadChar(string message);
```
---
# 28
What did you learn?
```cpp

```

What changed?
```cpp
void InvertStringChars(string& source);
```
---
# 29
What did you learn?
```cpp

```

What changed?
```cpp
enum enLetterType {LowerLetter,CapitalLetter};
int CountCapitalLetters(string source);
int CountLowerLetters(string source);
int CountLetters(string source, enLetterType letter_type);
```
---
# 30
What did you learn?
```cpp

```

What changed?
```cpp
int CountLetterInString(string source, char c);
```
---
# 31
What did you learn?
```cpp

```

What changed?
```cpp

// change this
int CountLetterInString(string source, char c, bool match_case = true);
```
---
# 32
What did you learn?
```cpp

```

What changed?
```cpp
bool isVowel(char c);
```
---
# 33
What did you learn?
```cpp

```

What changed?
```cpp
int CountVowels(string source);
```
---
# 34
What did you learn?
```cpp

```

What changed?
```cpp
vector<char> GetVowels(string source);
```
---
# 35
What did you learn?
```cpp
// use
string variable = "";
if(variable.find("something") == std::string::npos); // to check if find("some_string") did not find anything

variable.find();
variable.substr(starting_index, count);
variable.erase();
```

What changed?
```cpp
void PrintVectorOfStrings(vector<string>& source);

```
---
# 36
What did you learn?
```cpp

```

What changed?
```cpp
int CountWords(string source, string word_spliter);
```
---
# 37
What did you learn?
```cpp

```

What changed?
```cpp
// I just rewrote the SplitString function
vector<string> Split(string source, string delimiter);
```
---
# 38
What did you learn?
```cpp

```

What changed?
```cpp
string TrimLeft(string source);
string TrimRight(string source);
string Trim(string source);
```
---
# 39
What did you learn?
```cpp

```

What changed?
```cpp
string JoinString(vector<string> strings, string separator);
```
---
# 40
What did you learn?
```cpp
// Overloading makes things easier
// see the above and bottom functions
// instead of having JoinStringByVector and JoinStringByArray
// you just have JoinString
```

What changed?
```cpp
string JoinString(string* strings, int size, string separator);
```
---
# 41
What did you learn?
```cpp
// loop over a vector from back to begin
vector<-> test;
vector<->::itorator itor = test.begin(); // this gives you a pointer to the first element
// test.end() gives you a pointer to -> right after the last element
```

What changed?
```cpp
string ReversStringWords(string source, string separator);
```
---
# 42
What did you learn?
```cpp
string test;
test.replace(first_index_number, number_of_chars_to_replace, "new_word");
// you can use test.find(~) to find the first occurance
```

What changed?
```cpp
string ReplaceWordInString(string source, string old_word, string new_word);
string ReplaceWordInStringWithBuiltInFunction(string source, string old_word, string new_word);
```
---
# 43
What did you learn?
```cpp
// if you only have two values in the enum, you do not need it
// make it true/false
// use the built in functions, do not build everything form zero
```

What changed?
```cpp
string ReplaceWordInString(string source, string old_word, string new_word, bool case_sensetive = true);
```
---
# 44
What did you learn?
```cpp

```

What changed?
```cpp
string RemovePunctuations(string source);
```
---
# 45
What did you learn?
```cpp
// notice when to use the cin.ignore function
void FillAccountData(stAccount& account) {
	cout << "Enter account number: ";
	getline(cin, account.number);

	cout << "Enter pin code: ";
	cin >> account.pin_code;
	cin.ignore(1, '\n');

	cout << "Enter name: ";
	getline(cin, account.name);

	cout << "Enter phone: ";
	getline(cin, account.phone);

	cout << "Enter account balance: ";
	cin >> account.balance;
	cin.ignore(1, '\n');
}
```

What changed?
```cpp
struct stAccount;
stAccount ReadNewAccount();
string ConvertAccountToLine(const stAccount& account, string separator)
```
---
# 46
What did you learn?
```cpp
// How to convert string to double?
double_var = std::stod(string_var);

// after writing a function, ask yourself, does my function depend on something hardcoded?
// do not forget, you can use default values
```

What changed?
```cpp
void PrintAccount(const stAccount& account);
stAccount ConvertLineToAccount(string line, string separator = "#||#");
```
---
# 47
What did you learn?
```cpp
// we have another way to soleve the problem of whitespaces like '\n'
// std::ws will empty the buffer
getline(cin >> std::ws, string_var);
```

What changed?
```cpp
bool AddAccountToFile(const string file_name, string line);
void AddNewAccount();
void AddAccounts();
```
---
# 48
What did you learn?
```cpp

```

What changed?
```cpp
vector<stAccount> RetriveAccountsData(const string file_name);
void PrintAccounts(vector<stAccount> accounts);
```
---
# 49
What did you learn?
```cpp

```

What changed?
```cpp
bool FindAccountByNumber(string account_number, stAccount& resultant_account);
```
---
# 50
What did you learn?
```cpp
// when defining a struct
// you can put a default value
struct person{
	bool IsDead = false;
}
```

What changed?
```cpp
bool FindAccountByNumber(string account_number, vector<stAccount> accounts, stAccount& resultant_account);
bool SaveAccountsToFile(const string file_name, vector<stAccount> accounts);
bool MarkAsDeleted(vector<stAccount>& accounts, stAccount account);
bool DeleteAccountByNumber(string account_number);
void PerformDeleteAccount();
```
---
# 51
What did you learn?
```cpp

```

What changed?
```cpp
void UpdateAccountData(stAccount& account);
bool UpdateAccountInVector(vector<stAccount>& accounts, stAccount account);
bool UpdateAccountByNumber(string account_number);
void PerformUpdateAccount();
```
---
# Project
What did you learn?
```cpp
// when you want to declare a function like this
stAccount ConvertLineToAccount(string line, string separator = "#||#");
// you do not put "= #||#" in the definition
// you do not initialize the default values in the definition
// you only put
stAccount ConvertLineToAccount(string line, string separator){}

// you can pause the program by writing
system("pause"); // this will display a message "press any key to continue . . ."
// if you want to write the message yourself, you can write
cout << "your message . . .";
system("pause>0");
// any one of them will make the program continue executing after pressing any key
```

What changed?
```cpp

```
---

```ps
// script used to print the above layout
foreach($i in 1..50){write "# $i`nWhat did you learn?";write "``````cpp`n`n``````";  write "`nWhat changed?`n``````cpp`n`n``````n---"}
```