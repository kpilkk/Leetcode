// https://leetcode.com/problems/insertion-sort-list/

// Leetcode solution
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy(0);
        ListNode *curr = head, *prev, *next;
        
        while(curr){
            prev = &dummy;
            next = dummy.next;
            
            while(next){
                if(curr -> val < next -> val)
                    break;
                prev = next;
                next = next -> next;
            }
            ListNode* temp = curr -> next;
            curr -> next = next;
            prev -> next = curr;
            
            curr = temp;
        }
        
        return dummy.next;
    }
};

// straight forward solution
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *pre = &dummy, *curr =head;
        
        while(curr){
            if(curr -> next && curr -> next -> val < curr -> val){
                while(pre -> next && pre -> next -> val < curr -> next -> val)
                    pre = pre -> next;
                ListNode* temp = pre -> next;
                pre -> next = curr -> next;
                curr -> next = curr -> next -> next;
                pre -> next -> next = temp;
                pre = &dummy;
            }
            else
                curr = curr -> next;
        }
        return dummy.next;
    }
};

// similar as above
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy(0);
        ListNode *pre = &dummy, *curr = head, *next = nullptr;
        
        while(curr){
            next = curr -> next;
            while(pre -> next && pre ->next -> val < curr -> val)
                pre = pre -> next;
            
            curr -> next = pre -> next;
            pre -> next = curr;
            pre = &dummy;
            curr = next;
        }
        return dummy.next;
    }
};
