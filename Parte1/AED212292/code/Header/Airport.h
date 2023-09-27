#ifndef PROJ_AIRPORT_H
#define PROJ_AIRPORT_H

#include "string"
#include "iostream"

using namespace std;

class Airport {
private:
    string local;

public:
    /**
     * Constructor:
     * @param local
     */
    Airport(const string &local);

    /**
     *
     * @return the local of the airport
     */
    const string &getLocal() const;

    /**
     *
     * @param nome
     */
    void set_name(string nome);
};

#endif //PROJ_AIRPORT_H
