#pragma once

#include <list>
#include <iostream>

class MyHash {
private:
	static const int TABLE_SIZE = 10; // Size of the hash table
	std::list<int> table[TABLE_SIZE]; // Array of lists for chaining

	// Hash function
	int hashFunction(int key) {
		return key % TABLE_SIZE;
	}

public: 
	MyHash() {};
	void insert(int key);	
	void erase(int key);	
	bool contains(int key);
	void printTable();
};