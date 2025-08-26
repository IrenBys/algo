#include "MyHash.h"
#include <iostream>

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

	std::cout << "Hash table is full, cannot insert key: " << key << std::endl;
}




