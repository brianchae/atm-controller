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

    void setCardID(int id){
        cardId = id;
    };
    void setPinNumber(string pin){
        pinNumber = pin;
    };
    void setAccounts(Account accounts){
        accounts_lists.push_back(accounts);
    };

    int getCardID();
    string getPinNumber();
    vector<Account>& getAccounts();

private:
    int cardId = -1;
    string pinNumber;
    vector<Account> accounts_lists;
};
}
#endif