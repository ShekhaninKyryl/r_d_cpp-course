#include <iostream>

void swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}
void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

bool calculateSum(const double* arr, int arrSize, double& sum) {
	if (arrSize <= 0) return false;

	while (arrSize)
	{
		sum += *arr;
		arr++;
		arrSize--;
	}

	return true;
}

bool find(const int* arr, int size, int elem) {
	if (size <= 0) return false;

	while (size)
	{
		if(elem == *arr) return true;
		arr++;
		size--;
	}

	return false;
}


int main()
{
	int a = 1;
	int b = 2;
	swap(a, b);
	swap(&a, &b);

	std::cout << "A and B switched twice: " <<"a = "<< a << " " << "b = " << b << std::endl;

	int arraySize = 4;

	double array1[] = { 1.0, 2.0, 3.0, 4.0 };
	double sum = 0;
	calculateSum(array1, arraySize, sum);


	int array2[] = { 1, 2, 3, 4 };
	int elem = 3;
	find(array2, arraySize, elem);
}