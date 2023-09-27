#include "TicketsReg.h"

bool TicketsReg::addTicket(Ticket *ticket) {
    tickets.push_back(ticket);
    return true;
}

bool TicketsReg::addTicket(int id, int nSuitCases, Client *client, Flight *flight) {

    if(findTicket(id) == true) {
        cout << "Ticket Id "<< id << " already in use" << endl;
        return false;
    }

    Ticket *ticket =  new Ticket(flight, client, id, false, 0);

    for(int i = 0; i < nSuitCases; i++) {
        ticket->addSuitCase();
    }
    tickets.push_back(ticket);

    return true;
}

bool TicketsReg::findTicket(int id) {
    for(auto it = tickets.begin(); it != tickets.end(); it++) {
        if((*it)->getTicketId() == id) return true;
    }

    return false;
}

Ticket *TicketsReg::getTicket(int id) {

    for(auto it = tickets.begin(); it != tickets.end(); it++) {
        if((*it)->getTicketId() == id) return (*it);
    }

    return nullptr;
}

void TicketsReg::listTickets() {

    cout << "Listing tickets" << endl;

    for(auto it = tickets.begin(); it != tickets.end(); it++) {
        cout << "Ticket id: " <<(*it)->getTicketId() << " Flight number: " << (*it) ->getFlight() -> getFlightNumber()<<" "
        << (*it)->getFlight()->getOrigin()->getLocal() <<" -> " << (*it)->getFlight()->getDestination()->getLocal() << " "
        << (*it)->getClient()->getName() << " client id: " << (*it)->getClient()->getClientId()<< " Checked in: ";
        if((*it)->isCheckedIn()) {
            cout << "yes ";
        } else {
            cout << "no ";
        }
        cout << "Number of suitcases " << (*it)->getSuitCases().size() << " Number of checked in suitcases " << (*it)->getNumberOfCheckedInSuitCases()<< endl;
    }

}

const list<Ticket *> &TicketsReg::getTickets() const {
    return tickets;
}

void TicketsReg::listTickets(int clk) {
    cout << "Listing tickets belonging to client " << clk <<" :"<< endl;

    for(auto it = tickets.begin(); it != tickets.end(); it++) {

        if((*it)->getClient()->getClientId() == clk)
        {
            cout << "Ticket id: " << (*it)->getTicketId() << " Flight number: " << (*it)->getFlight()->getFlightNumber()
                 << " "
                 << (*it)->getFlight()->getOrigin()->getLocal() << " -> "
                 << (*it)->getFlight()->getDestination()->getLocal() << " "
                 << (*it)->getClient()->getName() << " client id: " << (*it)->getClient()->getClientId()
                 << " Checked in: ";
            if ((*it)->isCheckedIn()) {
                cout << "yes ";
            } else {
                cout << "no ";
            }
            cout << "Number of suitcases " << (*it)->getSuitCases().size() << " Number of checked in suitcases " << (*it)->getNumberOfCheckedInSuitCases()<< endl;
        }
    }
}

bool TicketsReg::matchTicketClient(int ticketId, int clientId) {

    for(Ticket *t:getTickets()) {
        if(t->getTicketId() == ticketId && t->getClient()->getClientId() == clientId) {
            return true;
        }
    }

    return false;
}

bool TicketsReg::checkIn(int ticketId) {
    Ticket *t = getTicket(ticketId);

    if(t->isCheckedIn()) {
        cout << "Already checked in" << endl;
        return false;
    }

    t->setCheckedIn(true);

    return true;
}

void TicketsReg::remTicket(string local) {
    auto it = tickets.begin();

    while(it != tickets.end()) {
        if((*it)->getFlight()->getOrigin()->getLocal() == local || (*it)->getFlight()->getDestination()->getLocal() == local) {
            tickets.erase(it);
        } else {
            it++;
        }
    }
}

void TicketsReg::remTicketAirplane(string airplane) {
    auto it = tickets.begin();

    while(it != tickets.end()) {
        if((*it)->getFlight()->getAirplane()->getLicensePlate() == airplane) {
            tickets.erase(it);
        } else {
            it++;
        }
    }
}

