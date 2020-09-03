/**
*You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

*You may assume the two numbers do not contain any leading zero, except the number 0 itself.

*Example:

*Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
*Output: 7 -> 0 -> 8
*Explanation: 342 + 465 = 807.
**/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode();
        
        ListNode* dummy = ans;
        
        int carry = 0;
        
        while(l1 || l2 || carry){
            int x = (l1!=NULL) ? l1->val : 0;
            int y = (l2!=NULL) ? l2->val : 0;
            int sum = carry + x + y;
            carry = sum / 10;
            ans->next = new ListNode(sum % 10);
            ans = ans->next;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        
        // if(carry > 0)
        //     ans->next = new ListNode(carry);
        
        return dummy->next;
    }
};
