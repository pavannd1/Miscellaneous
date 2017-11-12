/* 
 * Merge two sorted linked lists and return it as a new list.
 * The new list should be made by splicing together the nodes of the first two lists.
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) {
            return l2;
        } else if (l2 == NULL) {
            return l1;
        }
        
        ListNode* result = NULL;
        ListNode* curr = NULL;
        while (l1 && l2) {
            ListNode* node = NULL;
            if (l1->val < l2->val) {
                node = new ListNode(l1->val);
                l1 = l1->next;
            } else {
                node = new ListNode(l2->val);
                l2 = l2->next;
            }
            if (result == NULL) {
                result = node;
                curr = node;
            } else {
                curr->next = node;
                curr = node;
            }
        }
        
        while (l1) {
            ListNode* node = new ListNode(l1->val);
            curr->next = node;
            curr = node;
            l1 = l1->next;
        }
        
        while (l2) {
            ListNode* node = new ListNode(l2->val);
            curr->next = node;
            curr = node;
            l2 = l2->next;
        }
        return result;
    }
};
