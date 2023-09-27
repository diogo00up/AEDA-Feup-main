#ifndef PROJ_TICKETSREG_H
#define PROJ_TICKETSREG_H


#include "../Header/Ticket.h"
#include <list>

class TicketsReg {
private:
    list<Ticket *> tickets;
public:
    /**
     *
     * @param ticket
     * @return true if ticket was added to list of tickets
     */
    bool addTicket(Ticket *ticket);
    /**
     *
     * @param id
     * @param nSuitCases
     * @param client
     * @param flight
     * @return true if ticket with all parameters was added to list of tickets
     */
    bool addTicket(int id, int nSuitCases, Client* client, Flight* flight);
    /**
     *
     * @param id
     * @return true if ticket with id exits
     */

    bool findTicket(int id);
    /**
     *
     * @param ticketId
     * @param clientId
     * @return true if client with clientId matches with ticket with ticketId
     */

    bool matchTicketClient(int ticketId, int clientId);
    /**
     * @brief listd all tickets on the list
     */

    void listTickets();
    /**
     * @brief lists all tickets bellonging to client with clientID
     * @param clientId
     */
    void listTickets(int clientId);
    /**
     *
     * @param ticketId
     * @return true if tickedId was checkedin
     */

    bool checkIn(int ticketId);
    /**
     *
     * @param id
     * @return tickry with id
     */

    Ticket* getTicket(int id);
    /**
     *
     * @return list of tickets
     */

    const list<Ticket *> &getTickets() const;

    /**
     * removes tickets from an aiport and to an airport
     * @param local
     */
    void remTicket(string local);

    /**
     *
     * @param airplane
     */
    void remTicketAirplane(string airplane);

};


#endif //PROJ_TICKETSREG_H
