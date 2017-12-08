/**
 * Given a non-empty array of integers, return the third maximum number in this array.
 * If it does not exist, return the maximum number. The time complexity must be in O(n).
 * Example 1:
 * Input: [3, 2, 1]
 * Output: 1
 * Explanation: The third maximum is 1.
 *
 * Example 2:
 * Input: [1, 2]
 * Output: 2
 * Explanation: The third maximum does not exist, so the maximum (2) is returned instead.
 *
 * Example 3:
 * Input: [2, 2, 3, 1]
 * Output: 1
 * Explanation: Note that the third maximum here means the third maximum distinct number.
 * Both numbers with value 2 are both considered as second maximum.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int max1 = -1;
        int max2 = -1;
        int max3 = -1;
        for (auto ele : nums) {
            if (ele == max1 || ele == max2 || ele == max3) continue;
            if (max1 == -1 || ele > max1) {
                max3 = max2;
                max2 = max1;
                max1 = ele;
            } else if (max2 == -1 || ele > max2) {
                max3 = max2;
                max2 = ele;
            } else if (max3 == -1 || ele > max3) {
                max3 = ele;
            }
        }
        return max3 == -1 ? max1 : max3;
    }
};
