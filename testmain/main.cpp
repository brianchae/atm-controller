#include <iostream>
#include <fstream>
#include <sstream>

#include "../ATMController/include/ATMController.h"

using namespace std;
using namespace ATM_CONTROLLER;

int main()
{
    string cardPath;
    string card;
    ATMController* pATM = new ATMController();

    cout<<"[STEP 1] Insert your card: "<<endl;
    cin>>card;

    cardPath = "../TestCases/" + card + ".txt";
    cout<<"You have inserted the card: "<<card<<endl;
    pATM->parseCardLoc(cardPath);

    delete pATM;
}
