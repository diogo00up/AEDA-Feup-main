#ifndef PROJ_CARRIAGE_H
#define PROJ_CARRIAGE_H

#include "../Header/SuitCase.h"
#include "string"
#include "iostream"
#include "stack"
#include "vector"

using namespace std;
class Carriage{
private:
    int stackSize;
    int numberOfStacksPerCarriage;
    vector<stack<SuitCase*> *> vetor;
public:
    Carriage(int stackSize, int numberOfStacksPerCarriage);

    /**
     *
     * @return size of stack
     */
    int getStackSize() const;
    /**
     *
     * @return numbers of stacks per carriage
     */

    int getNumberOfStacksPerCarriage() const;
    /**
     *
     * @return vector of stacks of suitcases
     */

    vector<stack<SuitCase *> *> &getVetor();
    /**
     *
     * @param suitCase
     * @return true if adds suitcase sucefully to carriage
     */

    bool addToCar(SuitCase* suitCase);
    /**
     *
     * @return true if carriage is full
     */

    bool isFull();
    /**
     *
     * @return size of carriage
     */

    int getSize();
    /**
     * @brief prints information about the carriage
     */

    void printCarriage();


};

#endif //PROJ_CARRIAGE_H
