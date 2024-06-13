#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

const int subtractor = 'a' - 'A';
const unsigned short WORD_SIZE = 5;

void toUpperCase(std::string &str) {
    std::transform(str.begin(), str.end(), str.begin(), ::toupper);
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



/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    string secret_word;
    getline(cin, secret_word);
    string user_guess;
    getline(cin, user_guess);

    
    toUpperCase(secret_word);
    toUpperCase(user_guess);

    char result[WORD_SIZE + 1] = "*****";
    compareWords(&secret_word[0], &user_guess[0], result);
    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << result << endl;
}
