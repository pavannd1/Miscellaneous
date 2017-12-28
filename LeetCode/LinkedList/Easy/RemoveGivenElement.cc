/**
 * Remove all elements from a linked list of integers that have value val.
 * Example:
 * Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
 * Return: 1 --> 2 --> 3 --> 4 --> 5
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
    // Using double pointers
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* *curr = &head;
        while((*curr) != NULL) {
            if ((*curr)->val == val) {
                *curr = (*curr)->next;
            } else {
                curr = &(*curr)->next;
            }
        }
        return head;
    }
    
    // Using recursion
    ListNode* removeElementsRecursion(ListNode* head, int val) {
        if (head == NULL) return NULL;
        head->next = removeElementsRecursion(head->next, val);
        if (head->val == val) {
            head = head->next;
        }
        return head;
    }
};
