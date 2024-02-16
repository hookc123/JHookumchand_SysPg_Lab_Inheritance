#pragma once
#include <iostream>
#include <string>
namespace Helper

{

	void clearInputBuffer()
	{
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
	}
	
	int randNum(int min = 0, int max = 0)
	{
		srand(time(0));
		int output;
		if (min >= 0 && max != 0) {
			do
			{
				
				output = rand() % (max + 1);
			} while (output < min);
		}
		else
		{
			output = rand();
		}
		return output;
	}

	int GetValidatedInt(const char* strMessage, int nMinimumRange = 0, int nMaximumRange = 0)
	{
		int userInput;
		std::cout << strMessage;
		bool valid = false;
		do {
			std::cin >> userInput;
			if(std::cin.fail())
			{
				clearInputBuffer();
				std::cout << "That is not a valid input. Try again." << std::endl;
				continue;
				//GetValidatedInt(strMessage, nMinimumRange, nMaximumRange);

			}
			else if ((nMinimumRange != 0 && nMinimumRange > userInput) ||(nMaximumRange != 0 && userInput > nMaximumRange))
			{
				std::cout << "That input is out of range. Please try again" << std::endl;
				continue;
			}
			else
			{
					valid = true;
			}
				clearInputBuffer();
		} while (valid==false);
		return userInput;
	}
	int PrintMenu(const std::string menu[],int menuLength) {
		for (int i = 0; i < menuLength; i++) {
			std::cout << i + 1 << ") " << menu[i] << std::endl;
		}
		std::cout << std::endl;
		return (GetValidatedInt("Please enter your choice: ", 1, menu->length())-1);
	}
	void printBinary(int& number)
	{

		std::cout << "Decimal: " << number << "\n" << std::endl;
		std::cout << "Binary: ";
		for (int i = 31; i >= 0; i--)
		{
			int bit = (number >> i) & 1;
			std::cout << bit;
			if (i % 4 == 0) {
				std::cout << " ";
			}
		}
		std::cout << std::endl;

	}
	void GetRandRange(int& min, int& max) 
	{
		srand(time(0));
		do {
		max = rand();
		
			min = rand();
		} while (min > max);
	}
}