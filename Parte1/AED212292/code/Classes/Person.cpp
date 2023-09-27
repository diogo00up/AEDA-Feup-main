#include "../Header/Person.h"

Person::Person(const string &name, const Date &birthDate) : name(name), birthDate(birthDate) {}

const string &Person::getName() const {
    return name;
}

const Date &Person::getBirthDate() const {
    return birthDate;
}
