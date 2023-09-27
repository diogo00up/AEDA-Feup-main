//
// Created by mpspm on 30/11/2021.
//

#ifndef PROJ_AIRPORTREG_H
#define PROJ_AIRPORTREG_H

#include "vector"
#include "iostream"
#include "../Header/Airport.h"

using namespace std;

class AirportReg {
private:
    vector<Airport *> airports;

public:
    AirportReg();
    /**
     *
     * @return vector airports
     */

    const vector<Airport *> &getAirports() const;
    /**
     * @brief adds an airport to vector airports
     * @param airport
     */

    void addAirport(Airport *airport);
    /**
     *
     * @param local
     * @return true if airport was added
     */

    bool addAirport(string local);
    /**
     *
     * @param local
     * @return true if airport with parameter local exists
     */

    bool findAirport(string local);

    /**
     *
     * @param local
     * @return true if airport with paramater local was removed
     */

    bool remAirport(string local);

    /**
     * @brief lists airports in vector airports
     */

    void listAirports();

    /**
     *
     * @param local
     * @return Airport with paramater local
     */

    Airport* getAirport(string local);

    /**
     *
     * @param os
     * @param airport
     * @return prints information about an aeroport
     */

    friend ostream &operator<<(ostream &os, Airport &airport);
};


#endif //PROJ_AIRPORTREG_H
