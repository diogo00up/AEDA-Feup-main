#ifndef PROJ_FLIGHTREG_H
#define PROJ_FLIGHTREG_H

#include "vector"
#include "../Header/Flight.h"
#include "../Header/Airplane.h"

class FlightReg {
private:
    vector<Flight *> flights;
public:
    /**
     * @brief adds flight to vector of flights
     * @param flight
     */
    void addFlight(Flight* flight);
    /**
     *
     * @param flightNumber
     * @param duration
     * @param airplane
     * @param origin
     * @param destination
     * @param ticketsAvailable
     * @return if flight with this parameters doesnt exists creates and adds to vector of flight
     */
    bool addFlight(int flightNumber, int duration, Airplane *airplane, Airport *origin, Airport *destination,
                   int ticketsAvailable);
    /**
     *
     * @param flightNumber
     * @return true if flight with flightnumbers exits
     */
    bool findFlight(int flightNumber);
    /**
     *
     * @param flightNumber
     * @return true if flight with flightnumber is removed from vector of flights
     */

    bool remFlight(int flightNumber);
    /**
     * @brief lists all flights in vector of flights
     */

    void listFlights();
    /**
     *
     * @return vector of flights
     */
    const vector<Flight *> &getFlights() const;
    /**
     *
     * @param id
     * @return  Flight with id
     */
    Flight *getFlight(int id);

    /**
     *
     * @param local
     */
    void remFlight(string local);

    /**
     *
     * @param airplane
     */
    void remFlightAirplane(string airplane);
};

#endif //PROJ_FLIGHTREG_H
