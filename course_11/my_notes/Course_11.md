Before the beginning:
- This course answer question: "How do I use OOP to build real software".

> [!Note]
> Learn a little, apply a lot.

___
# Utility Library

> [!Thought]
> Will I use the classes/libraries I built in the up coming projects? If I'll do so, what will I do when I move to C#?
> I guess I won't use MY libraries, I guess I'll learn the professional C# classes/libraries and I'll use them in my work.
> Imagine yourself learning the C# date library in order to know how to deal with date in C#. That's cool.

## Things I learned

Whenever you have an idea of a function that can help you in your work. Implement it, and put it in your library. That will make you faster in your work.
Don't keep rebuilding things.

See the difference
```cpp
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

static void CopyPrimeElementsToArray(int original_arr[], int c_arr[], int size1, int& size2) {
	for (int i = 0; i < size1; i++) {
		if (IsPrime(original_arr[i]))
			AddElementToArray(original_arr[i], c_arr, size2);
	}
}
```

How to add a directory to your project, so you can include libraries directly
- create a folder, and put all libraries you want there (the `.h` files).
- right click on the project folder in VS.
- properties.
- configuration properties
- C/C++
- put it in additional include directories.
With that, you don't need to copy and paste in your project; the library each time you want to include it in your project.

___
# Input & Validation Library

This is an initial library for validation, it'll get bigger with time.

Any read from screen function, put it in this library.
Any validation idea put it in this library.

Be careful when you want to manipulate a function in your libraries, cuz you will use them in your projects.
You can add functions to your library as you want.

To read a valid number
```cpp
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

int readnum() {
	int number;
	cout << "enter a number: ";
	while (!(cin >> number)) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "error message, enter again: ";
	}
	return number;
}
```

Look at this, I implemented the function, then didn't use it
```cpp
static double ReadDbNumberInRange(double from, double to, string message, string error_message = "Number not in range, enter another one: ") {
	double number = ReadDbNumber(message, error_message);
	while (!(number >= from && number <= to)) {
		cout << error_message;
		number = ReadDbNumber("", error_message);
	}
	return number;
}

static double ReadDbNumberInRange(double from, double to, string message, string error_message = "Number not in range, enter another one: ") {
	double number = ReadDbNumber(message, error_message);
	while (!IsNumberBetween(number, from, to)) {
		cout << error_message;
		number = ReadDbNumber("", error_message);
	}
	return number;
}
```

Make the source code only in one place, so when you want to change something, you edit in one place, and it gets effected everywhere.

Remember the dotnet days, when you validate the same things in each new project.

___
# Bank System -> make a new project in VS

What did you learn:
- make all private members (data & methods) start with `_`.
- `public` -> only things that the user need to use.
- we write the logic only once, then we can  use it in desktop/web/mobile, we will write different code for the UI depending on the application desktop/web/mobile.
- we build on top of what we built
- remember the ides of leaving the feature empty.
- the UI and the business logic should be separated.
- each time, you should think about one think.
- everything inside the object shouldn't relate to the UI.
- important : we write the logic of the system in OOP, we also write the UI in OOP, and they are separated.
- before developing anything, make the skeleton and be sure that everything is working fine (then send messages), then put each piece in it space.
- remember the idea of the global `.h` file, where you put the global things.
- the global variables exist in a file, any class wants to use them, should include the file.

What did you learn from the extensions
- if you want a function, go write it in your library, then use it, just in case you needed it later again.
- if the code is related to the logic, put it with the logic code.
- always encrypt passwords before storing them, encrypt -> store, retrieve -> decrypt -> use.
- if you inherit an `interface or an abstract class` you should implement the same exact functions there.
- if you want to integrate with some other system, you give them your interface.

What did you learn from the currency exchange project
- huge projects are projects inside each other.
- first step in the project: prepare the classes of the business logic, because the UI classes will use them. Work on the database alone.
- at first create the logic(classes) with the basic needs, then you will add methods step by step as you need.
- add, delete, update, find, memorize them.
- make the feature and leave it empty.
- you follow the functional programming way inside your class, whether the class is related to the UI or the business logic.
___
# Template Functions

```cpp
template <typename t> t Sum(t number_one, t number_two) {
	return number_one + number_two;
}

int main()
{
	cout << Sum<int>(1, 2) << "\n";
	cout << Sum<float>(1.1, 2.2) << "\n";
	cout << Sum<string>("this is my ", "sentence") << "\n";
}
```

```
3
3.3
this is my sentence
```

```cpp
// it makes more sense in this form
template <typename t>
t Sum(t number_one, t number_two) {
	return number_one + number_two;
}
```

You can put more than one
```cpp
template <typename t, typename f>
void Print(t var_one, f var_two) {
	cout << var_one << "\n";
	cout << var_two << "\n";
}

int main()
{
	Print<int, float>(1, 1.1);
}
```

```
1
1.1
```
---
# Template Classes

```cpp
template <class t>
class clsCalculator {
	t _number_one;
	t _number_two;

public:
	clsCalculator(t n1, t n2) {
		_number_one = n1;
		_number_two = n2;
	}
	t Sum() { return _number_one + _number_two; }
	t Mul() { return _number_one * _number_two; }

	void Print() {
		cout << _number_one << " + " << _number_two << " = " << Sum() << "\n";
		cout << _number_one << " * " << _number_two << " = " << Mul() << "\n";
	}
};

int main()
{
	clsCalculator<int> _test_int_calculator(1, 2);
	clsCalculator<float> _test_float_calculator(1.1, 2.2);

	_test_int_calculator.Print();
	_test_float_calculator.Print();
}
```

```
1 + 2 = 3
1 * 2 = 2
1.1 + 2.2 = 3.3
1.1 * 2.2 = 2.42
```

___

