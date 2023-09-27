#include "../Header/TransportationLocal.h"

int TransportationLocal::getTransportationLocalId() const {
    return transportationLocalId;
}

float TransportationLocal::getDistanceToAirport() const {
    return distanceToAirport;
}

TransportationType TransportationLocal::getTransportationType() const {
    return transportationType;
}


const vector<string> &TransportationLocal::getTimetable() const {
    return timetable;
}

string TransportationLocal::getTransportationTypeString() const {
    if(transportationType == TransportationType::bus) {
        return "bus";
    } else if(transportationType == TransportationType::subway) {
        return "subway";
    } else if(transportationType == TransportationType::train){
        return "train";
    } else {
        return "";
    }
}

void TransportationLocal::insertTimeTable(string time) {
    if (searchTimeTable(time) == false) {
        timetable.push_back(time);
        sort(timetable.begin(), timetable.end());
    }
}

bool TransportationLocal::searchTimeTable(string time) {
    for(string s: timetable) {
        if(s == time) return true;
    }

    return false;
}

void TransportationLocal::removeTimeTable(string time) {
    if(searchTimeTable(time) == true || searchTimeTable("0"+time) == true) {
        for(auto it = timetable.begin(); it != timetable.end(); it++) {
            if( *it == time ) {
                timetable.erase(it);
                return;
            }
        }
    }
}

TransportationLocal::TransportationLocal(int transportationLocalId, float distanceToAirport,
                                         TransportationType transportationType, Airport *airport) : transportationLocalId(
        transportationLocalId), distanceToAirport(distanceToAirport), transportationType(transportationType), airport(airport) {

}

TransportationLocal::TransportationLocal(int transportationLocalId, float distanceToAirport,
                                         string transportationType, Airport *airport) {
    this->transportationLocalId = transportationLocalId;
    this->distanceToAirport = distanceToAirport;
    this->airport = airport;

    if(transportationType ==  "bus") {
        this->transportationType = TransportationType::bus;
    } else if(transportationType == "train") {
        this->transportationType = TransportationType::train;
    } else if(transportationType == "subway") {
        this->transportationType = TransportationType::subway;
    } else {
        this->transportationType = TransportationType::none;
    }

}

bool TransportationLocal::operator<(const TransportationLocal &transportationLocal) const {
    if(this->getAirport()->getLocal() == transportationLocal.getAirport()->getLocal()) {

        if(this->getDistanceToAirport() == transportationLocal.getDistanceToAirport()) {
            return this->getTransportationLocalId() < transportationLocal.getTransportationLocalId();
        }

        return this->getDistanceToAirport() < transportationLocal.getDistanceToAirport();
    }

    return this->getAirport()->getLocal() == transportationLocal.getAirport()->getLocal();
}

Airport *TransportationLocal::getAirport() const {
    return airport;
}

void TransportationLocal::listTimeTable() {

    if (transportationType == TransportationType::subway) {
        cout << "Timetable for subway Id: " << getTransportationLocalId() << endl;
    } else if (transportationType == TransportationType::train) {
        cout << "Timetable for train Id: " << getTransportationLocalId() << endl;
    } else if (transportationType == TransportationType::bus) {
        cout << "Timetable for bus Id: " << getTransportationLocalId() << endl;
    } else {
        cout << "Timetable for none Id: " << getTransportationLocalId() << endl;
    }

    for(string s:getTimetable()) {
        cout << stoi(s) /100 << "h" << stoi(s)%100 << endl;
    }
}




