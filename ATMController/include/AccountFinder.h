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
private:
    Card* pCardInfo;
};
}
#endif