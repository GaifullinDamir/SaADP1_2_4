#include <iostream>


using namespace std;

struct StackItem
{
	int data;
	StackItem* previous;
};

void init(StackItem* head) {
	head = NULL;
}

bool isEmpty(StackItem* head) {
	if (head == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void printStack(StackItem* head) {
	if (isEmpty(head))
	{
		cout << "Stack is empty" << endl;
	}

	else
	{
		StackItem* current = head;
		while(current != NULL)
		{ 
			cout << current->data << endl;
			current = current->previous;
		}
	}
	
}
int main()
{
	StackItem* head = NULL;
	init(head);
	printStack(head);
}