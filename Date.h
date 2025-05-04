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
    int getDay() const;
    int getMonth() const;
    int getYear() const;
    void setDay(int d);
    void setMonth(int m);
    void setYear(int y) ;

    time_t toTimeT() const {
        struct tm tm = { 0 };
        tm.tm_year = year - 1900;
        tm.tm_mon = month - 1;
        tm.tm_mday = day;
        return mktime(&tm);
    }

    int operator-(const Date& other) const;
    friend istream& operator>>(istream& is, Date& date);
    friend ostream& operator<<(ostream& os, const Date& date);
    bool operator<(const Date& other) const;
    bool operator>(const Date& other) const;
    bool operator<=(const Date& other) const;
    bool operator>=(const Date& other) const;
    bool operator==(const Date& other) const;
    bool operator!=(const Date& other) const;
};

#endif // DATE_H