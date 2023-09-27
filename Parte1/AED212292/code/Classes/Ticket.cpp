#include "../Header/Ticket.h"

Ticket::Ticket(Flight *flight, Client *client, int ticketId, const vector<SuitCase *> &suitCases, bool checkedIn, int nSuitCasesCheckIn)
        : flight(flight), client(client), ticketId(ticketId), suitCases(suitCases), checked_in(checkedIn),numberOfCheckedInSuitCases(nSuitCasesCheckIn) {}

Ticket::Ticket(Flight *flight, Client *client, int ticketId, bool checkedIn, int nSuitCasesCheckIn) : flight(flight), client(client),
                                                                               ticketId(ticketId),
                                                                               checked_in(checkedIn), numberOfCheckedInSuitCases(nSuitCasesCheckIn) {}

void Ticket::addSuitCase() {
    suitCases.push_back(new SuitCase());
}

Flight *Ticket::getFlight() const {
    return flight;
}

Client *Ticket::getClient() const {
    return client;
}

int Ticket::getTicketId() const {
    return ticketId;
}

const vector<SuitCase *> &Ticket::getSuitCases() const {
    return suitCases;
}

bool Ticket::isCheckedIn() const {
    return checked_in;
}

void Ticket::setCheckedIn(bool checkedIn) {
    checked_in = checkedIn;
}

int Ticket::getNumberOfCheckedInSuitCases() const {
    return numberOfCheckedInSuitCases;
}

void Ticket::setNumberOfCheckedInSuitCases(int numberOfCheckedInSuitCases) {
    this->numberOfCheckedInSuitCases = numberOfCheckedInSuitCases;
}
