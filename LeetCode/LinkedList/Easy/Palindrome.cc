/**
 * Given a linked list, determine if it is a palindrome.
 */

#include <iostream>
#include <stack>

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
    // Reverse a linked list
    ListNode* reverse(ListNode* head) {
        auto curr = head;
        ListNode* prev = NULL;
        
        while (curr) {
            auto next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    // Using reverse method
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return true;
        }
        auto slow = head;
        auto fast = head;
        // Move to the middle
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // Reverse the second half
        slow->next = reverse(slow->next);
        // Compare the halves
        slow = slow->next;
        fast = head;
        while (slow && fast) {
            if (fast->val != slow->val) {
                return false;
            }
            slow = slow->next;
            fast = fast->next;
        }
        return true;
    }
    
    // Stack method
    bool isPalindromeStack(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return true;
        }
        // Push the elements into a stack
        stack<ListNode*> s;
        auto curr = head;
        while (curr) {
            s.push(curr);
            curr = curr->next;
        }
        // Compare list and stack
        curr = head;
        while (!s.empty()) {
            if (curr->val != s.top()->val) {
                return false;
            }
            s.pop();
            curr = curr->next;
        }
        return true;
    }
};
