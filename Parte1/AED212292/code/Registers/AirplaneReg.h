#ifndef PROJ_AIRPLANEREG_H
#define PROJ_AIRPLANEREG_H

#include "vector"
#include "iostream"
#include "algorithm"
#include "../Header/Airplane.h"

class AirplaneReg {
private:
    vector<Airplane *> airplanes;

public:
    AirplaneReg();
    /**
     *
     * @param licensePlate
     * @return true if plane with licensePlate exists
     */

    bool findAirplane(string licensePlate);
    /**
     * @brief adds a plane to airplanes
     * @param plane
     */
    void addplane(Airplane *plane);
    /**
     *
     * @param licensePlate
     * @param type
     * @param capacity
     * @return true if plane was created and inserted
     */
    bool addplane(string licensePlate, string type, int capacity);
    /**
     *
     * @param licensePlate
     * @return true if planes was removed sucefully
     */
    bool remPlane(string licensePlate);
    /**
     *
     * @return planes vector
     */
    vector<Airplane *> getAirplanes();
    /**
     *
     * @param licensePlate
     * @return  plane with licensePlate
     */
    Airplane *getAirplane(string licensePlate);
    /**
     * @brief lists all planes from airplanes
     */
    void listAirplanes();
    /**
     * @brief sorts plane vector by plane capaicty
     */
    void sortPlanebyCapacity();

};

#endif //PROJ_AIRPLANEREG_H
