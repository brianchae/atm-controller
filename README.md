# atm-controller

build procedure:
- Option 1: build atm library and generate .so file only.
$ cd ATMController
$ ./atmlibbuilder.sh

atmlibbuilder.sh script contains library build commands.

- Option 2: Build atm library and run test module exe file.
$ ./testerbuilder.sh

In the folder TestCases, there is a sample of card format as txt. You can make new one with any number of accounts and balance, card id, pin number. However please stick to the format below.

CARD ID: 13423627525
PIN NUMBER: 123456
ACCOUNT LISTS:
  Account: 193-4586293-457 , Balance: 1000000000
  Account: 192-4585393-457 , Balance: 10000
  Account: 191-4583493-454 , Balance: 500000

Usage:
Once you execute the program, it will show:

$ [STEP 1] Insert your card:

Write the name of the card in TestCases folder WITHOUT '.txt'. Then,

$ [STEP 2] Enter the card pin number:

Write the pin number written in card.txt. Then,

$ [STEP 3] Select the action

Select whether you want to withdraw (as W) or deposit (as D). Then,

$ [STEP 4] Select the number of your account to WITHDRAW/DEPOSIT money

Select the account as number shown. Then,

$ [STEP 5] Type the amount you want to withdraw (as Dollar)

Write the number of money you want to withdraw/deposit.

As you withdraw or deposit money, the program will modify the balance in txt file.