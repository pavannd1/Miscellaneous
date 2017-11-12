/*
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 * The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 */

#include <iostream>
#include <map>
#include <stack>

class Solution {
public:
    bool isValid(string s) {
        map<char,char> dict;
        dict['('] = ')';
        dict['['] = ']';
        dict['{'] = '}';
        stack<char> st;
        for (char &c : s) {
            if (dict.find(c) != dict.end()) {
                st.push(c);
            } else if (st.empty() || dict[st.top()] != c) {
                return false;
            } else {
                st.pop();
            }
        }
        return st.empty();
    }
};
