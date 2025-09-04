// 1. Two Sum

/*
* Problem Statement: Given an array of integers nums and an integer target, 
* return indices of the two numbers such that they add up to target.
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> table;

        for (int i = 0; i < nums.size(); ++i) {
			table[i] = nums[i]; // Store index and value in the hash table

			for (auto& pair : table) { // Iterate through the hash table
                int idx = pair.first;      
                int val = pair.second;

				if (idx != i && val + nums[i] == target) {  // Check if the sum equals the target
					return { idx, i };  // Return the indices if found
                }
            }
        }

		return {};  // Return an empty vector if no solution is found
    }
};