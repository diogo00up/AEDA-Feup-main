#include "AirportReg.h"

using namespace std;

AirportReg::AirportReg() {}

const vector<Airport *> &AirportReg::getAirports() const {
    return airports;
}

void AirportReg::addAirport(Airport *airport) {
    airports.push_back(airport);
}

bool AirportReg::addAirport(string local) {
    if(findAirport(local) == true) {
        cout << "Airport already exists" << endl;
        return false;
    }

    Airport *airport = new Airport(local);
    airports.push_back(airport);

    return true;
}

bool AirportReg::remAirport(string local) {
    for(auto it = airports.begin(); it != airports.end(); it++) {
        if((*it)->getLocal() == local) {
            airports.erase(it);
            return true;
        }
    }
    cout << "Airport does not exist" << endl;
    return false;
}

void AirportReg::listAirports() {
    if(getAirports().size() == 0) {
        cout << "No airports registered" << endl;
        return;
    }
    int i = 1;
    for(auto it = airports.begin(); it != airports.end(); it++) {
        cout << i << ": " << (*it)->getLocal() << endl;
        i++;
    }
}

bool AirportReg::findAirport(string local) {
    for(Airport* ap: getAirports()) {
        if((*ap).getLocal() == local) {
            return true;
        }
    }

    return false;
}

Airport *AirportReg::getAirport(string local) {
    for(Airport* ap: getAirports()) {
        if((*ap).getLocal() == local) {
            return ap;
        }
    }
    return nullptr;
}

ostream &operator<<(ostream &os, Airport airport) {
    os << airport.getLocal() << endl;

    return os;
}
