// https://leetcode.com/problems/reverse-linked-list/
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

// Iterative solution

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *pre = NULL;
        while(head != NULL){
            auto next = head -> next;
            head -> next = pre;
            pre = head;
            head = next;
        }
        
        return pre;
    }
};

// Recursive solution

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head -> next)
            return head;
        
        ListNode* p = reverseList(head -> next);
        
        head -> next -> next = head;
        head -> next = NULL;
        return p;
    }
};
