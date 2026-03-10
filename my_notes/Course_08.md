# 1
What did you learn?
```cpp

```

What changed?
```cpp
string NumberToText(int number);
```
---
# 2
What did you learn?
```cpp

```

What changed?
```cpp
bool IsLeapYear(int year);
```
---
# 3
What did you learn?
```cpp

```

What changed?
```cpp
bool IsLeapYear(int year);
```
---
# 4
What did you learn?
```cpp

```

What changed?
```cpp
int GetYearTime(int year, enYearTime time);
int NumberOfDaysInYear(int year);
int NumberOfHoursInYear(int year);
int NumberOfMinutesInYear(int year);
int NumberOfSecondsInYear(int year);
```
---
# 5
What did you learn?
```cpp
// instead of switch, see if you can use an array
```

What changed?
```cpp
int GetDaysInMonth(int month, int year);
int GetHoursInMonth(int month, int year);
int GetMinutesInMonth(int month, int year);
int GetSecondsInMonth(int month, int year);
```
---
# 6
What did you learn?
```cpp

```

What changed?
```cpp
int GetDaysInMonth(int month, int year);
```
---
# 7
What did you learn?
```cpp

```

What changed?
```cpp
string GetDayName(int number);
string PrintDate(short day, short month, short year, string separator);
short GetDayOrderInWeek(int day, int month, int year);
```
---
# 8
What did you learn?
```cpp
// suppose you have a variable of type string called var_string
// to print it using %s and printf you convert it like this
printf("%s", var_string.c_str());
// I didn't try this
// + we do that because %s takes char* and not string
```

What changed?
```cpp
string GetMonthName(int month);
void PrintMonthCalender(short year, short month);
```
---
# 9
What did you learn?
```cpp

```

What changed?
```cpp
void PrintYearCalender(short year);
```
---
# 10
What did you learn?
```cpp

```

What changed?
```cpp
short NumberOfDayInYear(short day, short month, short year);
```
---
# 11
What did you learn?
```cpp

```

What changed?
```cpp
stDate GetDate(int number_of_day_from_beginning_of_year, int year);
string PrintDate(stDate date, string separator);
struct stDate {
	int day;
	int month;
	int year;
};
```
---
# 12
What did you learn?
```cpp

```

What changed?
```cpp
void AddDaysToDate(datetime::stDate& date, int days_to_add);
void FillCurrentMonth(datetime::stDate& date, int& days_to_add);
```
---
# 13
What did you learn?
```cpp

```

What changed?
```cpp
datetime::stDate CompareDates(datetime::stDate date1, datetime::stDate date2);
```
---
# 14
What did you learn?
```cpp

```

What changed?
```cpp
bool IsEqualDates(datetime::stDate date1, datetime::stDate date2);
```
---
# 15
What did you learn?
```cpp

```

What changed?
```cpp
bool IsLastDayInMonth(datetime::stDate date);
bool IsLastMonthInYear(datetime::stDate date);
```
---
# 16
What did you learn?
```cpp

```

What changed?
```cpp
void IncreaseDateByOne(stDate& date);
```
---
# 17
What did you learn?
```cpp
// You need to be aware of the built in functions in your language
// You really need to use the existing code/functions in the language to build things
// These are your tools to build
// It's hard to always build things form zero
```

What changed?
```cpp
int DifferentBtwDatesInDays(stDate date1, stDate date2, bool include_last_day = true);
```
---
# 18
What did you learn?
```cpp

```

What changed?
```cpp
int GetDateInDays(datetime::stDate date);
datetime::stDate GetSystemDate();
```
---
# 19
What did you learn?
```cpp
// backword compatebality means:
// edit something without ruins the code that already uses it
```

What changed?
```cpp
int DifferentBtwDatesInDays(stDate date1, stDate date2, bool include_last_day = false);
```
---
# 20~32
What did you learn?
```cpp
// be clear
for(int i = 1; i<= 10; i++){}
// no need for magic things, like
int x = 10;
while(x>0){x--;}
```

What changed?
```cpp
void IncreaseDateByXDays(int X, datetime::stDate& date);
void IncreaseDateByOneWeek(datetime::stDate& date);
void IncreaseDateByXWeeks(int X, datetime::stDate& date);
void IncreaseDateByOneMonth(datetime::stDate& date);
void IncreaseDateByXMonths(int X, datetime::stDate& date);
void IncreaseDateByOneYear(datetime::stDate& date);
void IncreaseDateByXYears(int X, datetime::stDate& date);
void IncreaseDateByXYearsFaster(int X, datetime::stDate& date);
void IncreaseDateByOneDecade(datetime::stDate& date);
void IncreaseDateByXDecades(int X, datetime::stDate& date);
void IncreaseDateByXDecadesFaster(int X, datetime::stDate& date);
void IncreaseDateByOneCentury(datetime::stDate& date);
void IncreaseDateByOneMillennuim(datetime::stDate& date);
```
---
# 33~46
What did you learn?
```cpp
// programming is a lot of functions working together
```

What changed?
```cpp
void DecreaseDateByOne(datetime::stDate& date);
void DecreaseDateByXDays(int X, datetime::stDate& date);
void DecreaseDateByOneWeek(datetime::stDate& date);
void DecreaseDateByXWeeks(int X, datetime::stDate& date);
void DecreaseDateByOneMonth(datetime::stDate& date);
void DecreaseDateByXMonths(int X, datetime::stDate& date);
void DecreaseDateByOneYear(datetime::stDate& date);
void DecreaseDateByXYears(int X, datetime::stDate& date);
void DecreaseDateByXYearsFaster(int X, datetime::stDate& date);
void DecreaseDateByOneDecade(datetime::stDate& date);
void DecreaseDateByXDecades(int X, datetime::stDate& date);
void DecreaseDateByXDecadesFaster(int X, datetime::stDate& date);
void DecreaseDateByOneCentury(datetime::stDate& date);
void DecreaseDateByOneMillennuim(datetime::stDate& date);
```
---
# 47~53
What did you learn?
```cpp
// there is a lot of things that built in the language!

// there is huge teams that working on the language, so it is worth spending time to learn the built in stuff
// you do not need to do everything yourself! use the builtin stuff!
```

What changed?
```cpp
int DayOfWeekOrder(datetime::stDate date);
string PrintDateLong(datetime::stDate date);
bool IsEndOfWeek(datetime::stDate date);
bool IsItWeekend(datetime::stDate date);
bool IsBusinessDay(datetime::stDate date);
int DaysUntilTheEndOfWeek(datetime::stDate date);
int DaysUntilTheEndOfMonth(datetime::stDate date);
int DaysUntilTheEndOfYear(datetime::stDate date);
```
---
# 54
What did you learn?
```cpp

```

What changed?
```cpp
int GetWeekendDays(datetime::stDate date1, datetime::stDate date2);
int GetBusinessDays(datetime::stDate date1, datetime::stDate date2);
int GetVacationDays(datetime::stDate date1, datetime::stDate date2);
```
---
# 55
What did you learn?
```cpp

```

What changed?
```cpp
datetime::stDate EndOfVacation(datetime::stDate startDate, short duration);
```
---
# 56
What did you learn?
```cpp

```

What changed?
```cpp
bool IsDate1AfterDate2(datetime::stDate date1, datetime::stDate date2);
bool IsDate1BeforeDate2(datetime::stDate date1, datetime::stDate date2);
```
---
# 57
What did you learn?
```cpp

```

What changed?
```cpp
int CompareDates2(datetime::stDate date1, datetime::stDate date2);
```
---
# 58
What did you learn?
```cpp

```

What changed?
```cpp
bool IsOverlapedPeriods(stPeriod period1, stPeriod period2);
struct stPeriod;
stPeriod ReadPeriod();
string PrintPeriod(stPeriod period);
```
---
# 59
What did you learn?
```cpp

```

What changed?
```cpp
int PeriodLengthInDays(datetime::stPeriod period, bool include_last_day = false);
```
---
# 60
What did you learn?
```cpp

```

What changed?
```cpp
bool IsDateWithinPeriod(datetime::stDate date, datetime::stPeriod period);
```
---
# 61
What did you learn?
```cpp

```

What changed?
```cpp
int PeriodLengthInYears(datetime::stPeriod period);
void SwitchPeriods(datetime::stPeriod& period1, datetime::stPeriod& period2);
int CountOverlapDays(datetime::stPeriod period1, datetime::stPeriod period2);
```
---
# 62
What did you learn?
```cpp

```

What changed?
```cpp
datetime::stDate ReadDate();
bool ValidateDate(datetime::stDate date);
```
---
# 63-64
What did you learn?
```cpp

```

What changed?
```cpp
datetime::stDate StringToDate(string str_date);
string DateToString(datetime::stDate date);
datetime::stDate ReadDateAsString();
```
---
---
# 65
What did you learn?
```cpp
// remember:
// you can actually use the .split() and .replace() for strings in your language!
// you need to actually LEARN how the built in functions in your language work

// can you see the diff btw the two functions? FormatDate

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

What changed?
```cpp
enum enFormatString;
string FormatDate(datetime::stDate date, enFormatString format);
string FormatDate(datetime::stDate date, string date_formated = "dd/mm/yyyy");
```
---
# Project
What did you learn?
```cpp
// you can put:
// enOptions, stUser, vecUsers, and listUsers :)
// they look nice
// instead of Options, User, Users. These feel unclear
```

What changed?
```cpp

```
---