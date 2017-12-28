/**
 * Write a program to find the node at which the intersection of two singly linked lists begins.
 * For example, the following two linked lists:
 * A:          a1 → a2
 *                   ↘
 *                    c1 → c2 → c3
 *                   ↗            
 * B:     b1 → b2 → b3
 * begin to intersect at node c1.
 * 
 * Notes:
 * 1. If the two linked lists have no intersection at all, return null.
 * 2. The linked lists must retain their original structure after the function returns.
 * 3. You may assume there are no cycles anywhere in the entire linked structure.
 * 4. Your code should preferably run in O(n) time and use only O(1) memory.
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
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // Length of the first list
        auto curr = headA;
        int countA = 0;
        while (curr) {
            countA++;
            curr = curr->next;
        }
        // Length of the second list
        curr = headB;
        int countB = 0;
        while (curr) {
            countB++;
            curr = curr->next;
        }
        // Difference between lengths
        int diff = (countA > countB) ? (countA - countB) : (countB - countA);
        auto big = (countA > countB) ? headA : headB;
        auto small = (big == headA) ? headB : headA;
        
        // Move long until difference
        for (auto i = 0; i < diff; i++) {
            big = big->next;
        }
        
        // Compare both the lists for intersection
        while (big && small) {
            if (big == small) {
                return big;
            }
            big = big->next;
            small = small->next;
        }
        
        return nullptr;
    }
};
