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
	switch (option)
	{
		case(1):
		{
			std::cout << "Add a random element (1) or from an additional stack (2)?" << std::endl;
			break;
		}
		case(2):
		{
			std::cout << "Add a random element (1) or from an additional stack (2)?" << std::endl;
			break;
		}
		case(3):
		{
			std::cout << "Remove element (1) or move to additional stack (2)?" << std::endl;
			break;
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
		//catch (std::invalid_argument)
		//{
		//	std::cout << "Only numbers are allowed." << std::endl;
		//	check = true;
		//}
		catch (const std::exception&)
		{
			std::cout << "Other exception." << std::endl;
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
			if (option < 1 || option > numbOfOptionsSecond)
			{
				std::cout << "There is no such menu item." << std::endl;
				check = true;
			}
		}
	}
	return option;
}
void processInput(StackItem* headMain, StackItem* headSecond)
{
	int option = userInput();
	int secondOption;
	switch (option)
	{
		case(addOneItem):
		{
			printAdditionalMenu(option);
			secondOption = userInput();
			switch (secondOption)
			{
				case(1):
				{
					addItem(headMain);
					std::cout << "An element has been added to the main stack." << std::endl;
				}
				case(2):
				{
					bool check = moveToSecondaryStack(headSecond, headMain);
					switch (check)
					{
						case(true):
						{
							std::cout << "Item added from additional stack." << std::endl;
						}
						case(false):
						{
							std::cout << "The stack is empty. Nothing to move." << std::endl;
						}
					default:
						break;
					}
				}
			default:
				break;
			}
			if (secondOption == 1)
			{
				addItem(headMain);
				std::cout << "An element has been added to the main stack." << std::endl;
			}
			else if (secondOption == 2)
			{
				
			}
		}

	default:
		break;
	}
}