#pragma once

#include <assert.h>
#include <iostream>
#include "MyQueue.h"

void test_queue_size() {
    MyQueue q;
    assert(q.queue_size() == 0);
    std::cout << "Test queue_size passed\n";
}

void test_push() {
    MyQueue q;
    q.push(10);
    assert(q.front() == 10);
    assert(q.back() == 10);
    std::cout << "Test push passed\n";
}

void test_pop() {
    MyQueue q;
    q.push(10);
    q.push(20);
    q.pop();
    assert(q.queue_size() == 1);
    assert(q.front() == 20);
    std::cout << "Test pop passed\n";
}

void test_front_back() {
    MyQueue q;
    q.push(1);
    q.push(2);
    q.push(3);
    assert(q.front() == 1);
    assert(q.back() == 3);
    std::cout << "Test front/back passed\n";
}

void test_wraparound() {
    MyQueue q(3);
    q.push(1);
    q.push(2);
    q.push(3);
    q.pop();
    q.push(4);
    assert(q.front() == 2);
    assert(q.back() == 4);
    std::cout << "Test wraparound passed\n";
}