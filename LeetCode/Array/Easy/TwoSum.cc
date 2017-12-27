/*
 * Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 * Example:
 *  Given nums = [2, 7, 11, 15], target = 9,
 *  Because nums[0] + nums[1] = 2 + 7 = 9,
 *  return [0, 1].
 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> arr = {0,0};
        if (nums.size() == 0) {
            assert(false);
        }
        map<int,int> sum;
        for (auto i = 0; i < nums.size(); i++) {
            auto temp = target - nums[i];
            if (sum.find(temp) != sum.end()) {
                arr[0] = sum[temp];
                arr[1] = i;
                return arr;
            }
            sum[nums[i]] = i;
        }
        return arr;
    }
};
