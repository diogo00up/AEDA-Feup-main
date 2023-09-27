#ifndef AEDA_G09_EXCEPTIONS_H
#define AEDA_G09_EXCEPTIONS_H

class InvalidDate {
private:
    unsigned day;
    unsigned month;
    int year;
    string date;
public:
    /**
     * Constructor
     * @param day
     * @param month
     * @param year
     */
    InvalidDate(unsigned day, unsigned month, int year);

    /**
     * Constructor
     * @param date
     */
    InvalidDate(string date);
};



#endif //AEDA_G09_EXCEPTIONS_H
