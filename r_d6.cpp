/*
1. Зчитати з консолі три числа: перший елемент, крок арифметичної прогресії, номер останнього елемента арифметичної прогресії (арифметична прогресія - це послідовність дійсних чисел, кожен член якої, починаючи з другого, утворюється додаванням до попереднього члена одного й того ж числа. Загальний вид арифметичної прогресії:

a1, a1 + d, a1 + 2d, …, a1 + (n - 1)d, …,

де a1 - це перший член прогресії, d = an+1 - an

Як результат, надрукувати всі елементи арифметичної прогресії починаючи з першого до останнього.

2. Зчитати з консолі число - номер елемента послідовності Фібоначчі. Надрукувати значення даного елемента послідовності Фібоначчі (послідовність Фібоначчі - числова послідовність, задана таким співвідношенням:

F1 = 1, F2 = 1, Fn+2 = Fn + Fn+1, n = 1, 2, 3, …,

F1 = 1, F2 = 1, F3 = 2, F4 = 3, F5 = 5, F6 = 8, F7 = 13, F8 = 21

3. Зчитати ціле додатне число. Вивести факторіал цього числа. (Факторіал натурального числа n - добуток чисел від 1 до цього числа, позначається як n! Н-д: 5! = 1⋅2⋅3⋅4⋅5 = 120).

4. За допомогою циклу надрукувати геометричні фігури; розмір сторін/кількість рядків вводить користувач з консолі;



5.В циклі зчитати символ char. В залежності від природи символу виконати наступні дії:

буква в нижньому регістрі - привести до верхнього та вивести;
цифра - додати до загальної суми введених цифр, та вивести результат поточної суми;
Інше (розділові знаки, спецсимвол, тд) - вивести повідомлення, що цей символ не обробляється програмою та продовжити цикл;
Завершити програму, якщо введено символ ‘.’;
*/

#include <iostream>

void arithmeticProgression()
{
    int firstElement = 0;
    int numberOfLastElement = 0;
    short step = 0;

    do 
    {
        std::cout << "Enter first element: ";
        std::cin >> firstElement;
    } while (!firstElement);


    do {
        std::cout << "Enter number of last element: ";
        std::cin >> numberOfLastElement;
    } while (!numberOfLastElement);


    do {
        std::cout << "Enter step value: ";
        std::cin >> step;
    } while (!step);


    for (int count = 0; count < numberOfLastElement; count++) {
        std::cout << firstElement + step * count << ", ";
    }


    return;
}

int fibonachi(int n)
{
    if (n <= 1)
        return n;
    return fibonachi(n - 1) + fibonachi(n - 2);
}

void fibonachiProgression()
{
    int numberOfLastElement = 0;
    do {
        std::cout << "Enter number of last element: ";
        std::cin >> numberOfLastElement;
    } while (!numberOfLastElement);

    std::cout << "Fibonachi value is: " << fibonachi(numberOfLastElement);

}

int factorial(int n)
{
    if (n <= 1)
        return n;
    return factorial(n - 1) * n;
}

void factorialProgression()
{
    int numberOfLastElement = 0;
    do {
        std::cout << "Enter number of last element: ";
        std::cin >> numberOfLastElement;
    } while (!numberOfLastElement);

    std::cout << "Factorial value is: " << factorial(numberOfLastElement);
}

void draw(char variant = 'a')
{
    int numberOfRows = 0;
    do {
        std::cout << "Enter number of rows: ";
        std::cin >> numberOfRows;
    } while (!numberOfRows);

    switch (variant)
    {
    case 'a': {
        for (int i = numberOfRows; i > 0; i--) {
            for (int j = i; j > 0; j--) {
            std::cout << "*";
            }
            std::cout << std::endl;
        }
        break;
    }
    case 'b': {
        for (int i = 0; i < numberOfRows; i++) {
            for (int j = 0; j <= i; j++) {
                std::cout << "*";
            }
            std::cout << std::endl;
        }
        break;
    };
    case 'c': {
        for (int i = 0; i < numberOfRows; i++) {
            for (int j = 0; j <= numberOfRows; j++) {
                std::cout << "*";
            }
            std::cout << std::endl;
        }
        break;
    };
    case 'd': {
        for (int i = 0; i < numberOfRows; i++) {
            for (int j = 0; j <= i-1; j++) {
                std::cout << " ";
            }

            for (int j = 0; j <= numberOfRows; j++) {
                std::cout << "*";
            }
            std::cout << std::endl;
        }
        break;
    }
    case 'e': {
        bool value = true;
        for (int i = 0; i < numberOfRows; i++) {
            for (int j = 0; j <= i; j++) {
                std::cout<< value;
                value = !value;
            }
            value = i%2;
            std::cout << std::endl;
        }
        break;
    }
    default:
        break;
    }
}



int main()
{
    draw('e');
}
