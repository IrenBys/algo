#include "MyQueueClass.h" // для FIFOQueue
#include <stdexcept> // для std::out_of_range

MyQueueCl::MyQueueCl() = default;

bool MyQueueCl::is_empty() const {
    return data.empty();
}

std::size_t MyQueueCl::queue_size() const {
    return data.size();
}

int& MyQueueCl::front() {
    if (is_empty()) {
        throw std::out_of_range("Queue is empty");
    }
    return data.front();
}

const int& MyQueueCl::front() const {
    if (is_empty()) {
        throw std::out_of_range("Queue is empty");
    }
    return data.front();
}

int& MyQueueCl::back() {
    if (is_empty()) {
        throw std::out_of_range("Queue is empty");
    }
    return data.back();
}

const int& MyQueueCl::back() const {
    if (is_empty()) {
        throw std::out_of_range("Queue is empty");
    }
    return data.back();
}

void MyQueueCl::push_back(int value) {
    data.push_back(value);
}

void MyQueueCl::pop_front() {
    if (is_empty()) {
        throw std::out_of_range("Queue is empty");
    }
    data.erase(data.begin());
}
