#include "ServiceReg.h"

bool ServiceReg::findServiceToDo(int serviceId) {
    queue<Service *> temp(servicesToDo);

    while(temp.empty() != true) {
        if(temp.front()->getServiceId() == serviceId) return true;
        temp.pop();
    }

    return false;
}

bool ServiceReg::findServiceDone(int serviceId) {
    queue<Service *> temp(servicesDone);

    while(temp.empty() != true) {
        if(temp.front()->getServiceId() == serviceId) return true;
        temp.pop();
    }

    return false;
}

bool ServiceReg::findServiceToDo(Date date, ServiceType serviceType) {
    queue<Service *> temp(servicesToDo);

    while(temp.empty() != true) {
        if(temp.front()->getDate() == date && temp.front()->getServiceType() == serviceType) return true;
        temp.pop();
    }

    return false;
}

bool ServiceReg::findServiceDone(Date date, ServiceType serviceType) {
    queue<Service *> temp(servicesDone);

    while(temp.empty() != true) {
        if(temp.front()->getDate() == date && temp.front()->getServiceType() == serviceType) return true;
        temp.pop();
    }

    return false;
}

void ServiceReg::addService(Service *service) {
    if(service->getDate() < Date::getCurrentDate()) {
        servicesDone.push(service);
    } else {
        servicesToDo.push(service);
    }
}

bool ServiceReg::addService(int serviceId, ServiceType serviceType, Date date, Worker *worker, Airplane *airplane) {

    if(findServiceToDo(serviceId) == true || findServiceDone(serviceId) == true) {
        cout << "There is already a service with this service Id registered" << endl;
        return false;
    }

    Service *service = new Service(date, serviceType, serviceId, worker, airplane);

    if(service->getDate() < Date::getCurrentDate()) {
        servicesDone.push(service);
        return true;
    }

    servicesToDo.push(service);

    return true;

}

bool ServiceReg::remService(int serviceId) {
    bool retValue = false;

    if(findServiceDone(serviceId) == true) {
        queue<Service *> temp(servicesDone), final;

        while (temp.empty() != true) {
            if(temp.front()->getServiceId() == serviceId) {
                temp.pop();
                retValue = true;
                continue;
            }
            final.push(temp.front());
            temp.pop();
        }

        servicesDone.swap(final);
    } else if(findServiceToDo(serviceId) == true) {
        queue<Service *> temp(servicesToDo), final;

        while (temp.empty() != true) {
            if(temp.front()->getServiceId() == serviceId) {
                temp.pop();
                retValue = true;
                continue;
            }
            final.push(temp.front());
            temp.pop();
        }

        servicesToDo.swap(final);
    }

    return retValue;
}

void ServiceReg::listServices() {
    queue<Service *> temp(servicesDone);

    cout << "Services done: \n" <<endl;

    while (temp.empty() != true) {
        if(temp.front()->getServiceType() == ServiceType::maintenance) {
            cout << "Service ticketId: " << temp.front()->getServiceId() << " Type: " << "maintenance" << " Date: "
                 << temp.front()->getDate() << " Worker: " << temp.front()->getWorker()->getWorkerId() << " "
                 << temp.front()->getWorker()->getName() << " Airlane: "
                 << temp.front()->getAirplane()->getLicensePlate() << endl;
        } else {
            cout << "Service ticketId: " << temp.front()->getServiceId() << " Type: " << "cleaning" << " Date: "
                 << temp.front()->getDate() << " Worker: " << temp.front()->getWorker()->getWorkerId() << " "
                 << temp.front()->getWorker()->getName() << " Airlane: "
                 << temp.front()->getAirplane()->getLicensePlate() << endl;
        }

        temp.pop();
    }

    cout << "\nServices to do:\n" << endl;

    queue<Service *> temp1(servicesToDo);

    while (temp1.empty() != true) {
        if(temp1.front()->getServiceType() == ServiceType::maintenance) {
            cout << "Service ticketId: " << temp1.front()->getServiceId() << " Type: " << "maintenance" << " Date: "
                 << temp1.front()->getDate() << " Worker: " << temp1.front()->getWorker()->getWorkerId() << " "
                 << temp1.front()->getWorker()->getName() << " Airlane: "
                 << temp1.front()->getAirplane()->getLicensePlate() << endl;
        } else {
            cout << "Service ticketId: " << temp1.front()->getServiceId() << " Type: " << "cleaning" << " Date: "
                 << temp1.front()->getDate() << " Worker: " << temp1.front()->getWorker()->getWorkerId() << " "
                 << temp1.front()->getWorker()->getName() << " Airlane: "
                 << temp1.front()->getAirplane()->getLicensePlate() << endl;
        }

        temp1.pop();
    }
}

const queue<Service *> &ServiceReg::getServicesToDo() const {
    return servicesToDo;
}

const queue<Service *> &ServiceReg::getServicesDone() const {
    return servicesDone;
}




