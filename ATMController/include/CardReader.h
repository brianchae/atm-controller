#ifndef CARDREADER_H_
#define CARDREADER_H_

#include <vector>
#include <iostream>
#include <fstream>
#include "Card.h"

using namespace std;
namespace ATM_CONTROLLER{

class CardReader {
public:
    CardReader(Card* pCard);
    ~CardReader();

    void parseCardInfo(ifstream& cardInfo);
private:
    Card* pCardInfo;
};
}
#endif