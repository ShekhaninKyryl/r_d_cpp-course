#include "DynamicIntArray.h"

DynamicIntArray::DynamicIntArray()
{
	this->array = nullptr;
	this->size = 0;
}

DynamicIntArray::DynamicIntArray(std::size_t size)
{
	this->array = new int[size];
	this->size = size;
}

DynamicIntArray::DynamicIntArray(const DynamicIntArray& other)
{
	std::size_t originalSize = other.getSize();
	this->array = new int[originalSize];
	this->size = originalSize;


	for (std::size_t i = 0; i < originalSize; i++) {
		this->array[i] = other[i];
	}
}

DynamicIntArray::~DynamicIntArray()
{
	delete[] this->array;
}

DynamicIntArray& DynamicIntArray::operator=(const DynamicIntArray& other)
{
	if (this == &other) {
		return *this;
	}

	std::size_t originalSize = other.getSize();
	this->array = new int[originalSize];
	this->size = originalSize;


	for (std::size_t i = 0; i < originalSize; i++) {
		this->array[i] = other[i];
	}

	return *this;
}

int& DynamicIntArray::operator[](std::size_t index)
{
	return this->array[index];
}

const int& DynamicIntArray::operator[](std::size_t index) const
{
	return this->array[index];
}

void DynamicIntArray::setSize(std::size_t newSize)
{
	delete[] this->array;

	this->size = newSize;
	this->array = new int[newSize];
}

std::size_t DynamicIntArray::getSize() const
{
	return this->size;
}

void DynamicIntArray::clear()
{
	delete[] this->array;

	this->size = 0;
	this->array = nullptr;
}

bool DynamicIntArray::operator==(const DynamicIntArray& other)
{
	if (this->size != other.getSize()) return false;

	for (std::size_t i = 0; i < this->size; i++) {
		if (this->array[i] != other[i]) return false;
	}

	return true;
}

bool DynamicIntArray::operator!=(const DynamicIntArray& other)
{
	return !(*this==other);
}

void DynamicIntArray::push_back(int element)
{
	std::size_t newSize = this->getSize() + 1;
	int* newArray = new int[newSize];

	for (std::size_t i = 0; i < this->getSize(); i++) {
		newArray[i] = this->array[i];
	}

	newArray[newSize - 1] = element;
	delete[] this->array;

	this->array = newArray;
	this->size = newSize;
}
