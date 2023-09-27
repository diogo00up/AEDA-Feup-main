#ifndef PROJ_CAR_H
#define PROJ_CAR_H

#include "Carriage.h"
#include "vector"

using namespace std;
class Car {
private:
    int numberOfCarriages;
    int stackSize;
    int numberOfStacksPerCarriage;
    vector<Carriage *> carro;

public:
    Car(int numberOfCarriages, int stackSize, int numberOfStacksPerCarriage);

    /**
     *
     * @return  numbers of carriaes
     */
    int getNumberOfCarriages() const;
    /**
     *
     * @return size of stack
     */

    int getStackSize() const;
    /**
     *
     * @return  numbers of stacks in each carriage
     */

    int getNumberOfStacksPerCarriage() const;

    /**
     *
     * @return  vector of carriages
     */

    vector<Carriage *> &getCarro();

    /**
     *
     * @param suitCase
     * @return  true if suitcase was added sucefully
     */

    bool add(SuitCase *suitCase);

    /**
     * @brief prints information about the car
     */

    void printCar();

    /**
     *
     * @return true if car is full
     */

    bool isFull();


};


#endif //PROJ_CAR_H
