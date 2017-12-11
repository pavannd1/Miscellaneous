/**
 * Given a binary tree, return the postorder traversal of its nodes' values.
 * For example:
 * 1
 *  \
 *   2
 *  /
 * 3
 * Output: [3, 2, 1]
 * Iterative solution.
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == NULL) {
            return res;
        }
        
        stack<TreeNode*> s;
        // Push root into the first stack
        s.push(root);
        
        // Iterate through the first stack and fill the result
        while (!s.empty()) {
            auto node = s.top();
            s.pop();
            // Push front to the result
            res.insert(res.begin(), node->val);
            if (node->left) {
                s.push(node->left);
            }
            if (node->right) {
                s.push(node->right);
            }
        }
        return res;
    }
};
