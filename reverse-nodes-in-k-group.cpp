// https://leetcode.com/problems/reverse-nodes-in-k-group/

// Intuitive solution
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1)
            return head;
        int n = 0;
        ListNode* temp = head;
        while(temp){
            temp = temp -> next;
            ++n;
        }

        int i = 1;
        while(i + k <= n + 1){
            head = reverseBetween(head, i , i + k - 1);
            i += k;
        }
        return head;
    }
    
    // Following code is from Linked List II
    ListNode* reverseBetween(ListNode* head, int m, int n){
        if(m != 1){
            head -> next = reverseBetween(head -> next, m - 1, n -1);
            return head;
        }
        else{
            // Following code is similar to Linked List I
            ListNode *prev = nullptr, *next = nullptr, *temp = head;
            int count = 0;
            while(count++ < n){
                next = head -> next;
                head -> next = prev;
                prev = head;
                head = next;
            }
            temp -> next = head;
            return prev;
        }
    }
};
