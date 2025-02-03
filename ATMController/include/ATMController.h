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
    bool withdrawAccount(int idx, int dollar);
    bool depositAccount(int idx, int dollar);
    void writeNewBalance();

private:
    string cardPath;
    Card* pCard;
    AccountFinder* pAccountFinder;
    CardReader* pCardReader;
    PINIdentificator* pPINIdentificator;
};
}
#endif