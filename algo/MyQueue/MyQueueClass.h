#pragma once

#include <vector>

class MyQueueCl {
private:
    std::vector<int> data;

public:
    MyQueueCl() = default; // default constructor

    bool is_empty() const;       // check if empty
    std::size_t queue_size() const; // get number of elements

    int& front();             // access first element
    const int& front() const;

    int& back();              // access last element
    const int& back() const;

    void push_back(int value); // add element to the back
    void pop_front();          // remove element from the front
};

