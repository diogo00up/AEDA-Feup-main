//
// Created by mpspm on 06/12/2021.
//

#include "WorkerReg.h"

const vector<Worker *> &WorkerReg::getWorkers() const {
    return workers;
}

bool WorkerReg::addWorker(int workerId, string name, Date date, int salary) {
    if(findWorker(workerId) == true) {
        cout << "The worker ticketId is already registered" << endl;
        return false;
    }

    Worker *c = new Worker(name, date, workerId, salary);
    workers.push_back(c);

    return true;
}

bool WorkerReg::remWorker(int workerId) {
    for(auto it = workers.begin(); it != workers.end(); it++) {
        if((*it)->getWorkerId() == workerId) {
            workers.erase(it);
            return true;
        }
    }

    return false;
}

bool WorkerReg::findWorker(int workerId) {
    for(Worker *w : workers) {
        if((*w).getWorkerId() == workerId) {
            return true;
        }
    }

    return false;
}

void WorkerReg::listWorkers() {
    for(Worker *c: workers) {
        cout << c->getWorkerId() << " " << c->getName() << " " << c->getBirthDate() <<" " << c->getSalary()<< endl;
    }
}

void WorkerReg::addWorker(Worker *worker) {
    workers.push_back(worker);
}

Worker *WorkerReg::getWorker(int workerId) {
    for(auto it = workers.begin(); it != workers.end(); it++) {
        if((*it)->getWorkerId() == workerId) {
            return *it;
        }
    }

    return nullptr;
}


