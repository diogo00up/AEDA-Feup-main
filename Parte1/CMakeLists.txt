cmake_minimum_required(VERSION 3.20)
project(proj)

set(CMAKE_CXX_STANDARD 14)

add_executable(proj main.cpp Classes/Menus.cpp Header/Menus.h Header/ManagmentSystem.h Header/Airport.h Classes/Airport.cpp Header/Airplane.h Classes/Airplane.cpp Header/Flight.h Classes/Flight.cpp Registers/AirportReg.cpp Registers/AirportReg.h Registers/AirplaneReg.cpp Registers/AirplaneReg.h Registers/FlightReg.cpp Registers/FlightReg.h ManagmentSystem.cpp Classes/Date.cpp Header/Date.h Header/Person.h Classes/Person.cpp Header/Client.h Classes/Client.cpp Header/Worker.h Classes/Worker.cpp Registers/ClientReg.h Registers/ClientReg.cpp Registers/WorkerReg.cpp Registers/WorkerReg.h Header/Service.h Classes/Service.cpp Registers/ServiceReg.cpp Registers/ServiceReg.h Header/bst.h Header/TransportationLocal.h Classes/TransportationLocal.cpp Registers/TransportationLocalReg.cpp Registers/TransportationLocalReg.h Registers/Carriage.h Header/SuitCase.h Registers/TapeteReg.h Header/Ticket.h Registers/Carriage.cpp Classes/SuitCase.cpp Registers/TapeteReg.cpp Classes/Ticket.cpp Registers/TicketsReg.cpp Registers/TicketsReg.h Registers/Car.cpp Registers/Car.h)
