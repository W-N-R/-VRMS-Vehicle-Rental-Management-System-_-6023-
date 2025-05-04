#include "Date.h"

Date::Date(int d, int m, int y)
{
	day = d;
	month = m;
	year = y;
}

int Date::getDay() const
{
	return day;
}

int Date::getMonth() const
{
	return month;
}

int Date::getYear() const
{
	return year;
}

void Date::setDay(int d)
{
	day = d;
}

void Date::setMonth(int m)
{
	month = m;
}

void Date::setYear(int y)
{
	year = y;
}

int Date::operator-(const Date& other) const
{
	time_t thisTime = this->toTimeT();
	time_t otherTime = other.toTimeT();
	return difftime(thisTime, otherTime) / (60 * 60 * 24);
}

bool Date::operator<(const Date& other) const
{
	if (year != other.year) {
		return year < other.year;
	}
	if (month != other.month) {
		return month < other.month;
	}
	return day < other.day;
}

bool Date::operator>(const Date& other) const {
	 return other < *this; 
}

bool Date::operator<=(const Date& other) const
{
	 return !(*this > other); 
}

bool Date::operator>=(const Date& other) const
{
	return !(*this < other);
}
bool Date::operator==(const Date& other) const
{
	return day == other.day && month == other.month && year == other.year;
}
bool Date::operator!=(const Date& other) const
{
	return !(*this == other);
}
istream& operator>>(istream& is, Date& date)
{
	char separator;
	is >> date.day >> separator >> date.month >> separator >> date.year;
	return is;
}

ostream& operator<<(ostream& os, const Date& date)
{
	os << date.day << "/" << date.month << "/" << date.year;
	return os;
}

