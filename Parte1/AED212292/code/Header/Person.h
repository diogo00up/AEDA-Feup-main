#ifndef PROJ_PERSON_H
#define PROJ_PERSON_H

#include "Date.h"

class Person {
private:
    string name;
    Date birthDate;

public:
    /**
     * Constructor
     * @param name
     * @param birthDate
     */
    Person(const string &name, const Date &birthDate);

    /**
     *
     * @return a string representing the name
     */
    const string &getName() const;

    /**
     *
     * @return the birth date
     */
    const Date &getBirthDate() const;
};

#endif //PROJ_PERSON_H
