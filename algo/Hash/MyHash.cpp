#include "MyHash.h"
#include <iostream>
#include <stdexcept> 

MyHash::MyHash() {
	for(int i = 0; i < TABLE_SIZE; i++) {
		table[i] = 0;
		used[i] = false;
	}
}

void MyHash::insert(int key) {
	int index = hashFunction(key);

	for (int i = 0; i < TABLE_SIZE; i++) {		// Linear probing
		int probeIndex = (index + i) % TABLE_SIZE;	// Wrap around the table
		
		// If an empty slot is found, insert the key
		if (!used[probeIndex]) {
			table[probeIndex] = key;
			used[probeIndex] = true;
			return;
		}

		if (used[probeIndex] && table[probeIndex] == key) { // Key already exists
			return;
		}
	}

	throw std::overflow_error("Hash table is full");
}

void MyHash::erase(int key) {
	int index = hashFunction(key);
	for (int i = 0; i < TABLE_SIZE; i++) {		// Linear probing
		int probeIndex = (index + i) % TABLE_SIZE;	// Wrap around the table
		
		if (!used[probeIndex]) { // Key not found
			return;
		}
		if (used[probeIndex] && table[probeIndex] == key) { // Key found
			used[probeIndex] = false; // Mark as deleted
			return;
		}
	}

	throw std::runtime_error("Key not found");
}

bool MyHash::contains(int key) {
	int index = hashFunction(key);
	for (int i = 0; i < TABLE_SIZE; i++) {		// Linear probing
		int probeIndex = (index + i) % TABLE_SIZE;	// Wrap around the table
		
		if (!used[probeIndex]) { // Key not found
			return false;
		}
		if (used[probeIndex] && table[probeIndex] == key) { // Key found
			return true;
		}
	}
	return false;
}

void MyHash::printTable() {
	for(int i = 0; i < TABLE_SIZE; i++) {
		if(used[i]) {
			std::cout << i << ": " << table[i] << std::endl;
		} else {
			std::cout << i << ": " << "empty" << std::endl;
		}
	}
}

