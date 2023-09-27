#include "../Header/Menus.h"

int Menus::MainMenu() {
    string str_instruction;
    int instruction;
    cout << "x 1  - Add Airport" << endl;
    cout << "x 2  - Remove Airport" << endl;
    cout << "x 3  - List Airports" << endl;
    cout << "x 4  - Add Plane" << endl;
    cout << "x 5  - Remove Plane" << endl;
    cout << "x 6  - List Planes" << endl;
    cout << "x 7  - Add Flight" << endl;
    cout << "x 8  - Remove Flight" << endl;
    cout << "x 9  - List Flights" << endl;
    cout << "x 10 - Add Client" << endl;
    cout << "x 11 - Remove Client" << endl;
    cout << "x 12 - List Clients" << endl;
    cout << "x 13 - Add Worker" << endl;
    cout << "x 14 - Remove Worker" << endl;
    cout << "x 15 - List Workers" << endl;
    cout << "x 16 - Add Service" << endl;
    cout << "x 17 - Remove Service" << endl;
    cout << "x 18 - List Services" << endl;
    cout << "x 19 - Add Transportation Local" << endl;
    cout << "x 20 - Remove Transportation Local" << endl;
    cout << "x 21 - List Transportation Locals" << endl;
    cout << "x 22 - Add Time to Timetable" << endl;
    cout << "x 23 - Remove Time from Timetable" << endl;
    cout << "x 24 - List Timetable" << endl;
    cout << "x 25 - Buy Ticket" << endl;
    cout << "x 26 - List Tickets" << endl;
    cout << "x 27 - Check In" << endl;
    cout << "x 28 - Check luggage" << endl;
    cout << "x 29 - Transfer Luggage to the Car" << endl;
    cout << "x 30 - Print Tapete Size" << endl;
    cout << "x 31 - Sort planes by Capacity"<<endl;

    cout << "x 0 - Exit" << endl;

    cin >> str_instruction;

    if (!is_number(str_instruction)) return -1;
    stringstream sst(str_instruction);
    sst >> instruction;
    return instruction;
}

bool Menus::is_number(const string &s) {
    string::const_iterator it = s.begin();
    while (it != s.end() && isdigit(*it))it++;
    return !s.empty() && it == s.end();
}

void Menus::returnToMainMenu() {
    string perm_to_cont;
    cout << "Type anything to go to the menu\n";
    cin >> perm_to_cont;
}

string Menus::addAirportMenu() {
    string local;
    cout << "Insert the local/name of the Airport to add:" << endl;
    cin >> local;

    return local;
}

string Menus::remAirportMenu() {
    string local;
    cout << "Insert the local/name of the Airport to remove:" << endl;
    cin >> local;

    return local;

}

vector<string> Menus::splitString(string s, string delimiter) {
    vector<string> vector;
    size_t position = 0;
    while ((position = s.find((delimiter))) != string::npos) {
        if (position != 0)vector.push_back(s.substr(0, position));
        s.erase(0, position + delimiter.length());
    }
    if (!s.empty())vector.push_back(s);
    return vector;
}

void Menus::addPlaneMenu(string &licensePlate, string &type, int &capacity) {

    cout<<"License plate of new plane?"<<endl;
    cin>>licensePlate;
    cout<<"Type of new plane?"<<endl;
    cin>>type;
    cout<<"Capacity?"<<endl;
    cin>>capacity;

}

void Menus::remPlaneMenu(string &licensePlate) {
    cout<<"License plate of the plane to remove?"<<endl;
    cin>>licensePlate;
}

void Menus::addFlightMenu(string &originAirport, string &destinationAirport, int &flightNumber, int &duration,
                          string &planeLicensePlate) {
    cout << "Enter the origin airport: " <<endl;
    cin >> originAirport;

    cout << "Enter the destination airport: "<<endl;
    cin >> destinationAirport;

    cout << "Enter the flight number: "<<endl;
    cin >> flightNumber;

    cout << "Enter the flight duration: "<<endl;
    cin >> duration;

    cout << "Enter the plane license plate: "<<endl;
    cin >> planeLicensePlate;
}

void Menus::remFlightMenu(int &flightNumber){
    cout << "Enter the flight number of the flight to remove:"<< endl;
    cin >> flightNumber;
}

void Menus::addClientMenu(int &clientId, string &name, Date &date) {
    string data;

    cout << "Insert the Id for the client:" << endl;
    cin >> clientId;

    cout << "Insert the client name:" << endl;
    cin >> name;

    cout << "Insert the client birth date dd-mm-yy:" << endl;
    cin >> data;

    Date newDate(data);
    date = newDate;
}

void Menus::remClientMenu(int &clientId) {
    cout << "Insert the id of the client to remove" << endl;
    cin >> clientId;
}

void Menus::addWorkerMenu(int &workerId, string &name, Date &date, int &salary) {
    string data;

    cout << "Insert the id for the worker:" << endl;
    cin >> workerId;

    cout << "Insert the worker name:" << endl;
    cin >> name;

    cout << "Insert the worker birth date dd-mm-yy:" << endl;
    cin >> data;

    cout << "Insert the worker salary" << endl;
    cin >> salary;

    Date newDate(data);
    date = newDate;
}

void Menus::remWorkerMenu(int &workerId) {
    cout << "Insert the id of the worker to remove" << endl;
    cin >> workerId;
}

void Menus::addServiceMenu(int &serviceId, string &serviceType, Date &date, int &workerId, string &planeLicensePlate) {
    string data;

    cout << "Insert the id for the service:" << endl;
    cin >> serviceId;

    cout << "Insert the service type (maintenance or cleaning):" << endl;
    cin >> serviceType;

    cout << "Insert the service date dd-mm-yy:" << endl;
    cin >> data;

    cout << "Insert the worker id associated with the service:" << endl;
    cin >> workerId;

    cout << "Insert the plane license plate:" << endl;
    cin >> planeLicensePlate;

    Date newDate(data);
    date = newDate;
}

void Menus::remServiceMenu(int &serviceId) {
    cout << "Insert the id for the service to remove:" << endl;
    cin >> serviceId;
}

void Menus::addTransportationLocalMenu(int &transportationLocalId, float &distance, string &transportationType,
                                       string &airportLocal) {

    cout << "Insert the transportationLocalId" << endl;
    cin >> transportationLocalId;

    cout << "Insert the distance to the airport " << endl;
    cin >> distance;

    cout << "Insert the name of the airport" << endl;
    cin >> airportLocal;

    cout << "Insert the transportation type (bus, subway, train)" << endl;
    cin >> transportationType;
}

void Menus::remTransportationMenu(int &id) {
    cout << "Insert the id of the Transportation Local to remove" << endl;
    cin >> id;
}

void Menus::addTimeTableMenu(int &id, string &time) {
    int hours, minutes;
    cout << "Insert the id of the Transportation Local to add to the timetable" << endl;
    cin >> id;

    cout << "Insert the time (hours 0-23):" << endl;
    cin >> hours;
    while( hours < 0  || hours > 23) {
        cout << "Invalid hours. Try again." << endl;
        fflush(stdin);
        cin >> hours;
    }

    cout << "Insert the minutes (hours 0-59):" << endl;
    cin >> minutes;
    while( minutes < 0  || minutes > 59) {
        cout << "Invalid minutes. Try again." << endl;
        fflush(stdin);
        cin >> minutes;
    }
    if(hours < 10 && minutes < 10) {
        time = "0" + to_string((hours)) + "0" + to_string(minutes);
    } else if(hours < 10) {
        time = "0" + to_string((hours*100+minutes));
    } else if (minutes < 10){
        time = to_string((hours)) + "0" + to_string(minutes);
    } else {

        time = to_string((hours*100+minutes));
    }
}

void Menus::remTimeTable(int &id, string &time) {
    int hours, minutes;
    cout << "Insert the id of the Transportation Local to remove from the timetable" << endl;
    cin >> id;

    cout << "Insert the time (hours 0-23):" << endl;
    cin >> hours;
    while( hours < 0  || hours > 23) {
        cout << "Invalid hours. Try again." << endl;
        fflush(stdin);
        cin >> hours;
    }

    cout << "Insert the minutes (hours 0-59):" << endl;
    cin >> minutes;
    while( minutes < 0  || minutes > 59) {
        cout << "Invalid minutes. Try again." << endl;
        fflush(stdin);
        cin >> minutes;
    }

    if(hours < 10 && minutes < 10) {
        time = "0" + to_string((hours)) + "0" + to_string(minutes);
    } else if(hours < 10) {
        time = "0" + to_string((hours*100+minutes));
    } else if (minutes < 10){
        time = to_string((hours)) + "0" + to_string(minutes);
    } else {

        time = to_string((hours*100+minutes));
    }
}

void Menus::listTimeTable(int &id) {
    cout << "Insert the Transportation local id to print its timetable" << endl;
    cin >> id;
}

void Menus::buyTicketMenu(int &clientId, int &flightId, vector<int> &ticketIds,int &numTickets, vector<int> &suitCases,FlightReg &flightReg) {
    cout << "Insert the client Id" << endl;
    cin >> clientId;

    cout<<endl<<"--Displaying flights--"<<endl;
    flightReg.listFlights();

    cout <<endl<< "Insert the Flight number" << endl;
    cin >> flightId;

    cout << "Insert how many tickets to buy:"<<endl;
    cin >> numTickets;
    while(numTickets < 0) {
        cout << "Number of tickets can not be negative. Try again:"<<endl;
        cin >> numTickets;
    }

    int id_aux=1090;
    int aux = 0;
    for(int i = 1; i < numTickets+1; i++) {
        cout << "Insert how many suitcases associated with ticket " << i << endl;
        cin >> aux;
        while(aux < 0) {
            cout << "Number of suitcases can not be negative. Try again:"<<endl;
            cin >> aux;
        }
        suitCases.push_back(aux);

        id_aux+=20;
        ticketIds.push_back(id_aux);
    }
}

void Menus::getClientIdMenu(int &clientId,ClientReg &clientReg) {
    cout<<"--Displaying clients--"<<endl;
    clientReg.listClients();
    cout << "Insert the client id:" << endl;
    cin >> clientId;

}

void Menus::checkInMenu(int &ticketId) {
    cout << "Insert the ticket id:" << endl;
    cin >> ticketId;
}

void Menus::checkLuggageMenu(int &ticketId) {
    cout << "Insert the ticket id to check in your luggage:" << endl;
    cin >> ticketId;
}

void Menus::newCarMenu(int &stackSize, int &nStacks, int &nCarriages) {
    cout << "Insert the number of carriages:" <<endl;
    cin >> nCarriages;

    cout << "Insert the number of stacks:" << endl;
    cin >> nStacks;

    cout << "Insert the size of the stacks:" << endl;
    cin >> stackSize;
}
