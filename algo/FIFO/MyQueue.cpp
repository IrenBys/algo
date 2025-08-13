#include "MyQueue.h" // для FIFOQueue
#include <stdexcept> // для std::out_of_range

MyQueue::MyQueue()
    : data(nullptr), capacity(0), size(0), head(0), tail(0) {
}

MyQueue::MyQueue(size_t n)
    : capacity(n), size(0), head(0), tail(0) {
    data = new int[n];
}

MyQueue::~MyQueue() {
    delete[] data;
}

void MyQueue::push(int value) {
    if (size == capacity) {
        size_t new_capacity = (capacity == 0) ? 1 : capacity * 2; // выделяем новый массив в 2 раза больше
        int* new_data = new int[new_capacity];

        for (size_t i = 0; i < size; ++i) {
			new_data[i] = data[(head + i) % capacity]; // копируем элементы из старого массива в новый по кольцу
        }

		// Освобождаем старый массив и переназначаем указатели
        delete[] data;
        data = new_data;
        capacity = new_capacity;
        head = 0;
        tail = size;
    }

    data[tail] = value;
	tail = (tail + 1) % capacity; // двигаем tail на один вперёд по модулю от capacity
    ++size;
}

void MyQueue::pop() {
    if (size == 0) {
        throw std::underflow_error("Cannot pop from empty queue");
    }
    head = (head + 1) % capacity; //  сдвигаем head вперёд на 1 по модулю от capacity
    --size;
}

int& MyQueue::front() {
    if (size == 0) {
        throw std::underflow_error("Queue is empty");
    }
	return data[head]; // возвращаем первый элемент, который находится в head
}

int& MyQueue::back() {
    if (size == 0) {
        throw std::underflow_error("Queue is empty");
    }
	return data[(tail + capacity - 1) % capacity]; // возвращаем последний элемент, который находится перед tail
}

bool MyQueue::empty() const {
    return size == 0;
}

size_t MyQueue::queue_size() const {
    return size;
}
