#include <iostream>
#include "RD9.h"


void readFromConsole(int input[], const int size)
{
	std::cout << "Type " << size << " numbers: ";
	for (int i = 0; i < size; i++) {
		std::cin >> input[i];
	}
}

void readFromConsole(char input[])
{
	std::cout << "Type string: ";
	std::cin >> input;
}

void showInConsole(int output[], const int size)
{
	std::cout << "Output array: ";
	for (int i = 0; i < size; i++) {
		std::cout << output[i] << ", ";
	}
	std::cout << std::endl;
}

void translateArray(int numbers[], const int size)
{
	for (int i = 0; i < size; i++) {
		if (numbers[i] > 0) numbers[i] *= 2;
		else if (numbers[i] < 0) numbers[i] = 0;
	}
}

void toUppercase(char str[])
{
	int subtractor = 'a' - 'A';
	int i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= (int)'a' && str[i] <= (int)'z') str[i] -= subtractor;
		i++;
	}
}

bool isPalindrom(const char str[])
{
	int size = 0;
	while (str[size]) size++;

	for (int i = 0; i < size / 2; i++) {
		if (str[i] != str[size - i - 1]) return false;
	}

	return true;
}

void parseStringLetters(const char str[], int& vowelsCount, int& constonantsCount)
{
	for (int i = 0; str[i] != '\0'; i++) {
		bool isVowel = false;
		for (int v = 0; VOWELS[v] != '\0'; v++) {
			if (str[i] == VOWELS[v]) {
				isVowel = true;
				break;
			}
		}
		isVowel ? vowelsCount++ : constonantsCount++;
	}
}

bool isEqual(const char str1[], const char str2[])
{
	for (int i = 0; str1[i] != '\0' || str2[i] != '\0'; i++) {
		if (str1[i] != str2[i]) return false;
	}
	return true;
}

void task1()
{
	const int ARRAY_SIZE = 10;
	int numbers[ARRAY_SIZE];

	readFromConsole(numbers, ARRAY_SIZE);
	translateArray(numbers, ARRAY_SIZE);
	showInConsole(numbers, ARRAY_SIZE);
}
void task2()
{
	const int MAX_STRING_SIZE = 100;
	char string[MAX_STRING_SIZE];

	readFromConsole(string);
	toUppercase(string);
	std::cout << "Output: " << string;
}
void task3() {
	const int MAX_STRING_SIZE = 100;
	char string[MAX_STRING_SIZE];

	readFromConsole(string);
	std::cout << "Output: " << isPalindrom(string);
}

void task4() {
	const int MAX_STRING_SIZE = 100;
	char string[MAX_STRING_SIZE];

	int vowelsCount = 0;
	int constonantsCount = 0;

	readFromConsole(string);
	parseStringLetters(string, vowelsCount, constonantsCount);
	std::cout << "Output: " << "Vowels - " << vowelsCount << " Constonants - " << constonantsCount << std::endl;
}

void task5()
{
	const int MAX_STRING_SIZE = 100;
	char string1[MAX_STRING_SIZE];
	char string2[MAX_STRING_SIZE];

	readFromConsole(string1);
	readFromConsole(string2);

	std::cout << "Output: " << isEqual(string1, string2) << std::endl;
}
