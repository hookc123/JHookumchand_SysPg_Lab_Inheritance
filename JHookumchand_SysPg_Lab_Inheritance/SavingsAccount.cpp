#include "SavingsAccount.h"


void SavingsAccount::Withdraw(float amount)
{
	if (mNumberOfWithdrawls > 3)
	{
		std::cout << "You cannot make more than 3 withdrawls. Sorry." << std::endl;
	}
	else
	{
		BaseAccount::Withdraw(amount);
	}
}
