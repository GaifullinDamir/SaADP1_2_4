#pragma once
#include <iostream>

struct StackItem
{
	int data;
	StackItem* previous;
};
StackItem* stackInit(StackItem* head);

void addItem(StackItem*& head);

void addMultipleItems(StackItem*& head, int amount);

bool moveToSecondaryStack(StackItem*& headFirst, StackItem*& headSecond);

bool emptyCheck(StackItem* head);

void deleteItem(StackItem*& head);

void printStack(StackItem* head);
