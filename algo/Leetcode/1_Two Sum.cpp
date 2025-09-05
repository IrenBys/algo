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
			int search = target - nums[i];  // Calculate the complement

            if (table.count(search)) {  // Check if the complement exists in the map
                return {table[search], i};  // Return the indices of the two numbers
			}
			table[nums[i]] = i;  // Store the number and its index in the map                
        }

		return {};  // Return an empty vector if no solution is found
    }
};