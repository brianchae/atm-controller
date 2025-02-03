#include "PINIdentificator.h"

using namespace std;
namespace ATM_CONTROLLER{

PINIdentificator::PINIdentificator(Card* pCard)
    :pCardInfo(pCard)
{
    //cout<<"PINIdentificator"<<endl;
}

PINIdentificator::~PINIdentificator(){

}
}