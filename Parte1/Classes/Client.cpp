#include "../Header/Client.h"

Client::Client(const string &name, const Date &birthDate, int clientId) : Person(name, birthDate), clientId(clientId) {}

int Client::getClientId() const {
    return clientId;
}
