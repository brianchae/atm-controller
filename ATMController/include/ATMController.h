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

    bool parseCardLoc(string cardLoc);
    bool matchPinNum(int pin);
    void showAccountInfo();
    void withdrawAccount(int dollar);

private:
    ifstream cardInfo;
    Card* pCard;
    AccountFinder* pAccountFinder;
    CardReader* pCardReader;
    PINIdentificator* pPINIdentificator;
};
}
#endif