// https://leetcode.com/problems/remove-nth-node-from-end-of-list/
/*
Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

Given n will always be valid.

Follow up:

Could you do this in one pass?
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// Two pass algorithm
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(n==0) return head;
        int count = 0;
        ListNode *temp = head;
        while(temp!=NULL){
            temp=temp->next;
            ++count;
        }
        temp = head;
        n = count-n+1;
        if(n<=1){
            ListNode *t = temp;
            temp = temp->next;
            delete t;
            return temp;
        }
        else{
            ListNode *prev = NULL;
            while(n>1){
                prev = temp;
                temp=temp->next;
                --n;
            }
            ListNode *t = prev->next;
            prev->next = temp->next;
            delete t;
            return head;
        }
    }
};

// One pass algorithm
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
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode *slow = dummy, *fast = dummy;
        for(int i=0;i<n+1;++i)
            fast = fast->next;
    
        while(fast!=NULL){
            slow = slow->next;
            fast = fast->next;
        }
        
        ListNode *temp = slow->next;
        slow->next = slow->next->next;
        delete temp;
        return dummy->next;
    }
};