#pragma once
#include <iostream>
#include <string>


struct StackItem
{
	int data;
	StackItem* previous, * head; //указатель на пред-й эл-т и на голову
};

StackItem* init();

void add(int data, StackItem*& stack);

void deleteItem(StackItem* stack);

void show(StackItem* stack)