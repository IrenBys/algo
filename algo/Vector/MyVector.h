#pragma once

class Vector
{
public:
    Vector();
    Vector(size_t n);
    ~Vector();

    int& operator[](size_t index);

    void insert(size_t index, int value);
    void remove(size_t index);
    void push_back(int value);
    void pop_back();

    size_t vec_size() const;

private:
    int* data;
    size_t size;
    size_t capacity;
};
