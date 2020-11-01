// https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/

// Approach 1: Binary Representation
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int n = 0;
        ListNode* temp = head;
        while(temp){
            temp = temp -> next;
            ++n;
        }
        
        int ans = 0;
        while(head){
            if(head -> val == 1)
                ans += pow(2, n - 1);
            head = head -> next;
            --n;
        }
        return ans;
    }
};

// Approach 2: Bit Manipulation
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int ans = 0;
        while(head != NULL){
            ans <<= 1;
            ans += head -> val ;
            head = head -> next;
        }
        return ans;
    }
};
