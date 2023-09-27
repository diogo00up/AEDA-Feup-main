#include "Header/ManagmentSystem.h"

void ManagmentSystem::listAirports() {
    airportReg.listAirports();
}

void ManagmentSystem::addAirport() {
    string local = Menus::addAirportMenu();
    if(airportReg.addAirport(local) == false) {
        cout << "Failed to add the Airport" << endl;

    }
}

void ManagmentSystem::remAirport() {
    string local = Menus::remAirportMenu();

    if(airportReg.findAirport(local) == true) {
        ticketsReg.remTicket(local);
        flightReg.remFlight(local);
        transportationLocalReg.remTransportationLocal(local);
    }

    if(airportReg.remAirport(local) == false) {
        cout << "Failed to remove the Airport" << endl;
        return;
    }

}

void ManagmentSystem::addPlane() {
    string licensePlate, type;
    int capacity;
    Menus::addPlaneMenu(licensePlate, type, capacity);

    if(airplaneReg.addplane(licensePlate, type, capacity) == false) {
        cout << "Failed to add the Plane" << endl;
    }
}

void ManagmentSystem::remPlane() {
    string licensePlate;
    Menus::remPlaneMenu(licensePlate);

    if(airplaneReg.findAirplane(licensePlate) == true) {
        ticketsReg.remTicketAirplane( licensePlate);
        flightReg.remFlightAirplane( licensePlate);
    }

    if(airplaneReg.remPlane(licensePlate) == false) {
        cout << "Failed to remove the Plane" << endl;
    }
}

void ManagmentSystem::listPlanes() {
    airplaneReg.listAirplanes();
}

void ManagmentSystem::addFlight() {
    string originAirport, destinationAirport;
    int flightNumber, duration;
    string planeLicensePlate;

    Menus::addFlightMenu(originAirport, destinationAirport, flightNumber, duration, planeLicensePlate);

    if(airportReg.findAirport(originAirport) == false || airportReg.findAirport(destinationAirport) == false) {
        cout << "Please enter valid airports" << endl;
        return;
    }
    Airport* origin = airportReg.getAirport(originAirport);
    Airport* destination = airportReg.getAirport(destinationAirport);

    if(airplaneReg.findAirplane(planeLicensePlate) == false) {
        cout << "Please enter a valid plane license plate" << endl;
        return;
    }

    Airplane* airplane = airplaneReg.getAirplane(planeLicensePlate);

    if(flightReg.addFlight(flightNumber, duration, airplane, origin, destination, airplane->getCapacity()) == false) {
        cout << "Failed to add the flight" << endl;
    }

}

void ManagmentSystem::remFlight() {
    int flightNumber;

    Menus::remFlightMenu(flightNumber);

    if(flightReg.remFlight(flightNumber) == false) {
        cout << "Failed to remove the flight" << endl;
    }
}

void ManagmentSystem::listFlights() {
    flightReg.listFlights();
}

void ManagmentSystem::buyTicket() {
    int nTickets;
    int clientId;
    int flightNumber;
    vector<int> ticketIds;
    vector<int> suitcases;

    clientReg.listClients();
    Menus::buyTicketMenu(clientId, flightNumber, ticketIds ,nTickets, suitcases,flightReg);

    if(clientReg.findClient(clientId) == false) {
        cout << "Client not found" << endl;
        cout << "Failed to buy the ticket(s)" << endl;
        return;
    }
    Client *client = clientReg.getClient(clientId);

    if(flightReg.findFlight(flightNumber) ==  false) {
        cout << "Flight not found" << endl;
        cout << "Failed to buy the ticket(s)" << endl;
        return;
    }

    Flight *flight = flightReg.getFlight(flightNumber);

    if(nTickets > flight->getTicketsAvailable()) {
        cout << "There are only " << flight->getTicketsAvailable() << " tickets available" << endl;
        cout << "Failed to buy the ticket(s)" << endl;
        return;
    }

    flight->updateTickets(nTickets);

    for(int i = 0; i < nTickets; i++) {
        if(ticketsReg.addTicket(ticketIds[i], suitcases[i], client, flight) == false) {
            cout << "Failed to add ticket " << ticketIds[i] << endl;
        } else {
            //cout << "Added " << ticketIds[i]<<endl;
        }
    }

}

void ManagmentSystem::addClient() {
    string name;
    Date date;
    int id;

    Menus::addClientMenu(id, name, date);

    if(clientReg.addClient(id, name, date) == false) {
        cout << "Failed to add the client" << endl;
    }
}

void ManagmentSystem::remClient() {
    int id;

    Menus::remClientMenu(id);

    if(clientReg.remClient(id) == false) {
        cout << "Failed to remove the client" << endl;
    }
}

void ManagmentSystem::listClients() {
    clientReg.listClients();
}

void ManagmentSystem::addWorker() {
    string name;
    Date date;
    int id, salary;

    Menus::addWorkerMenu(id, name, date, salary);

    if(workerReg.addWorker(id, name, date, salary) == false) {
        cout << "Failed to add the worker" << endl;
    }
}

void ManagmentSystem::remWorker() {
    int id;

    Menus::remWorkerMenu(id);

    if(workerReg.remWorker(id) == false) {
        cout << "Failed to remove the worker" << endl;
    }
}

void ManagmentSystem::listWorkers() {
    workerReg.listWorkers();
}

void ManagmentSystem::addService() {
    int serviceId;
    string serviceType1;
    Date date;
    int workerId;
    string planeLicensePlate;

    Menus::addServiceMenu(serviceId, serviceType1, date, workerId, planeLicensePlate);

    ServiceType serviceType;

    if(serviceType1 == "maintenance") {
        serviceType = ServiceType::maintenance;
    } else if(serviceType1 == "cleaning") {
        serviceType = ServiceType::cleaning;
    } else {
        cout << "There are no services of this type: " << serviceType1 <<endl;
        cout << "The accepted options are 'maintenance' or 'cleaning'" << endl;
    }

    if(workerReg.findWorker(workerId) == false) {
        cout << "There is no worker associated with this ticketId: " << workerId << endl;
        return;
    }
    if(airplaneReg.findAirplane(planeLicensePlate) == false) {
        cout << "Please enter a valid plane license plate" << endl;
        return;
    }

    Worker *worker = workerReg.getWorker(workerId);
    Airplane *airplane = airplaneReg.getAirplane(planeLicensePlate);

    if(serviceReg.addService(serviceId, serviceType, date, worker, airplane) == false) {
        cout << "Failed to add the service" << endl;
    }
}

void ManagmentSystem::remService() {
    int serviceId;

    Menus::remServiceMenu(serviceId);

    if(serviceReg.remService(serviceId) == false) {
        cout << "Failed to remove the service" << endl;
        return;
    }
}

void ManagmentSystem::listServices() {
    serviceReg.listServices();
}

void ManagmentSystem::addTransportationLocal() {

    int transportationId;
    float distance;
    string transportationType;
    string airportLocal;

    Menus::addTransportationLocalMenu(transportationId, distance, transportationType, airportLocal);

    if(airportReg.findAirport(airportLocal) == false) {
        cout << "Failed to add the Transportation Local. There is no airport: " << airportLocal << endl;
        return;
    }

    Airport *airport = airportReg.getAirport(airportLocal);

    if(transportationLocalReg.addTransportationLocal(transportationId, distance, transportationType, airport) == false) {
        cout << "Failed to add the Transportation Local." <<  endl;
        return;
    }
}


void ManagmentSystem::remTransportationLocal() {
    int transportationLocalId;

    Menus::remTransportationMenu(transportationLocalId);

    if(transportationLocalReg.findTransportationLocal(transportationLocalId) == false){
        cout << "Failed to remove the Transportation Local. There is no ticketId: " << transportationLocalId << endl;
        return;
    }

    if(transportationLocalReg.remTransportationLocal(transportationLocalId) == false) {
        cout << "Failed to remove the Transportation Local." <<  endl;
        return;
    }
}

void ManagmentSystem::addTimeTable() {
    int id;
    string time;

    Menus::addTimeTableMenu(id, time);

    if(transportationLocalReg.addTransportationLocalTimeTable(id, time) == false) {
        cout << "Failed to add the time to the transport local timetable" << endl;
        return;
    }
}

void ManagmentSystem::remTimeTable() {
    int id;
    string time;

    Menus::remTimeTable(id, time);

    if(transportationLocalReg.remTransportationLocalTimeTable(id, time) == false) {
        cout << "Failed to remove the time from the transport local timetable" << endl;
        return;
    }
}

void ManagmentSystem::listTimeTable() {
    int id;

    Menus::listTimeTable(id);

    transportationLocalReg.listTransportationLocalTimeTable(id);
}


void ManagmentSystem::read_from_file() {
    string textline;

    ifstream file_Airplanes;
    ifstream file_Airports;
    ifstream file_Flights;
    ifstream file_Clients;
    ifstream file_Workers;
    ifstream file_Services;
    ifstream file_Transports;
    ifstream file_Tickets;

    file_Airplanes.open("../files/plane.txt");
    file_Airports.open("../files/airports.txt");
    file_Flights.open("../files/flights.txt");
    file_Clients.open("../files/clients.txt");
    file_Workers.open("../files/workers.txt");
    file_Services.open("../files/services.txt");
    file_Transports.open("../files/transports.txt");
    file_Tickets.open("../files/tickets.txt");

    while (getline(file_Airplanes, textline)) {
        vector<string> info;
        string word = "";
        for (auto x : textline) {
            if (x == ' ') {
                info.push_back(word);
                word = "";
            } else {
                word = word + x;
            }
        }
        info.push_back(word);
        Airplane *airplane = new Airplane(info[0],info[1],stoi(info[2]));
        airplaneReg.addplane(airplane);
    }

    while (getline(file_Airports, textline)) {
        vector<string> info;
        string word = "";
        for (auto x : textline) {
            if (x == ' ') {
                info.push_back(word);
                word = "";
            } else {
                word = word + x;
            }
        }
        info.push_back(word);
        Airport *airport = new Airport(info[0]);
        airportReg.addAirport(airport);
    }

    while (getline(file_Flights, textline)) {
        vector<string> info;
        string word = "";
        for (auto x : textline) {
            if (x == ' ') {
                info.push_back(word);
                word = "";
            } else {
                word = word + x;
            }
        }
        info.push_back(word);

        if(airplaneReg.findAirplane(info[2]) == false || airportReg.findAirport(info[3]) == false || airportReg.findAirport(info[4]) == false) {
            continue;
        }

        Airplane *plane = airplaneReg.getAirplane(info[2]);
        Airport *airport1 = airportReg.getAirport(info[3]);
        Airport *airport2 = airportReg.getAirport(info[4]);
        int tickets = stoi(info[5]);
        if(tickets > plane->getCapacity() || tickets < 0) {
            tickets = plane->getCapacity();
        }

        Flight *flight = new Flight(stoi(info[0]),stoi(info[1]), plane,airport1,airport2,tickets);

        flightReg.addFlight(flight);

    }

    while (getline(file_Clients, textline)) {
        vector<string> info;
        string word = "";
        for (auto x : textline) {
            if (x == ' ') {
                info.push_back(word);
                word = "";
            } else {
                word = word + x;
            }
        }
        info.push_back(word);

        Date date(info[2]);


        Client *client = new Client(info[1], date, stoi(info[0]));

        clientReg.addClient(client);

    }

    while (getline(file_Workers, textline)) {
        vector<string> info;
        string word = "";
        for (auto x : textline) {
            if (x == ' ') {
                info.push_back(word);
                word = "";
            } else {
                word = word + x;
            }
        }
        info.push_back(word);

        Date date(info[2]);

        Worker *worker = new Worker(info[1], date, stoi(info[0]), stoi(info[3]));

        workerReg.addWorker(worker);

    }

    while (getline(file_Services, textline)) {
        vector<string> info;
        string word = "";
        for (auto x : textline) {
            if (x == ' ') {
                info.push_back(word);
                word = "";
            } else {
                word = word + x;
            }
        }
        info.push_back(word);

        Date date(info[0]);

        ServiceType serviceType;
        if(info[1] == "maintenance"){
            serviceType = ServiceType::maintenance;
        } else {
            serviceType = ServiceType::cleaning;
        }

        Worker *worker = workerReg.getWorker(stoi(info[3]));
        Airplane *airplane = airplaneReg.getAirplane(info[4]);

        Service* service = new Service(date, serviceType, stoi(info[2]), worker, airplane);

        serviceReg.addService(service);

    }

    while (getline(file_Transports, textline)) {
        vector<string> info;
        string word = "";
        for (auto x : textline) {
            if (x == ' ') {
                info.push_back(word);
                word = "";
            } else {
                word = word + x;
            }
        }
        info.push_back(word);

        Airport *airport = airportReg.getAirport(info[3]);
        TransportationLocal *transportationLocal = new TransportationLocal(stoi(info[0]), stof(info[1]), info[2], airport);

        for(auto it = info.begin()+4; it != info.end(); it++) {
            (*transportationLocal).insertTimeTable(*it);
        }

        transportationLocalReg.addTransportationLocal(transportationLocal);

    }

    while (getline(file_Tickets, textline)) {
        vector<string> info;
        string word = "";
        for (auto x : textline) {
            if (x == ' ') {
                info.push_back(word);
                word = "";
            } else {
                word = word + x;
            }
        }
        info.push_back(word);

        Flight *flight = flightReg.getFlight(stoi(info[0]));

        Client *client = clientReg.getClient(stoi(info[1]));

        int ticketId = stoi(info[2]);
        bool checkedIn;
        if(info[3] == "0") {
            checkedIn = true;
        } else {
            checkedIn = false;
        }
         int nSuitCases = stoi(info[4]);

        Ticket *ticket = new Ticket(flight, client, ticketId, checkedIn, stoi(info[5]));
        for(int i = 0; i < nSuitCases; i++)
            ticket->addSuitCase();
        ticketsReg.addTicket(ticket);

    }


    file_Airplanes.close();
    file_Airports.close();
    file_Flights.close();
    file_Workers.close();
    file_Clients.close();
    file_Services.close();
    file_Transports.close();
    file_Tickets.close();
}

void ManagmentSystem::print_to_file() {

    ofstream file_Airplanes;
    ofstream file_Airports;
    ofstream file_Flights;
    ofstream file_Clients;
    ofstream file_Workers;
    ofstream file_Services;
    ofstream file_Transports;
    ofstream file_Tickets;

    file_Airplanes.open("../files/plane.txt");
    file_Airports.open("../files/airports.txt");
    file_Flights.open("../files/flights.txt");
    file_Clients.open("../files/clients.txt");
    file_Workers.open("../files/workers.txt");
    file_Services.open("../files/services.txt");
    file_Transports.open("../files/transports.txt");
    file_Tickets.open("../files/tickets.txt");

    for(Airplane *plane : airplaneReg.getAirplanes()) {
        file_Airplanes << (*plane).getLicensePlate() << " " << (*plane).getType() << " " <<(*plane).getCapacity()<<endl;
    }

    for(Airport *airport: airportReg.getAirports()) {
        file_Airports << (*airport).getLocal() <<endl;
    }

    for(Flight *flight : flightReg.getFlights()) {
        file_Flights << (*flight).getFlightNumber() << " " << (*flight).getDuration()
        << " " << (*flight).getAirplane()->getLicensePlate() << " " << (*flight).getOrigin()->getLocal() << " "
        << (*flight).getDestination()->getLocal() << " " << (*flight).getTicketsAvailable() <<endl;
    }

    for(Client *client : clientReg.getClients()) {
        file_Clients << (*client).getClientId() << " " << (*client).getName() << " " << (*client).getBirthDate() << endl;
    }

    for(Worker *worker : workerReg.getWorkers()) {
        file_Workers << (*worker).getWorkerId() << " " << (*worker).getName() << " " << (*worker).getBirthDate() << " " << (*worker).getSalary() << endl;
    }

    queue<Service *> temp(serviceReg.getServicesDone());

    while(temp.empty()!=true) {
        file_Services << (temp.front()->getDate()) << " " << temp.front()->getServiceTypeString() << " " << temp.front()->getServiceId() << " " << temp.front()->getWorker()->getWorkerId() << " " << temp.front()->getAirplane()->getLicensePlate() << endl;
        temp.pop();
    }

    queue<Service *> temp1(serviceReg.getServicesToDo());
    temp.swap(temp1);

    while(temp.empty()!=true) {
        file_Services << (temp.front()->getDate()) << " " << temp.front()->getServiceTypeString() << " " << temp.front()->getServiceId() << " " << temp.front()->getWorker()->getWorkerId() << " " << temp.front()->getAirplane()->getLicensePlate() << endl;
        temp.pop();
    }

    BSTItrIn<TransportationLocal *>it(transportationLocalReg.getTransportationLocals());
    while (it.isAtEnd() == false) {

        file_Transports << it.retrieve()->getTransportationLocalId() << " "
        << it.retrieve()->getDistanceToAirport() << " " << it.retrieve()->getTransportationTypeString() << " "
        << it.retrieve()->getAirport()->getLocal();

        for(auto it1 = it.retrieve()->getTimetable().begin(); it1 != it.retrieve()->getTimetable().end(); it1++) {
            file_Transports << " " << *it1;
        }

        file_Transports << endl;

        it.advance();
    }

    for(auto it = ticketsReg.getTickets().begin(); it != ticketsReg.getTickets().end(); it++) {
        file_Tickets << (*it)->getFlight()->getFlightNumber() << " " << (*it)->getClient()->getClientId() << " "
        << (*it)->getTicketId() << " " << ((*it)->isCheckedIn()? "0":"1") << " " << (*it)->getSuitCases().size() << " " << (*it)->getNumberOfCheckedInSuitCases() << endl;
    }


    file_Airplanes.close();
    file_Airports.close();
    file_Flights.close();
    file_Workers.close();
    file_Clients.close();
    file_Services.close();
    file_Transports.close();
    file_Tickets.close();

}

void ManagmentSystem::listTransportationLocal() {
    transportationLocalReg.listTransportationLocals();
}

void ManagmentSystem::listTickets() {
    ticketsReg.listTickets();
}

void ManagmentSystem::checkIn() {
    int clientId;
    Menus::getClientIdMenu(clientId,clientReg);
    if(clientReg.findClient(clientId) == false) {
        cout << "Client does not exist\n" << endl;
        cout << "Failed to chek in" << endl;
        return;
    }
    ticketsReg.listTickets(clientId);

    int ticketId;
    Menus::checkInMenu(ticketId);

    if(ticketsReg.matchTicketClient(ticketId, clientId) == false) {
        cout << "There are no tickets associated with client " << clientId << " " << clientReg.getClient(clientId)->getName() << " and ticketId " << ticketId << endl;
        cout << "Failed to chek in" << endl;
        return;
    }

    if(ticketsReg.checkIn(ticketId) == false) {
        cout << "Failed to chek in" << endl;
        return;
    }
    cout<<"Client checked in!"<<endl;
}

void ManagmentSystem::checkLuggage() {
    int clientId, ticketId;

    Menus::getClientIdMenu(clientId,clientReg);
    if(clientReg.findClient(clientId) == false) {
        cout << "Failed to check the luggage" << endl;
        return;
    }
    ticketsReg.listTickets(clientId);

    Menus::checkLuggageMenu(ticketId);
    if(ticketsReg.findTicket(ticketId) == false) {
        cout << "Failed to check the luggage" << endl;
        return;
    }

    if(ticketsReg.matchTicketClient(ticketId, clientId) == false){
        cout << "Failed to check the luggage" << endl;
        return;
    }

    if(ticketsReg.getTicket(ticketId)->isCheckedIn() == false) {
        cout << "The client needs to be checked in to be able to check the luggage" << endl;
        cout << "Failed to check the luggage" << endl;
        return;
    }
    int nSuitCases = ticketsReg.getTicket(ticketId)->getSuitCases().size();
    int checkedSuitCases = ticketsReg.getTicket(ticketId)->getNumberOfCheckedInSuitCases();

    if(nSuitCases == checkedSuitCases) {
        cout << "All of your luggage has been check in" << endl;
        cout << "Failed to check the luggage" << endl;
        return;
    }

    ticketsReg.getTicket(ticketId)->setNumberOfCheckedInSuitCases(nSuitCases);

    for(SuitCase *s : ticketsReg.getTicket(ticketId)->getSuitCases()){
        cout<<"Suitcase with ID "<<s<< " sent to queue!"<<endl;
        tapete.addSuitCase(s);
    }
    cout<<"All suitcases belonging to client checked in and sent to queue!"<<endl;
}

void ManagmentSystem::transferLuggageToCar() {
    int stackSize, nStacks, nCarriages;

    Menus::newCarMenu(stackSize, nStacks, nCarriages);

    int n = 0;
    Car car(nCarriages, stackSize, nStacks);
    while(car.isFull() ==  false && tapete.get_tapete().empty() == false) {
        if(car.add(tapete.popSuitcase()) == false) {

            cout << "Failed to add suitcase from tapete to car" << endl;
            return;
        }
        n++;
    }
    cout << "Number of suit cases taken from tapete: " << n << endl;
    if(car.isFull()) cout << "Car is full" <<endl;
    if(tapete.get_tapete().empty()) {
        cout << "Tapete is empty" <<endl;
    } else {
        cout << "Number of suit cases in tapete: " << tapete.get_tapete().size() << endl;
    }
    car.printCar();
}

void ManagmentSystem::printTapete() {
    cout << "Suit Cases in Tapete: " << tapete.get_tapete().size()<<endl;
}

void ManagmentSystem::addDecoySuitCases() {
    for(int i = 0; i < 50; i++)
        tapete.addSuitCase(new SuitCase());
}


void ManagmentSystem::sortplanes() {
    airplaneReg.sortPlanebyCapacity();
    airplaneReg.listAirplanes();
}

