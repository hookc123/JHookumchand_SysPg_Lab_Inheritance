#pragma once
class BaseAccount
{

public:
	//constructor
	BaseAccount() 
	{
		mAccountBalance = 0;
		mNumberOfWithdrawls = 0;
	}
	//methods
	virtual void Withdraw(float amount);
	virtual void Deposit(float amount);
	float GetBalance() const;
protected:
	//member fields
	float mAccountBalance;
	int mNumberOfWithdrawls;

};

