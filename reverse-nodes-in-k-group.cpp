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
    
    // Following code is from Reverse Linked List II
    ListNode* reverseBetween(ListNode* head, int m, int n){
        if(m != 1){
            head -> next = reverseBetween(head -> next, m - 1, n -1);
            return head;
        }
        else{
            // Following code is similar to Reverse Linked List
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

// recursive solution using same function
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1)
            return head;
        ListNode *curr = head, *prev = nullptr, *next = nullptr;
        int count = 0;
        while(count++ < k && curr){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        if(next){
            int i = 0;
            ListNode* temp = next;
            while(temp && i < k){
                temp = temp -> next;
                i++;
            }
            if(i == k)
                head -> next = reverseKGroup(next, k);
            else
                head -> next = next;
        }
        
        return prev;
    }
};
