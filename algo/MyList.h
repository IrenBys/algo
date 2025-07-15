#pragma once

class List
{
public:
    List() : head(nullptr), tail(nullptr), size(0) {};
              
    void push_front(int value);             
    void pop_front();   
    void insert(size_t index, int value);
    void remove(size_t index);
    void push_back();
    void pop_back();

    int front();                   
    int back();                    
private:
    struct Node {
        int data;
        Node* next;
    };

    Node* head;
    Node* tail;
    size_t size;
};
