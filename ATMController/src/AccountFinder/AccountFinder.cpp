#include "AccountFinder.h"

using namespace std;
namespace ATM_CONTROLLER{

AccountFinder::AccountFinder(Card* pCard)
    :pCardInfo(pCard)
{
    //cout<<"AccountFinder"<<endl;
}

AccountFinder::~AccountFinder(){

}
}