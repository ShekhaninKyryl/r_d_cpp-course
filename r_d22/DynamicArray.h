#pragma once
#include <cstdlib>

template<class T>
class DynamicIntArray
{
public:
    //default c-tor
    DynamicIntArray() {
        this->array = nullptr;
        this->size = 0;
        this->capacity = 0;
    };

    //c-tor with size
    DynamicIntArray(std::size_t size) {
        this->array = new T[size];
        this->size = size;
        this->capacity = size + size / 2;
    };

    //copy c-tor
    DynamicIntArray(const DynamicIntArray<T>& other) {
        std::size_t originalSize = other.getSize();
        this->array = new T[originalSize];
        this->size = originalSize;
        this->capacity = other.capacity;

        for (std::size_t i = 0; i < originalSize; i++) {
            this->array[i] = other[i];
        }
    };

    //free allocated memory
    ~DynamicIntArray() {
        delete[] this->array;
    };

    DynamicIntArray<T>& operator=(const DynamicIntArray<T>& other) {
        if (this == &other) {
            return *this;
        }

        delete[] this->array;

        std::size_t originalSize = other.getSize();
        this->array = new T[originalSize];
        this->size = originalSize;
        this->capacity = other.capacity;

        for (std::size_t i = 0; i < originalSize; i++) {
            this->array[i] = other[i];
        }

        return *this;
    };

    T& operator[](std::size_t index) {
        return this->array[index];
    };
    const T& operator[](std::size_t index) const {
        return this->array[index];
    };

    //delete previous memory, create new inner array with updated size
    void setSize(std::size_t newSize) {
        delete[] this->array;

        this->size = newSize;
        this->capacity = size + size / 2;
        this->array = new T[newSize];
    };
    std::size_t getSize() const {
        return this->size;
    };

    //Clear internal memory, set size to 0
    void clear() {
        delete[] this->array;

        this->size = 0;
        this->capacity = 0;
        this->array = nullptr;
    };

    bool operator==(const DynamicIntArray<T>& other) const {
        if (this->size != other.getSize()) return false;

        for (std::size_t i = 0; i < this->size; i++) {
            if (this->array[i] != other[i]) return false;
        }

        return true;
    }
    bool operator!=(const DynamicIntArray<T>& other) const {
        return !(*this == other);
    };

    // Allocate new memory for new element
    // Copy old content to new inner array
    // insert element at the last index
    // update size
    void push_back(T element) {
        std::size_t newSize = this->getSize() + 1;

        if (this->capacity < newSize) {
            std::size_t newCapacity = this->capacity == 0 ? 1 : this->capacity * 1.5;
            T* newArray = new T[newCapacity];

            for (std::size_t i = 0; i < this->getSize(); i++) {
                newArray[i] = this->array[i];
            }

            delete[] this->array;
            this->array = newArray;
            this->capacity = newCapacity;
        }

        this->array[this->size] = element;
        this->size = newSize;
    };

    void reserve(std::size_t reservedSpace) {
        if (reservedSpace > this->capacity) {
            T* newArray = new T[reservedSpace];

            for (std::size_t i = 0; i < this->size; i++) {
                newArray[i] = this->array[i];
            }

            delete[] this->array;
            this->array = newArray;
            this->capacity = reservedSpace;
        }
    }

    std::size_t getCapacity() const {
        return this->capacity;
    }

    void shrinkToFit() {
        if (this->capacity > this->size) {
            T* newArray = new T[this->size];

            for (std::size_t i = 0; i < this->size; i++) {
                newArray[i] = this->array[i];
            }

            delete[] this->array;
            this->array = newArray;
            this->capacity = this->size;
        }
    }

    void pop_back() {
        if (this->size > 0) {
            this->size--;
        }
    }

    T back() const {
       return this->size == 0 ? nullptr : this->array[this->size - 1];
    }

private:
    std::size_t size;
    std::size_t capacity;
    T* array;
};
