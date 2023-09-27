#ifndef PROJ_WORKER_H
#define PROJ_WORKER_H

#include "Person.h"

class Worker: public Person {
private:
    int workerId;
    int salary;
public:
    /**
     * Constructor
     * @param name
     * @param birthDate
     * @param workerId
     * @param salary
     */
    Worker(const string &name, const Date &birthDate, int workerId, int salary);

    /**
     *
     * @return the id of the worker
     */
    int getWorkerId() const;

    /**
     *
     * @return the salary of the worker
     */
    int getSalary() const;

    /**
     * Changes the salary of the worker
     * @param salary
     */
    void setSalary(int salary);
};

#endif //PROJ_WORKER_H
