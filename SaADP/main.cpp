#include <iostream>
#include <string>
#include "stackItem.h"
#include "userInterface.h"

int main()
{
	StackItem* headMain = new StackItem;
	StackItem* headSecond = new StackItem;
	headMain = stackInit(headMain);
	headSecond = stackInit(headSecond);
	workWithUser(headMain, headSecond);
	clearMemory(headMain, headSecond);
}