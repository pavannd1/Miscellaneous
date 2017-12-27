/*
 * Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0?
 * Find all unique triplets in the array which gives the sum of zero.
 * Note: The solution set must not contain duplicate triplets.
 * For example, given array S = [-1, 0, 1, 2, -1, -4]
 * A solution set is:
 * [
 * [-1, 0, 1],
 * [-1, -1, 2]
 * ]
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        std::sort(nums.begin(), nums.end());
        for (auto i = 0; i < (int)nums.size() - 1; i++) {
            auto target = 0 - nums[i];
            auto start = i + 1;
            auto end = nums.size() - 1;
            if (target < 0) {
                break;
            }
            while (start < end) {
                auto sum = nums[start] + nums[end];
                if (sum < target) {
                    start++;
                } else if (sum > target) {
                    end--;
                } else {
                    vector<int> temp = {nums[i], nums[start], nums[end]};
                    res.push_back(temp);
                    
                    while (start < end && nums[start] == temp[1]) start++;
                    while (start < end && nums[end] == temp[2]) end--;
                }
            }    
            while (i + 1 < nums.size() && nums[i + 1] == nums[i]) i++;
        }    
        return res;
    }
};
