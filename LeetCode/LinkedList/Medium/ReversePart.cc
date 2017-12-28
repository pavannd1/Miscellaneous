/**
 * Reverse a linked list from position m to n. Do it in-place and in one-pass.
 * For example:
 * Given 1->2->3->4->5->NULL, m = 2 and n = 4,
 * return 1->4->3->2->5->NULL.
 *
 * Note:
 * Given m, n satisfy the following condition:
 * 1 ≤ m ≤ n ≤ length of list.
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode newHead(-1);
        newHead.next = head;
        ListNode* prev = &newHead;
        for (int i = 0; i < m - 1; i++) {
            prev = prev->next;
        }
        auto curr = prev->next;
        for (int i = 0; i < n - m; i++) {
            auto next = curr->next;
            curr->next = next->next;
            next->next = prev->next;
            prev->next = next;
        }
        return newHead.next;
    }
};
