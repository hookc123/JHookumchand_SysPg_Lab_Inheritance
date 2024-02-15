#pragma once
#include "BaseAccount.h"
class CreditAccount :
    public BaseAccount
{
private:
    //member fields
    int mData;
protected:

public:
    //constructor
    CreditAccount() :mData(0) {}
    
    void Withdraw(float amount) override;

};

