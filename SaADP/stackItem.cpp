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
	StackItem* temp = new StackItem;                              //Выделяем память для нового элемента
	temp->data = data;                                        //Записываем в поле x принимаемый в функцию элемент x
	temp->previous = stack->head;                          //Указываем, что следующий элемент это предыдущий
	stack->head = temp;                                //Сдвигаем голову на позицию вперед
}


void deleteItem(StackItem* stack)
{

}