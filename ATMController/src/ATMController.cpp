#include "ATMController.h"

namespace ATM_CONTROLLER{

ATMController::ATMController(){
    pAccountFinder = new AccountFinder();
    pCardReader = new CardReader();
    pPINIdentificator = new PINIdentificator();
}

ATMController::~ATMController(){
    delete pAccountFinder;
    delete pCardReader;
    delete pPINIdentificator;
}
}