//2824. Count Pairs Whose Sum is Less than Target

/*
* Given a 0-indexed integer array nums of length n and an integer target, 
* return the number of pairs (i, j) where 0 <= i < j < n and nums[i] + nums[j] < target.
*/

#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
    int countPairs(std::vector<int>& nums, int target) {
        int result = 0;

    std:sort(nums.begin(), nums.end());

        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int summ = nums[left] + nums[right];
            if (summ < target) {
                result += right - left;     // count all these pairs at once
                left++; // move left pointer forward to find more pair
            }
            else {
                --right;    // summ too large, move right pointer left to reduce summ
            }
        }
        return result;
    }
};
