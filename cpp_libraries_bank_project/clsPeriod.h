#pragma once
#pragma warning(disable : 4996) // for removing the ctime() function warning

#include <iostream>
#include <string>
#include <ctime>
#include <vector>

using namespace std;

#include "clsDate.h"

class clsPeriod
{
private:
	clsDate _Start_Date;
	clsDate _End_Date;

	// this function calculate approximatly the diff btw the years
	static int PeriodLengthInYears(clsPeriod period) {
		return abs(period.starDate.year - period.endDate.year);
	}

public:
	clsPeriod(clsDate StartDate, clsDate EndDate) {
		this->_Start_Date = StartDate;
		this->_End_Date = EndDate;
	}

	clsDate getStartDate() { return _Start_Date; }
	void setStartDate(clsDate StartDate) { this->_Start_Date = StartDate; }
	__declspec(property(get = getStartDate, put = setStartDate)) clsDate starDate;

	clsDate getEndDate() { return _End_Date; }
	void setEndDate(clsDate EndDate) { this->_End_Date = EndDate; }
	__declspec(property(get = getEndDate, put = setEndDate)) clsDate endDate;

	static bool IsOverlapedPeriods(clsPeriod period1, clsPeriod period2) {
		return !(clsDate::IsDate1BeforeDate2(period1.endDate, period2.starDate) ||
			clsDate::IsDate1BeforeDate2(period2.endDate, period1.starDate));
	}
	bool IsOverlapedWith(clsPeriod period) {
		return IsOverlapedPeriods(*this, period);
	}

	static string ToString(clsPeriod period) {
		return "{\n\tStartDate: " + period.starDate.ToString() + ",\n\tEndDate  : " + period.endDate.ToString() + "\n}";
	}
	string ToString() {
		return ToString(*this);
	}

	static clsPeriod ReadPeriod() {
		int start_date_day = 0;
		int start_date_month = 0;
		int start_date_year = 0;

		int end_date_day = 0;
		int end_date_month = 0;
		int end_date_year = 0;


		cout << "Filling a period:" << "\n";
		cout << "Filling start date:" << "\n\n";

		cout << "Enter a date: ";
		cin >> start_date_day;

		cout << "Enter a month: ";
		cin >> start_date_month;

		cout << "Enter a year: ";
		cin >> start_date_year;
		cout << "\n";

		cout << "Filling end date:" << "\n\n";

		cout << "Enter a date: ";
		cin >> end_date_day;

		cout << "Enter a month: ";
		cin >> end_date_month;

		cout << "Enter a year: ";
		cin >> end_date_year;
		cout << "\n";

		return clsPeriod(clsDate(start_date_day, start_date_month, start_date_year),
			clsDate(end_date_day, end_date_month, end_date_year));
	}

	static int PeriodLengthInDays(clsPeriod period, bool include_last_day = false) {
		return clsDate::DifferentBtwDatesInDays(period.starDate, period.endDate, include_last_day);
	}
	int PeriodLengthInDays(bool include_last_day = false) {
		return PeriodLengthInDays(*this, include_last_day);
	}

	static bool IsDateWithinPeriod(clsDate date, clsPeriod period) {
		return !(clsDate::IsDate1BeforeDate2(date, period.starDate) || clsDate::IsDate1AfterDate2(date, period.endDate));
	}
	bool IsDateWithinPeriod(clsDate date) {
		return IsDateWithinPeriod(date, *this);
	}

	static void SwitchPeriods(clsPeriod& period1, clsPeriod& period2) {
		clsPeriod aux_period = period1;
		period1 = period2;
		period2 = aux_period;
	}

	static int CountOverlapDays(clsPeriod period1, clsPeriod period2) {
		if (!IsOverlapedPeriods(period1, period2)) return 0;

		int years_length1 = PeriodLengthInYears(period1);
		int years_length2 = PeriodLengthInYears(period2);

		if (years_length1 > years_length2) SwitchPeriods(period1, period2);


		clsDate date = period1.starDate;
		int overlaped_days = 0;


		while (!clsDate::IsEqualDates(date, period1.endDate)) {
			if (IsDateWithinPeriod(date, period2)) overlaped_days++;
			clsDate::IncreaseDateByOne(date);
		}
		if (IsDateWithinPeriod(date, period2)) overlaped_days++;

		return overlaped_days;
	}
	int CountOverlapDays(clsPeriod period) {
		return CountOverlapDays(*this, period);
	}
};

