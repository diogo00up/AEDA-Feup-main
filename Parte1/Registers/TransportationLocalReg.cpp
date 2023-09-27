#include "TransportationLocalReg.h"

TransportationLocalReg::TransportationLocalReg(): transportationLocals(new TransportationLocal(0, 0, "", nullptr)){

}

bool TransportationLocalReg::addTransportationLocal(int transportationLocalId, float distanceToAirport,
                                                    string transportationType, Airport *airport) {
    if(findTransportationLocal(transportationLocalId) == true) {
        cout << "Transport ticketId already in use" << endl;
        return false;
    }
    if(transportationType != "subway" && transportationType != "train" && transportationType != "bus") {
        cout << "No matching transportation type for: " << transportationType <<endl;
        return false;
    }

    TransportationLocal *transportationLocal = new TransportationLocal(transportationLocalId, distanceToAirport, transportationType, airport);

    if(transportationLocals.insert(transportationLocal)==false) {
        cout << "Failed to add Transportation Local" << endl;
        return false;
    }

    return true;
}

bool TransportationLocalReg::findTransportationLocal(int transportationLocalId) {

    BSTItrLevel<TransportationLocal *> it(transportationLocals);

    while(it.isAtEnd() == false) {
        if(it.retrieve()->getTransportationLocalId() == transportationLocalId) {
            return true;
        }

        it.advance();
    }

    return false;
}

bool TransportationLocalReg::addTransportationLocalTimeTable(int transportationLocalId, string time) {
    if(findTransportationLocal(transportationLocalId) == false) {
        cout << "Transport ticketId does not match any ticketId in the database" << endl;
        return false;
    }
    getTransportationLocalById(transportationLocalId)->insertTimeTable(time);
    return true;
}

TransportationLocal *TransportationLocalReg::getTransportationLocalById(int transportationLocalId) {

    if(findTransportationLocal(transportationLocalId) == false) return nullptr;


    BSTItrLevel<TransportationLocal *> it(transportationLocals);

    while(it.isAtEnd() == false) {
        if(it.retrieve()->getTransportationLocalId() == transportationLocalId) {
            return it.retrieve();
        }

        it.advance();
    }

    return nullptr;
}

bool TransportationLocalReg::remTransportationLocalTimeTable(int transportationLocalId, string time) {
    if(findTransportationLocal(transportationLocalId) == false) {
        cout << "Transport ticketId does not match any ticketId in the database" << endl;
        return false;
    }
    getTransportationLocalById(transportationLocalId)->removeTimeTable(time);

    return true;
}

void TransportationLocalReg::listTransportationLocalTimeTable(int transportationLocalId) {
    if(findTransportationLocal(transportationLocalId) == false) {
        cout << "Transport ticketId does not match any ticketId in the database" << endl;
        return;
    }

    getTransportationLocalById(transportationLocalId)->listTimeTable();
}

void TransportationLocalReg::listTransportationLocals() {
    BSTItrIn<TransportationLocal *> it(transportationLocals);

    cout << "Listing All Transportation" << endl;
    while(it.isAtEnd() == false) {
        cout << it.retrieve()->getTransportationLocalId() << " " << it.retrieve()->getTransportationTypeString() << " "
        << it.retrieve()->getDistanceToAirport() << " " << it.retrieve()->getAirport()->getLocal() << endl;

        it.advance();
    }
}

bool TransportationLocalReg::remTransportationLocal(int transportationLocalId) {
    if(findTransportationLocal(transportationLocalId) == false) {
        cout << "Transport ticketId does not match any ticketId in the database" << endl;
        return false;
    }

    BSTItrIn<TransportationLocal *> it(transportationLocals);
    while(it.isAtEnd() == false) {
        if(it.retrieve()->getTransportationLocalId() == transportationLocalId) {
            transportationLocals.remove(it.retrieve());
            return true;
        }

        it.advance();
    }

    return false;
}

void TransportationLocalReg::addTransportationLocal(TransportationLocal *transportationLocal) {
    transportationLocals.insert(transportationLocal);
}

const BST<TransportationLocal *> &TransportationLocalReg::getTransportationLocals() const {
    return transportationLocals;
}

void TransportationLocalReg::remTransportationLocal(string local) {
    BSTItrIn<TransportationLocal *> it(transportationLocals);
    while(it.isAtEnd() == false) {
        if(it.retrieve()->getAirport()->getLocal() == local) {
            transportationLocals.remove(it.retrieve());
        }
        it.advance();
    }
}
