#include <iostream>
#include "wordle.h"
#include "utils.h"

const int MAX_ROUND = 5;

int main()
{
	bool isExit = false;
	do {
		int round = 0;
		bool isFound = false;
		char* word;

		showStart();
		TypeOfWord type = inputTypeOfWord();
		if (type == TypeOfWord::Exit) {
			isExit = true;
			break;
		}

		getWord(type, word);
		do {
			isFound = gameRound(word, round);
		} while (round != MAX_ROUND && !isFound);

		showFinish(isFound, round);

	} while (!isExit);
	return 0;
}