#pragma once

template <typename T>
class Vector
{
public:
    Vector();
    Vector(size_t n);
    ~Vector();

    T& operator[](size_t index);
    const T& operator[](size_t index) const;

    void insert(size_t index, const T& value);
    void remove(size_t index);
    void push_back(const T& value);
    void pop_back();

    size_t vec_size() const;

private:
    T* data;;
    size_t size;
    size_t capacity;
};

template <typename T>
Vector<T>::Vector() : data(nullptr), capacity(0), size(0) {}

template <typename T>
Vector<T>::Vector(size_t n) : capacity(n), size(n) {
    data = new T[n];;
}

template <typename T>
Vector<T>::~Vector() {
    delete[] data;
}


template<typename T>
T& Vector<T>::operator[](size_t index) {
    if (index >= size) {
        throw std::out_of_range("Index out of range in operator[]");
    }

    return data[index];
}

template<typename T>
const T& Vector<T>::operator[](size_t index) const {
    if (index >= size) {
        throw std::out_of_range("Index out of range in operator[]");
    }
    return data[index];
}

template<typename T>
void Vector<T>::insert(size_t index, const T& value) {
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

        T* new_data = new T[new_capacity];;

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

template<typename T>
void Vector<T>::remove(size_t index) {
    if (index >= size) {
        throw std::out_of_range("Remove index out of range");
    }

    for (size_t i = index; i + 1 < size; ++i) {
        data[i] = data[i + 1];
    }
    --size;
}

template<typename T>
void Vector<T>::push_back(const T& value) {
    if (size == capacity) {
        size_t new_capacity;
        if (capacity == 0) {
            new_capacity = 1;
        }
        else {
            new_capacity = capacity * 2;
        }

        T* new_data = new T[new_capacity];

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

template<typename T>
void Vector<T>::pop_back() {
    if (size == 0) {
        throw std::underflow_error("Cannot pop_back from empty vector");
    }

    --size;
}

template<typename T>
size_t Vector<T>::vec_size() const {
    return size;
}

