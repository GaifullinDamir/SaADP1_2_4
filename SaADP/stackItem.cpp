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
	try
	{
		StackItem* current = new StackItem;
		current -> previous = head;
		current -> data = rand();
		head = current;
	}
	catch (const std::exception&)
	{
		std::cout << "   The stack is full. Can't be added." << std::endl;
	}
}

void addMultipleItems(StackItem*& head, int amount)
{
	for (int i = 0; i < amount; i++)
	{
		addItem(head);
	}
	std::cout << "   Elements in quantity: " << amount << " - were added to the stack." << std::endl;
	std::cout << std::endl;
}

bool moveToSecondaryStack(StackItem*& headFirst, StackItem*& headSecond)
{
	if(!emptyCheck(headFirst))
	{
		StackItem* current = headFirst;
		headFirst = headFirst -> previous;
		current->previous = headSecond;
		headSecond = current;
		return true;
	}
	else
	{
		return false;
	}

}


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

bool deleteItem(StackItem*& head)
{
	if (!emptyCheck(head))
	{
		StackItem* current = head;
		head = head -> previous;
		delete current;
		return true;
	}
	else
	{
		return false;
	}
}

void printStack(StackItem* head)
{
	if (emptyCheck(head))
	{
		std::cout << "   The stack is empty. Nothing to print." << std::endl;
	}
	else
	{
		StackItem* current = head;
		while (current != NULL)
		{
			std::cout << "   " << current->data << std::endl;
			current = current -> previous;
		}
	}
}

void clearMemory(StackItem*& headFirst, StackItem*& headSecond)
{
	StackItem* current = NULL;
	
	for (int stackNumber = 0; stackNumber < 2; stackNumber++)
	{
		if (stackNumber == 0) { current = headFirst; }
		else if (stackNumber == 1) { current = headSecond; }
		while (current != NULL)
		{
			deleteItem(current);
		}
	}
}