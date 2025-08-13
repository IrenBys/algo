#pragma once

#include <assert.h>
#include <iostream>
#include "MyQueue.h"

void test_empty_and_size() {
    MyQueue q;
    assert(q.empty());
    assert(q.size() == 0);
    std::cout << "Test empty and size passed\n";
}

void test_push_back_and_back() {
    MyQueue q;
    q.push_back(10);
    assert(!q.empty());
    assert(q.size() == 1);
    assert(q.back() == 10);
    std::cout << "Test push_back and back passed\n";
}

void test_front_and_back() {
    MyQueue q;
    q.push_back(1);
    q.push_back(2);
    q.push_back(3);
    assert(q.front() == 1);
    assert(q.back() == 3);
    std::cout << "Test front and back passed\n";
}

void test_pop_front() {
    MyQueue q;
    q.push_back(5);
    q.push_back(6);
    q.pop_front();
    assert(q.size() == 1);
    assert(q.front() == 6);
    std::cout << "Test pop_front passed\n";
}

void test_pop_front_until_empty() {
    MyQueue q;
    q.push_back(100);
    q.pop_front();
    assert(q.empty());
    std::cout << "Test pop_front until empty passed\n";
}

