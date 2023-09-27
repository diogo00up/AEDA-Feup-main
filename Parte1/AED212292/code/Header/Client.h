#ifndef PROJ_CLIENT_H
#define PROJ_CLIENT_H
#include "Person.h"

class Client : public Person {
private:
    int clientId;
public:
    /**
     * Constructor:
     * @param name
     * @param birthDate
     * @param clientId
     */
    Client(const string &name, const Date &birthDate, int clientId);

    /**
     *
     * @return the id of the client
     */
    int getClientId() const;
};

#endif //PROJ_CLIENT_H
