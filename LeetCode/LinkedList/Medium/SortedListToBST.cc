/**
 * Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
 * For this problem, a height-balanced binary tree is defined as a binary tree in which
 * the depth of the two subtrees of every node never differ by more than 1.
 *
 * Example:
 * Given the sorted linked list: [-10,-3,0,5,9],
 * One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:
 *       0
 *      / \
 *    -3   9
 *    /   /
 * -10  5
 *
 */

#include <iostream>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    // Recursive solution
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == NULL) return NULL;
        if (head->next == NULL) {
            return new TreeNode(head->val);
        }
        // Split list into two parts
        auto slow = head;
        auto fast = head;
        auto prev = head;
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = NULL;
        // Create the BST with middle node as the root
        auto res = new TreeNode(slow->val);
        res->left = sortedListToBST(head);
        res->right = sortedListToBST(slow->next);
        
        return res;
    }
};
