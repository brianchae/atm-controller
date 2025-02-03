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

    cout << endl;
    cardPath = "../TestCases/" + card + ".txt";
    cout << "You have inserted the card: " << card << endl;
    
    if(pATM->parseCardLoc(cardPath)){
        int cnt = 0;
        bool isAccesed = false;

        cout << endl;
        
        // Give 3 times of opportunities to try pin
        while(cnt < 3){
            cout << "[STEP 2] Enter the card pin number: " << endl;
            int accessedPin = 0;
            cin >> accessedPin;
            
            // Try matching pin number
            if(pATM->matchPinNum(accessedPin)){
                cout << "Pin number matched!!" << endl;
                pATM->showAccountInfo();
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
            cout << "Select the number of your account to withdraw money" << endl;
            int idx = -1;
            cin >> idx;
            cout << "Type the amount you want to withdraw (as Dollar)" << endl;
            int dollar = -1;
            cin >> dollar;
            if(!pATM->withdrawAccount(idx, dollar)){
                cout << "Your account does not have enough money."<< endl;
            }
        }
    } else {
        cout << "Card is not valid..." << endl;
    }

    cout << "------------ Finishing ATM ------------" << endl;

    delete pATM;
}
