#include <iostream>
#include "stackItem.h"
#include "userInterface.h"

StackItem* stackInit(StackItem* head)
{
	head = NULL;
	return head;
}

void addItem(StackItem*& head)
{
	srand(static_cast<unsigned int>(time(0)));
	try
	{
		StackItem* current = new StackItem;
		current -> previous = head;
		current -> data = rand();
		head = current;
	}
	catch (const std::exception&)
	{
		std::cout << "The stack is full. Can't be added." << std::endl;
	}
}

void addMultipleItems(StackItem*& head, int amount)
{
	for (int i = 0; i < amount; i++)
	{
		addItem(head);
	}
}

bool moveToSecondaryStack(StackItem*& headFirst, StackItem*& headSecond)
{
	if(!emptyCheck(headFirst))
	{
		StackItem* current = headFirst;
		headFirst = headMain->previous;
		current->previous = headSecond;
		headSecond = current;
		return true;
	}
	else
	{
		return false
	}

}

//void moveToMainStack(StackItem*& headMain, StackItem*& headSecond)
//{
//	StackItem* current = headSecond;
//	headSecond = headSecond -> previous;
//	current -> previous = headMain;
//	headMain = current;
//}

bool emptyCheck(StackItem* head)
{
	if (head == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void deleteItem(StackItem*& head)
{
	if (!emptyCheck(head))
	{
		StackItem* current = head;
		head = head -> previous;
		delete current;
	}
	else
	{
		std::cout << "The stack is empty. Nothing to delete." << std::endl;
	}
}

void printStack(StackItem* head)
{
	if (emptyCheck(head))
	{
		std::cout << "The stack is empty. Nothing to print." << std::endl;
	}
	else
	{
		StackItem* current = head;
		while (current != NULL)
		{
			std::cout << current -> data << std::endl;
			current = current -> previous;
		}
	}
}