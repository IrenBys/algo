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

// 1470. Shuffle the Array
/*
* Given the array nums consisting of 2n elements in the form [x1,x2,...,xn,y1,y2,...,yn].
Return the array in the form [x1,y1,x2,y2,...,xn,yn].
*/
std::vector<int> shuffle(std::vector<int>& nums, int n) {
    for (int i = 1; i < n; ++i) {
        // позиция, куда надо вставить элемент из второй половины
        int insert_pos = 2 * i - 1;
        // индекс элемента из второй половины, который надо "вставить"
        int from_pos = n + i - 1;

        // "перекатываем" элемент в нужную позицию через последовательные свапы
        for (int j = from_pos; j > insert_pos; --j) {
            std::swap(nums[j], nums[j - 1]);
        }
    }
    return nums;
}