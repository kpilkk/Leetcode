// https://leetcode.com/problems/swap-nodes-in-pairs/

// Using recursion
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head -> next)
            return head;

        ListNode* nxt = head -> next;
        head -> next = swapPairs(nxt -> next);
        nxt -> next = head;
        
        return nxt;
    }
};

// Iterative solution using constant space
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head)
            return head;
        ListNode dummy(0);
        ListNode* pre = &dummy;
        
        pre -> next = head;
        
        while(head && head -> next){
            ListNode* temp = head -> next;
            head -> next = temp -> next;
            temp -> next = head;
            pre -> next = temp;
            pre = head;
            head = head -> next;
        }
        return dummy.next;
    }
};

// Easy understand
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head)
            return head;
        
        ListNode dummy(0);
        ListNode* cur = &dummy;
        cur -> next = head;
        
        while(cur -> next && cur -> next -> next){
            cur -> next = swap(cur -> next, cur -> next -> next);
            cur = cur -> next -> next;
        }
        
        return dummy.next;
    }
    
    ListNode* swap(ListNode* next1, ListNode* next2){
        next1 -> next = next2 -> next;
        next2 -> next = next1;
        return next2;
    }
};
