#include <iostream>


using namespace std;

struct StackItem
{
	int data;
	StackItem* previous;
};

void init(StackItem* head) 
{
	head = NULL;
}

bool isEmpty(StackItem* head) 
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

void printStack(StackItem* head) 
{
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

void addItem(StackItem*& head, int data)
{
	try
	{
		StackItem* current = new StackItem;
		current->previous = head;
		current->data = data;
		head = current;
	}
	catch (const std::exception&)
	{
		cout << "Стек заполнен" << endl;
	}
}

void addMultipleItems(StackItem*& head, int amount)
{
	for (int i = 0; i < amount; i++)
	{
		int data = rand();
		addItem(head, data);
	}
}

void deleteItem(StackItem*& head)
{
	if (!isEmpty(head))
	{
		StackItem* temp = head;
		head = head->previous;
		delete temp;
	}
	else
	{
		cout << "Стек пустой" << endl;
	}
}

void moveToSecond(StackItem*& head1, StackItem*& head2)
{
	StackItem* temp = head1;
	head1 = head1->previous;
	temp->previous = head2;
	head2 = temp;
}

void moveToFirst(StackItem*& head1, StackItem*& head2)
{
	StackItem* temp = head2;
	head2 = head2->previous;
	temp->previous = head1;
	head1 = temp;
}
int main()
{
	StackItem* head1 = NULL;
	StackItem* head2 = NULL;
	init(head1);
	addMultipleItems(head1, 5);
	cout << endl;
	cout << "head1 old" << endl;
	cout << endl;
	printStack(head1);
	moveToSecond(head1, head2);
	moveToSecond(head1, head2);
	cout << endl;
	cout << "head2" << endl;
	cout << endl;
	printStack(head2);
	cout << endl;
	cout << "head1 new" << endl;
	cout << endl;
	printStack(head1);
	cout << endl;
	moveToFirst(head1, head2);
	moveToFirst(head1, head2);
	cout << endl;
	cout << "head 1 newNew" << endl;
	cout << endl;
	printStack(head1);


	/*deleteItem(head);
	deleteItem(head);
	cout << " " << endl;
	printStack(head);*/
}