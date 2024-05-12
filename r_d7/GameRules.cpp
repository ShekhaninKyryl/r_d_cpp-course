#include <algorithm>
#include <iostream>
#include <iomanip>
#include "GameRules.h"

int startGame()
{
	int roundCount = -1;
	std::cout << "Hello! Welcome to 'Rock-Paper-Scissors' game for 2 players." << std::endl;
	std::cout << "Enter rounds number (-1 to quit): ";
	std::cin >> roundCount;
	//validate roundCount;
	return roundCount;
}

char convertVariantToSymbol(Variant value)
{
	switch (value)
	{
	case Variant::Rock: return 'r';
	case Variant::Paper: return 'p';
	case Variant::Scissors: return 's';
	default: return 'u';
	}
	return 0;
}

void showPossibleVariant()
{
	std::cout << '\t' << "r - rock" << std::endl;
	std::cout << '\t' << "p - paper" << std::endl;
	std::cout << '\t' << "s - scissors" << std::endl;

	return;
}

int validateEnteredValue(char symbol)
{
	if (symbol == 'r' || symbol == 'R') return 1;
	if (symbol == 'p' || symbol == 'P') return 1;
	if (symbol == 's' || symbol == 's') return 1;
	if (symbol == -1) return -1;
	return 0;
}

Variant convertToVariant(int value)
{
	if (value == 0) return Variant::Rock;
	if (value == 1) return Variant::Paper;
	if (value == 2) return Variant::Scissors;
	return Variant();
}

Variant convertToVariant(char symbol)
{

	if (symbol == 'r' || symbol == 'R') return Variant::Rock;
	if (symbol == 'p' || symbol == 'P') return Variant::Paper;
	if (symbol == 's' || symbol == 's') return Variant::Scissors;
	return Variant();
}

void showStatistics(int winCount, int drawCount, int loosCount)
{
	std::cout << "Thanks for playing. Your final stats: " << std::endl;
	std::cout << '\t' << "number of wins - " << winCount << std::endl;
	std::cout << '\t' << "number of losses - " << loosCount << std::endl;
	std::cout << '\t' << "number of draws - " << drawCount << std::endl;

	const int max = std::max({ winCount, loosCount, drawCount });
	if (max == winCount) {
		std::cout << "---You're smarter than my PC algo!---" << std::endl;
	}
	else if (max == drawCount) {
		std::cout << "---You're almost win!---" << std::endl;
	}
	else if (max == loosCount) {
		std::cout << "---You should try again! Never give up!---" << std::endl;
	}
	else {
		std::cout << "!!!smth wrong!!!" << std::endl;
	}

	std::cout << "-------------------------" << std::endl;
	return;
}

RoundResult gameRaund(int& raundNumber, bool& isExit)
{
	// generate choose form -1 to 1
	const Variant randomChoose = convertToVariant(std::rand() % VARIANT_LENGTH);
	Variant userChoose;

	std::cout << "To make your turn enter one of possible symbols: " << std::endl;
	showPossibleVariant();
	
	int isCorrectInput;
	char input;
	do {
		std::cin >> input;
		isCorrectInput = validateEnteredValue(input);
		if (isCorrectInput == -1) {
			isExit = true;
			return RoundResult::Unknown;
		}
		else if (isCorrectInput == 0) {
			std::cout << "Incorrect input value. Try Again!" << std::endl;
		}
	} while (!isCorrectInput);

	userChoose = convertToVariant(input);

	std::cout << "Your choise: " << convertVariantToSymbol(userChoose) << std::endl;
	std::cout << "PC choice: " << convertVariantToSymbol(randomChoose) << std::endl;

	int result = checkWinner(userChoose, randomChoose);

	raundNumber -= 1;
	if (!raundNumber) isExit = true;

	if (result == 1) {
		return RoundResult::Loose;
	}
	if (result == 0) {
		return RoundResult::Draw;
	}
	if (result == -1) {
		return RoundResult::Win;
	}
	return RoundResult::Unknown;
}

int checkWinner(Variant left, Variant right)
{

	/*
	Here is a condition table;
			| 0 | 1 | 2
			| R | P | S
		0-R	| 0 | 1 |-1
		1-P	| -1| 0 | 1
		2-S	| 1 |-1 | 0

	implemented checker based on sum result.
	Instead, we may use 3 * 3 conditions;
	*/

	const int sum = static_cast<int>(left) + static_cast<int>(right);
	switch (left)
	{
	//0-R	0	1	2
	case Variant::Rock: {
		return sum == 2 ? -1 : sum;
	}
	//1-P	1	2	3
	case Variant::Paper: {
		return sum == 1 ? -1 : sum % 2;
	}
	//2-S	2	3	4
	case Variant::Scissors: {
		return sum == 2 ? 1 : sum - 4;
	}
	default:
		std::cout << "!!!Warning: unresolvew condition!!!" << std::endl;
		return 0;
	}
}
