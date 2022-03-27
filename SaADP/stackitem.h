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

bool isEmpty(StackItem* head);

bool deleteItem(StackItem*& head);

void printStack(StackItem* head);

void clearMemory(StackItem*& headFirst, StackItem*& headSecond);
