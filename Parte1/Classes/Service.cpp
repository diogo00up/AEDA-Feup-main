#include "../Header/Service.h"

const Date &Service::getDate() const {
    return date;
}

ServiceType Service::getServiceType() const {
    return serviceType;
}

int Service::getServiceId() const {
    return serviceId;
}

bool Service::operator<(Service s1) {
    if(this->date == s1.getDate()) {
        return this->serviceId < s1.getServiceId();
    }
    return this->date < s1.getDate();
}

Service::Service(const Date &date, ServiceType serviceType, int serviceId, Worker *worker, Airplane *airplane) : date(
        date), serviceType(serviceType), serviceId(serviceId), worker(worker), airplane(airplane) {}

Worker *Service::getWorker() const {
    return worker;
}

Airplane *Service::getAirplane() const {
    return airplane;
}

string Service::getServiceTypeString() const {
   if(serviceType == ServiceType::maintenance) {
       return "maintenance";
   } else {
       return "cleaning";
   }
}
