/*
 * Given a sorted linked list, delete all duplicates such that each element appear only once.
 * For example,
 * Given 1->1->2, return 1->2.
 * Given 1->1->2->3->3, return 1->2->3.
 */

#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) {
            return head;
        }
        ListNode* curr = head;
        ListNode* next;
        while (curr && curr->next) {
            next = curr->next;
            if (curr->val == next->val) {
                curr->next = next->next;
                next = curr->next;
            } else {
                curr = next;
            }
        }
        return head;
    }
};
