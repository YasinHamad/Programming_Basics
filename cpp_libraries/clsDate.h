#pragma once
#pragma warning(disable : 4996) // for removing the ctime() function warning

#include <iostream>
#include <string>
#include <ctime>
#include <vector>

//#include "clsString.h"

using namespace std;

class clsDate
{
private:
	int _Day;
	int _Month;
	int _Year;

	enum enPosition { left, center, right };

	// just returns the date to print
	static string PrintDate(clsDate date, string separator) {
		return to_string(date.day) + separator + to_string(date.month) + separator + to_string(date.year);
	}

	static int DayOfWeekOrder(clsDate date) {
		return GetDayOrderInWeek(date);
	}

	static string PrintNameInMiddleOfDashes(int dashes_number, string name, string dashes = "-") {
		int length = name.length();
		string result = "";
		int left_padding = 0;
		int right_padding = 0;

		if ((IsEven(length) && IsEven(dashes_number)) || (!IsEven(length) && !IsEven(dashes_number))) {
			left_padding = right_padding = (dashes_number - length) / 2;
		}
		else {
			left_padding = (dashes_number - length) / 2;
			right_padding = (dashes_number - length) / 2;
			right_padding++;
		}

		result += PrintDashes(left_padding, dashes);
		result += name;
		result += PrintDashes(right_padding, dashes);

		return result;
	}

	static bool IsEven(int number) {
		return (number % 2) == 0;
	}

	static string PrintDashes(int number, string dashes = "-") {
		string result = "";
		for (int i = 0; i < number; i++) result += dashes;
		return result;
	}

	static string FormatedCout(int number, string sentence, enPosition position) {
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

	static string PrintSpaces(int number) {
		string result = "";
		for (int i = 0; i < number; i++) result += " ";
		return result;
	}

	static void FillCurrentMonth(clsDate& date, int& days_to_add) {
		int current_month_days = GetDaysInMonth(date.month, date.year);
		int remaining_days_to_fill_month = current_month_days - date.day;

		if (days_to_add == 0) return;
		else if (days_to_add <= remaining_days_to_fill_month) {
			date.day += days_to_add;
			days_to_add = 0;
			return;
		}
		else {
			if (remaining_days_to_fill_month == 0) {
				if (date.month == 12) {
					date.month = 1;
					date.year++;
				}
				else {
					date.month++;
				}
				date.day = 0;
				FillCurrentMonth(date, days_to_add);
				return;
			}
			date.day += remaining_days_to_fill_month;
			days_to_add -= remaining_days_to_fill_month;
		}
	}

	static vector<string> Split(string source, string delimiter) {
		vector<string> strings;
		int pos = 0;
		string word;

		while ((pos = source.find(delimiter)) != std::string::npos) {
			word = source.substr(0, pos);
			if (word != "") {
				strings.push_back(word);
			}
			source.erase(0, pos + delimiter.length());
		}
		if (source.length() != 0) strings.push_back(source);

		return strings;
	}

	static string ReplaceWordInStringWithBuiltInFunction(string source, string old_word, string new_word) {
		int pos = 0;

		pos = source.find(old_word);

		while (pos != std::string::npos) {
			source.replace(pos, old_word.length(), new_word);
			pos = source.find(old_word);
		}

		return source;
	}
	
	static int ReadNumber(string message) {
		int Number;
		cout << message;
		cin >> Number;
		while (cin.fail()) {
			// user didn't input a number    
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Invalid Number, Enter a valid one: ";
			cin >> Number;

		}
		return Number;
	}

	static string _FormatNumber(int number, int digits = 1) {
		if (digits == 1 || number < 0) return to_string(number);

		string result = to_string(number);
		int length = result.length();
		for (int i = 1; i <= digits - length; i++) {
			result = "0" + result;
		}

		return result;
	}

public:
	enum enDateTime { enYear, enMonth, enDay, enHour, enMinute, enSeconds, enWeek_day, enYear_day, enDaylight_saving_time };
	enum enYearTime { enYearDays, enYearHours, enYearMinutes, enYearSeconds };

	clsDate() {
		*this = GetSystemDate();
	}
	clsDate(string date) {
		*this = StringToDate(date);
	}
	clsDate(int day, int month, int year) {
		this->_Day = day;
		this->_Month = month;
		this->_Year = year;
	}
	clsDate(int number_of_day_in_year, int year) {
		*this = GetDate(number_of_day_in_year, year);
	}

	int getDay() { return _Day; }
	void setDay(int day) { this->_Day = day; }
	__declspec(property(get = getDay, put = setDay)) int day;

	int getMonth() { return _Month; }
	void setMonth(int month) { this->_Month = month; }
	__declspec(property(get = getMonth, put = setMonth)) int month;

	int getYear() { return _Year; }
	void setYear(int year) { this->_Year = year; }
	__declspec(property(get = getYear, put = setYear)) int year;

	string ToString() {
		return "{Day:" + to_string(day) + ", Month: " + to_string(month) + ", Year:" + to_string(year) + "}";
	}

	static int GetDateTime(enDateTime _var) {

		time_t t = time(0);

		tm* now = localtime(&t);

		switch (_var)
		{
		case enDateTime::enYear:
			return now->tm_year + 1900;
		case enDateTime::enMonth:
			return now->tm_mon + 1;
		case enDateTime::enDay:
			return now->tm_mday;
		case enDateTime::enHour:
			return now->tm_hour;
		case enDateTime::enMinute:
			return now->tm_min;
		case enDateTime::enSeconds:
			return now->tm_sec;
		case enDateTime::enWeek_day:
			return now->tm_wday;
		case enDateTime::enYear_day:
			return now->tm_yday;
		case enDateTime::enDaylight_saving_time:
			return now->tm_isdst;
		default:
			return -1;
		}
	}

	static clsDate StringToDate(string str_date) {
		vector<string> vec_date = Split(str_date, "/");

		clsDate date;
		date.day = stoi(vec_date[0]);
		date.month = stoi(vec_date[1]);
		date.year = stoi(vec_date[2]);

		return date;
	}

	static string DateToString(clsDate date) {
		return PrintDate(date, "/");
	}
	string DateToString() {
		return DateToString(*this);
	}

	// returns the order of the day in week
	// 0->sunday, 1->monday
	static short GetDayOrderInWeek(clsDate date) {
		int day = date.day;
		int month = date.month;
		int year = date.year;

		int a = (14 - month) / 12;
		int y = year - a;
		int m = month + 12 * a - 2;

		int d = (day + y + (y / 4) - (y / 100) + (y / 400) + (31 * m / 12));

		return d % 7;
	}
	short GetDayOrderInWeek() {
		return GetDayOrderInWeek(*this);
	}

	// returns the name of the day
	static string GetDayName(int number) {
		if (number >= 7 || number <= -1) return "";
		string days[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
		return days[number];
	}
	string GetDayName() {
		return GetDayName(GetDayOrderInWeek());
	}

	static string GetMonthName(int month) {
		if (month <= 0 || month >= 13) return "";
		string months[12] = {
		"January", "February", "March", "April", "May", "June",
		"July", "August", "September", "October", "November", "December"
		};

		return months[month - 1];
	}
	string GetMonthName() {
		return GetMonthName(month);
	}

	static string PrintDateLong(clsDate date) {
		return GetDayName(DayOfWeekOrder(date)) + ", " + PrintDate(date, "/");
	}
	string PrintDateLong() {
		return PrintDateLong(*this);
	}

	static bool IsLeapYear(int year) {
		return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
	}
	bool IsLeapYear() {
		return IsLeapYear(year);
	}

	static int NumberOfDaysInYear(int year) {
		return IsLeapYear(year) ? 366 : 365;
	}
	int NumberOfDaysInYear() {
		return NumberOfDaysInYear(year);
	}

	static int NumberOfHoursInYear(int year) {
		return NumberOfDaysInYear(year) * 24;
	}
	int NumberOfHoursInYear() {
		return NumberOfHoursInYear(year);
	}

	static int NumberOfMinutesInYear(int year) {
		return NumberOfHoursInYear(year) * 60;
	}
	int NumberOfMinutesInYear() {
		return NumberOfMinutesInYear(year);
	}

	static int NumberOfSecondsInYear(int year) {
		return NumberOfMinutesInYear(year) * 60;
	}
	int NumberOfSecondsInYear() {
		return NumberOfSecondsInYear(year);
	}

	static int GetDaysInMonth(int month, int year) {
		if (month <= 0 || month >= 13) return 0;
		int NumberOfDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		return (month == 2) ? (IsLeapYear(year) ? 29 : 28) : NumberOfDays[month - 1];
	}
	int GetDaysInMonth() {
		return GetDaysInMonth(month, year);
	}

	static int GetHoursInMonth(int month, int year) {
		return GetDaysInMonth(month, year) * 24;
	}
	int GetHoursInMonth() {
		return GetHoursInMonth(month, year);
	}

	static int GetMinutesInMonth(int month, int year) {
		return GetHoursInMonth(month, year) * 60;
	}
	int GetMinutesInMonth() {
		return GetMinutesInMonth(month, year);
	}

	static int GetSecondsInMonth(int month, int year) {
		return GetMinutesInMonth(month, year) * 60;
	}
	int GetSecondsInMonth() {
		return GetSecondsInMonth(month, year);
	}

	static void PrintMonthCalender(clsDate date) {
		int year = date.year;
		int month = date.month;

		string month_name = GetMonthName(month);
		int month_days = GetDaysInMonth(month, year);
		int break_line = 1;

		cout << PrintNameInMiddleOfDashes(40, month_name, "_");
		cout << "\n\n";

		string Days[7]{ "Sun", "Mon", "Tue", "Wed", "Thu", "Fir", "Sat" };
		for (int i = 0; i < 7; i++) {
			cout << Days[i] << "  ";
		}
		cout << "\n";

		break_line = GetDayOrderInWeek(clsDate(1, month, year));

		for (int i = 0; i < break_line; i++) {
			cout << FormatedCout(3, "", enPosition::left) << "  ";
		}

		for (int i = 1; i <= month_days; i++) {
			cout << FormatedCout(3, to_string(i), enPosition::left) << "  ";
			break_line++;
			if (break_line % 7 == 0) {
				cout << "\n";
				break_line = 0;
			}
		}
		cout << "\n";
		cout << PrintDashes(40, "_");
		cout << "\n";
	}
	void PrintMonthCalender() {
		PrintMonthCalender(*this);
	}

	static void PrintYearCalender(short year) {

		cout << PrintDashes(40, "_") << "\n\n";
		cout << FormatedCout(40, "Calender - " + to_string(year), enPosition::center) << "\n";
		cout << PrintDashes(40, "_") << "\n\n";

		for (int i = 1; i <= 12; i++) {
			PrintMonthCalender(clsDate(1, i, year));
			cout << endl;
		}
	}
	void PrintYearCalender() {
		PrintYearCalender(year);
	}

	// takes the number of day from the beggining of the year
	static clsDate GetDate(int number_of_day_from_beginning_of_year, int year) {
		clsDate date;
		int counter = 0;
		for (int i = 1; i <= 12; i++) {
			int number_of_days_in_month = GetDaysInMonth(i, year);
			if (number_of_days_in_month > number_of_day_from_beginning_of_year) {
				counter++;
				break;
			}
			number_of_day_from_beginning_of_year -= number_of_days_in_month;
			counter++;
			if (number_of_day_from_beginning_of_year <= GetDaysInMonth(i+1, year)) {
				counter++;
				break;
			}
		}
		date.day = number_of_day_from_beginning_of_year;
		date.year = year;
		date.month = counter;

		return date;
	}

	static void AddDaysToDate(clsDate& date, int days_to_add) {
		while (days_to_add != 0) {
			FillCurrentMonth(date, days_to_add);
		}
	}
	void AddDaysToDate(int days_to_add) {
		AddDaysToDate(*this, days_to_add);
	}

	static short NumberOfDayInYear(clsDate date) {
		short day = date.day;
		short month = date.month;
		short year = date.year;

		int counter = 0;

		for (int i = 1; i < month; i++) {
			counter += GetDaysInMonth(i, year);
		}

		return (counter + day);
	}
	short NumberOfDayInYear() {
		return NumberOfDayInYear(*this);
	}

	static clsDate CompareDates(clsDate date1, clsDate date2) {
		int year_diff = date2.year - date1.year;

		if (year_diff > 0) return date2;
		else if (year_diff < 0) return date1;
		else {
			int days_from_beggining1 = NumberOfDayInYear(date1);
			int days_from_beggining2 = NumberOfDayInYear(date2);
			int diff = days_from_beggining2 - days_from_beggining1;
			if (diff > 0) return date2;
			return date1;
		}
	}
	clsDate CompareWithDate(clsDate date) {
		return CompareDates(*this, date);
	}

	static bool IsEqualDates(clsDate date1, clsDate date2) {
		return (date1.year == date2.year && date1.month == date2.month && date1.day == date2.day);
	}
	bool IsEqualToDate(clsDate date) {
		return IsEqualDates(*this, date);
	}

	static bool IsLastDayInMonth(clsDate date) {
		return (date.day == GetDaysInMonth(date.month, date.year));
	}
	bool IsLastDayInMonth() {
		return IsLastMonthInYear(*this);
	}

	static bool IsLastMonthInYear(clsDate date) {
		return (date.month == 12) ? true : false;
	}
	bool IsLastMonthInYear() {
		return IsLastMonthInYear(*this);
	}

	static void IncreaseDateByOne(clsDate& date) {
		if (IsLastDayInMonth(date)) {
			if (IsLastMonthInYear(date)) {
				date.month = 1;
				date.year++;
				date.day = 1;
			}
			else {
				date.month++;
				date.day = 1;
			}
		}
		else {
			date.day++;
		}
	}
	void IncreaseDateByOne() {
		IncreaseDateByOne(*this);
	}

	static int DifferentBtwDatesInDays(clsDate date1, clsDate date2, bool include_last_day = false) {
		if (!IsEqualDates(date2, CompareDates(date1, date2))) {
			return -1 * DifferentBtwDatesInDays(date2, date1, include_last_day);
		}

		int counter = 0;
		while (!IsEqualDates(date1, date2)) {
			counter++;
			IncreaseDateByOne(date1);
		}

		return include_last_day ? counter + 1 : counter;
	}
	int DifferentInDaysWithDate(clsDate date, bool include_last_day = false) {
		return DifferentBtwDatesInDays(*this, date, include_last_day);
	}

	static int GetDateInDays(clsDate date) {
		int days = 0;
		while (date.year != 0) {
			days += NumberOfDaysInYear(date.year--);
		}
		days += NumberOfDayInYear(date);

		return days;
	}
	int GetDateInDays() {
		return GetDateInDays(*this);
	}

	static clsDate GetSystemDate() {
		clsDate current_date(
			GetDateTime(enDateTime::enDay),
			GetDateTime(enDateTime::enMonth),
			GetDateTime(enDateTime::enYear)
		);
		return current_date;
	}

	static void IncreaseDateByXDays(int X, clsDate& date) {
		while (X > 0) {
			IncreaseDateByOne(date);
			X--;
		}
	}
	void IncreaseDateByXDays(int X) {
		IncreaseDateByXDays(X, *this);
	}

	static void IncreaseDateByOneWeek(clsDate& date) {
		IncreaseDateByXDays(7, date);
	}
	void IncreaseDateByOneWeek() {
		IncreaseDateByOneWeek(*this);
	}

	static void IncreaseDateByXWeeks(int X, clsDate& date) {
		while (X > 0) {
			IncreaseDateByOneWeek(date);
			X--;
		}
	}
	void IncreaseDateByXWeeks(int X) {
		IncreaseDateByXWeeks(X, *this);
	}

	static void IncreaseDateByOneMonth(clsDate& date) {
		if (IsLastMonthInYear(date)) {
			date.year++;
			date.month = 1;
		}
		else {
			date.month++;
		}

		int current_month_days = GetDaysInMonth(date.month, date.year);
		if (date.day > current_month_days) {
			date.day = current_month_days;
		}
	}
	void IncreaseDateByOneMonth() {
		IncreaseDateByOneMonth(*this);
	}

	static void IncreaseDateByXMonths(int X, clsDate& date) {
		while (X > 0) {
			IncreaseDateByOneMonth(date);
			X--;
		}
	}
	void IncreaseDateByXMonths(int X) {
		IncreaseDateByXMonths(X, *this);
	}

	static void IncreaseDateByOneYear(clsDate& date) {
		IncreaseDateByXMonths(12, date);
	}
	void IncreaseDateByOneYear() {
		return IncreaseDateByOneYear(*this);
	}

	static void IncreaseDateByXYears(int X, clsDate& date) {
		while (X > 0) {
			if (IsLeapYear(date.year + 1)) IncreaseDateByOne(date);
			date.year++;
			X--;
		}
	}
	void IncreaseDateByXYears(int X) {
		IncreaseDateByXYears(X, *this);
	}

	static void IncreaseDateByOneDecade(clsDate& date) {
		IncreaseDateByXYears(10, date);
	}
	void IncreaseDateByOneDecade() {
		IncreaseDateByOneDecade(*this);
	}

	static void IncreaseDateByXDecades(int X, clsDate& date) {
		IncreaseDateByXYears(X * 10, date);
	}
	void IncreaseDateByXDecades(int X) {
		IncreaseDateByXDecades(X, *this);
	}

	static void IncreaseDateByOneCentury(clsDate& date) {
		IncreaseDateByXDecades(10, date);
	}
	void IncreaseDateByOneCentury() {
		IncreaseDateByOneCentury(*this);
	}

	static void IncreaseDateByOneMillennuim(clsDate& date) {
		for (int i = 1; i <= 10; i++) IncreaseDateByOneCentury(date);
	}
	void IncreaseDateByOneMillennuim() {
		IncreaseDateByOneMillennuim(*this);
	}

	static void DecreaseDateByOne(clsDate& date) {
		if (date.day == 1) {
			if (date.month == 1) {
				date.year--;
				date.month = 12;
				date.day = GetDaysInMonth(date.month, date.year);
			}
			else {
				date.month--;
				date.day = GetDaysInMonth(date.month, date.year);
			}
		}
		else {
			date.day--;
		}
	}
	void DecreaseDateByOne() {
		DecreaseDateByOne(*this);
	}

	static void DecreaseDateByXDays(int X, clsDate& date) {
		while (X > 0) {
			DecreaseDateByOne(date);
			X--;
		}
	}
	void DecreaseDateByXDays(int X) {
		DecreaseDateByXDays(X, *this);
	}

	static void DecreaseDateByOneWeek(clsDate& date) {
		DecreaseDateByXDays(7, date);
	}
	void DecreaseDateByOneWeek() {
		DecreaseDateByOneWeek(*this);
	}

	static void DecreaseDateByXWeeks(int X, clsDate& date) {
		while (X > 0) {
			DecreaseDateByOneWeek(date);
			X--;
		}
	}
	void DecreaseDateByXWeeks(int X) {
		DecreaseDateByXWeeks(X, *this);
	}

	static void DecreaseDateByOneMonth(clsDate& date) {
		if (date.month == 1) {
			date.year--;
			date.month = 12;
		}
		else {
			date.month--;
		}

		int current_month_days = GetDaysInMonth(date.month, date.year);
		if (date.day > current_month_days) {
			date.day = current_month_days;
		}
	}
	void DecreaseDateByOneMonth() {
		DecreaseDateByOneMonth(*this);
	}

	static void DecreaseDateByXMonths(int X, clsDate& date) {
		while (X > 0) {
			DecreaseDateByOneMonth(date);
			X--;
		}
	}
	void DecreaseDateByXMonths(int X) {
		DecreaseDateByXMonths(X, *this);
	}

	static void DecreaseDateByOneYear(clsDate& date) {
		DecreaseDateByXMonths(12, date);
	}
	void DecreaseDateByOneYear() {
		DecreaseDateByOneYear(*this);
	}

	static void DecreaseDateByXYears(int X, clsDate& date) {
		while (X > 0) {
			if (IsLeapYear(date.year - 1)) DecreaseDateByOne(date);
			date.year--;
			X--;
		}
	}
	void DecreaseDateByXYears(int X) {
		DecreaseDateByXYears(X, *this);
	}

	static void DecreaseDateByOneDecade(clsDate& date) {
		DecreaseDateByXYears(10, date);
	}
	void DecreaseDateByOneDecade() {
		DecreaseDateByOneDecade(*this);
	}

	static void DecreaseDateByXDecades(int X, clsDate& date) {
		DecreaseDateByXYears(X * 10, date);
	}
	void DecreaseDateByXDecades(int X) {
		DecreaseDateByXDecades(X, *this);
	}

	static void DecreaseDateByOneCentury(clsDate& date) {
		DecreaseDateByXDecades(10, date);
	}
	void DecreaseDateByOneCentury() {
		DecreaseDateByOneCentury(*this);
	}

	static void DecreaseDateByOneMillennuim(clsDate& date) {
		for (int i = 1; i <= 10; i++) DecreaseDateByOneCentury(date);
	}
	void DecreaseDateByOneMillennuim() {
		DecreaseDateByOneMillennuim(*this);
	}

	static bool IsEndOfWeek(clsDate date) {
		return DayOfWeekOrder(date) == 6;
	}
	bool IsEndOfWeek() {
		return IsEndOfWeek(*this);
	}

	static bool IsItWeekend(clsDate date) {
		int day_order = DayOfWeekOrder(date);
		return (day_order == 6 || day_order == 5);
	}
	bool IsItWeekend() {
		return IsItWeekend(*this);
	}

	static bool IsBusinessDay(clsDate date) {
		return !IsItWeekend(date);
	}
	bool IsBusinessDay() {
		return IsBusinessDay(*this);
	}

	static int DaysUntilTheEndOfWeek(clsDate date) {
		return (6 - DayOfWeekOrder(date));
	}
	int DaysUntilTheEndOfWeek() {
		return DaysUntilTheEndOfWeek(*this);
	}

	static int DaysUntilTheEndOfMonth(clsDate date) {
		clsDate last_day_date;

		last_day_date.day = GetDaysInMonth(date.month, date.year);
		last_day_date.month = date.month;
		last_day_date.year = date.year;

		return DifferentBtwDatesInDays(date, last_day_date, false);
	}
	int DaysUntilTheEndOfMonth() {
		return DaysUntilTheEndOfMonth(*this);
	}

	static int DaysUntilTheEndOfYear(clsDate date) {
		return (NumberOfDaysInYear(date.year) - NumberOfDayInYear(date));
	}
	int DaysUntilTheEndOfYear() {
		return DaysUntilTheEndOfYear(*this);
	}

	static int GetWeekendDays(clsDate date1, clsDate date2) {
		if (!IsEqualDates(date2, CompareDates(date1, date2))) return 0;

		int weekend_days = 0;

		while (!IsEqualDates(date1, date2)) {
			if (IsItWeekend(date1)) weekend_days++;
			IncreaseDateByOne(date1);
		}
		return weekend_days;
	}
	int GetWeekendDays(clsDate date) {
		return GetWeekendDays(*this, date);
	}

	static int GetBusinessDays(clsDate date1, clsDate date2) {
		return DifferentBtwDatesInDays(date1, date2) - GetWeekendDays(date1, date2);
	}
	int GetBusinessDays(clsDate date) {
		return GetBusinessDays(*this, date);
	}

	static int GetVacationDays(clsDate date1, clsDate date2) {
		return GetBusinessDays(date1, date2);
	}
	int GetVacationDays(clsDate date) {
		return GetVacationDays(*this, date);
	}

	static clsDate EndOfVacation(clsDate startDate, short duration) {
		clsDate end_date = startDate;

		while (duration != GetVacationDays(startDate, end_date))
			IncreaseDateByOne(end_date);

		return end_date;
	}
	clsDate EndOfVacation(short duration) {
		return EndOfVacation(*this, duration);
	}

	static bool IsDate1AfterDate2(clsDate date1, clsDate date2) {
		return (!IsEqualDates(date1, date2) &&IsEqualDates(date1, CompareDates(date1, date2)));
	}
	bool IsAfterDate(clsDate date) {
		return IsDate1AfterDate2(*this, date);
	}

	static bool IsDate1BeforeDate2(clsDate date1, clsDate date2) {
		return (!IsEqualDates(date1, date2) && IsEqualDates(date2, CompareDates(date1, date2)));
	}
	bool IsBeforeDate(clsDate date) {
		return IsDate1BeforeDate2(*this, date);
	}

	static int CompareDates2(clsDate date1, clsDate date2) {
		return IsEqualDates(date1, date2) ? 0 :
			IsDate1AfterDate2(date1, date2) ? 1 : -1;
	}
	int CompareDates2(clsDate date) {
		return CompareDates2(*this, date);
	}

	static int GetYearTime(int year, enYearTime time) {
		int year_days = IsLeapYear(year) ? 366 : 365;

		switch (time) {
		case enYearTime::enYearDays: return year_days;
		case enYearTime::enYearHours: return year_days * 24;
		case enYearTime::enYearMinutes: return year_days * 24 * 60;
		case enYearTime::enYearSeconds: return year_days * 24 * 60 * 60;
		default: return -1;
		}
	}
	int	GetYearTime(enYearTime time) {
		return GetYearTime(year, time);
	}

	static char* GetCurrentTime() {
		time_t t = time(0);

		char* t_string = ctime(&t);

		return t_string;
	}

	static char* GetGreenwichTime() {
		time_t t = time(0);
		char* t_string = NULL;

		tm* gmtm = gmtime(&t);
		t_string = asctime(gmtm);

		return t_string;
	}

	static clsDate ReadDate() {
		clsDate date;
		date.day = ReadNumber("Enter the day: ");
		date.month = ReadNumber("Enter the month: ");
		date.year = ReadNumber("Enter the year: ");
		return date;
	}

	static bool ValidateDate(clsDate date) {
		if (!(date.month >= 1 && date.month <= 12)) return false;
		if (date.year <= 0) return false;
		if (!(date.day >= 1 && date.day <= GetDaysInMonth(date.month, date.year))) return false;
		return true;
	}
	bool ValidateDate() {
		return ValidateDate(*this);
	}

	static clsDate ReadDateAsString() {
		string str_date = "";
		clsDate date;

		cout << "Please enter date dd/mm/yyyy: ";
		cin >> str_date;

		date = StringToDate(str_date);
		return date;
	}

	static string FormatDate(clsDate date, string date_formated = "dd/mm/yyyy") {
		date_formated = ReplaceWordInStringWithBuiltInFunction(date_formated, "dd", to_string(date.day));
		date_formated = ReplaceWordInStringWithBuiltInFunction(date_formated, "mm", to_string(date.month));
		date_formated = ReplaceWordInStringWithBuiltInFunction(date_formated, "yyyy", to_string(date.year));
		return date_formated;
	}
	string FormatDate(string date_formated = "dd/mm/yyyy") {
		return FormatDate(*this, date_formated);
	}

	/* ---------- NOT DOCUMENTED ---------- */
	static string GetSystemDateTime(string string_format = "DAY/MONTH/YEAR - HOURS:MINUTES:SECONDS") {



		string_format = ReplaceWordInStringWithBuiltInFunction(string_format, "DAY", _FormatNumber(GetDateTime(enDateTime::enDay), 2));
		string_format = ReplaceWordInStringWithBuiltInFunction(string_format, "MONTH", _FormatNumber(GetDateTime(enDateTime::enMonth), 2));
		string_format = ReplaceWordInStringWithBuiltInFunction(string_format, "YEAR", _FormatNumber(GetDateTime(enDateTime::enYear), 4));

		string_format = ReplaceWordInStringWithBuiltInFunction(string_format, "HOURS", _FormatNumber(GetDateTime(enDateTime::enHour), 2));
		string_format = ReplaceWordInStringWithBuiltInFunction(string_format, "MINUTES", _FormatNumber(GetDateTime(enDateTime::enMinute), 2));
		string_format = ReplaceWordInStringWithBuiltInFunction(string_format, "SECONDS", _FormatNumber(GetDateTime(enDateTime::enSeconds), 2));

		return string_format;
	}
};


