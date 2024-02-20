// JHookumchand_SysPg_Lab_Inheritance.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include "CreditAccount.h"
#include "Helper.h"
void deposit(BaseAccount* account, float amount)
{
	account->Deposit(amount);
	std::cout << "\n$" << amount << " deposited to your account!" << std::endl;
	std::cout << "New balance: $" << account->GetBalance() << std::endl;
}
void withdraw(BaseAccount* account, float amount)
{
	account->Withdraw(amount);
	std::cout << "\n$" << amount << " withdrawn from your account!" << std::endl;
	std::cout << "New balance: $" << account->GetBalance() << std::endl;
}
std::string GetAccountType(int& account)
{
	std::string output;
	switch (account)
	{
	case 0:
		output = "Checking Account: $";
		break;
	case 1:
		output = "Savings Account: $";
		break;
	case 2:
		output = "Credit Account: $";
		break;
	}
	return output;
}
int main()
{
	srand(time(0));

	Helper::memoryLeak();

	float deposit1 = Helper::randNum();
	float deposit2 = Helper::randNum();
	float deposit3 = Helper::randNum();
	CheckingAccount* hookChecking= new CheckingAccount();
	hookChecking->Deposit(deposit1);
	SavingsAccount* hookSavings=new SavingsAccount;
	hookSavings->Deposit(deposit2);
	CreditAccount* hookCredit=new CreditAccount;
	hookCredit->Deposit(deposit3);
	std::cout << "----------Welcome to City Bank!----------" << std::endl;
	std::cout << "\nWhich account would you like to access ? " << std::endl;
	std::string accounts[4]{ "Checking","Savings","Credit","Exit" };
	std::string accountOptions[3]{ "Withdrawl", "Deposit","Exit" };
	int choice;
	do {
		choice = Helper::PrintMenu(accounts, 4);
		if (choice == 3)
			break;
		BaseAccount* selectedAccount=nullptr;

		switch (choice)
		{
			
		case 0:
				selectedAccount = hookChecking;
					break;
		case 1:
				selectedAccount = hookSavings;
			break;
		case 2:
				selectedAccount = hookCredit;
				break;
			break;
		default:
			std::cout << "Invalid choice!" << std::endl;
			break;
		}
		
		float amount;
		do {
			std::cout << "\n"<<GetAccountType(choice) << selectedAccount->GetBalance() << "\n\nWhat do you want to do? " << std::endl;
			choice = Helper::PrintMenu(accountOptions, 3);
			if (choice == 2)
				break;
			switch (choice)
			{
			case 0:

				amount = Helper::GetValidatedInt("\nHow much would you like to withdraw? $");
				withdraw(selectedAccount, amount);
				break;
			case 1:
				amount = Helper::GetValidatedInt("\nHow much would you like to deposit? $");
				deposit(selectedAccount, amount);
				break;
			default:
				std::cout << "Invalid choice!" << std::endl;
				break;
			}
		} while (choice != 2);

	} while (choice != 3);
	delete hookChecking;
	delete hookSavings;
	delete hookCredit;

	//std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
