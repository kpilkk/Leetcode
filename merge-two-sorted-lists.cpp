// https://leetcode.com/problems/merge-two-sorted-lists/submissions/

// Using extra memory
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode();
        ListNode* dummy = ans;

        while(l1 && l2){
            if(l1->val <= l2->val){
                ans->next = new ListNode(l1->val);
                l1 = l1->next;
            }
            else{
                ans->next = new ListNode(l2->val);
                l2 = l2->next;
            }
            ans = ans->next;
        }
        
        while(l1){
            ans->next = new ListNode(l1->val);
            l1 = l1->next;
            ans = ans->next;
        }
        
        while(l2){
            ans->next = new ListNode(l2->val);
            l2 = l2->next;
            ans = ans->next;
        }
        return dummy->next;
    }
};
