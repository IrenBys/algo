#pragma once


class MyHash {
private:
	static const int TABLE_SIZE = 10; // Size of the hash table
	int table[TABLE_SIZE];	// The hash table
	bool used[TABLE_SIZE];	// To track used slots

	// Hash function
	int hashFunction(int key) {
		return key % TABLE_SIZE;
	}

public: 
	MyHash();	
	void insert(int key);	
	void erase(int key);	
	bool contains(int key);
	void printTable();
};