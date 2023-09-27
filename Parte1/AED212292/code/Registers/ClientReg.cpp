#include "ClientReg.h"

const vector<Client *> &ClientReg::getClients() const {
    return clients;
}

bool ClientReg::findClient(int clientId) {
    for(Client *c : clients) {
        if((*c).getClientId() == clientId) return true;
    }

    return false;
}

bool ClientReg::addClient(int clientId, string name, Date date) {
    if(findClient(clientId) == true) {
        cout << "The client ticketId is already registered" << endl;
        return false;
    }

    Client *c = new Client(name, date, clientId);
    clients.push_back(c);

    return true;
}

bool ClientReg::remClient(int clientId) {
    for(auto it = clients.begin(); it != clients.end(); it++) {
        if((*it)->getClientId() == clientId) {
            clients.erase(it);
            return true;
        }
    }

    return false;
}

void ClientReg::listClients() {
    for(Client *c: clients) {
        cout << c->getClientId() << " " << c->getName() << " " << c->getBirthDate() << endl;
    }
}

void ClientReg::addClient(Client *client) {
    clients.push_back(client);
}

Client *ClientReg::getClient(int id) {

    for(auto it = clients.begin(); it != clients.end(); it++) {
        if((*it)->getClientId() == id) {
            return (*it);
        }
    }

    return nullptr;
}
