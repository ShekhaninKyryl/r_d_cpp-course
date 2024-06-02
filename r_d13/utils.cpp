#define _CRT_SECURE_NO_WARNINGS

#include <string.h>
#include "utils.h"
#include "wordle.h"

const int subtractor = 'a' - 'A';


// TODO: add file, add day word;
void getWord(TypeOfWord type, char *& wordSource)
{
    char word[] = "cocon";
    wordSource = new char[strlen(word) + 1];
    strcpy(wordSource, word);
    toUpperCase(wordSource);
}

bool compareWords(char* word, char* userInput, char* result)
{
    bool ignorePosition[WORD_SIZE] = { false };

    for (int i = 0; i < WORD_SIZE; i++) {
        ignorePosition[i] = isSymbolOnPlace(word, userInput[i], i, result);
    }

    for (int i = 0; i < WORD_SIZE; i++) {
            isSymbolExist(word, userInput[i], i, result, ignorePosition);
    }

    if (strcmp(word, result) == 0) return true;

    return false;
}

bool isSymbolExist(char* word, char symbol, unsigned short position, char*& result, bool* ignorePosition)
{
    for (int localPos = 0; word[localPos] != '\0'; ++localPos)
    {
        if (word[localPos] == symbol && !(ignorePosition[position] || ignorePosition[localPos])) {

            ignorePosition[localPos] = true;
            result[position] = symbol + subtractor;
            return true;
        }
    }
    return false;
}

bool isSymbolOnPlace(char* word, char symbol, unsigned short position, char*& result)
{
    if (word[position] == symbol) {
        result[position] = symbol;
        return true;
    }
    return false;
}

void toUpperCase(char str[])
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] >= (int)'a' && str[i] <= (int)'z') str[i] -= subtractor;
        i++;
    }
}
