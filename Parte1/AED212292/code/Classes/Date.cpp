#include "../Header/Date.h"

#include <vector>

#include "sstream"
#include "../Header/Menus.h"
#include "../Header/exceptions.h"

Date::Date(string date) {
    char separator;
    unsigned day;
    unsigned month;
    int year;
    vector<string> v = Menus::splitString(date, "-");
    if (v.size() == 3 && Menus::is_number(v[0]) && Menus::is_number(v[1]) && Menus::is_number(v[2])) {
        stringstream(v[0]) >> day;
        stringstream(v[1]) >> month;
        stringstream(v[2]) >> year;
        if (!checkDate(day, month, year)) throw InvalidDate(date);
        this->day = day;
        this->month = month;
        this->year = year;
    } else throw InvalidDate(date);
}

InvalidDate::InvalidDate(string date) {
    this->date = date;
}

InvalidDate::InvalidDate(unsigned day, unsigned month, int year) {
    this->day = day;
    this->month = month;
    this->year = year;
}

Date &Date::getCurrentDate() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    Date *date = new Date(ltm->tm_mday, ltm->tm_mon + 1, 1900 + ltm->tm_year);
    return *date;
}

Date::Date(unsigned int day, unsigned int month, int year) {
    if (!checkDate(day, month, year)) throw InvalidDate(day, month, year);
    this->day = day;
    this->month = month;
    this->year = year;
}

Date::Date(const Date &date) {
    this->day = date.getDay();
    this->month = date.getMonth();
    this->year = date.getYear();
}

Date::Date() {
    this->day = 1;
    this->month = 1;
    this->year = 0;
}


bool Date::has31(unsigned month) {
    switch (month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return true;
    }
    return false;
}

bool Date::isLeapYear(int year) {
    return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

bool Date::checkDate(unsigned int day, unsigned int month, int year) {
    if (day < 1 || day > 31 || month < 1 || month > 12) return false;
    if (month == 2) {
        if (isLeapYear(year)) {
            if (day > 29) {
                return false;
            }
        } else {
            if (day > 28) {
                return false;
            }
        }
    }
    if (has31(month)) {
        if (day > 31) return false;
    } else {
        if (day > 30) return false;
    }
    return true;
}

std::tm make_tm(int year, int month, int day) {
    std::tm tm = {0};
    tm.tm_year = year - 1900; // years count from 1900
    tm.tm_mon = month - 1;    // months count from January=0
    tm.tm_mday = day;         // days count from 1
    return tm;
}

int Date::differenceBetween(const Date &d1) const {
    // Structures representing the two dates
    std::tm tm1 = make_tm(this->year, this->month, this->day);    // April 2nd, 2012
    std::tm tm2 = make_tm(d1.year, d1.month, d1.day);    // February 2nd, 2003

// Arithmetic time values.
// On a posix system, these are seconds since 1970-01-01 00:00:00 UTC
    std::time_t time1 = std::mktime(&tm1);
    std::time_t time2 = std::mktime(&tm2);

// Divide by the number of seconds in a day
    const int seconds_per_day = 60 * 60 * 24;
    return (time1 - time2) / seconds_per_day;
}


unsigned int Date::getDay() const {
    return day;
}



unsigned int Date::getMonth() const {
    return month;
}


int Date::getYear() const {
    return year;
}


ostream &operator<<(ostream &os, const Date &date) {
    os << date.getDay() << "-" << date.getMonth() << "-" << date.getYear();
    return os;
}

bool operator<(const Date &d1, const Date &d2) {
    if (d1.differenceBetween(d2) < 0) {
        return true;
    } else return false;

}

bool operator==(const Date &d1, const Date &d2) {
    if (d1.differenceBetween(d2) == 0) {
        return true;
    } else return false;
}
