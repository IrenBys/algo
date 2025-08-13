#pragma once

#include <vector>

class MyQueue {
private:
    int* data;          // массив данных
    size_t capacity;    // емкость
    size_t size;        // количество элементов
    size_t head;        // индекс начала
    size_t tail;        // индекс конца

public:
    MyQueue();
    MyQueue(size_t n);
    ~MyQueue();

    void push(int value);      // добавить в конец
    void pop();                // удалить из начала
    int& front();              // первый элемент
    int& back();               // последний элемент
    bool empty() const;        // проверка на пустоту
    size_t queue_size() const; // количество элементов
};

