#pragma once
#include <iostream>
#include "userInterface.h"

struct StackItem
{
	int data;
	StackItem* previous;
};
StackItem* stackInit(StackItem* head);

void addItem(StackItem*& head);

void addMultipleItems(StackItem*& head, int amount);

bool moveToSecondaryStack(StackItem*& headFirst, StackItem*& headSecond);

//void moveToMainStack(StackItem*& headMain, StackItem*& headSecond);

bool emptyCheck(StackItem* head);

void deleteItem(StackItem*& head);

void printStack(StackItem* head);
