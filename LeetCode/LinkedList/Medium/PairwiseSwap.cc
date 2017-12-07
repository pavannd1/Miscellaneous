/*
 * Given a linked list, swap every two adjacent nodes and return its head.
 * For example,
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
 * Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
 */

#include <iostream>

using namespace std;

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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        auto prev = head;
        auto curr = head->next;
        
        head = curr;
        
        while (true) {
            auto next = curr->next;
            curr->next = prev;
            
            if (next == NULL || next->next == NULL) {
                prev->next = next;
                break;
            }
            
            prev->next = next->next;
            
            prev = next;
            curr = prev->next;  
        }
        return head;
    }
};
