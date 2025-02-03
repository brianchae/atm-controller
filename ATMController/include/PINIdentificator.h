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
private:
    Card* pCardInfo;
};
}
#endif