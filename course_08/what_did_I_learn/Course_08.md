# Note #1
Instead of Switch, see if it is easier to use an array.
Example:
```cpp
// code 01
Switch(number){
	case 1: return "one";
	case 2: return "two";
	.
	.
	.
}

// code 02
string numbers[] = {"", "one", "two", . . . };
return numbers[number];
```

# Note #2
Not technical information:
> [!NOTE] Months
> Each month is either 30 or 31 days, except for February (month number 2), it may come 28 or 29 depending on the year weather it is leap one or not.

# Note #3
We can't print string `Cpp` variables using `printf`.
Example:
```cpp
string string_cpp_variable = "hi";
printf("%s", string_cpp_variable); // this is wrong
```
Instead, we can do the following:
```cpp
string string_cpp_variable = "hi";
printf("%s", string_cpp_variable.c_str());
// we do so becase %s takes char* and not string
```

# Note #4
You need to be aware of the built-in functions in your language.
You really need to use the existing code/functions in the language to build things.
These are your tools to build stuff.
It's hard to always build things from zero.
Implementing your idea will be easier if you know the built-in functions in the language you use.

# Note #5
> [!NOTE] Backward Compatibility
> Edit x without ruins the old code that uses x.

# Note #6
Be clear
```cpp
for(int i = 1; i <= 10; i++){}
```
No need for magic stuff
```cpp
int x = 10;
while(x>0){x--;}
```

# Note #7
> [!NOTE] Think of it!
> Programming is a lot of functions working together.

# Note #8
There is a lot of things that built in the language!
There are huge teams that working on the language, so it is worth spending time to actually LEARN the built-in stuff.
You do not need to do everything yourself! USE THE BUILD-IN STUFF!

# Note #9
Think about this!
This function takes a string and returns a Date structure.
How do you think the ORMs are built?
```cpp
	datetime::stDate StringToDate(string str_date) {
		vector<string> vec_date = manipulators::string_utilities::Split(str_date, "/");
		datetime::stDate date;
		date.day = stoi(vec_date[0]);
		date.month = stoi(vec_date[1]);
		date.year = stoi(vec_date[2]);
		return date;
	}
```

# Note #10
Remember:
you can actually use the `.split()` and `.replace()` that are built-in your language for manipulating strings!
You need to actually LEARN how the built in functions in your language work.

Can you see the diff btw these two functions:
```cpp
enum enFormatString {
// this should be enFormatDate, never mind
	day_month_year_forward_slash,
	year_day_month_forward_slash,
	month_day_year_forward_slash,
	day_month_year_dash,
	year_day_month_dash,
	month_day_year_dash,
	details
};
string FormatDate(datetime::stDate date, enFormatString format) {
	switch(format) {
	case enFormatString::day_month_year_forward_slash: return to_string(date.day) + "/" + to_string(date.month) + "/" + to_string(date.year);
	case enFormatString::year_day_month_forward_slash: return to_string(date.year) + "/" + to_string(date.day) + "/" + to_string(date.month);
	case enFormatString::month_day_year_forward_slash: return to_string(date.month) + "/" + to_string(date.day) + "/" + to_string(date.year);
	case enFormatString::day_month_year_dash: return to_string(date.day) + "-" + to_string(date.month) + "-" + to_string(date.year);
	case enFormatString::year_day_month_dash: return to_string(date.year) + "-" + to_string(date.day) + "-" + to_string(date.month);
	case enFormatString::month_day_year_dash: return to_string(date.month) + "-" + to_string(date.day) + "-" + to_string(date.year);
	default: return "Day:" + to_string(date.month) + ", Month:" + to_string(date.day) + ", Year:" + to_string(date.year);
	};
}

string FormatDate(datetime::stDate date, string date_formated = "dd/mm/yyyy") {
	date_formated = manipulators::string_utilities::ReplaceWordInStringWithBuiltInFunction(date_formated, "dd", to_string(date.day));
	date_formated = manipulators::string_utilities::ReplaceWordInStringWithBuiltInFunction(date_formated, "mm", to_string(date.month));
	date_formated = manipulators::string_utilities::ReplaceWordInStringWithBuiltInFunction(date_formated, "yyyy", to_string(date.year));
	return date_formated;
}
```

# Note #11
You can name your variables like this
`enOption`, `stUser`, `vecUsers`,  `listUsers`, and `stackUsers`.
Instead of
`Option`, `User`, or `Users`.
They feel more clear.
