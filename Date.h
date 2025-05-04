#pragma once
#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <ctime>
#include <string>

using namespace std;

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date(int d = 1, int m = 1, int y = 2000);

    // Getter methods
    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }

    // Setter methods
    void setDay(int d) { day = d; }
    void setMonth(int m) { month = m; }
    void setYear(int y) { year = y; }

    // Convert Date to time_t
    time_t toTimeT() const {
        struct tm tm = { 0 };
        tm.tm_year = year - 1900;
        tm.tm_mon = month - 1;
        tm.tm_mday = day;
        return mktime(&tm);
    }

    // Operator overloading for date difference (in days)
    int operator-(const Date& other) const {
        time_t thisTime = this->toTimeT();
        time_t otherTime = other.toTimeT();
        return difftime(thisTime, otherTime) / (60 * 60 * 24); // Convert seconds to days
    }

    // Input operator overloading
    friend istream& operator>>(istream& is, Date& date) {
        char separator;
        is >> date.day >> separator >> date.month >> separator >> date.year;
        return is;
    }

    // Output operator overloading
    friend ostream& operator<<(ostream& os, const Date& date) {
        os << date.day << "/" << date.month << "/" << date.year;
        return os;
    }

    // Comparison operators
    bool operator<(const Date& other) const {
        if (year != other.year) return year < other.year;
        if (month != other.month) return month < other.month;
        return day < other.day;
    }

    bool operator>(const Date& other) const { return other < *this; }
    bool operator<=(const Date& other) const { return !(*this > other); }
    bool operator>=(const Date& other) const { return !(*this < other); }
    bool operator==(const Date& other) const {
        return day == other.day && month == other.month && year == other.year;
    }
    bool operator!=(const Date& other) const { return !(*this == other); }
};

#endif // DATE_H