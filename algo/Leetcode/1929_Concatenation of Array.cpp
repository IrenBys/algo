#include <vector>

// 1929. Concatenation of Array

/*
* Given an integer array nums of length n, you want to create an array ans of length 2n
where ans[i] == nums[i] and ans[i + n] == nums[i] for 0 <= i < n (0-indexed).
Specifically, ans is the concatenation of two nums arrays.
Return the array ans.
*/

std::vector<int> getConcatenation(std::vector<int>& nums) {
    size_t n = nums.size();
    std::vector<int> ans(2 * n);

    for (int i = 0; i < n; ++i) {
        ans[i] = nums[i];
        ans[i + n] = nums[i];
    }
    return ans;
}