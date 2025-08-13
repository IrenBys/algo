#include "MyQueue.h" // для FIFOQueue
#include <stdexcept> // для std::out_of_range

MyQueue::MyQueue() = default;

bool MyQueue::empty() const {
    return data.empty();
}

std::size_t MyQueue::size() const {
    return data.size();
}

int& MyQueue::front() {
    if (empty()) {
        throw std::out_of_range("Queue is empty");
    }
    return data.front();
}

const int& MyQueue::front() const {
    if (empty()) {
        throw std::out_of_range("Queue is empty");
    }
    return data.front();
}

int& MyQueue::back() {
    if (empty()) {
        throw std::out_of_range("Queue is empty");
    }
    return data.back();
}

const int& MyQueue::back() const {
    if (empty()) {
        throw std::out_of_range("Queue is empty");
    }
    return data.back();
}

void MyQueue::push_back(int value) {
    data.push_back(value);
}

void MyQueue::pop_front() {
    if (empty()) {
        throw std::out_of_range("Queue is empty");
    }
    data.erase(data.begin());
}
