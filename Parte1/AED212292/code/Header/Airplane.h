#ifndef PROJ_AIRPLANE_H
#define PROJ_AIRPLANE_H

#include "string"

using namespace std;

class Airplane {
private:
    string licensePlate;
    string type;
    int capacity;

public:
    /**
     * Constructor:
     * @param licensePlate
     * @param type
     * @param capacity
     */
    Airplane(const string &licensePlate, const string &type, int capacity);

    /**
     *
     * @return the license plate of the airplane
     */
    const string &getLicensePlate() const;

    /**
     *
     * @return the type of the airplane
     */
    const string &getType() const;

    /**
     *
     * @return the number of people the plane can carry
     */
    int getCapacity() const;


};

#endif //PROJ_AIRPLANE_H
