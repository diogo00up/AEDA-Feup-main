#ifndef PROJ_WORKERREG_H
#define PROJ_WORKERREG_H

#include <vector>
#include "../Header/Worker.h"

class WorkerReg {
private:
    vector<Worker *> workers;
public:
    /**
     *
     * @return vector of workers
     */
    const vector<Worker *> &getWorkers() const;
    /**
     *
     * @param workerId
     * @param name
     * @param date
     * @param salary
     * @return true if worker with parameters was added sucefully
     */
    bool addWorker(int workerId, string name, Date date, int salary);
    /**
     * @brief adds worker to vector of workers
     * @param worker
     */
    void addWorker(Worker *worker);
    /**
     *
     * @param workerId
     * @return true if worker with workerId was removed sucefully
     */
    bool remWorker(int workerId);
    /**
     *
     * @param workerId
     * @return true if worker with workerId exits
     */
    bool findWorker(int workerId);
    /**
     * @brief lists all workers
     */
    void listWorkers();
    /**
     *
     * @param workerId
     * @return worker with workerId
     */

    Worker* getWorker(int workerId);
};


#endif //PROJ_WORKERREG_H
