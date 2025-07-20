#include <vector>


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