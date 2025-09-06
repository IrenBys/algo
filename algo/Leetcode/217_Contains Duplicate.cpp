// 217. Contains Duplicate

/*
* Given an integer array nums, return true if any value appears at least twice in the array, 
* and return false if every element is distinct.
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_map<int, int> table;

        for (int i = 0; i < nums.size(); i++) {
			if (table.find(nums[i]) != table.end()) {   // Check if the number is already in the map
                return true;
            }
			table[nums[i]] = i; // Store the index of the number
        }
        return false;
    }
};


