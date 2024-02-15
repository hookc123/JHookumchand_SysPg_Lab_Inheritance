#include "CheckingAccount.h"

void CheckingAccount::Withdraw(float& amount)
{
	BaseAccount::Withdraw(amount);
	if (mNumberOfWithdrawls > 10) {
		mAccountBalance -= 5;
	}
}
