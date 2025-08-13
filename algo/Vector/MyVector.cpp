/*/#include "MyVector.h"
#include <iostream>

Vector::Vector() : data(nullptr), capacity(0), size(0) {}

Vector::Vector(size_t n) : capacity(n), size(n) {
    data = new int[n];
}

Vector::~Vector() {
    delete[] data;
}

int& Vector::operator[](size_t index) {
    if (index >= size) {
        throw std::out_of_range("Index out of range in operator[]");
    }

    return data[index];
}

void Vector::insert(size_t index, int value) {
    if (index > size) {
        throw std::out_of_range("Insert index out of range");
    }

    if (size == capacity) {
        size_t new_capacity;

        if (capacity == 0) {
            new_capacity = 1;
        }
        else {
            new_capacity = capacity * 2;
        }

        int* new_data = new int[new_capacity];

        for (size_t i = 0; i < index; ++i) {
            new_data[i] = data[i];
        }

        for (size_t i = index; i < size; ++i) {
            new_data[i + 1] = data[i];
        }

        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }
    else {
        for (size_t i = size; i > index; --i) {
            data[i] = data[i - 1];
        }
    }
    data[index] = value;
    ++size;
}

void Vector::remove(size_t index) {
    if (index >= size) {
        throw std::out_of_range("Remove index out of range");
    }

    for (size_t i = index; i + 1 < size; ++i) {
        data[i] = data[i + 1];
    }
    --size;
}

void Vector::push_back(int value) {
    if (size == capacity) {
        size_t new_capacity;
        if (capacity == 0) {
            new_capacity = 1;
        }
        else {
            new_capacity = capacity * 2;
        }

        int* new_data = new int[new_capacity];

        for (size_t i = 0; i < size; ++i) {
            new_data[i] = data[i];
        }

        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }

    data[size] = value;
    ++size;
}

void Vector::pop_back() {
    if (size == 0) {
        throw std::underflow_error("Cannot pop_back from empty vector");
    }

    --size;
}

size_t Vector::vec_size() const {
    return size;
}*/
