#include "FlightReg.h"

bool FlightReg::addFlight(int flightNumber, int duration, Airplane *airplane, Airport *origin, Airport *destination,
                          int ticketsAvailable) {
    if(findFlight(flightNumber) == true) {
        cout << "The flight number ( " << flightNumber <<" ) is already registered" << endl;
        return false;
    }

    Flight *flight = new Flight(flightNumber, duration, airplane, origin, destination, ticketsAvailable);
    flights.push_back(flight);

    return true;
}

bool FlightReg::findFlight(int flightNumber) {
    for(Flight* f : flights) {
        if(f->getFlightNumber() == flightNumber) return true;
    }

    return false;
}

void FlightReg::listFlights() {
    int i = 1;
    for(Flight* f : flights) {
        cout << i << ") Flight Number: " <<f->getFlightNumber()
        << " Origin: "<< f->getOrigin()->getLocal()
        << " Destination: "<< f->getDestination()->getLocal()
        <<" Duration: "<< f->getDuration()
        << " Tickets Available: " <<f->getTicketsAvailable()
        << " Plane License Plate: " << f->getAirplane()->getLicensePlate() << endl;
        i++;
    }
}

bool FlightReg::remFlight(int flightNumber) {
    for(auto it = flights.begin(); it != flights.end(); it++) {
        if((*it)->getFlightNumber() == flightNumber) {
            flights.erase(it);
            return true;
        }
    }

    cout << "Flight with this flight number does not exist" << endl;
    return false;
}

void FlightReg::addFlight(Flight *flight) {
    flights.push_back(flight);
}

const vector<Flight *> &FlightReg::getFlights() const {
    return flights;
}

Flight *FlightReg::getFlight(int id) {

    for(auto it = flights.begin(); it != flights.end(); it++) {
        if((*it)->getFlightNumber() == id) {
            return (*it);
        }
    }


    return nullptr;
}

void FlightReg::remFlight(string local) {
    for(auto it = flights.begin(); it != flights.end(); it++) {
        if((*it)->getDestination()->getLocal() == local || (*it)->getOrigin()->getLocal() == local) {
            flights.erase(it);
        }
    }
}

void FlightReg::remFlightAirplane(string airplane) {
    for(auto it = flights.begin(); it != flights.end(); it++) {
        if((*it)->getAirplane()->getLicensePlate() == airplane) {
            flights.erase(it);
        }
    }
}

