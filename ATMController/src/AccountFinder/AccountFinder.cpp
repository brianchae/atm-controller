#include "AccountFinder.h"

using namespace std;
namespace ATM_CONTROLLER{

AccountFinder::AccountFinder(Card* pCard)
    :pCardInfo(pCard)
{
    //cout<<"AccountFinder"<<endl;
}

void AccountFinder::accountSelector(int idx){
    seletedIdx = idx;
}

bool AccountFinder::setWithdraw(int dollar){
    // Recall the selected account
    vector<Account>& vecAccounts = pCardInfo->getAccounts();

    Account account = vecAccounts[seletedIdx-1]; // Arrange index from user's (1~) to array's (0~) 
    if(account.accountBalance < dollar){
        return false;
    }

    int leftover = account.accountBalance - dollar;
    cout << endl;
    cout << "########################################"<< endl;
    cout << "### Seleted account: " << account.accountNum << endl;
    cout << "### You have withdrawed: " << dollar << endl;
    cout << "### Your balance: " << leftover << endl;
    cout << "########################################"<< endl;

    account.accountBalance = leftover;
    vecAccounts[seletedIdx-1] = account;

    return true;
}

bool AccountFinder::setDeposit(int dollar){
    // Recall the selected account
    vector<Account>& vecAccounts = pCardInfo->getAccounts();

    Account account = vecAccounts[seletedIdx-1];
    if(dollar < 0){
        return false;
    }

    int leftover = account.accountBalance + dollar;
    cout << endl;
    cout << "########################################"<< endl;
    cout << "### Seleted account: " << account.accountNum << endl;
    cout << "### You have deposited: " << dollar << endl;
    cout << "### Your balance: " << leftover << endl;
    cout << "########################################"<< endl;

    account.accountBalance = leftover;
    vecAccounts[seletedIdx-1] = account;

    return true;
}

void AccountFinder::printAccountInfo(){
    vector<Account>& vecAccounts = pCardInfo->getAccounts();

    for(int i = 0 ; i < vecAccounts.size() ; i++){
        Account account = vecAccounts[i];
        cout << "[Account" << i+1 <<"]: " << account.accountNum;
        cout << " with current balance: $" << account.accountBalance << endl;
    }
}

AccountFinder::~AccountFinder(){

}
}