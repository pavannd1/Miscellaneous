/**
 * The set S originally contains numbers from 1 to n.
 * But unfortunately, due to the data error, one of the numbers in the set got duplicated to another number in the set,
 * which results in repetition of one number and loss of another number.
 * Given an array nums representing the data status of this set after the error.
 * Your task is to firstly find the number occurs twice and then find the number that is missing.
 * Return them in the form of an array.
 * Example:
 * Input: nums = [1,2,2,4]
 * Output: [2,3]
 * NOTE:
 *  1. The given array size will in the range [2, 10000].
 *  2. The given array's numbers won't have any order.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> res;
        if (nums.size() == 0) {
            return res;
        }
        
        // Re-organize array to have nums[i] at i - 1
        for (int i = 0; i < nums.size(); i++) {
            while (nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        
        // If any number is not in that order,
        // that would be the repeated number.
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i + 1) {
                res.push_back(nums[i]);
                res.push_back(i + 1);
            }
        }
       
        return res;
    }
};
