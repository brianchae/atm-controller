#include "AccountFinder.h"

using namespace std;
namespace ATM_CONTROLLER{

AccountFinder::AccountFinder(Card* pCard)
    :pCardInfo(pCard)
{
    //cout<<"AccountFinder"<<endl;
}

void AccountFinder::accountSelector(int idx){

}

void AccountFinder::setWithdraw(int dollar){

}

void AccountFinder::printAccountInfo(){
    vector<Account>& vecAccounts = pCardInfo->getAccounts();

    for(int i = 0 ; i < vecAccounts.size() ; i++){
        Account account = vecAccounts[i];
        cout << "[Account" << i+1 <<"]: " << account.accountNum;
        cout << " with current balance: $" << account.accountBalance << endl;
    }
}

void AccountFinder::printBalanceInfo(){

}

AccountFinder::~AccountFinder(){

}
}