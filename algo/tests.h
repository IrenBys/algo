#pragma once

#include <assert.h>
#include "MyVector.h"
#include "MyList.h"


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

// Список
void test_size_for_list() {
    List l;
    assert(l.list_size() == 0);
    std::cout << "test_size_for_list passed\n";
}

void test_push_front_for_list() {
    List l;
    l.push_front(10);
    assert(l.front() == 10);
    assert(l.list_size() == 1);
    std::cout << "test_push_front_for_list passed\n";
}

void test_push_back_for_list() {
    List l;
    l.push_back(20);
    assert(l.back() == 20);
    assert(l.list_size() == 1);
    std::cout << "test_push_back_for_list passed\n";
}

void test_pop_front_for_list() {
    List l;
    l.push_front(5);
    l.push_front(10); 
    l.pop_front();     
    assert(l.front() == 5);
    assert(l.list_size() == 1);
    std::cout << "test_pop_front_for_list passed\n";
}

void test_pop_back_for_list() {
    List l;
    l.push_back(1);
    l.push_back(2);  
    l.pop_back();    
    assert(l.back() == 1);
    assert(l.list_size() == 1);
    std::cout << "test_pop_back_for_list passed\n";
}

void test_insert_for_list() {
    List l;
    l.push_back(1);
    l.push_back(3);     
    l.insert(1, 2);      
    assert(l.list_size() == 3);
    l.remove(0);         
    assert(l.front() == 2);
    std::cout << "test_insert_for_list passed\n";
}

void test_remove_for_list() {
    List l;
    l.push_back(100);
    l.push_back(200);  
    l.remove(0);        
    assert(l.front() == 200);
    assert(l.list_size() == 1);
    std::cout << "test_remove_for_list passed\n";
}
