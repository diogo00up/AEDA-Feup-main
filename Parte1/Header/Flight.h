#ifndef PROJ_FLIGHT_H
#define PROJ_FLIGHT_H

#include "Airport.h"
#include "Airplane.h"

class Flight {
private:

    int flightNumber, duration;
    Airplane *airplane;
    Airport *origin, *destination;
    int ticketsAvailable;

public:
    /**
     * Constructor:
     * @param flightNumber
     * @param duration
     * @param airplane
     * @param origin
     * @param destination
     * @param ticketsAvailable
     */
    Flight(int flightNumber, int duration, Airplane *airplane, Airport *origin, Airport *destination,
           int ticketsAvailable);

    /**
     *
     * @return the flight number
     */
    int getFlightNumber() const;

    /**
     *
     * @return the flight duration
     */
    int getDuration() const;

    /**
     *
     * @return a pointer to the airplane associated with the flight
     */
    Airplane *getAirplane() const;

    /**
     *
     * @return a pointer to the origin airport of the flight
     */
    Airport *getOrigin() const;

    /**
     *
     * @return a pointer to the destination airport of the flight
     */
    Airport *getDestination() const;

    /**
     *
     * @return the number of tickets available for the flight
     */
    int getTicketsAvailable() const;

    /**
     * update the number of available tickets
     * @param x
     */
    void updateTickets(int x);
};

#endif //PROJ_FLIGHT_H
