#include "ATMController.h"

using namespace std;
namespace ATM_CONTROLLER{

ATMController::ATMController(){
    // Define ATM core classes
    pCard = new Card();
    pAccountFinder = new AccountFinder(pCard);
    pCardReader = new CardReader(pCard);
    pPINIdentificator = new PINIdentificator(pCard);
}

bool ATMController::parseCardLoc(string cardLoc){
    cardInfo.open(cardLoc);

    if(!cardInfo){
        return false;
    }

    pCardReader->parseCardInfo(cardInfo);

    return true;
}

bool ATMController::matchPinNum(int pin){
    if(!pPINIdentificator->comparePinNum(pin)){
        return false;
    }

    return true;
}

void ATMController::showAccountInfo(){
    pAccountFinder->printAccountInfo();  
}

bool ATMController::withdrawAccount(int idx, int dollar){
    pAccountFinder->accountSelector(idx);
    if(pAccountFinder->setWithdraw(dollar)){
        return true;
    } 
    else{
        return false;
    }
}

ATMController::~ATMController(){
    delete pAccountFinder;
    delete pCardReader;
    delete pPINIdentificator;
}
}