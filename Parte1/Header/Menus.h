#ifndef PROJ_MENUS_H
#define PROJ_MENUS_H

#include "sstream"
#include "iostream"
#include "vector"


#include "Date.h"
#include "../Registers/ClientReg.h"
#include "../Registers/FlightReg.h"

using namespace std;

class Menus {
public:
    /**
     * @brief Main menu presents all the options
     * @return the option selected
     */
    static int MainMenu();

    /**
     *
     * @param s
     * @return true if the input parameter is of the numeric type, else false
     */
    static bool is_number(const string &s);

    /**
     * @brief Menu used to retrieve the name of the airport to create
     * @return string which represents the local of an airport
     */
    static string addAirportMenu();

    /**
     * @brief Menu used to retrieve the name of the airport to remove
     * @return string which represents the local of an airport
     */
    static string remAirportMenu();

    /**
     * @brief returns to the main menu
     */
    static void  returnToMainMenu();

    /**
     *
     * @param s
     * @param delimiter
     * @return vector of strings after splitting the main string
     */
    static vector<string> splitString(string s, string delimiter);

    /**
     * @brief Menu used to retrieve data to add an airplane
     * @param licensePlate
     * @param type
     * @param capacity
     */
    static void addPlaneMenu(string &licensePlate, string &type, int &capacity);

    /**
     * @brief Menu used to retrieve the license plate of the airplane to remove
     * @param licensePlate
     */
    static void remPlaneMenu(string &licensePlate);

    /**
     * @brief Menu used to retrieve data to add a flight
     * @param originAirport
     * @param destinationAirport
     * @param flightNumber
     * @param duration
     * @param planeLicensePlate
     */
    static void addFlightMenu(string &originAirport, string &destinationAirport, int &flightNumber, int &duration, string &planeLicensePlate);

    /**
     * @brief Menu used to retrieve the flight number of the flight to remove
     * @param flightNumber
     */
    static void remFlightMenu(int &flightNumber);

    /**
     * @brief Menu used to retrieve data to add a client
     * @param clientId
     * @param name
     * @param date
     */
    static void addClientMenu(int &clientId, string &name, Date &date);

    /**
     * @brief Menu used to retrieve the clientId of the client to remove
     * @param clientId
     */
    static void remClientMenu(int &clientId);

    /**
     * @brief Menus used to retrieve data to add a worker
     * @param workerId
     * @param name
     * @param date
     * @param salary
     */
    static void addWorkerMenu(int &workerId, string &name, Date &date, int &salary);

    /**
     * @brief Menu used to retrieve the workerId of the worker to remove
     * @param workerId
     */
    static void remWorkerMenu(int &workerId);

    /**
     * @brief Menu used to retrieve data to add a service
     * @param serviceId
     * @param serviceType
     * @param date
     * @param workerId
     * @param planeLicensePlate
     */
    static void addServiceMenu(int &serviceId, string &serviceType, Date &date, int &workerId, string &planeLicensePlate);

    /**
     * @brief Menu used to retrieve the serviceId of the service to remove
     * @param serviceId
     */
    static void remServiceMenu(int &serviceId);

    /**
     * @brief Menu used to retrieve data to add a transport
     * @param transportationLocalId
     * @param distance
     * @param transportationType
     * @param airportLocal
     */
    static void addTransportationLocalMenu(int &transportationLocalId, float &distance, string &transportationType, string &airportLocal);

    /**
     * @brief Menu used to retrieve the id of the transport to remove
     * @param id
     */
    static void remTransportationMenu(int &id);

    /**
     * @brief Menu used to add times to the timetable of a transport
     * @param id
     * @param time
     */
    static void addTimeTableMenu(int &id, string &time);

    /**
     * @brief Menu used to remove times from a transport's timetable
     * @param id
     * @param time
     */
    static void remTimeTable(int &id, string &time);

    /**
     * @brief Menu used to list the timetable of a specific transport
     * @param id
     */
    static void listTimeTable(int &id);

    /**
     * @brief Menu used to retrieve data to add a ticket
     * @param clientId
     * @param flightId
     * @param ticketIds
     * @param numTickets
     * @param suitCases
     */
    static void buyTicketMenu(int &clientId, int &flightId,vector<int> &ticketIds, int &numTickets, vector<int> &suitCases,FlightReg &flightReg);

    /**
     * @brief Menu used to retrieve a clientId
     * @param clientId
     */
    static void getClientIdMenu(int &clientId,ClientReg &clientReg);

    /**
     * @brief Menu used to check in a ticket
     * @param ticketId
     */
    static void checkInMenu(int &ticketId);

    /**
     * @brief Menu used to check in the luggage
     * @param ticketId
     */
    static void checkLuggageMenu(int &ticketId);

    /**
     * @brief Menu used to create a car to transport the luggage
     * @param stackSize
     * @param nStacks
     * @param nCarriages
     */
    static void newCarMenu(int &stackSize, int &nStacks, int &nCarriages);
};

#endif //PROJ_MENUS_H
