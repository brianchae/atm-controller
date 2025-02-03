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
    
    while(!cardInfo.eof()){
        cardInfo >> parseLine;
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
        } else if(parseLine == "ACCOUNT"){
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

void CardReader::writeNewCardInfo(ofstream& cardInfo){
    string cardId = pCardInfo->getCardID();
    string pinNum = pCardInfo->getPinNumber();
    vector<Account>& accountLists = pCardInfo->getAccounts();

    cardInfo << "CARD ID: " << cardId << endl;
    cardInfo << "PIN NUMBER: " << pinNum << endl;
    cardInfo << "ACCOUNT LISTS:" << endl;

    for(int i = 0 ; i < accountLists.size() ; i++){
        cardInfo << "  Account: " << accountLists[i].accountNum << " , Balance: " << accountLists[i].accountBalance << endl;
    }
}

CardReader::~CardReader(){

}
}