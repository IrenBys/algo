#pragma once
#include <stdexcept> // для исключений
#include <cstddef>   // для size_t

template <typename T>
class List {
private:
    struct Node {
        T data;
        Node* next;
        Node* prev;
        Node(const T& value) : data(value), next(nullptr), prev(nullptr) {}
    };

    Node* head;
    Node* tail;
    size_t size;

public:
    List() : head(nullptr), tail(nullptr), size(0) {}
    ~List() { clear(); }

    void push_front(const T& value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        if (head) {
            head->prev = newNode;
        }
        else {
            tail = newNode;
        }
        head = newNode;
        ++size;
    }

    void push_back(const T& value) {
        Node* newNode = new Node(value);
        newNode->prev = tail;
        if (tail) {
            tail->next = newNode;
        }
        else {
            head = newNode;
        }
        tail = newNode;
        ++size;
    }

    void pop_front() {
        if (!head) throw std::underflow_error("Cannot pop_front from empty list");

        Node* temp = head;
        head = head->next;
        delete temp;
        if (head) {
            head->prev = nullptr;
        }
        else {
            tail = nullptr;
        }
        --size;
    }

    void pop_back() {
        if (!tail) throw std::underflow_error("Cannot pop_back from empty list");

        Node* temp = tail;
        tail = tail->prev;
        delete temp;
        if (tail) {
            tail->next = nullptr;
        }
        else {
            head = nullptr;
        }
        --size;
    }

    void insert(size_t index, const T& value) {
        if (index > size) throw std::out_of_range("Insert index out of range");

        if (index == 0) { push_front(value); return; }
        if (index == size) { push_back(value); return; }

        Node* nextNode = head;
        for (size_t i = 0; i < index; ++i) {
            nextNode = nextNode->next;
        }

        Node* prevNode = nextNode->prev;
        Node* newNode = new Node(value);
        newNode->next = nextNode;
        newNode->prev = prevNode;
        prevNode->next = newNode;
        nextNode->prev = newNode;
        ++size;
    }

    void remove(size_t index) {
        if (index >= size) throw std::out_of_range("Remove index out of range");

        if (index == 0) { pop_front(); return; }
        if (index == size - 1) { pop_back(); return; }

        Node* current = head;
        for (size_t i = 0; i < index; ++i) {
            current = current->next;
        }
        Node* prevNode = current->prev;
        Node* nextNode = current->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        delete current;
        --size;
    }

    T& front() {
        if (!head) throw std::underflow_error("List is empty");
        return head->data;
    }

    const T& front() const {
        if (!head) throw std::underflow_error("List is empty");
        return head->data;
    }

    T& back() {
        if (!tail) throw std::underflow_error("List is empty");
        return tail->data;
    }

    const T& back() const {
        if (!tail) throw std::underflow_error("List is empty");
        return tail->data;
    }

    size_t list_size() const { return size; }

    void clear() {
        while (head) {
            pop_front();
        }
    }
};
