#include "BaseAccount.h"

void BaseAccount::Withdraw(float amount)
{
	mAccountBalance -= amount;
	mNumberOfWithdrawls++;
}

void BaseAccount::Deposit(float amount)
{
	mAccountBalance += amount;
}

float BaseAccount::GetBalance() const
{
	return mAccountBalance;
}
