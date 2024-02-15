// JHookumchand_SysPg_Lab_Inheritance.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include "CreditAccount.h"
#include "../../JHookumchand_SysPg_LabHelperLibrary/JHookumchand_SysPg_LabHelperLibrary/Helper.h"

int main()
{
	srand(time(0));

#define MEMORY_LEAK_LINE -1

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	_CrtSetBreakAlloc(MEMORY_LEAK_LINE); // DO NOT COMMENT OUT THIS LINE

	float deposit1 = Helper::randNum();
	float deposit2 = Helper::randNum();
	float deposit3 = Helper::randNum();
	CheckingAccount hookChecking;
	hookChecking.Deposit(deposit1);
	SavingsAccount hookSavings;
	hookSavings.Deposit(deposit2);
	CreditAccount hookCredit;
	hookCredit.Deposit(deposit3);
	std::cout << "Welcome to City Bank!\nWhich account would you like to access?" << std::endl;
	std::string accounts[4]{ "Checking","Savings","Credit","Exit" };
	std::string accountOptions[3]{ "Withdrawl", "Deposit","Exit" };
	int choice1;
	do {
		choice1 = Helper::PrintMenu(accounts, 4);
		int choice2;
		float amount;

		switch (choice1)
		{
		case 0:
			do {
				std::cout << "Checking Account: $" << hookChecking.GetBalance() << "\nWhat do you want to do?" << std::endl;
				choice2 = Helper::PrintMenu(accountOptions, 3);

				switch (choice2)
				{
				case 0:

					amount = Helper::GetValidatedInt("How much would you like to withdraw? $");
					hookChecking.Withdraw(amount);
					break;
				case 1:
					amount = Helper::GetValidatedInt("How much would you like to deposit? $");
					hookChecking.Deposit(amount);
					break;
				default:
					choice2 = 2;
					break;
				}
			} while (choice2 != 2);
			break;
		case 1:
			do {
				std::cout << "Savings Account: $" << hookSavings.GetBalance() << std::endl;
				choice2 = Helper::PrintMenu(accountOptions, 3);

				switch (choice2)
				{
				case 0:

					amount = Helper::GetValidatedInt("How much would you like to withdraw? $");
					hookSavings.Withdraw(amount);
					break;
				case 1:
					amount = Helper::GetValidatedInt("How much would you like to deposit? $");
					hookSavings.Deposit(amount);
					break;
				default:
					choice2 = 2;
					break;
				}

			} while (choice2 != 2);
			break;
		case 2:
			do {
				std::cout << "Credit Account: $" << hookCredit.GetBalance() << std::endl;
				choice2 = Helper::PrintMenu(accountOptions, 3);

				switch (choice2)
				{
				case 0:

					amount = Helper::GetValidatedInt("How much would you like to withdraw? $");
					hookCredit.Withdraw(amount);
					break;
				case 1:
					amount = Helper::GetValidatedInt("How much would you like to deposit? $");
					hookCredit.Deposit(amount);
					break;
				default:
					choice2 = 2;
					break;
				}

			} while (choice2 != 2);
			break;
		default:
			break;
		}
		continue;
	} while (choice1 != 3);
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
