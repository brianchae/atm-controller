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
    cout << vecAccounts.size()<< endl;
    Account account = vecAccounts[seletedIdx-1];
    if(account.accountBalance < dollar){
        return false;
    }

    int leftover = account.accountBalance - dollar;
    cout << endl;
    cout << "########################################"<< endl;
    cout << "### Seleted account: " << account.accountNum << endl;
    cout << "### Original balance: " << account.accountBalance << endl;
    cout << "### You have withdraw: " << dollar << endl;
    cout << "### You have deposit: " << leftover << endl;
    cout << "########################################"<< endl;

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