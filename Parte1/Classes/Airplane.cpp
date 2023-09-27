#include "../Header/Airplane.h"

Airplane::Airplane(const string &licensePlate, const string &type, int capacity) : licensePlate(licensePlate),
                                                                                   type(type), capacity(capacity) {
}

const string &Airplane::getLicensePlate() const {
    return licensePlate;
}

const string &Airplane::getType() const {
    return type;
}

int Airplane::getCapacity() const {
    return capacity;
}

