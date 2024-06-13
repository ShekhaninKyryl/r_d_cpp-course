#include <iostream>

const int ARRAY_SIZE = 10;
const int ROWS = 2;
const int COLUMNS = 5;

void bubbleSort(int arr[], int size) {
	if (size <= 0) return;

	int tmp;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}

enum class SortingDirection
{
	ByRows,
	ByColumns,
};


void swap(int*& leftItem, int*& rightItem)
{
	int temp = *leftItem;

	*leftItem = *rightItem;

	*rightItem = temp;
}

 int* getPivot(int *minIndex, int* maxIndex)
{
	int* pivot = minIndex - 1;

	for (int* i = minIndex; i <= maxIndex; i++)
	{
		if (*i < *maxIndex)
		{
			pivot++;
			swap( pivot, i);
		}
	}

	pivot++;
	swap(pivot, maxIndex);

	return pivot;
}


void quickSort(int *start, int *end) {

	if (start >= end)
	{
		return;
	}

	int* pivot = getPivot(start, end);

	quickSort(start, pivot - 1);
	quickSort(pivot + 1, end);

	return;
}



void convertArray(int arr[ROWS][COLUMNS], SortingDirection direction) {
	switch (direction)
	{
	case SortingDirection::ByRows: return;

	// TODO: fix
	case SortingDirection::ByColumns: {
		int newArray[COLUMNS][ROWS];

		for (int i = 0; i < ROWS; ++i) {
			for (int j = 0; j < COLUMNS; ++j) {
				newArray[j][i] = arr[i][j];
			}
		}

		for (int i = 0; i < ROWS; ++i) {
			for (int j = 0; j < COLUMNS; ++j) {
				arr[i][j] = newArray[i][j];
			}
		}
		return;
	}
	}
}

void sort(int arr[ROWS][COLUMNS], SortingDirection direction) {

	quickSort(&arr[0][0], &arr[ROWS - 1][COLUMNS - 1]);
	convertArray(arr, direction);
}

int main()
{
	int array[ROWS][COLUMNS] = {10, 20, 3, 4, 15, 6, 7, 8, 9, 10};
   
	//bubbleSort(array, ARRAY_SIZE);

	sort(array, SortingDirection::ByColumns);

	return 0;
}