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
