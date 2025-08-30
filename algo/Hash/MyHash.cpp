#include "MyHash.h"
#include <iostream>
#include <stdexcept> 

void MyHash::insert(int key) {
	int index = hashFunction(key);

	for (int val : table[index]) {	
		if (val == key) {
			return; // Key already exists
		}
	}

	table[index].push_back(key);	// Insert key	
}

void MyHash::erase(int key) {
	int index = hashFunction(key);
	table[index].remove(key); // Remove key if it exists	
}

bool MyHash::contains(int key) {
	int index = hashFunction(key);
	for (int val : table[index]) {
		if(val == key) {
			return true; // Key found
		}
	}
	return false;
}

void MyHash::printTable() {
	for (int i = 0; i < TABLE_SIZE; i++) {
		std::cout << i << ": ";
		for (int val : table[i]) {
			std::cout << val << " -> ";
		}
		std::cout << "nullptr" << std::endl;
	}
}

