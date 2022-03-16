#include <iostream>
#include <string>
#include "stackItem.h"
#include "userInterface.h"

void printMainMenu()
{
	std::cout << "   What do you want to do?" << std::endl;
	std::cout << "1. Add an element to the stack." << std::endl;
	std::cout << "2. Add multiple elements to the stack." << std::endl;
	std::cout << "3. Remove an element from the stack." << std::endl;
	std::cout << "4. Display stack on screen." << std::endl;
}

void printAdditionalMenu(int option)
{
	int secondOption;
	switch (option)
	{
		case(1):
		{
			std::cout << "Add a random element or from an additional stack?" << std::endl;
		}
	default:
		break;
	}
}

int userInput(int numberOfMenu)
{
	int option;
	bool check = true;
	std::string optionInput;
	
	while (check) 
	{
		try
		{
			std::cout << "Enter selection number, please." << std::endl;
			std::cin >> optionInput;
			option = std::stoi(optionInput);
			check = false;
		}
		catch (std::invalid_argument)
		{
			std::cout << "Only numbers are allowed." << std::endl;
			check = true;
		}
		catch (std::out_of_range)
		{
			std::cout << "The number is too big." << std::endl;
			check = true;
		}
		catch (std::exception)
		{
			std::cout << "Other exeption." << std::endl;
			check = true;
		}
		
		if (numberOfMenu == mainMenu)
		{
			if (option < 1 || option > numbOfOptionsMain)
			{
				std::cout << "There is no such menu item." << std::endl;
				check = true;
			}
		}
		else if (numberOfMenu == secondMenu)
		{

		}
	}
	return option;
}
void processInput(StackItem* headMain, StackItem* headSecond)
{
	int option = userInput();
	switch (option)
	{
		case(1):

			

	default:
		break;
	}
}