/*
 * Given a 32-bit signed integer, reverse digits of an integer.
 * Example 1:
 *  Input: 123
 *  Output: 321
 * Example 2:
 *  Input: -123
 *  Output: -321
 * Example 3:
 *  Input: 120
 *  Output: 21
 * Note:
 * Assume we are dealing with an environment which could only hold integers within the 32-bit signed integer range.
 * For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
 */

#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        long long rev = 0;
        while (x) {
            rev = (rev * 10) + (x % 10);
            x = x / 10;
        }
        
        return (rev < INT_MIN || rev > INT_MAX) ? 0 : rev;
    }
};
