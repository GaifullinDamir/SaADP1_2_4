#include <iostream>
#include <string>
#include "stackitem.h"

StackItem* init()
{
	StackItem* stack = new StackItem;
	stack->head = NULL;
	return stack;
}

void add(int data, StackItem*& stack)
{
	StackItem* temp = new StackItem;                              //�������� ������ ��� ������ ��������
	temp->data = data;                                        //���������� � ���� x ����������� � ������� ������� x
	temp->previous = stack->head;                          //���������, ��� ��������� ������� ��� ����������
	stack->head = temp;                                //�������� ������ �� ������� ������
}


void deleteItem(StackItem* stack)
{

}