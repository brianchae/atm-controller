#ifndef ACCOUNTFINDER_H_
#define ACCOUNTFINDER_H_

#include <vector>
#include <iostream>
#include "Card.h"

using namespace std;
namespace ATM_CONTROLLER{

class AccountFinder {
public:
    AccountFinder(Card* pCard);
    ~AccountFinder();

    void printAccountInfo();
    void accountSelector(int idx);
    void setWithdraw(int dollar);

private:
    Card* pCardInfo;
    void printBalanceInfo();
};
}
#endif