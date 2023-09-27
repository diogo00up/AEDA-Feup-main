#ifndef PROJ_MANAGMENTSYSTEM_H
#define PROJ_MANAGMENTSYSTEM_H

#include <fstream>
#include "../Registers/AirportReg.h"
#include "../Registers/AirplaneReg.h"
#include "../Registers/FlightReg.h"
#include "../Registers/ClientReg.h"
#include "../Registers/WorkerReg.h"
#include "../Registers/ServiceReg.h"
#include "../Registers/TransportationLocalReg.h"
#include "../Registers/TicketsReg.h"
#include "../Registers/TapeteReg.h"
#include "../Header/Menus.h"
#include "../Registers/Car.h"

class ManagmentSystem {
private:
    AirportReg airportReg;
    AirplaneReg airplaneReg;
    FlightReg flightReg;
    ClientReg clientReg;
    WorkerReg workerReg;
    ServiceReg serviceReg;
    TransportationLocalReg transportationLocalReg;
    TicketsReg ticketsReg;
    TapeteReg tapete;

public:
    /**
     * add an airport to the database
     */
    void addAirport();
    /**
     * remove an airport from the database
     */
    void remAirport();
    /**
     * list the airports in the database
     */
    void listAirports();

    /**
     * add an airplane to the database
     */
    void addPlane();
    /**
     * remove an airplane from the data base
     */
    void remPlane();
    /**
     * list the planes in the database
     */
    void listPlanes();

    /**
     * add a flight to the database
     */
    void addFlight();
    /**
     * remove a flight from the database
     */
    void remFlight();
    /**
     * list the flights in the database
     */
    void listFlights();

    /**
     * add a client to the database
     */
    void addClient();
    /**
     * remove a client from the database
     */
    void remClient();
    /**
     * list the clients in the database
     */
    void listClients();

    /**
     * add a worker to the database
     */
    void addWorker();
    /**
     * remove a worker from the database
     */
    void remWorker();
    /**
     * list the worker in the database
     */
    void listWorkers();

    /**
     * add a service to the database
     */
    void addService();
    /**
     * remove a service from the database
     */
    void remService();
    /**
     * list the services in the database
     */
    void listServices();

    /**
     * add a transport to the database
     */
    void addTransportationLocal();
    /**
     * remove a transport from the databse
     */
    void remTransportationLocal();
    /**
     * list the transports in the database
     */
    void listTransportationLocal();
    /**
     * add a time to the timetable of a transport
     */
    void addTimeTable();
    /**
     * remove the time from the timetable of a transport
     */
    void remTimeTable();
    /**
     * list the timetable of a transport
     */
    void listTimeTable();

    /**
     * buy a ticket to a flight
     */
    void buyTicket();
    /**
     * list the tickets bought
     */
    void listTickets();

    /**
     * Check in the flight
     */
    void checkIn();
    /**
     * Send the luggage (suitcases) to the tapete
     */
    void checkLuggage();

    /**
     * Transfer luggage (suitcases) from the tapete to the car
     */
    void transferLuggageToCar();

    /**
     * Print the number of suitcases in the tapete
     */
    void printTapete();
    /**
     * print the content of the car
     */
    void printCar();

    /**
     * read information from the files .txt and load into the databse
     */
    void read_from_file();

    /**
     * print the information from the database to the files .txt
     */
    void print_to_file();

    /**
     * add decoy suitcases to tapete to perform tests
     */
    void addDecoySuitCases();

    void sortplanes();
};

#endif //PROJ_MANAGMENTSYSTEM_H
