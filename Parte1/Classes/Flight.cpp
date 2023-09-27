#include "../Header/Flight.h"

Flight::Flight(int flightNumber, int duration, Airplane *airplane, Airport *origin, Airport *destination,
               int ticketsAvailable) : flightNumber(flightNumber), duration(duration), airplane(airplane),
                                       origin(origin), destination(destination), ticketsAvailable(ticketsAvailable) {}

int Flight::getFlightNumber() const {
    return flightNumber;
}

int Flight::getDuration() const {
    return duration;
}

Airplane *Flight::getAirplane() const {
    return airplane;
}

Airport *Flight::getOrigin() const {
    return origin;
}

Airport *Flight::getDestination() const {
    return destination;
}

int Flight::getTicketsAvailable() const {
    return ticketsAvailable;
}

void Flight::updateTickets(int x) {
    this->ticketsAvailable = this->ticketsAvailable - x;
}
