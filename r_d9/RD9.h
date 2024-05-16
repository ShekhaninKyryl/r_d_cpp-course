#pragma once

void readFromConsole(int input[],  const int size);
void readFromConsole(char input[]);

void showInConsole(int output[], const int size);

void translateArray(int numbers[], const int size);
void toUppercase(char str[]);
bool isPalindrom(const char str[]);
const char VOWELS[] = "aeiouAEIOU";
void parseStringLetters(const char str[], int& vowelsCount, int& constonantsCount);
bool isEqual(const char str1[], const char str2[]);

void task1();
void task2();
void task3();
void task4();
void task5();