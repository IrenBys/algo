#pragma once
#include "MyVector.h"
#include <assert.h>

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