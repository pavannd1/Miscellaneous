/**
 * Given a binary tree, return the zigzag level order traversal of its nodes' values.
 * (ie, from left to right, then right to left for the next level and alternate between).
 * Example:
 *   3
 *  / \
 * 9  20
 *   /  \
 *  15   7
 * Output:
 * [
 * [3],
 * [20,9],
 * [15,7]
 * ]
 *
 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL) {
            return res;
        }

        // Two stacks method
        // S1 will have nodes from left to right
        // S2 will have nodes from right to left
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        
        // Push root
        s1.push(root);
        
        while (!s1.empty() || !s2.empty()) {
            vector<int> row1;
            // Right to left
            while (!s1.empty()) {
                auto node = s1.top();
                s1.pop();
                row1.push_back(node->val);
                if (node->left) {
                    s2.push(node->left);
                }
                if (node->right) {
                    s2.push(node->right);
                }
            }
            // Push into the result
            if (!row1.empty()) {
                res.push_back(row1);   
            }
            
            vector<int> row2;
            // Left to right
            while (!s2.empty()) {
                auto node = s2.top();
                s2.pop();
                row2.push_back(node->val);
                if (node->right) {
                    s1.push(node->right);
                }
                if (node->left) {
                    s1.push(node->left);
                }
            }
            // Push into the result
            if (!row2.empty()) {
                res.push_back(row2);
            }
        }
        return res;
    }
};
