/*
 * Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
 * For example, given the array [-2,1,-3,4,-1,2,1,-5,4], the contiguous subarray [4,-1,2,1] has the largest sum = 6.
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int currSum = 0;
        auto maxSoFar = nums[0];
        for (auto i = 0; i < nums.size(); i++) {
            currSum += nums[i];
            maxSoFar = max(maxSoFar, currSum);
            currSum = max(0, currSum);
        }
        return maxSoFar;
    }
};
