#include "CreditAccount.h"

void CreditAccount::Withdraw(float& amount)
{
	
	if (mData+amount > 40) {
		mAccountBalance -= 5000;
	}
	else
	{
		BaseAccount::Withdraw(amount);
		mData += amount;
	}
}
