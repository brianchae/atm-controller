#ifndef PINIDENTIFICATOR_H_
#define PINIDENTIFICATOR_H_

#include <vector>
#include <iostream>
#include "Card.h"

using namespace std;
namespace ATM_CONTROLLER{

class PINIdentificator {
public:
    PINIdentificator(Card* pCard);
    ~PINIdentificator();

    bool comparePinNum(int pin);
    bool pinMatching(string pinInput);
private:
    Card* pCardInfo;
};
}
#endif