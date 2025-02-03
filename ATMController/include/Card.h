#ifndef CARD_H_
#define CARD_H_

#include <vector>
#include <iostream>
#include <string>

using namespace std;
namespace ATM_CONTROLLER{

// Account structure
struct Account {
    string accountNum;
    int accountBalance;
};

// Card container for information
class Card {
public:
    Card(){};
    ~Card(){};

    // Setter
    void setCardID(string id){
        cardId = id;
    };
    void setPinNumber(string pin){
        pinNumber = pin;
    };
    void setAccounts(Account accounts){
        accounts_lists.push_back(accounts);
    };

    // Getter
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