#include "ATMController.h"

using namespace std;
namespace ATM_CONTROLLER{

ATMController::ATMController(){
    pCard = new Card();
    pAccountFinder = new AccountFinder(pCard);
    pCardReader = new CardReader(pCard);
    pPINIdentificator = new PINIdentificator(pCard);
}

void ATMController::parseCardLoc(string cardLoc){
    cardInfo.open(cardLoc);

    if(!cardInfo){
        cout<<"Invalid card"<<endl;
        return;
    }
    cout<<"Reading card from: "<<cardLoc<<endl;
    pCardReader->parseCardInfo(cardInfo);
}

ATMController::~ATMController(){
    delete pAccountFinder;
    delete pCardReader;
    delete pPINIdentificator;
}
}