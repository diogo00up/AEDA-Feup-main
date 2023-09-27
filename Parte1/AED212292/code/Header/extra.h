//
// Created by diogo on 02.12.2021.
//

#include <fstream>
#include <iostream>
#include <algorithm>
#include "../Registers/TapeteReg.h"
#include "../Registers/Carriage.h"

#ifndef PROJ_EXTRA_H
#define PROJ_EXTRA_H
/*
Airplane* search_plane_for_flight(AirplaneReg *plane_list,int flight_number){
    for(int i=0; i<plane_list->get_plane_list().size();i++){
        for(int a=0;a<plane_list->get_plane_list()[i]->get_voos()->get_voos().size();a++){
            if(plane_list->get_plane_list()[i]->get_voos()->get_voos()[a]->getflight_number()==flight_number){
                return plane_list->get_plane_list()[i];
            }
        }
    }
}

Flight* search_flights(FlightReg *all_flight_regist,string cidade){
    for(int i=0;i<all_flight_regist->get_voos().size();i++){
        if(all_flight_regist->get_voos()[i]->get_origin()->getLocal()==cidade){
            cout<<"["<<i<<"]"<<" Flight number: "<<all_flight_regist->get_voos()[i]->getflight_number()<<" Origin: "<<all_flight_regist->get_voos()[i]->get_origin()->getLocal()<<" Destination: "<<all_flight_regist->get_voos()[i]->get_destination()->getLocal()<<" Duration: "<<all_flight_regist->get_voos()[i]->get_duration()<<endl;
        }
    }
    int x;
    cout<<"Which flight would you like to choose? (ex: 0,1,2..)"<<endl;
    cin>>x;
    auto viagem_escolhida = all_flight_regist->get_voos()[x];
    //auto numero_viagem=all_flight_regist->get_voos()[x]->getflight_number();
    return viagem_escolhida;
}


void choose_flight(FlightReg *all_flight_regist,AirplaneReg *plane_list){
    cout<<endl<<"----BUYING TICKET-----"<<endl;
    vector<string> places={"LA","LIS","OPO","SYD","PAR","LON","KIE","MDR","BAR"};
    int choice;
    cout<<"Choose Origin(ex: 0,1,2... ) "<<endl;
    for(auto x=0; x<places.size();x++){
        cout<<"["<<x<<"] "<<places[x]<<endl;
    }
    cin>>choice;
    auto origem=places[choice];
    cout<<"Displaying all flights from this Origin:"<<endl;
    auto numero_viagem_escolhida=search_flights(all_flight_regist,origem);   // return the flight choosen
    auto aviao_viagem= search_plane_for_flight(plane_list,numero_viagem_escolhida->getflight_number()); //returns the plane for this flight
    cout<<"The plane for your trip: "<<endl;
    cout<<"Matricula: "<<aviao_viagem->getLicensePlate()<<" Tipo: "<<aviao_viagem->getType()<<endl;
    cout<<endl<<"CHECKING TICKET AVALABILITY..."<<endl;
    int bilhetes_disponiveis=aviao_viagem->getCapacity()-numero_viagem_escolhida->get_bilhetes_adquiridos();
    //cout<<"AQUIIIIIII numero de bilhetes vendidos neste voo: "<< numero_viagem_escolhida->get_bilhetes2().size();
    if(bilhetes_disponiveis>0){
        cout<<"There are "<<bilhetes_disponiveis<<" tickets available, how many do you want?"<<endl;
        int numero_bilhetes;
        cin>>numero_bilhetes;
        numero_viagem_escolhida->update_bilhetes(numero_bilhetes);
        cout<<"Congrats, you bought "<<numero_bilhetes<<" tickets for this flight!"<<endl;
        for(int i=0;i<numero_bilhetes;i++){
            int x;
            cout<<"Person number: "<< i << "  .How many pieces of luggage for the flight(1,2,3)?"<<endl;
            cin>>x;
            Ticket *ticket = new Ticket();
            ticket->change_check_in(false);
            for(int a=0;a<x;a++){
                SuitCase *suitcase = new SuitCase();
                cout<<" nova mala "<< suitcase<<" adicionada"<<endl;
                ticket->add(suitcase);
            }
            numero_viagem_escolhida->addto_bilhetes(ticket);
        }
    }
}

void list_planes(AirplaneReg *plane_list){   // funcao mostra todos os avioes na base de dados
    for(int i=0;i<plane_list->get_plane_list().size();i++){
        cout<<"Matricula aviao: "<<plane_list->get_plane_list()[i]->getLicensePlate()<<"  Tipo: "<< plane_list->get_plane_list()[i]->getType()<<" Capacidade: "<<plane_list->get_plane_list()[i]->getCapacity()<<endl;
    }
}

void list_flights( FlightReg *all_flight_regist){   // funcao mostra todos os avioes na base de dados
    for(int i=0;i<all_flight_regist->get_voos().size();i++){
        cout<<"["<<i<<"]"<<"Flight number: "<<all_flight_regist->get_voos()[i]->getflight_number()<<" Origin: "<<all_flight_regist->get_voos()[i]->get_origin()->getLocal()<<" Destination: "<<all_flight_regist->get_voos()[i]->get_destination()->getLocal()<<" Duration: "<<all_flight_regist->get_voos()[i]->get_duration()<<endl;
    }
}

Ticket* list_ticket(vector<Ticket*> tickets,TapeteReg *tapete){
    int contador=0;
    while(true){
        for(int i=0; i<tickets.size();i++){
            if(!tickets[i]->get_checked_in()){
                cout<<"["<<i<<"]"<<tickets[i]->get_id()<<" CHECKED IN: "<<tickets[i]->get_checked_in()<<" Number of suitcases: "<<tickets[i]->get_malas().size()<<endl;
            }
        }
        int x;
        cout<<"Choose ticket to check in: "<<endl;
        cin>>x;

        cout<<"CHECKING IN..."<<endl;
        cout<<tickets[x]->get_id()<<endl;
        cout<<"Sending "<<tickets[x]->get_malas().size()<<" suitcases to queue"<<endl;

        for(int i=0;i<tickets[x]->get_malas().size();i++){
            cout<<"Sending suitcase "<<tickets[x]->get_malas()[i]<< " to queue"<<endl;
            tapete->addSuitCase(tickets[x]->get_malas()[i]);
        }
        tickets[x]->change_check_in(true);
        contador++;
        if(contador==tickets.size()){
            break;
        }
    }
}

void Check_in( FlightReg *all_flight_regist,TapeteReg *tapete ){
    cout<<"DISPLAYING ALL FLIGHTS!"<<endl;
    list_flights(all_flight_regist);
    int x;
    cout<<"Which flight do you want to check in for?"<<endl;
    cin>>x;
    auto flight_number=all_flight_regist->get_voos()[x]->getflight_number(); //numero do voo escolhido
    vector<Ticket*> voos;
    for(int i=0;i<all_flight_regist->get_voos().size();i++){
        if(all_flight_regist->get_voos()[i]->getflight_number()==flight_number){
            for(int a=0; a<all_flight_regist->get_voos()[i]->get_bilhetes2().size();a++){
                if(!all_flight_regist->get_voos()[i]->get_bilhetes2()[a]->get_checked_in()){  // if not checked in
                    //cout<<"["<<a<<"]"<< all_flight_regist->get_voos()[i]->get_bilhetes2()[a]->get_id()<< " ID do bilhete!"<<endl;
                    voos.push_back(all_flight_regist->get_voos()[i]->get_bilhetes2()[a]);
                }
            }
        }
    }
    list_ticket(voos,tapete); // return ticket to check in
}


void add_plane(AirplaneReg *plane_list){
    int capacity;
    string lplate, type;
    cout<<"License plate of new plane?"<<endl;
    cin>>lplate;
    cout<<"Type of new plane?"<<endl;
    cin>>type;
    cout<<"Capacity?"<<endl;
    cin>>capacity;

    Airplane *airplane = new Airplane(lplate,type,capacity);
    plane_list->addplane(airplane);
    ofstream myfile;
    myfile.open ("../plane.txt",std::ios_base::app);
    myfile<<endl<< lplate <<" "<< type <<" "<<  capacity;
    myfile.close();
}

void list_queue(TapeteReg *tapete){
    vector<SuitCase*> auxiliar;
    while(!tapete->get_tapete().empty()){
        cout<<"SuitCase "<<tapete->get_tapete().front()<<" on queue"<<endl;
        auxiliar.push_back(tapete->get_tapete().front());
        tapete->popSuitcase();
    }
    for(int i=0;i<auxiliar.size();i++){
        tapete->addSuitCase(auxiliar[i]);
    }
}

void send_suitcases(TapeteReg *tapete, Carriage *car){
    int contador=0;
    stack<SuitCase*> pilha;
    while(!tapete->get_tapete().empty()){
        pilha.push(tapete->get_tapete().front());
        cout<<" Placing "<<tapete->get_tapete().front()<< " in stack"<<endl;
        tapete->popSuitcase();
        contador++;
        if(contador==4){
            cout<<"Limite de suitCases no stack atingido!"<<endl;
            car->addStack(pilha);
            while(!pilha.empty()){
                pilha.pop();
            }
            contador=0;
        }
    }
    if(pilha.size()>0){
        cout<<"Carrinho tem " <<car->getsize()+1<< " stacks"<<endl;
    }
    cout<<"Carrinho tem " <<car->getSize()<< " stacks"<<endl;
}

*/
#endif //PROJ_EXTRA_H
