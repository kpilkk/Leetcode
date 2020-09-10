// https://leetcode.com/problems/merge-two-sorted-lists/submissions/

// Using constant space

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy = ListNode(0);
        ListNode* ans = &dummy;
        
        while(l1 && l2){
            if(l1 -> val < l2 -> val){
                ans -> next = l1;
                l1 = l1 -> next;
            }
            else{
                ans -> next = l2;
                l2 = l2 -> next;
            }
            ans = ans -> next;
        }
        
        ans -> next = l1 ? l1 : l2;
        
        return dummy.next;
    }
};

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

// Using recursion
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;
        
        if(l1->val < l2->val){
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else{
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};
