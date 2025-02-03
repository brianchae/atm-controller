#ifndef ATMCONTROLLER_H_
#define ATMCONTROLLER_H_

#include <vector>
#include <iostream>
#include <fstream>
#include "CardReader.h"
#include "AccountFinder.h"
#include "PINIdentificator.h"

using namespace std;
namespace ATM_CONTROLLER{

class ATMController {
public:
    ATMController();
    ~ATMController();

    void parseCardLoc(string cardLoc);
private:
    ifstream cardInfo;
    Card* pCard;
    AccountFinder* pAccountFinder;
    CardReader* pCardReader;
    PINIdentificator* pPINIdentificator;
};
}
#endif