#include <iostream>
#include "Header/Menus.h"
#include "Header/ManagmentSystem.h"
#include "Registers/AirplaneReg.h"


int main() {

    ManagmentSystem managmentSystem;
    managmentSystem.read_from_file();
    managmentSystem.addDecoySuitCases(); //testing remove later
    bool exit = false;

    while (!exit) {
        switch (Menus::MainMenu()) {
            case 0:
                exit = true;
                cout << "\nClosing app" << endl;
                break;

            case 1:
                managmentSystem.addAirport();
                Menus::returnToMainMenu();
                break;

            case 2:
                managmentSystem.remAirport();
                Menus::returnToMainMenu();
                break;

            case 3:
                managmentSystem.listAirports();
                Menus::returnToMainMenu();
                break;

            case 4:
                managmentSystem.addPlane();
                Menus::returnToMainMenu();
                break;
            case 5:
                managmentSystem.remPlane();
                Menus::returnToMainMenu();
                break;

            case 6:
                managmentSystem.listPlanes();
                Menus::returnToMainMenu();
                break;

            case 7:
                managmentSystem.addFlight();
                Menus::returnToMainMenu();
                break;

            case 8:
                managmentSystem.remFlight();
                Menus::returnToMainMenu();
                break;

            case 9:
                managmentSystem.listFlights();
                Menus::returnToMainMenu();
                break;

            case 10:
                managmentSystem.addClient();
                Menus::returnToMainMenu();
                break;

            case 11:
                managmentSystem.remClient();
                Menus::returnToMainMenu();
                break;

            case 12:
                managmentSystem.listClients();
                Menus::returnToMainMenu();
                break;

            case 13:
                managmentSystem.addWorker();
                Menus::returnToMainMenu();
                break;

            case 14:
                managmentSystem.remWorker();
                Menus::returnToMainMenu();
                break;

            case 15:
                managmentSystem.listWorkers();
                Menus::returnToMainMenu();
                break;

            case 16:
                managmentSystem.addService();
                Menus::returnToMainMenu();
                break;


            case 17:
                managmentSystem.remService();
                Menus::returnToMainMenu();
                break;


            case 18:
                managmentSystem.listServices();
                Menus::returnToMainMenu();
                break;

            case 19:
                managmentSystem.addTransportationLocal();
                Menus::returnToMainMenu();
                break;

            case 20:
                managmentSystem.remTransportationLocal();
                Menus::returnToMainMenu();
                break;

            case 21:
                managmentSystem.listTransportationLocal();
                Menus::returnToMainMenu();
                break;

            case 22:
                managmentSystem.addTimeTable();
                Menus::returnToMainMenu();
                break;

            case 23:
                managmentSystem.remTimeTable();
                Menus::returnToMainMenu();
                break;

            case 24:
                managmentSystem.listTimeTable();
                Menus::returnToMainMenu();
                break;

            case 25:
                managmentSystem.buyTicket();
                Menus::returnToMainMenu();
                break;

            case 26:
                managmentSystem.listTickets();
                Menus::returnToMainMenu();
                break;

            case 27:
                managmentSystem.checkIn();
                Menus::returnToMainMenu();
                break;

            case 28:
                managmentSystem.checkLuggage();
                Menus::returnToMainMenu();
                break;

            case 29:
                managmentSystem.transferLuggageToCar();
                Menus::returnToMainMenu();
                break;

            case 30:
                managmentSystem.printTapete();
                Menus::returnToMainMenu();
                break;
            case 31:
                managmentSystem.sortplanes();
                Menus::returnToMainMenu();
                break;

            default:
                cout << "Invalid option" << endl;
                Menus::returnToMainMenu();
        }
    }

    managmentSystem.print_to_file();
    return 0;
}
