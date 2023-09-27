#ifndef PROJ_SERVICE_H
#define PROJ_SERVICE_H

#include "Date.h"
#include "Airplane.h"
#include "Worker.h"

using namespace std;

enum class ServiceType { maintenance, cleaning };

class Service {
private:

    Date date;
    enum ServiceType serviceType;
    int serviceId;
    Worker *worker;
    Airplane *airplane;

public:
    /**
     * Constructor
     * @param date
     * @param serviceType
     * @param serviceId
     * @param worker
     * @param airplane
     */
    Service(const Date &date, ServiceType serviceType, int serviceId, Worker *worker, Airplane *airplane);

    /**
     *
     * @return the date of the service
     */
    const Date &getDate() const;

    /**
     *
     * @return a pointer to the worker associated with the service
     */
    Worker *getWorker() const;

    /**
     *
     * @return a pointer to the airplane associated with the service
     */
    Airplane *getAirplane() const;

    /**
     *
     * @return the service type
     */
    ServiceType getServiceType() const;

    /**
     *
     * @return the service type as a string
     */
    string getServiceTypeString() const;

    /**
     *
     * @return the service id
     */
    int getServiceId() const;

    bool operator<(Service s1);

};

#endif //PROJ_SERVICE_H
