#pragma once

#include "utils.h"

const unsigned short WORD_SIZE = 5;

void showStart();
TypeOfWord inputTypeOfWord();

void showRound(char* result);
void readFromConsole(char* input);

void showFinish(bool isFound, int round);



bool gameRound(char*& word, int &round);


