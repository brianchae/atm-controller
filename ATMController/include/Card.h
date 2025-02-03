#ifndef CARD_H_
#define CARD_H_

#include <vector>
#include <iostream>
#include <string>

using namespace std;
namespace ATM_CONTROLLER{

struct Account {
    string accountNum;
    int accountBalance;
};

class Card {
public:
    Card(){};
    ~Card(){};

    void setCardID(string id){
        cardId = id;
    };
    void setPinNumber(string pin){
        pinNumber = pin;
    };
    void setAccounts(Account accounts){
        accounts_lists.push_back(accounts);
    };

    string getCardID(){
        return cardId;
    };
    string getPinNumber(){
        return pinNumber;
    };
    vector<Account>& getAccounts(){
        return accounts_lists;
    };

private:
    string cardId;
    string pinNumber;
    vector<Account> accounts_lists;
};
}
#endif