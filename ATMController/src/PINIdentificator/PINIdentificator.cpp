#include "PINIdentificator.h"

using namespace std;
namespace ATM_CONTROLLER{

PINIdentificator::PINIdentificator(Card* pCard)
    :pCardInfo(pCard)
{
    //cout<<"PINIdentificator"<<endl;
}

bool PINIdentificator::comparePinNum(int pin){
    string pinStr = to_string(pin);
    if(pinStr.size() != pCardInfo->getPinNumber().size()){
        // If the card pin number and the user's input pin number does not match the size.
        return false;
    } 
    
    // If the card pin number and the user's input pin number have the size,
    // compare if they are the same.
    if(pinMatching(pinStr)) {
        return true;
    } else {
        return false;
    }
}

bool PINIdentificator::pinMatching(string pinInput){
    int matchCnt = 0;

    string pinNum = pCardInfo->getPinNumber();
    for(int i = 0 ; i < pinNum.size() ; i++){
        char aCardPin = pinNum[i];   // Pin from the card
        char aInputPin = pinInput[i];// Pin from the user
        if(aCardPin == aInputPin){
            matchCnt++;
        }
    }
    if(matchCnt == pinNum.size()){
        return true;
    } else {
        return false;
    }
}

PINIdentificator::~PINIdentificator(){

}
}