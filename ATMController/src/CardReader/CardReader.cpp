#include "CardReader.h"

using namespace std;
namespace ATM_CONTROLLER{

CardReader::CardReader(Card* pCard)
    :pCardInfo(pCard)
{
    //cout<<"CardReader"<<endl;
}

void CardReader::parseCardInfo(ifstream& cardInfo){
    string parseLine;

    // Read Card information from the txt
    
    while(cardInfo >> parseLine){
        // Read txt line-by-line through the loop
        if(parseLine == "CARD"){
            cardInfo >> parseLine; // Read "ID:" for skip
            string cardId;
            cardInfo >> cardId;
            pCardInfo->setCardID(cardId);
        } else if (parseLine == "PIN"){
            cardInfo >> parseLine; // Read "NUMBER:" for skip
            int pinNum = 0;
            cardInfo >> pinNum;
            string pinStr = to_string(pinNum);
            pCardInfo->setPinNumber(pinStr);
        } else if(parseLine == "ACCOUNT:"){
            cardInfo >> parseLine; // Read "LISTS:" for skip
            while(cardInfo >> parseLine){
                Account aAccount;
                cardInfo >> aAccount.accountNum;
                cardInfo >> parseLine;            // Read "," for skip
                cardInfo >> parseLine;            // Read "Balance:" for skip
                cardInfo >> aAccount.accountBalance;

                pCardInfo->setAccounts(aAccount);
            }
        }
    }
    cout<<"Card " << pCardInfo->getCardID() << " accessed successfully!!"<<endl;
}

CardReader::~CardReader(){

}
}