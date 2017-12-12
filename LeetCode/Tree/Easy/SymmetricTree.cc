/**
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
 * Example 1:
 *     1
 *    / \
 *   2   2
 *  / \ / \
 * 3  4 4  3
 * Output: True.
 * Example 2:
 *    1
 *   / \
 *  2   2
 *   \   \
 *    3    3
 * Output: False.
 */

#include <iostream>
#include <queue>

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
    // Iterative solution
    bool isSymmetricIterative(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        
        while (!q.empty()) {
            auto left = q.front();
            q.pop();
            auto right = q.front();
            q.pop();
            if (left == NULL && right == NULL) {
                continue;
            } else if (left == NULL || right == NULL) {
                return false;
            }
            if (left->val != right->val) {
                return false;
            }
            q.push(left->left);
            q.push(right->right);
            q.push(left->right);
            q.push(right->left);
        }
        return true;
    }
    // Recursive solution
    bool isSymmetricHelper(TreeNode* left, TreeNode* right) {
        if (left == NULL && right == NULL) {
            return true;
        } else if (left == NULL || right == NULL) {
            return false;
        }
        if (left->val != right->val) return false;
        
        return isSymmetricHelper(left->left, right->right) && isSymmetric(left->right, right->left);
    }
    bool isSymmetricRecursive(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        return isSymmetricHelper(root->left, root->right);
    }
};
