#pragma once

#include <iostream>
#include <assert.h>

class Vector
{
public:
    Vector() : data(nullptr), capacity(0), size(0) {}

    Vector(size_t n) : capacity(n), size(n) {
        data = new int[n];       
    }

    ~Vector() {
        delete[] data;
    }

    int& operator[](size_t index) {
       return data[index];
    }

    void insert(size_t index, int value) {
        
        if (index > size) return;

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

    void remove(size_t index) {
        if (index >= size) return; 

        // Сдвигаем элементы после index влево на 1
        for (size_t i = index; i + 1 < size; ++i) {
            data[i] = data[i + 1];
        }
        --size;
    }

    void push_back(int value) {
        // Если памяти не хватает, выделяем новую, в 2 раза больше
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

    void pop_back() {
        if (size > 0) {
            --size;
        }
    }

    size_t vec_size() const {
        return size;
    }

private:
	int* data;
	size_t size;
	size_t capacity;
};


void test_size() {
    Vector v;
    assert(v.vec_size() == 0);
    std::cout << "Test vec_size passed\n";
}

void test_insert() {
    Vector v;
    v.insert(0, 1);
    assert(v[0] == 1);
    std::cout << "Test insert passed\n";
}

void test_remove() {
    Vector v;
    v.push_back(2);
    v.push_back(3);
    v.remove(0);
    assert(v.vec_size() == 1);
    assert(v[0] == 3);
    std::cout << "Test remove passed\n";
}

void test_push_back() {
    Vector v;
    v.push_back(2);
    assert(v[0] == 2);
    std::cout << "Test push_back passed\n";
}

void test_pop_back() {
    Vector v;
    v.push_back(2);
    v.push_back(3);
    v.pop_back();
    assert(v.vec_size() == 1);
    assert(v[0] == 2);
    std::cout << "Test pop_back passed\n";
}
