#include "AirplaneReg.h"

using namespace std;

AirplaneReg::AirplaneReg() {}

void AirplaneReg::addplane(Airplane *plane) {
    this->airplanes.push_back(plane);
}

vector<Airplane *> AirplaneReg::getAirplanes() {
    return this->airplanes;
}

bool AirplaneReg::addplane(string licensePlate, string type, int capacity) {
    if(findAirplane(licensePlate) == true) {
        cout << "This License Plate (" << licensePlate << ") is already registered" << endl;
        return false;
    }

    Airplane *airPlane = new Airplane(licensePlate, type, capacity);
    airplanes.push_back(airPlane);

    return true;
}

bool AirplaneReg::findAirplane(string licensePlate) {

    for(auto it = airplanes.begin(); it < airplanes.end(); it++) {
        if((*it)->getLicensePlate() == licensePlate) return true;
    }

    return false;
}

Airplane *AirplaneReg::getAirplane(string licensePlate) {
    for(auto it = airplanes.begin(); it < airplanes.end(); it++) {
        if((*it)->getLicensePlate() == licensePlate) return *it;
    }
    return nullptr;
}

bool AirplaneReg::remPlane(string licensePlate) {

    for(auto it = airplanes.begin(); it < airplanes.end(); it++) {
        if((*it)->getLicensePlate() == licensePlate) {
            airplanes.erase(it);
            return true;
        }
    }
    cout << "There is no Plane with License Plate (" << licensePlate << ") registered" << endl;
    return false;
}

void AirplaneReg::listAirplanes() {
    if(getAirplanes().size() == 0) {
        cout << "No planes registered" << endl;
        return;
    }
    int i = 1;
    for(auto it = airplanes.begin(); it != airplanes.end(); it++) {
        cout << i << ") license plate: " << (*it)->getLicensePlate() << " type: "<< (*it)->getType() << " capacity: " << (*it)->getCapacity() << endl;
        i++;
    }
}

bool comparePlanebyCapacity(Airplane *a1,Airplane *a2) {
    return a1->getCapacity()<a2->getCapacity();
}

void AirplaneReg::sortPlanebyCapacity() {
    sort(airplanes.begin(),airplanes.end(), comparePlanebyCapacity);

}




