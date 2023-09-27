#include "Car.h"

Car::Car(int numberOfCarriages, int stackSize, int numberOfStacksPerCarriage) : numberOfCarriages(numberOfCarriages),
                                                                                stackSize(stackSize),
                                                                                numberOfStacksPerCarriage(
                                                                                          numberOfStacksPerCarriage) {
    for(int i = 0; i < numberOfCarriages; i++) {
        carro.push_back(new Carriage(stackSize, numberOfStacksPerCarriage));
    }
}

int Car::getNumberOfCarriages() const {
    return numberOfCarriages;
}

int Car::getStackSize() const {
    return stackSize;
}

int Car::getNumberOfStacksPerCarriage() const {
    return numberOfStacksPerCarriage;
}

vector<Carriage *> &Car::getCarro() {
    return carro;
}

bool Car::add(SuitCase *suitCase) {
    for(Carriage *c : carro) {
        if(c->isFull() == false) {
            c->addToCar(suitCase);
            return true;
        }
    }

    return false;
}

void Car::printCar() {
    cout << "Printing car"<<endl;
    cout << "Start";
    for(Carriage *c : carro) {
        cout << " -- | ";
        c->printCarriage();
        cout << "|";
    }
    cout << " -- End" <<endl;
}

bool Car::isFull(){
    for(Carriage *c : carro) {
        if(c->isFull() == false) return false;
    }

    return true;
}
