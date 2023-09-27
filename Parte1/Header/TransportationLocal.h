#ifndef PROJ_TRANSPORTATIONLOCAL_H
#define PROJ_TRANSPORTATIONLOCAL_H

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

#include "../Header/Airport.h"

using namespace std;

enum class TransportationType {subway, train, bus, none};

class TransportationLocal {
private:
    Airport* airport;
    int transportationLocalId;
    float distanceToAirport;
    TransportationType transportationType;
    vector<string> timetable;
public:
    /**
     *
     * @param transportationLocalId
     * @param distanceToAirport
     * @param transportationType
     * @param airport
     */
    TransportationLocal(int transportationLocalId, float distanceToAirport, TransportationType transportationType, Airport *airport);

    /**
     *
     * @param transportationLocalId
     * @param distanceToAirport
     * @param transportationType
     * @param airport
     */
    TransportationLocal(int transportationLocalId, float distanceToAirport, string transportationType, Airport* airport);
    /**
     *
     * @return TransportationLoca ID
     */
    int getTransportationLocalId() const;
    /**
     *
     * @return distance from TransportationLocal to airport
     */

    float getDistanceToAirport() const;

    /**
     *
     * @return  type of transportation in TransportationLocal
     */

    TransportationType getTransportationType() const;
    /**
     *
     * @return TransportationLocal Type as a string
     */

    string getTransportationTypeString() const;
    /**
     *
     * @return  vector representing a timetable
     */

    const vector<string> &getTimetable() const;
    /**
     * @brief insert a new time into timetable
     * @param time
     */

    void insertTimeTable(string time);
    /**
     *
     * @return Aiport
     */

    Airport *getAirport() const;
    /**
     *
     * @param time
     * @return true if time exists in timetable
     */

    bool searchTimeTable(string time);
    /**
     * @brief removes time from timetable
     * @param time
     */

    void removeTimeTable(string time);
    /**
     * @brief lists timetable
     */

    void listTimeTable();

    bool operator<(const TransportationLocal& transportationLocal) const;
};

#endif //PROJ_TRANSPORTATIONLOCAL_H
