#ifndef PROJ_TAPETEREG_H
#define PROJ_TAPETEREG_H

#include "../Header/SuitCase.h"
#include <queue>
#include "string"
#include "iostream"

using namespace std;

class TapeteReg{
private:
    queue<SuitCase*> tapete;
public:
    TapeteReg();
    /**
     *
     * @return  queue of suitcases
     */
    queue<SuitCase*> get_tapete();
    /**
     * @brief adds a suitcase to the queue of suitcases
     * @param suitcase
     */
    void addSuitCase(SuitCase* suitcase);
    /**
     *
     * @return Suitcase that was poped out of queue of suitcases
     */
    SuitCase* popSuitcase();



};

#endif //PROJ_TAPETEREG_H
