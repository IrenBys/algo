#include "MyList.h"
#include <iostream>
#include <cassert> 

void List::push_front(int value) {
	Node* newNode = new Node;
	newNode->data = value;
	newNode->next = head;
	newNode->prev = nullptr;
	
	// если не пуст
	if (head != nullptr) {
		head->prev = newNode;
	}
	else {
		tail = newNode;
	}

	head = newNode;
	++size;
}

void List::push_back(int value) {
	Node* newNode = new Node;
	newNode->data = value;
	newNode->next = nullptr;
	newNode->prev = tail;

	// список не пуст
	if (tail != nullptr) {
		tail->next = newNode;
	}
	else {
		head = newNode;
	}

	tail = newNode;
	++size;
}

void List::pop_front() {
	assert(head != nullptr && "Cannot pop_front from empty list");

	Node* temp = head;
	head = head->next;
	delete temp;

	// после удаления элемента список пустой
	if (head == nullptr) {
		tail = nullptr;
	}
	else {
		head->prev = nullptr; //обнуляем prev у новой головы
	}
	--size;
}

void List::pop_back() {
	assert(tail != nullptr && "Cannot pop_back from empty list");

	Node* temp = tail; //Сохраняем указатель на последний узел

	if (head == tail) {
		head = nullptr;
		tail = nullptr;
	}
	else {
		// если несколько
		tail = tail->prev;
		tail->next = nullptr;
	}

	delete temp;
	--size;
}

void List::insert(size_t index, int value) {
	assert(index <= size && "Insert index out of range");

	if (index == 0) {
		push_front(value);
		return;
	}

	if (index == size) {
		push_back(value);
		return;
	}

	// ищем узел, который перед индексом
	Node* nextNode = head;
	for (size_t i = 0; i < index; ++i) {
		nextNode = nextNode->next;
	}

	// предыдуший узел (будем вставлять между ними)
	Node* prevNode = nextNode->prev;

	// новый узел, который нужно вставить
	Node* newNode = new Node;
	newNode->data = value;
	newNode->next = nextNode;  
	newNode->prev = prevNode;		

	// обновляем указатели элементов до и после вставки
	prevNode->next = newNode;
	nextNode->prev = newNode;
	
	++size;
}


void List::remove(size_t index) {
	assert(index < size && "Remove index out of range");

	if (index == 0) {
		pop_front();
		return;
	}

	if (index == size - 1) {
		pop_back();
		return;
	}

	// узел который нужно удалить
	Node* current = head;
	for (size_t i = 0; i < index; ++i) {
		current = current->next;
	}

	// соседи
	Node* prevNode = current->prev;
	Node* nextNode = current->next;

	// пересохраним у них указатели
	prevNode->next = nextNode;
	nextNode->prev = prevNode;

	delete current;
	--size;
}


int List::front() const {
	assert(head != nullptr && "List is empty (front)");
	return head->data;
}

int List::back() const {
	assert(tail != nullptr && "List is empty (back)");
	return tail->data;
}

size_t List::list_size() const {
	return size;
}

