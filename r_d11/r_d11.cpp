#include <iostream>

#define ROWS 3
#define COLS 3

bool find(int arr_2d[][COLS], int toFind, unsigned short rows = ROWS) {
    if (rows <= 0 && COLS <= 0) return false;

    for (unsigned short i = 0; i < rows; i++)
    {
        for (unsigned short j = 0;  j < COLS;  j++)
        {
            if (arr_2d[i][j] == toFind) return true;
        }
    }

    return false;
}

enum class SortingDirection
{
    ASCENDING,
    DESCENDING,
};

bool isSorted(const int* arr, int size, SortingDirection direction) {
    if (size <= 0) return false;

    switch (direction)
    {
    case SortingDirection::ASCENDING: {
        int min = INT16_MIN;
        for (unsigned int i = 0; i < size; i++)
        {
            if (min >= arr[i]) return false;
            min = arr[i];
        }
        return true;
    }
    case SortingDirection::DESCENDING: {
        int max = INT16_MAX;
        for (unsigned int i = 0; i < size; i++)
        {
            if (max <= arr[i]) return false;
            max = arr[i];
        }
        return true;
    }
    }
}


int stackColsRevers(int arr_2d[][COLS], int *&pointer, unsigned short rows = ROWS) {
    pointer +=rows;
    if (pointer - arr_2d[0] > ROWS * COLS) pointer -= (ROWS * COLS) + 1;
    return *pointer;
}

int snakeRowsRevers(int arr_2d[][COLS], int*& pointer, unsigned short rows = ROWS) {
    short int orientation = 1;
    unsigned int distance = pointer - arr_2d[0];

    if ((distance / (ROWS)) % 2) orientation = -1;
    pointer += orientation;

    distance = pointer - arr_2d[0];
    if (orientation == 1 && ((distance / (ROWS)) % 2)) pointer -= (ROWS + 1);
    if (orientation == -1 && !(distance / (ROWS)) % 2) pointer -= (ROWS - 1);

    return *pointer;
}

enum class ArrayTraversal
{
    StackColsRevers,
    SnakeRowsRevers,
};

void showArray(int array[][COLS], ArrayTraversal variant, unsigned short rows = ROWS) {
    switch (variant)
    {
    case ArrayTraversal::StackColsRevers: {
        // Would be good to calculate start|end for all possible array size but I`m lazy
        // It is true for 3*3
        int* start = &array[0][COLS - 1];
        int* end = &array[ROWS - 1][0];

        std::cout << *start << '\t';
        while (start != end)
        {
            std::cout << stackColsRevers(array, start) << '\t';
        }
        std::cout << std::endl;
        break;
    }
    case ArrayTraversal::SnakeRowsRevers: {
        // Would be good to calculate start|end for all possible array size but I`m lazy
        // It is true for 3*3
        int* start = &array[ROWS - 1][0];
        int* end = &array[0][COLS - 1];

        std::cout << *start << '\t';
        while (start != end)
        {
            std::cout << snakeRowsRevers(array, start) << '\t';
        }
        std::cout << std::endl;
        break;
    }
    default:
        std::cout << "Unknown variant" << std::endl;
        break;
    }
}

int main()
{
    int array[ROWS][COLS]= {
        { 1,  2,  3},
        {11, 12, 13},
        {21, 22, 23},
    };

    //std::cout << find(array, 5);
    //std::cout << isSorted(array[1], COLS, SortingDirection::ASCENDING);


    //  3       13      23      2       12      22      1       11      21
    showArray(array, ArrayTraversal::StackColsRevers);

    //  21      22      23      13      12      11      1       2       3
    showArray(array, ArrayTraversal::SnakeRowsRevers);
}