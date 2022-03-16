#pragma once
#include "stackItem.h"

enum userInterface
{
	mainMenu = 0,
	secondMenu = 1,
	numbOfOptionsMain = 4,
	numbOfOptionsSecond = 2
};

enum options
{
	addOneItem,
	addMultipleItems,
	removeItem,
	printStack
};

StackItem* headMain = new StackItem;
StackItem* headSecond = new StackItem;

void printMainMenu();

void printAdditionalMenu(int option);

int userInput();

void processInput(int option);

