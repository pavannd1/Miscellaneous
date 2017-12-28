/**
 * Given a linked list, remove the nth node from the end of list and return its head.
 * For example,
 * Given linked list: 1->2->3->4->5, and n = 2.
 * After removing the second node from the end, the linked list becomes 1->2->3->5.
 * Note:
 * Given n will always be valid.
 * Try to do this in one pass.
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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL) {
            return NULL;
        }
        ListNode** slow = &head;
        auto fast = head;
        // Move fast n nodes ahead
        for (int i = 1; i < n; i++) {
            if (fast == NULL) {
                return NULL;
            }
            fast = fast->next;
        }
        // Move slow and fast at same pace
        while (fast && fast->next) {
            fast = fast->next;
            slow = &((*slow)->next);
        }
        // Delete the node
        ListNode* del = *slow;
        *slow = (*slow)->next;
        
        if (del) {
            delete del;
        }
        
        return head;
    }
};
