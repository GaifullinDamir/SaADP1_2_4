#include <iostream>
#include "stackItem.h"

using namespace std;
//struct StackItem
//{
//	int data;
//	StackItem* previous;
//};
//
//void init(StackItem* head) 
//{
//	head = NULL;
//}
//
//bool isEmpty(StackItem* head) 
//{
//	if (head == NULL)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//
//void printStack(StackItem* head) 
//{
//	if (isEmpty(head))
//	{
//		cout << "Stack is empty" << endl;
//	}
//
//	else
//	{
//		StackItem* current = head;
//		while(current != NULL)
//		{ 
//			cout << current->data << endl;
//			current = current->previous;
//		}
//	}
//	
//}
//
//void addItem(StackItem*& head, int data)
//{
//	try
//	{
//		StackItem* current = new StackItem;
//		current->previous = head;
//		current->data = data;
//		head = current;
//	}
//	catch (const std::exception&)
//	{
//		cout << "Стек заполнен" << endl;
//	}
//}
//
//void addMultipleItems(StackItem*& head, int amount)
//{
//	for (int i = 0; i < amount; i++)
//	{
//		int data = rand();
//		addItem(head, data);
//	}
//}
//
//void deleteItem(StackItem*& head)
//{
//	if (!isEmpty(head))
//	{
//		StackItem* temp = head;
//		head = head->previous;
//		delete temp;
//	}
//	else
//	{
//		cout << "Стек пустой" << endl;
//	}
//}
//
//void moveToSecond(StackItem*& head1, StackItem*& head2)
//{
//	StackItem* temp = head1;
//	head1 = head1->previous;
//	temp->previous = head2;
//	head2 = temp;
//}
//
//void moveToFirst(StackItem*& head1, StackItem*& head2)
//{
//	StackItem* temp = head2;
//	head2 = head2->previous;
//	temp->previous = head1;
//	head1 = temp;

int main()
{
	StackItem* headMain = new StackItem;
	StackItem* headSecond = new StackItem;
	headMain = stackInit(headMain);
	headSecond = stackInit(headMain);
	//addMultipleItems(headMain, 5);
	//moveToSecondaryStack(headMain, headSecond);
	/*addMultipleItems(headSecond, 5);*/
	printStack(headMain);
	deleteItem(headMain);
	/*std::cout << std::endl;
	printStack(headSecond);
	moveToSecondaryStack(headSecond, headMain);
	printStack(headMain);
	std::cout << std::endl;
	printStack(headSecond);*/
}