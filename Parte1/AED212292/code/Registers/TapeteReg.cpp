#include "TapeteReg.h"


queue<SuitCase *> TapeteReg::get_tapete() {
    return this->tapete;
}

void TapeteReg::addSuitCase(SuitCase *suitcase) {
    this->tapete.push(suitcase);
}

SuitCase *TapeteReg::popSuitcase() {
    auto x = this->tapete.front();
    this->tapete.pop();

    return x;
}

TapeteReg::TapeteReg() {}
