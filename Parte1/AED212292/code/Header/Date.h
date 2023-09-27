#ifndef PROJ_DATE_H
#define PROJ_DATE_H

#include <ctime>
#include "iostream"

using namespace std;

class Date {
private:
    unsigned day;
    unsigned month;
    int year;
private:
    bool checkDate(unsigned day, unsigned month, int year);

public:
    /**
     * Empty constructor, default date is 1-1-0
     */
    Date();

    /**
     * Constructor:
     * turns a string on the format dd-mm-yyyy to a date
     * @param Date
     */
    Date(string Date);

    /**
     * Constructor
     * @param day
     * @param month
     * @param year
     */
    Date(unsigned day, unsigned month, int year);

    /**
     * Copy constructor
     * @param date
     */
    Date(const Date &date);

    /**
     *
     * @param d1
     * @return the difference, in days, of the date and d1
     */
    int differenceBetween(const Date &d1) const;

    /**
     *
     * @param month
     * @return if the month received has 31 days
     */
    static bool has31(unsigned month);

    /**
     *
     * @param year
     * @return if the year passed is leap year
     */
    static bool isLeapYear(int year);

    /**
     *
     * @return a Date with the values of the current system
     */
    static Date &getCurrentDate();

    /**
     *
     * @return day
     */
    unsigned int getDay() const;

    /**
     *
     * @return month
     */
    unsigned int getMonth() const;

    /**
     *
     * @return year
     */
    int getYear() const;

    /**
     *
     * @param os
     * @param date
     * @return an ostream with the information about the date
     */
    friend ostream &operator<<(ostream &os, const Date &date);

    friend bool operator<(const Date &d1, const Date &d2);

    friend bool operator==(const Date &d1, const Date &d2);
};

#endif //PROJ_DATE_H
