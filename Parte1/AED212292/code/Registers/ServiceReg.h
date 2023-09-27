#ifndef PROJ_SERVICEREG_H
#define PROJ_SERVICEREG_H

#include "../Header/Service.h"
#include "queue"

class ServiceReg {
private:
    queue<Service *> servicesToDo;
    queue<Service *> servicesDone;

public:
    /**
     *
     * @param serviceId
     * @param serviceType
     * @param date
     * @param worker
     * @param airplane
     * @return true if service with all parameters didnt exist and was added to queue
     */
    bool addService(int serviceId, ServiceType serviceType, Date date, Worker *worker, Airplane *airplane);
    /**
     * @brief adds a service to queue
     * @param service
     */
    void addService(Service *service);
    /**
     *
     * @param serviceId
     * @return  true if service with serviceId was removed from queue of services
     */

    bool remService(int serviceId);
    /**
     *
     * @param serviceId
     * @return  true if service with serviceId was founf
     */

    bool findServiceToDo(int serviceId);
    /**
     *
     * @param date
     * @param serviceType
     * @return true if service with all parameters was found
     */
    bool findServiceToDo(Date date, ServiceType serviceType);
    /**
     *
     * @param serviceId
     * @return true if service with serviceId was found
     */

    bool findServiceDone(int serviceId);
    /**
     *
     * @param date
     * @param serviceType
     * @return true if service with all parameters was found
     */
    bool findServiceDone(Date date, ServiceType serviceType);
    /**
     * @brief lists all services in the queue
     */

    void listServices();
    /**
     *
     * @return  queue of services to do
     */

    const queue<Service *> &getServicesToDo() const;

    /**
     *
     * @return  queue of services to be done
     */

    const queue<Service *> &getServicesDone() const;

};


#endif //PROJ_SERVICEREG_H
