#define _CRT_SECURE_NO_WARNINGS

#include <string.h>
#include <iostream>
#include <fstream>
#include <string>
#include "utils.h"
#include "wordle.h"

const int subtractor = 'a' - 'A';

std::string readFromFile(const std::string filePath, int lineNumber, std::string currentDate)
{
    std::string line;
    std::ifstream myfile(filePath);

    std::string date;
    std::string bestTries;
    int currentLine = 0;

    if (myfile.is_open())
    {
        while (getline(myfile, line, ':') && getline(myfile, date, ':') && getline(myfile, bestTries))
        {
            if (currentLine == lineNumber)
            {
                if (!currentDate.empty() && date == currentDate) {
                    std::cout << "Sorry you've already paly today!" << std::endl;
                    return "";
                }
                myfile.close();
                return line;
            }
            ++currentLine;
        }
        myfile.close();
    }
    else
    {
        std::cout << "Unable to open file" << std::endl;
    }

    return "";
}

bool writeToFile(const std::string filePath, std::string word, std::string currentDate, int tries)
{
    std::fstream file(filePath, std::ios::in | std::ios::out);
    std::ifstream inputFile(filePath);
    std::ofstream tempFile("temp.txt");
    std::string line;
    std::streampos pos = 0;
    bool lineReplaced = false;


    if (!inputFile.is_open() || !tempFile.is_open()) {
        std::cerr << "Failed to open files." << std::endl;
        return false;
    }

    while (getline(inputFile, line)) {
        toUpperCase(&line[0]);
        if (line.find(word) != std::string::npos) {
            tempFile << word + ':' + currentDate + ':' + std::to_string(tries) << std::endl;
            lineReplaced = true;
        }
        else {
            tempFile << line << std::endl;
        }
    }

    if (lineReplaced) {
        //TODO: fix removing file
        if (remove(filePath.c_str()) != 0) {
            std::cerr << "Error deleting original file." << std::endl;
            return false;
        }
        if (rename("temp.txt", filePath.c_str()) != 0) {
            std::cerr << "Error renaming temporary file." << std::endl;
            return false;
        }
        std::cout << "Word stats updated successfully." << std::endl;
        return true;
    }
    else {
        std::cout << "Word not found in the file." << std::endl;
        remove("temp.txt");
        return false;
    }
}

void getWord(TypeOfWord type, char *& wordSource, const std::string filePath)
{
    std::string word;
    time_t now = time(0);
    tm* ltm = localtime(&now);
    std::string monthDay = std::to_string(ltm->tm_mon) + "/" + std::to_string(ltm->tm_mday);
    switch (type)
    {
    case TypeOfWord::WordOfTheDay: {

        word = readFromFile(filePath, ltm->tm_mday, monthDay);
        if (word == "") return;
        break;
    }
    case TypeOfWord::RandomWord: {
        std::srand(std::time(0));
        int randomNumber = std::rand() % 31 + 1;
        word = readFromFile(filePath, randomNumber, monthDay);
        break;
    }
    default: return;
    }

    toUpperCase(&word[0]);
    wordSource = new char[word.size() + 1];
    std::strcpy(wordSource, word.c_str());
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
