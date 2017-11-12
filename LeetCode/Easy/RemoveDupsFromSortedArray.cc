/*
 * Given a sorted array, remove the duplicates in-place such that each element appear only once and return the new length.
 * Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
 * Example:
 *  Given nums = [1,1,2],
 *  Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
 *  It doesn't matter what you leave beyond the new length.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {       
        if (nums.size() == 0) {
            return 0;
        }
        
        int j = 0;
        for (auto i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[j]) {
                j++;
                nums[j] = nums[i];
            }
        }
        
        return (j+1);
    }
};
