#pragma once
#include "stackItem.h"

const int mainMenu = 0;
const int secondMenu = 1;
const int numbOfOptionsMain = 4;
const int numbOfOptionsSecond = 2;

void printMainMenu();

void printAdditionalMenu(int option);

int userInput();

void processInput(int option);

