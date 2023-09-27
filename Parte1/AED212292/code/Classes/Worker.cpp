#include "../Header/Worker.h"

Worker::Worker(const string &name, const Date &birthDate, int workerId, int salary) : Person(name, birthDate),
                                                                                      workerId(workerId),
                                                                                      salary(salary) {}

int Worker::getWorkerId() const {
    return workerId;
}

int Worker::getSalary() const {
    return salary;
}

void Worker::setSalary(int salary) {
    this->salary = salary;
}
