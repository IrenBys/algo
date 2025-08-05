// 349. Intersection of Two Arrays

/*
* Given two integer arrays nums1 and nums2, return an array of their intersection. 
* Each element in the result must be unique and you may return the result in any order.
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> result;
        int i = 0, j = 0;

        // Use two pointers to iterate over both sorted arrays
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                // If this is the first element or it's different from the last added,
                // add it to the result to avoid duplicates
                if (result.empty() || result.back() != nums1[i]) {
                    result.push_back(nums1[i]);
                }
                ++i;  // Move both pointers forward
                ++j;
            }
            else if (nums1[i] < nums2[j]) {
                ++i;  // Move i forward to catch up
            }
            else {
                ++j;  // Move j forward to catch up
            }
        }

        return result;
    }
};