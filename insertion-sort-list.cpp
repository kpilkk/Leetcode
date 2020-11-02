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
