#pragma once

#include <assert.h>
#include <iostream>
#include "MyHash.h"

void test_insert_and_contains() {
	MyHash hash;
	hash.insert(5);
	assert(hash.contains(5));	 // 5 was inserted
	assert(!hash.contains(100)); // 100 was not inserted
	std::cout << "test_insert_and_contains passed." << std::endl;
}

void test_erase() {
	MyHash hash;
	hash.insert(17);
	assert(hash.contains(17)); // 10 was inserted
	hash.erase(17);
	assert(!hash.contains(17)); // 10 was erased
	std::cout << "test_erase passed." << std::endl;
}

void test_printTable() {
	MyHash hash;
	hash.insert(1);
	hash.insert(2);
	hash.insert(3);
	std::cout << "Current hash table: ";
	hash.printTable(); // Should print the current state of the hash table
	std::cout << "test_printTable passed." << std::endl;
}

void collision_test() {
	MyHash hash;
	
	int x1 = 7; // 7 % 10 = 7
	int x2 = 17; // 17 % 10 = 7 (collision with 7)
	hash.insert(x1);
	hash.insert(x2); // Should handle collision

	// Both should be present
	assert(hash.contains(x1));
	assert(hash.contains(x2));

	// Erase one and check the other still exists
	hash.erase(x1);
	assert(!hash.contains(x1));
	assert(hash.contains(x2));
	std::cout << "collision_test passed." << std::endl;
}

