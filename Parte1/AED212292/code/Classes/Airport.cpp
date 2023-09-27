#include "../Header/Airport.h"

Airport::Airport(const string &local) : local(local) {}

const string &Airport::getLocal() const {
    return local;
}

void Airport::set_name(string nome) {
    this->local=nome;
}
