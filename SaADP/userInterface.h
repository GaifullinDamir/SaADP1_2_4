#pragma once
#include "stackItem.h"

enum userInterface
{
	MainMenu = 0,
	SecondMenu = 1,
	NumbOfOptionsMain = 4,
	NumbOfOptionsSecond = 2,
	NumbOfStacks = 2
};

enum options
{
	AddItem = 1,
	AddMultipleItems,
	DeleteItem,
	PrintStack
};

enum secondaryCases
{
	RandomItem = 1,
	ItemFromAdditionalStack = 2,
	ClearMemory = 1,
	MoveItem = 2,
	MainStack = 1,
	SecondStack = 2
};

void printMainMenu();

void printAdditionalMenu(int option);

int userInput(int numberOfMenu);

void workWithUser(StackItem*& headMain, StackItem*& headSecond);

void caseAddItem(StackItem*& headMain, StackItem*& headSecond, int numberOfItems);

void caseDeleteItem(StackItem*& headMain, StackItem*& headSecond);

void casePrintStack(StackItem*& headMain, StackItem*& headSecond);

