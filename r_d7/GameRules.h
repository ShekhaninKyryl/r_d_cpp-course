#pragma once

const int VARIANT_LENGTH = 3;

enum class Variant
{
	Rock = 0,
	Paper = 1,
	Scissors = 2,
};


enum class RoundResult
{
	Win,
	Draw,
	Loose,
	Unknown,
};



void showPossibleVariant();
int validateEnteredValue(char symbol);

Variant convertToVariant(int value);
Variant convertToVariant(char symbol);

char convertVariantToSymbol(Variant value);

void showStatistics(int winCount, int drawCount, int loosCount);
int startGame();
RoundResult gameRaund(int &raundNumber, bool &isExit);

/*
* 
* -1 left win
*  0 standoff
*  1 right win
*/
int checkWinner(Variant left, Variant right);

