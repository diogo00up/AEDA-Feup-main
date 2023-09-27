#ifndef PROJ_TICKET_H
#define PROJ_TICKET_H


#include <string>
#include <iostream>
#include <vector>

#include "SuitCase.h"
#include "Flight.h"
#include "Client.h"

using namespace std;

class Ticket {
private:
    Flight *flight;
    Client *client;

    int ticketId;
    int numberOfCheckedInSuitCases;
    vector<SuitCase*> suitCases;
    bool checked_in;

public:
    /**
     *
     * @param flight
     * @param client
     * @param ticketId
     * @param suitCases
     * @param checkedIn
     * @param nSuitCasesCheckIn
     */
    Ticket(Flight *flight, Client *client, int ticketId, const vector<SuitCase *> &suitCases, bool checkedIn, int nSuitCasesCheckIn);
    /**
     *
     * @param flight
     * @param client
     * @param ticketId
     * @param checkedIn
     * @param nSuitCasesCheckIn
     */
    Ticket(Flight *flight, Client *client, int ticketId, bool checkedIn, int nSuitCasesCheckIn);
    /**
     * @brief adds a new suitcase to ticket
     */
    void addSuitCase();
    /**
     *
     * @return Flight associated with ticket
     */

    Flight *getFlight() const;
    /**
     *
     * @return client associated with ticket
     */

    Client *getClient() const;
    /**
     *
     * @return ticket ID
     */

    int getTicketId() const;
    /**
     *
     * @return  vector of suitcases
     */

    const vector<SuitCase *> &getSuitCases() const;
    /**
     *
     * @return true if ticket is already checked in
     */

    bool isCheckedIn() const;

    /**
     * @brief sets new value for bool checkedIn
     * @param checkedIn
     */

    void setCheckedIn(bool checkedIn);
    /**
     * @brief changes the number of checked in suitcases
     * @param numberOfCheckedInSuitCases
     */

    void setNumberOfCheckedInSuitCases(int numberOfCheckedInSuitCases);
    /**
     *
     * @return  number of checked in suitcases
     */

    int getNumberOfCheckedInSuitCases() const;
};



#endif //PROJ_TICKET_H
