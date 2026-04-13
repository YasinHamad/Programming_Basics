Errors:
- Syntax error
- Runtime error
- Logical error

Breakpoint: if you reach at this line, stop.

While debugging you can hover over the variable to see its value.
You can go to the next step without putting a breakpoint.
You can debug your program line by line.
You can step to the next breakpoint.
You can hold and move the yellow arrow to the line you want to re-execute it.
Disable breakpoints -> if you want to run the program without the affect of the breakpoints you have. You use this when you want to reuse the breakpoints again after the run.
Delete all breakpoints.

You can find your variables in the autos window, so you can trace. (You can find the autos window in the debug mood).
Select an expression -> Quickwatch: to see its result. You can edit the expression, and write a new expression. You can also highlight functions.
(You can find this in the debug mood)

If you hover over the variable, you can change its value.

Step into -> line by line.
Step over -> if there a function, it does not go deep in it. It execute the whole function without doing that.
Step out -> if it is inside the function, it executes the whole function and goes out of it to the next line.
(If you did that inside the main, the program ends).

---

To create a library:
- Go to Header Files folder.
- Add a new .h file.
- Do not touch the "#pragma once".
- If you want to include some library, add it after "pragma once". (It actually worked in the opposite order, too!).
- Add a new Namespace. It is better to make its name similar to your library name.
- Put your functions and procedures in this Namespace. 
- Build your project.
- To include the library in your main file -> `#include "your_library_name.h"`
- To call a function -> `your_namepace_name::your_function_name()`. You can write `using namespace your_namespace;` and then use the function directly.
- This way `Namespace::your_function_name()` is better, to avoid function name problems, in case you have the same function name in two diff namespaces.
- To define a namespace -> `namespace your_namepace_name{}`

`condition ? true : false;` -> short hand if. **It returns results**
```cpp
string result;
result = (51 > 50) ? "Pass" : "Fial";

// you can use nested short hand ifs
string CheckNumber(int number) {
	return (number >= 0) ?
		((number == 0) ? "Zero\n" : "Positive\n") :
		"Negative\n";
}
```

Ranged loop -> use this when you want to iterate in collections
```cpp
int arr[3] = { 2,3,4 };

for (int n : arr) {
	cout << n << endl;
}

// or you can do this

for (int n : { 2,3,4 }) {
	cout << n << endl;
}
```

To read a valid number
```cpp
int ReadNumber(string message) {
	int Number;
	cout << message;
	cin >> Number;
	while (cin.fail()) {
		// user didn't enter a number    
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Invalid Number, Enter a valid one: ";
		cin >> Number;

	}
	return Number;
}
```

Logical And operator -> &&
Bitwise And operator -> &
```cpp
int result = (12 & 25); // 8

12 = 0000 1100
25 = 0001 1001  &
---------------
     0000 1000
= 8
```

Logical Or operator -> ||
Bitwise Or operator -> |
```cpp
int result = (12 | 25); // 29

12 = 0000 1100
25 = 0001 1001  |
---------------
     0001 1101
= 29
```

---
```cpp
// function declaration
int add(int, int);

// function definition
int add(int a, int b){
	retrun a+b;
}
```
You can put the function declaration then the main() then the function definition.

Optional parameters
```cpp
int Sum(int a, int b, int c = 0, int d = 0) {
	return (a + b + c + d);
}

// All of these are valid
cout << Sum(10, 20) << endl;
cout << Sum(10, 20, 30) << endl;
cout << Sum(10, 20, 30, 40) << endl;
```

Function Overloading
```cpp

// notice that they have the same name
int MySum(int a, int b){
	return a+b;
}
int MySum(int a, int b, int c){
	return a+b;
}
```

Right click on the function, then click view call hierarchy to see who called this function.

VS Function Tips
- Right click -> find all references
- Click on the function name to highlight it.
- Right click -> go to definition
- Right click -> peek definition. To see the function definition quickly
- Right click on the function name -> rename. To change the function name in the entire solution

Recursion
- You can not call it a lot of times, because there is a limit to the call stack. If you did, you'll have an exception.
- Use recursion when you are sure you'll not hit the call stack limit.

---

**Static Variables**
```cpp
void MyFun() {
	static int number = 1;
	cout << "Number is: " << number << endl;
	number++;
}

int main()
{
	while (true) {
		
		MyFun();
		MyFun();
		MyFun();
		break;
	}
	return 0;
}
// 1
// 2
// 3

// allocate this variable in the memory, and remember its value each time I call this function.
// the program knows that this variable is for this funciton.
// the life time for this variable: program life, not function life.
```

**Auto Variables**
```cpp
auto int_var = 10;
auto float_var = 10.2;
auto string_var = "Yasin Hamad";

cout << int_var << endl;
cout << float_var << endl;
cout << string_var << endl;

// it knows the variable type at the first initialization.
// do not use it :)
```

**Register Variables** : normal variables -> allocated in RAM. register variables -> allocated in a Register. It is not available any more. 

---
**`Printf`**
It is easier than `cout` :)

| Notation | Variable Type  |
| -------- | -------------- |
| %d       | int            |
| %f       | float, double  |
| %s       | array of chars |
| %c       | char           |
```cpp
printf("This number is on 3 digits: %0*d \n", 3, 2); // 002
printf("This number is on 3 digits: %03d \n", 2); // 002

printf("3 digits after comma: %.*f \n", 3, 2.123567); // 2.124 notice the 4
printf("3 digits after comma: %.*f \n", 3, 2.1); // 2.100
printf("3 digits after comma: %.3f \n", 2.1); // 2.100

// printf does not deal with string variables, you need to use an array of chars

char name[] = "Yasin Hamad";

printf("This is you name %s, welcome! \n", name); // This is you name Yasin Hamad, welcome!

printf("This char is on 3 digits :%*c \n", 3, 'Y'); // :  Y
printf("This char is on 3 digits :%3c \n", 'Y'); // :  Y
```

**setw**
```cpp
// we use this for formatting the output
// include this

#include <iomanip>

cout << "---------|--------------------------------|---------|" << endl;
cout << "  Code   |              Name              |  Mark   |" << endl;
cout << "---------|--------------------------------|---------|" << endl;

cout << setw(9) << "I3301" << "|" << setw(32) << "Software Engineering" << "|" << setw(9) << "95" << "|" << endl;
cout << setw(9) << "I3302" << "|" << setw(32) << "Server Side Language" << "|" << setw(9) << "88" << "|" << endl;
cout << setw(9) << "I3303" << "|" << setw(32) << "Operating System" << "|" << setw(9) << "82" << "|" << endl;
cout << setw(9) << "I3304" << "|" << setw(32) << "Network" << "|" << setw(9) << "91" << "|" << endl;

cout << "---------|--------------------------------|---------|" << endl;
```

During the lesson, I made this, to print in the middle
```cpp

enum enPosition { left, center, right };

bool IsEven(int number) {
	return (number % 2) == 0;
}

string PrintSpaces(int number) {
	string result = "";
	for (int i = 0; i < number; i++) result += " ";
	return result;
}

string FormatedCout(int number, string sentence, enPosition position) {
	int length = sentence.length();
	int padding_summation = length - number;

	string result = "";

	int left_padding = 0;
	int right_padding = 0;

	switch (position)
	{
	case(enPosition::center):
	{
		if ((IsEven(length) && IsEven(number)) || (!IsEven(length) && !IsEven(number))) {
			left_padding = right_padding = (number - length) / 2;
		}
		else {
			left_padding = (number - length) / 2;
			right_padding = (number - length) / 2;
			right_padding++;
		}

		result += PrintSpaces(left_padding);
		result += sentence;
		result += PrintSpaces(right_padding);
		break;
	}
	case(enPosition::left):
	{
		result += sentence;
		result += PrintSpaces(number - length);
		break;
	}
	default:
	{
		result += PrintSpaces(number - length);
		result += sentence;
		break;
	}
	}
	return result;
}


int main()
{
	while (true) {
		cout << "---------|--------------------------------|---------|" << endl;
		cout << "  Code   |              Name              |  Mark   |" << endl;
		cout << "---------|--------------------------------|---------|" << endl;

		cout << FormatedCout(9, "I3301", enPosition::right) << 
			"|" << FormatedCout(32, "Software Engineering", enPosition::right) << 
			"|" << FormatedCout(9, "95", enPosition::right) << 
			"|" << endl;

		cout << FormatedCout(9, "I3302", enPosition::right) << 
			"|" << FormatedCout(32, "Server Side Language", enPosition::right) << 
			"|" << FormatedCout(9, "88", enPosition::right) << 
			"|" << endl;

		cout << FormatedCout(9, "I3303", enPosition::right) << 
			"|" << FormatedCout(32, "Operating System", enPosition::right) << 
			"|" << FormatedCout(9, "82", enPosition::right) << 
			"|" << endl;

		cout << FormatedCout(9, "I3304", enPosition::right) << 
			"|" << FormatedCout(32, "Network", enPosition::right) << 
			"|" << FormatedCout(9, "91", enPosition::right) << 
			"|" << endl;
		cout << "---------|--------------------------------|---------|" << endl;
		break;
	}
	return 0;
}
```

---
# Two Dim Array
```cpp
// initialization
int arr[3][4] = {
	{1,2,3,4},
	{5,6,7,8},
	{9,10,11,12}
};
```

# Vectors
It is same as arrays, but the size is dynamic.
```cpp
#include <vector>

// std::vector <Type> vector_name

vector <int> vNumbers = {1,2,3,4};

for(int e : vNumbers){
	cout << e;
}

// in e you have a COPY of each element. That is slow.

for(int &e : vNumbers){
	cout << e;
}

// This is faster. You have a reference to each element.
```

How to add an element?
```cpp
vector <int> vNumbers;

vNumbers.push_back(10);
vNumbers.push_back(20);
vNumbers.push_back(30);
vNumbers.push_back(40);
vNumbers.push_back(50);

for (int &e : vNumbers) {
	cout << e << " ";
}

cout << endl;

// 10 20 30 40 50
```

How to remove an element?
```cpp
vector <int> vNumbers;

vNumbers.push_back(1);
vNumbers.push_back(2);
vNumbers.push_back(3);

for (int& i : vNumbers) {
	cout << i << " ";
}cout << endl;
// 1 2 3

if (!vNumbers.empty()) {
	vNumbers.pop_back();
}
// you can use the following or the above one
if (vNumbers.size() > 0) {
	vNumbers.pop_back();
}

for (int& i : vNumbers) {
	cout << i << " ";
}cout << endl;
// 1 2
```

To clear the vector (remove all elements)
```cpp
vNumbers.clear();
```

Vector functions
```cpp
cout << vNumbers.front() << endl; // the front element
cout << vNumbers.back() << endl; // the last element
cout << vNumbers.size() << endl; // how many element in the vector
cout << vNumbers.capacity() << endl; // what is the actual size of the vector in the memory

// do not forget to check if(vNumbers.empty()) before using the .front() and .back() :) I hope you notice this note in the future
```

Call by ref and call by value
```cpp
void function(int x){} // by value
void function(int &x){} // by reference

int a; 
cout << a << endl;
cout << &a << endl; // address of a
```

```cpp
int x = 10;
int& y = x;

// x == y and &x == &y

// if y is changed, x so will.
```

# Pointers
```cpp

// Remember: for each variable you have: its name, value, and address.
// In pointers, we store addresses.

int x = 10;
int* p = &x;
cout << "x value: " << x << endl; // 10
cout << "x address: " << &x << endl; // 0000007B082FFB84

cout << "pointer value: " << p << endl; // 0000007B082FFB84
cout << "pointer address: " << &p << endl; // 0000007B082FFBA8
cout << "pointer address value: " << *p << endl; // 10

*p = 20;
cout << "x value: " << x << endl; // 20
cout << "pointer address value: " << *p << endl; // 20
```

# Pointer vs Reference
```cpp
// ref -> another name for the variable.
// when you type int& y = x; that means y is for x. You can't change that later.

int x = 10;
int z = 30;
int& y = x;
int* p = &x;

*p = 20;
cout << y << endl; // 20
y = z; // this does not mean y will change if you changed z any more.
// &y = z; and this is wrong
cout << y << endl; // 30
cout << x << endl; // 30
cout << *p << endl; // 30
y = 100;
cout << y << endl; // 100
cout << x << endl; // 100
cout << *p << endl; // 100
cout << z << endl; // 30
z = 300;
cout << y << endl; // 100
cout << x << endl; // 100
cout << *p << endl; // 100
cout << z << endl; // 300
```

How to convert an address to string
```cpp
string ConvertAddressToString(void * address) {
	ostringstream oss;
	string address_st = "";

	oss << address;
	address_st += oss.str();
	oss.str("");
	oss.clear();

	return address_st;
}
```

You do not need to read the following code
```cpp
#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
#include <vector>
#include <iomanip> // for setw()

#include <sstream> // for ostringstream oss;

#include "readers.h"
#include "printers.h"
#include "converters.h"

using namespace std;

#define SIZE 50

int main()
{

	while (true) {
		
		int arr[5] = { 10,20,30,40,50 };
		int* ptr = arr;

		string address, sentence, value;
		ostringstream oss;

		cout << "   variable   " << "|" << "          address          " << "|" << "          value          " << "|\n";
		cout << "--------------" << "|" << "---------------------------" << "|" << "-------------------------" << "|\n";
		



		sentence = "arr";


		address = converters::ConvertAddressToString(&arr);

		value = converters::ConvertAddressToString(arr);

		cout << printers::FormatedCout(14, sentence, printers::enPosition::center);
		cout << "|";

		cout << printers::FormatedCout(27, address, printers::enPosition::center);
		cout << "|";

		cout << printers::FormatedCout(25, value, printers::enPosition::center);
		cout << "|\n";

		cout << "--------------" << "|" << "---------------------------" << "|" << "-------------------------" << "|\n";

		for (int i = 0; i < 5; i++) {
			sentence = "arr[";
			sentence += to_string(i);
			sentence += "]";

			
			address = converters::ConvertAddressToString(&arr[i]);


			value = to_string(arr[i]);

			cout << printers::FormatedCout(14, sentence, printers::enPosition::center);
			cout << "|";

			cout << printers::FormatedCout(27, address, printers::enPosition::center);
			cout << "|";

			cout << printers::FormatedCout(25, value, printers::enPosition::center);
			cout << "|\n";


		}
		cout << "--------------" << "|" << "---------------------------" << "|" << "-------------------------" << "|\n";

		sentence = "ptr";
		address = converters::ConvertAddressToString(&ptr);

		value = converters::ConvertAddressToString(ptr);

		cout << printers::FormatedCout(14, sentence, printers::enPosition::center);
		cout << "|";

		cout << printers::FormatedCout(27, address, printers::enPosition::center);
		cout << "|";

		cout << printers::FormatedCout(25, value, printers::enPosition::center);
		cout << "|\n";

		cout << "--------------" << "|" << "---------------------------" << "|" << "-------------------------" << "|\n";

		for (int i = 0; i < 5; i++) {
			string sentence = "ptr + ";
			sentence += to_string(i);

			address = "-";


			value = converters::ConvertAddressToString(ptr + i);

			cout << printers::FormatedCout(14, sentence, printers::enPosition::center);
			cout << "|";

			cout << printers::FormatedCout(27, address, printers::enPosition::center);
			cout << "|";

			cout << printers::FormatedCout(25, value, printers::enPosition::center);
			cout << "|\n";


		}
		cout << "--------------" << "|" << "---------------------------" << "|" << "-------------------------" << "|\n";

		for (int i = 0; i < 5; i++) {
			string sentence = "*(ptr + ";
			sentence += to_string(i);
			sentence += ")";

			address = converters::ConvertAddressToString(&(*(ptr + i)));


			value = to_string(*(ptr + i));

			cout << printers::FormatedCout(14, sentence, printers::enPosition::center);
			cout << "|";

			cout << printers::FormatedCout(27, address, printers::enPosition::center);
			cout << "|";

			cout << printers::FormatedCout(25, value, printers::enPosition::center);
			cout << "|\n";


		}
		cout << "--------------" << "|" << "---------------------------" << "|" << "-------------------------" << "|\n";

		
	


		break;
	}

	return 0;
}

// this is the result ![[Pasted image 20250908083240.png]]
```
[[Pasted image 20250908083240.png]]
# Pointer and Structure
```cpp
stPerson person, * ptr;
ptr = &person;
person.first_name = "Yasin";
ptr->last_name = "Hamad";

Print("First name: " + person.first_name);
Print("Lirst name: " + ptr->last_name);
```

# Void pointer
It is a normal pointer.
You can store addresses of diff types in it.
You need to cast when you want to use the value it points to.

```cpp
int a = 10;
int* ptr = &a;
void* vptr = &a;

cout << ptr << endl;//   000000316ACFF814
cout << vptr << endl; // 000000316ACFF814

cout << *ptr << endl;
//cout << *vptr << endl; error, you need to cast
cout << *(static_cast<int*>(vptr)) << endl;
```

# Memory Allocation
```cpp
int* i_ptr = NULL;
float* f_ptr = NULL;

// allocate memory
i_ptr = new int;
f_ptr = new float;

*i_ptr = 25;
*f_ptr = 25.5;

cout << *i_ptr << endl;
cout << *f_ptr << endl;

// deallocate the memory
delete i_ptr;
delete f_ptr;
```

# Memory allocation and arrays
```cpp

int* arr_ptr = NULL;
int size = 0;
cout << "Enter array size: ";
cin >> size;

arr_ptr = new int[size];

for (int i = 0; i < size; i++) {
	*(arr_ptr + i) = i;
	cout << *(arr_ptr + i) << " ";
}

delete[] arr_ptr;

```

# Stack vs Heap
When we say memory, we mean RAM.
RAM is four parts

| 1. Source Code / Instructions                        |
| ---------------------------------------------------- |
| 2. Static / Global                                   |
| 3. Stack: local variables / functions / pointers     |
| 4. Heap: any dynamic variables / objs / arrays etc.. |
In stack you have limited memory for your program.

```cpp
int *ptr = new int;
// ptr -> in Stack
// the allocated space for int -> in Heap
```

# More about vectors

How to access the elements
```cpp
vector<int> nums = { 1,2,3,4,5 };
// vector<int> nums{ 1,2,3,4,5 }; this is also correct

cout << "Element at index 1 is: " << nums[1] << endl;
// nums[5] -> warning

cout << "Element at index 1 is: " << nums.at(1) << endl;
// nums[5] -> exception
```

How to change an element
```cpp
for (const int& i : nums) {
	cout << i << " ";
	// i = 22; because of "const" you can not change the i anymore.
	/// "const" make a lock on i. "read-only"
	// which is the vector elements. Notice the &.
	// they are making a new i for each iteration.
}

for (int& i : nums) {
	i = 20;// here we are changing the vector elements.
	cout << i << " ";
}

nums[0] = 1;
nums.at(1) = 2;

// best way to loop if you do not want to change anything
for (const int& i : nums) {
	cout << i << " ";
}
```

Vector iterator over the vector using pointers
```cpp
vector<int> nums = { 1,2,3,4,5 };

vector<int>::iterator iter;

for (iter = nums.begin(); iter != nums.end(); iter++) {
	cout << "Value: " << *iter << endl;
}
```

# Exception Handling
Try-catch makes your program slower. Use it when you do not have any other way.

```cpp
vector<int> nums = { 1,2,3,4,5 };

try {
	nums.at(5);
}
catch (...) {
	cout << "You have an exception" << endl;
}
```

# Strings

```cpp
string s = "My name is Yasin Hamad. I love programming.";

// string length
cout << s.length() << endl;

// the char at this position
cout << s.at(5) << endl;

// put this at the end of the string
s.append(" I am a human.");
cout << s << endl;

s.insert(5, "INSERTED TEXT");
cout << s << endl;

// returns a string. From char 20 to 25
cout << s.substr(20, 5) << endl;

// insert this char at the end
s.push_back('Y');
cout << s << endl;

// remove an element from the end
s.pop_back();
cout << s << endl;

// If found, it returns the position of the first letter. Otherwise returns a big number.
// You can find this number in s.npos
cout << s.find("Yasin") << endl;
cout << s.find("yasin") << endl;
if (s.find("yasin") == s.npos) {
	cout << "Substring not found!" << endl;
}

s.clear();
cout << s << endl;
```

# Some functions in the `cctype` library

```cpp
#include <cctype>

// toupper('a')
// tolower('a')

// the following four functions return zero if false, and not zero if true

// isupper('A')
// islower('A')

// isdigit('A')
// ispunct('A')

cout << toupper('a') << endl; // 65
cout << toupper('A') << endl; // 65
cout << toupper('3') << endl; // 51 is 3 ascii code
char c = toupper('3');
cout << c << endl; // 3
c = toupper('a');
cout << c << endl; // A

cout << printers::PrintDashes(20) << endl;

cout << tolower('a') << endl; // 97
cout << tolower('A') << endl; // 97
cout << tolower('3') << endl; // 51
c = tolower('3');
cout << c << endl; // 3
c = tolower('a');
cout << c << endl; // a

cout << printers::PrintDashes(20) << endl;

cout << isupper('A') << endl; // use this to check if the char (A-Z)
cout << isupper('a') << endl;
cout << isupper('3') << endl;

cout << islower('A') << endl; // use this to check if the char (a-z)
cout << islower('a') << endl;
cout << islower('3') << endl;

cout << printers::PrintDashes(20) << endl;

cout << isdigit('0') << endl; // use this to check if the char (0-9)
cout << isdigit('a') << endl;

cout << printers::PrintDashes(20) << endl;

// punctuation characters are !"#$%&'()*+,-./:;<=>?@[\]^_`{|}~
cout << ispunct('a') << endl;
cout << ispunct('@') << endl;
```
# Files

Open-Write-Close
```cpp

#include <fstream>

fstream my_file;
my_file.open("text01.txt", ios::out);

if (my_file.is_open()) {
	my_file << "First line\n";
	my_file << "Second line\n";
	my_file << "Third line\n";

	my_file.close();
}

// ios::out -> Open it in write mode. If it does not exist, create and open it. If it exists erase everything and open it.
// my_file.close(); if you do not put this, the computer prevent anyone from opening this file(file in use).
```

Append
```cpp
fstream my_file;
my_file.open("text021.txt", ios::out | ios::app);

if (my_file.is_open()) {
	my_file << "First line\n";
	my_file << "Second line\n";
	my_file << "Third line\n";

	my_file.close();
}

// | -> more
// ios::out | ios::app -> w and a. a proirity is higher.
```

Read mode
```cpp
void PrintFileContent(string file_path) {
	fstream my_file;
	my_file.open(file_path, ios::in);

	if (my_file.is_open()) {
		string line = "";
		cout << PrintNameInMiddleOfDashes(20, file_path) << endl;

		while (getline(my_file, line)) {
			cout << line << endl;
		}

		my_file.close();
		cout << PrintDashes(20) << endl;
	}
}

// ios::in -> r
```

Load data to vector 
```cpp

// In files, you can not edit/delete
// You need to load -> edit/delete -> write
// We just know how to r-w-a

void LoadDataFromFileToVector(string file_path, vector<string>& _vector) {
	fstream my_file;
	my_file.open(file_path, ios::in);

	if (my_file.is_open()) {
		string line = "";

		while (getline(my_file, line)) {
			_vector.push_back(line);
		}

		my_file.close();
	}
}
```

Save vector to file
```cpp
void SaveVectorToFile(const string file_path, vector<string>& _vector) {
	fstream my_file;
	my_file.open(file_path, ios::out);

	if (my_file.is_open()) {

		for (string& line : _vector) {
			if (!line.empty()) {
				my_file << line << endl;
			}
		}

		my_file.close();
	}
}
```

Delete and update record
```cpp
void DeleteRecordFromFile(const string file_path, string record) {
	vector<string> _vector;

	files::LoadDataFromFileToVector(file_path, _vector);

	for (string& line : _vector) {
		if (line == record) line = "";
	}

	files::SaveVectorToFile(file_path, _vector);
}

void UpdateRecordInFile(const string file_path, string record, string new_record) {
	vector<string> _vector;

	files::LoadDataFromFileToVector(file_path, _vector);

	for (string& line : _vector) {
		if (line == record) line = new_record;
	}

	files::SaveVectorToFile(file_path, _vector);
}
```

# Date and Time
Local time -> you country
Universal time -> Greenwich

```cpp
#pragma warning(disable : 4996) // for removing the ctime() function warning
#include <ctime>

time_t t = time(0); // you have in t the current data and time in seconds

char* t_string = ctime(&t); // convert the seconds to readable date and time + as string
cout << "Local time: " << t_string << endl;



tm* gmtm = gmtime(&t); // now we have in the gmtm(pointer to sturct of type tm) everythings related to Greenwich time.
t_string = asctime(gmtm); // convert it to string
cout << "Universal time: " << t_string << endl;




// t_stirng is char* -> this is a C library :)
```

I made two functions from the above code
```cpp

#pragma warning(disable : 4996)
#include <ctime>

char* GetCurrentTime() {
	time_t t = time(0);

	char* t_string = ctime(&t);
	
	return t_string;
}

char* GetGreenwichTime() {
	time_t t = time(0);
	char* t_string = NULL;

	tm* gmtm = gmtime(&t);
	t_string = asctime(gmtm);

	return t_string;
}
```

tm structure
```cpp
time_t t = time(0);

tm* now = localtime(&t);

// now->tm_year gives you the number of years from 1900 until today
cout << "Year   :" << now->tm_year + 1900 << endl;
// now->tm_mon gives you today's month-1
cout << "Month  :" << now->tm_mon + 1 << endl;
// tm_mday -> month day
cout << "Day  :" << now->tm_mday << endl;
cout << "Hour  :" << now->tm_hour << endl;
cout << "Minute  :" << now->tm_min << endl;
cout << "Seconds  :" << now->tm_sec << endl;
// number of the day in the week (Sunday is the number 0)
cout << "Week Day  :" << now->tm_wday << endl;
// number of the day in the year (1-Jan is the first day)
cout << "Year Day  :" << now->tm_yday << endl;
// summer-winnter hour
cout << "Hours of daylight savings time  :" << now->tm_isdst << endl;
```

useful function instead the above code
```cpp
enum enDateTime { year, month, day, hour, minute, seconds, week_day, year_day, daylight_saving_time };

int GetDateTime(enDateTime _var) {

	time_t t = time(0);

	tm* now = localtime(&t);

	switch (_var)
	{
	case year:
		return now->tm_year + 1900;
	case month:
		return now->tm_mon + 1;
	case day:
		return now->tm_mday;
	case hour:
		return now->tm_hour;
	case minute:
		return now->tm_min;
	case seconds:
		return now->tm_sec;
	case week_day:
		return now->tm_wday;
	case year_day:
		return now->tm_yday;
	case daylight_saving_time:
		return now->tm_isdst;
	default:
		return -1;
	}
}
```