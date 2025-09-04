#pragma once

#include <list>
#include <vector>
#include <iostream>

class MyHash {
private:
	size_t bucket_count; ; // Size of the hash table
	std::vector<std::list<int>> table;  // Array of lists for chaining

public: 
	MyHash(size_t size);
	void insert(int key);	
	void erase(int key);	
	bool contains(int key);
	void printTable();
};