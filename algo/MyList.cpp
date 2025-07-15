#include "MyList.h"
#include <iostream>

void List::push_front(int value) {
	Node* newNode = new Node;
	newNode->data = value;
	newNode->next = head;

	head = newNode;

	// если список был пустой
	if (tail == nullptr) {
		tail = newNode;
	}

	++size;
}

void List::push_back(int value) {
	Node* newNode = new Node;
	newNode->data = value;
	newNode->next = nullptr;

	if (head == nullptr) {
		head = newNode;
		tail = newNode;
	}
	else {
		tail->next = newNode;
		tail = newNode; 
	}
	++size;
}

void List::pop_front() {
	if (head == nullptr) return;

	Node* temp = head;
	head = head->next;
	delete temp;

	if (head == nullptr) {
		tail = nullptr;
	}

	--size;
}

void List::pop_back() {
	if (head == nullptr) return;

	if (head == tail) {
		// если один элемент
		delete head;
		head = nullptr;
		tail = nullptr;
	}
	else {
		// если несколько
		Node* current = head;
		while (current->next != tail) {
			current = current->next;
		}

		delete tail;
		tail = current;
		tail->next = nullptr;
	}

	--size;
}

void List::insert(size_t index, int value) {
	if (index > size) return;

	if (index == 0) {
		push_front(value);
		return;
	}

	if (index == size) {
		push_back(value);
		return;
	}

	Node* current = head;
	for (size_t i = 0; i < index - 1; ++i) {
		current = current->next;
	}

	Node* newNode = new Node;
	newNode->data = value;
	newNode->next = current->next;
	current->next = newNode;

	++size;

}


void List::remove(size_t index) {
	if (index >= size) return;

	if (index == 0) {
		pop_front();
		return;
	}

	if (index == size - 1) {
		pop_back();
		return;
	}

	Node* current = head;
	for (size_t i = 0; i < index - 1; ++i) {
		current = current->next;
	}

	Node* toDelete = current->next;
	current->next = toDelete->next;
	delete toDelete;

	--size;
}


int List::front() {
	return head->data;
}

int List::back() {
	return tail->data;
}

size_t List::list_size() const {
	return size;
}

