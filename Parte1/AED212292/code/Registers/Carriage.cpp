#include "Carriage.h"

Carriage::Carriage(int stackSize, int numberOfStacksPerCarriage) : stackSize(stackSize),
                                                                                numberOfStacksPerCarriage(numberOfStacksPerCarriage) {
    for(int i = 0; i < numberOfStacksPerCarriage; i++) {
        vetor.push_back(new stack<SuitCase *>);
    }
}

int Carriage::getStackSize() const {
    return stackSize;
}

int Carriage::getNumberOfStacksPerCarriage() const {
    return numberOfStacksPerCarriage;
}

vector<stack<SuitCase *> *> &Carriage::getVetor() {
    return vetor;
}

bool Carriage::addToCar(SuitCase *suitCase) {
    for(int i = 0; i < numberOfStacksPerCarriage; i++) {
        if(vetor.at(i)->size() < stackSize) {
            vetor.at(i)->push(suitCase);

            return true;
        }
    }

    return false;
}

bool Carriage::isFull() {
    for(stack<SuitCase *> *s : vetor) {
        if(s->size() < stackSize) return false;
    }

    return true;
}

void Carriage::printCarriage() {
    for(stack<SuitCase *> *s : vetor) {
        cout << s->size() << " ";
    }
}
