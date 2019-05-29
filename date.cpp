#include "date.h"
using namespace std;

Date::Date(int year, int month, int day)
	: year_(year), month_(month), day_(day) {}
int Date::GetDay() const { return (day_); }
int Date::GetMonth() const { return (month_); }
int Date::GetYear() const { return (year_); }

Date ParseDate(istream& is)
{
	string date;
	int year, month, day;
	getline(is, date, '-');
	year = stoi(date);
	getline(is, date, '-');
	month = stoi(date);
	getline(is, date, ' ');
	day = stoi(date);
	Date date_(year, month, day);
	return (date_);
}