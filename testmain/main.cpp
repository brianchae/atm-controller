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

    cout << "[STEP 1] Insert your card: " << endl;
    cin >> card;

    cardPath = "../TestCases/" + card + ".txt";
    cout << "You have inserted the card: " << card << endl;
    
    if(pATM->parseCardLoc(cardPath)){
        int cnt = 0;
        bool isAccesed = false;

        // Give 3 times of opportunities to try pin
        while(cnt < 3){
            cout << "[STEP 2] Enter the card pin number: " << endl;
            int accessedPin = 0;
            cin >> accessedPin;
            
            // Try matching pin number
            if(pATM->matchPinNum(accessedPin)){
                cout << "Pin number matched!!" << endl;
                isAccesed = true;
                break;
            } else {
                cnt++;
                cout << "Pin number INCORRECT. Try again (" << 3-cnt << " trial left)" << endl;
            }
        }
        if(!isAccesed){
            cout << "Invalid pin number" << endl;
        } else {
            // Ask withdraw and print balance and deposit
        }
    } else {
        cout << "Card is not valid..." << endl;
    }

    cout << "------------ Finishing ATM ------------" << endl;

    delete pATM;
}
