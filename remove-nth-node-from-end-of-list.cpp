// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

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
 
// Two pass algorithm

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        int length = 0;
        ListNode* first = head;
        
        while(first){
            length++;
            first = first -> next;
        }
        
        length -= n;
        first = dummy;
        
        while(length){
            length--;
            first = first -> next;
        }
        
        ListNode* tmp = first -> next;
        first -> next = first -> next -> next;
        
        delete tmp;
        return dummy -> next;
    }
};

// One pass algorithm

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        ListNode *first = dummy, *second = dummy;
        
        while(n >= 0){
            first = first -> next;
            n--;
        }
        
        while(first){
            first = first -> next;
            second = second -> next;
        }
        
        ListNode* tmp = second -> next;
        second -> next = second -> next -> next;
        if(tmp)
            delete tmp;
        return dummy -> next;
    }
};

// Without dummy variable

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *first = head,  *second = head;
        
        while(n > 1){
            second = second -> next;
            n--;
        }
        
        ListNode* pre = NULL;
        
        while(second -> next){
            pre = first;
            first = first -> next;
            second = second -> next;
        }
        // when second will reach end, first will reach the pointer of the required element to be removed
        
        if(first == second && pre != NULL)   // first == second, when n =1 
            pre -> next = NULL;              // and pre != NULL, when Linked list contains only 1 element
        else if(pre == NULL)                 // pre == NULL for the case when we need to remove 1st element
            head = first -> next;
        else                                 // This is for normal cases
            pre -> next = first -> next;     // Only we need to change the pointer of previous to its next of next
        
        delete first;                        // delete removed element to flush the memory
        
        return head;
    }
};
