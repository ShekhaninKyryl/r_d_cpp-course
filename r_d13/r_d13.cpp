#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include "wordle.h"
#include "utils.h"

const int MAX_ROUND = 5;
std::string filePath = "words.txt";

int main()
{
	bool isExit = false;
	do {
		int round = 0;
		bool isFound = false;
		char* word = nullptr;

		showStart();
		TypeOfWord type = inputTypeOfWord();
		if (type == TypeOfWord::Exit) {
			isExit = true;
			break;
		}

		getWord(type, word, filePath);
		if (word == nullptr) continue;

		do {
			isFound = gameRound(word, round);
		} while (round != MAX_ROUND && !isFound);

		showFinish(isFound, round);

		time_t now = time(0);
		tm* ltm = localtime(&now);
		std::string monthDay = std::to_string(ltm->tm_mon) + "/" + std::to_string(ltm->tm_mday);
		writeToFile(filePath, word, monthDay, round);

	} while (!isExit);
	return 0;
}