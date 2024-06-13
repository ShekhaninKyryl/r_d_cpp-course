#pragma once

enum class TypeOfWord
{
	WordOfTheDay,
	RandomWord,
	Exit,
};

std::string readFromFile(const std::string filePath, int lineNumber, std::string currentDate);
bool writeToFile(const std::string filePath, std::string word, std::string currentDate, int tries);

void getWord(TypeOfWord type, char*& wordSource, const std::string filePath);
bool compareWords(char* word, char* userInput, char* result);

bool isSymbolExist(char* word, char symbol, unsigned short position, char*& result, bool* ignorePosition);
bool isSymbolOnPlace(char* word, char symbol, unsigned short position, char*& result);

void toUpperCase(char str[]);