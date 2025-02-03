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
        return false;
    } 
    
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
        char aCardPin = pinNum[i];
        char aInputPin = pinInput[i];
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