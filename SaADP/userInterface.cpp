#include <iostream>
#include <string>
#include "stackItem.h"
#include "userInterface.h"

void printMainMenu()
{
	std::cout << std::endl;
	std::cout << "1. Add an element to the stack." << std::endl;
	std::cout << "2. Add multiple elements to the stack." << std::endl;
	std::cout << "3. Remove an element from the stack." << std::endl;
	std::cout << "4. Display stack on screen." << std::endl;
	std::cout << std::endl;
}

void printAdditionalMenu(int option)
{
	switch (option)
	{
		case(1):
		{
			std::cout << "   Add a random element (1) or from an additional stack (2)?" << std::endl;
			std::cout << std::endl;
			break;
		}
		case(2):
		{
			std::cout << "   Add a random element (1) or from an additional stack (2)?" << std::endl;
			std::cout << std::endl;
			break;
		}
		case(3):
		{
			std::cout << "   Remove element (1) or move to additional stack (2)?" << std::endl;
			std::cout << std::endl;
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
			std::cout << "   Enter a number, please: ";
			std::cin >> optionInput;
			option = std::stoi(optionInput);
			check = false;
		}

		catch (const std::exception&)
		{
			std::cout << "   Please enter a number!" << std::endl;
			std::cout << std::endl;
			check = true;
		}
		
		if (numberOfMenu == MainMenu)
		{
			if (option < 1 || option > NumbOfOptionsMain)
			{
				std::cout << "   There is no such menu item." << std::endl;
				std::cout << std::endl;
				check = true;
			}
		}
		else if (numberOfMenu == SecondMenu)
		{
			if (option < 1 || option > NumbOfOptionsSecond)
			{
				std::cout << "   There is no such menu item." << std::endl;
				std::cout << std::endl;
				check = true;
			}
		}
	}
	return option;
}
void workWithUser(StackItem*& headMain, StackItem*& headSecond)
{
	bool work = true;
	while (work)
	{
		printMainMenu();

		std::cout << "   What do you want to do? " << std::endl;
		std::cout << std::endl;
		int option = userInput(FourCases);
		switch (option)
		{
			case(AddItem):
			{
				caseAddItem(headMain, headSecond, 1);
				break;
			}
			case(AddMultipleItems):
			{
				std::cout << "   How many elements to add to the stack?" << std::endl;
				std::cout << std::endl;
				int amountOffElements = userInput(-1);
				caseAddItem(headMain, headSecond, amountOffElements);
				break;
			}
			case(DeleteItem):
			{
				caseDeleteItem(headMain, headSecond);
				break;
			}
			case(PrintStack):
			{
				casePrintStack(headMain, headSecond);
				break;
			}
			default:
				break;
		}
		work = workOrExit();
	}
}

void caseAddItem(StackItem*& headMain, StackItem*& headSecond, int numberOfItems)
{
	int secondOption;
	printAdditionalMenu(AddItem);
	secondOption = userInput(TwoCases);
	switch (secondOption)
	{
		case(RandomItem):
		{
			addMultipleItems(headMain, numberOfItems);
			break;
		}
		case(ItemFromAdditionalStack):
		{
			bool check = true;
			int movedItems;
			for (movedItems = 0; movedItems < numberOfItems; movedItems++)
			{
				check = moveToSecondaryStack(headSecond, headMain);
				if (check == false) { break; }
			}

			switch (check)
			{
				case(true):
				{
					std::cout << "   Elements in quantity: " << numberOfItems <<" added from additional stack." << std::endl;
					std::cout << std::endl;
					break;
				}
				case(false):
				{
					std::cout << "   The stack doesn't have that many elements to move." << std::endl;
					std::cout << "   Only" << movedItems << " items were moved" << std::endl;
					std::cout << std::endl;
					break;
				}
				default:
					break;
			}
			break;
		}
		default:
			break;
	}
}

void caseDeleteItem(StackItem*& headMain, StackItem*& headSecond)
{
	int secondOption;
	printAdditionalMenu(DeleteItem);
	secondOption = userInput(TwoCases);
	switch (secondOption)
	{
		case(ClearMemory):
		{
			deleteItem(headMain);
			break;
		}
		case(MoveItem):
		{
			bool check = moveToSecondaryStack(headMain, headSecond);
			switch (check)
			{
				case(true):
				{
					std::cout << "   Item moved to additional stack." << std::endl;
					std::cout << std::endl;
					break;
				}
				case(false):
				{
					std::cout << "   The stack is empty. Nothing to move." << std::endl;
					std::cout << std::endl;
					break;
				}
				default:
					break;
			}
			break;
		}
		default:
			break;
	}
}

void casePrintStack(StackItem*& headMain, StackItem*& headSecond)
{
	int stackOption;
	std::cout << "   What stack to print?" << std::endl;
	std::cout << "   Primary (1) or Secondary (2)." << std::endl;
	stackOption = userInput(TwoCases);
	switch (stackOption)
	{
		case(MainStack):
		{
			std::cout << "   Primary stack:" << std::endl;
			std::cout << std::endl;
			printStack(headMain);
			std::cout << std::endl;
			break;
		}
		case(SecondStack):
		{
			std::cout << "   Secondary stack:" << std::endl;
			std::cout << std::endl;
			printStack(headSecond);
			std::cout << std::endl;
			break;
		}
		default:
			break;
	}
}

bool workOrExit()
{
	std::cout << "   Continue (1) / exit (2)" << std::endl;
	int action = userInput(TwoCases);
	switch (action)
	{
		case(Continue):
		{
			return true;
			break;
		}
		case(Exit):
		{
			return false;
			break;
		}
		default:
			break;
	}
}