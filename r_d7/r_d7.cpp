// r_d7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "GameRules.h"

int main()
{
	int roundCount = startGame();
	if (roundCount == -1) return 0;

	bool isExit = false;
	int wins = 0;
	int draws = 0;
	int looses = 0;




	while (roundCount) {
		RoundResult result = gameRaund(roundCount, isExit);

		switch (result)
		{
		case RoundResult::Win:
			std::cout << "Your win! " << std::endl;
			wins++;
			break;
		case RoundResult::Draw:
			std::cout << "It is draw! " << std::endl;
			draws++;
			break;
		case RoundResult::Loose:
			std::cout << "Your loose! " << std::endl;
			looses++;
			break;
		case RoundResult::Unknown:
			std::cout << "Warning: Unknown result!" << std::endl;
			break;
		default:
			std::cout << "Warning: Default behavior!" << std::endl;
			break;
		}

		if (isExit) {
			showStatistics(wins, draws, looses);
			return 0;
		}
	}

	return 0;
}