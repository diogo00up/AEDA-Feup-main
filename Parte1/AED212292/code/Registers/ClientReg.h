#ifndef PROJ_CLIENTREG_H
#define PROJ_CLIENTREG_H

#include <vector>

#include "../Header/Client.h"

using namespace std;

class ClientReg {
private:
    vector<Client *> clients;
public:
    /**
     *
     * @return vector of clients
     */
    const vector<Client *> &getClients() const;
    /**
     *
     * @param clientId
     * @param name
     * @param date
     * @return if doesnt exist adds clients sucesully to vector of clients
     */
    bool addClient(int clientId, string name, Date date);
    /**
     * @brief adds client to vector of clients
     * @param client
     */
    void addClient(Client *client);
    /**
     *
     * @param clientId
     * @return if client with clientId exists
     */
    bool findClient(int clientId);
    /**
     *
     * @param clientId
     * @return if client with clientId was removed
     */
    bool remClient(int clientId);
    /**
     *
     * @param id
     * @return client with id
     */
    Client* getClient(int id);
    /**
     * @brief lists all clients in vector clients
     */
    void listClients();
};

#endif //PROJ_CLIENTREG_H
