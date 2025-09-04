#include "MyHash.h"
#include <iostream>
#include <stdexcept> 

MyHash::MyHash(size_t size) : bucket_count(size), table(size) {}

void MyHash::insert(int key) {
	size_t index = std::hash<int>{}(key) % bucket_count;

	for (int val : table[index]) {	
		if (val == key) {
			return; // Key already exists
		}
	}

	table[index].push_back(key);	// Insert key	
}

void MyHash::erase(int key) {
	size_t index = std::hash<int>{}(key) % bucket_count;
	table[index].remove(key); // Remove key if it exists	
}

bool MyHash::contains(int key) {
	size_t index = std::hash<int>{}(key) % bucket_count;
	for (int val : table[index]) {
		if(val == key) {
			return true; // Key found
		}
	}
	return false;
}

void MyHash::printTable() {
	for (int i = 0; i < bucket_count; i++) {
		std::cout << i << ": ";
		for (int val : table[i]) {
			std::cout << val << " -> ";
		}
		std::cout << "nullptr" << std::endl;
	}
}

