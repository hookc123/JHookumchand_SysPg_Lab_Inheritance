#pragma once
#include "BaseAccount.h"
class CheckingAccount :
    public BaseAccount
{
public:
     //methods
    void Withdraw(float& amount) override;
};

