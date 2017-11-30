/*
 * Given a string, sort it in decreasing order based on the frequency of characters.
 * Example 1:
 *  "tree" => "eetr"
 * Example 2:
 *  "cccaaa" => "cccaaa"
 * Example 3:
 *  "Aabb" => "bbAa
 */

#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        if (s.empty()) {
            return s;
        }
        map<char, int> count;
        vector<string> v(s.size() + 1, "");
        string res;
        
        // Store the frequencies in a map
        for (char c: s) {
            count[c]++;
        }
        
        // For each character in the map,
        // create a string with the frequency
        // and add it to a vector of strings
        for (auto &it : count) {
            v[it.second].append(it.second, it.first);
        }
        
        // Scan the vector in reverse order,
        // since we want the larger frequencies first
        for (int i = s.size(); i > 0; i--) {
            if (!v[i].empty()) {
                res.append(v[i]);
            }
        }
        return res;
    }
};
