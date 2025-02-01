#include <vector>
#include <iostream>

#include "AccountFinder.h"
#include "CardReader.h"
#include "PINIdentificator.h"

namespace ATM_CONTROLLER{

class ATMController {
public:
    ATMController();
    ~ATMController();
private:
    AccountFinder* pAccountFinder;
    CardReader* pCardReader;
    PINIdentificator* pPINIdentificator;
};
}