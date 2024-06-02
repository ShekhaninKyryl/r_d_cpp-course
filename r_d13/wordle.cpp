#include <iostream>
#include "wordle.h"


void showStart()
{
	std::cout << "1 - Wordle of the day" << std::endl;
	std::cout << "2 - Random Wordle" << std::endl;
	std::cout << "0 - Exit" << std::endl;
}

TypeOfWord inputTypeOfWord()
{
	char input;
	while (true) {
		std::cout << "Enter: ";
		std::cin >> input;

		switch (input)
		{
		case '0': {
			return TypeOfWord::Exit;
		}
		case '1': {
			return TypeOfWord::RandomWord;
		}
		case '2': {
			return TypeOfWord::WordOfTheDay;
		}
		default: {
			std::cout << std::endl << "Unknown type, please try again!" << std::endl;
		}
		}
	}
}

void showRound(char* result)
{
	std::cout << "Result: " << '\t' << result << std::endl;
}

void readFromConsole(char* input)
{
	std::cout << "Enter: " << '\t' <<'\t';
	std::cin >> input;
}

void showFinish(bool isFound, int round)
{
	if (isFound) {
		std::cout << "That's right!" << std::endl;
		std::cout << "You made " << round << " tries!" << std::endl << std::endl;
	}
	else {
		std::cout << "You reach max tries: " << round  << "!" << std::endl << std::endl;
	}
}

bool gameRound(char*& word, int& round)
{
	round++;
	char result[WORD_SIZE + 1] = "*****";
	char input[WORD_SIZE + 1];

	readFromConsole(input);
	toUpperCase(input);
	bool isFound = compareWords(word, input, result);
	showRound(result);
	return isFound;
}
