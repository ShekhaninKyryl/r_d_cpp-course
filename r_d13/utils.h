#pragma once

enum class TypeOfWord
{
	WordOfTheDay,
	RandomWord,
	Exit,
};

void getWord(TypeOfWord type, char*& wordSource);
bool compareWords(char* word, char* userInput, char* result);

bool isSymbolExist(char* word, char symbol, unsigned short position, char*& result, bool* ignorePosition);
bool isSymbolOnPlace(char* word, char symbol, unsigned short position, char*& result);

void toUpperCase(char str[]);