// https://leetcode.com/problems/reverse-linked-list-ii/

// 1st solution

class Solution {
public:
   ListNode* reverseBetween(ListNode* head, int m, int n) {
       ListNode *dummy = new ListNode(0), *pre = dummy, *cur;
       dummy -> next = head;
       for (int i = 0; i < m - 1; i++) {
           pre = pre -> next;
       }
       cur = pre -> next;
       for (int i = 0; i < n - m; i++) {
           ListNode* temp = pre -> next;
           pre -> next = cur -> next;
           cur -> next = cur -> next -> next;
           pre -> next -> next = temp;
       }
       return dummy -> next;
   }
};

// 2nd solution
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head == NULL) return NULL;
        
        ListNode *cur = head, *prev = NULL;
        while(m>1){
            prev = cur;
            cur = cur->next;
            --m, --n;
        }
        
        ListNode *con = prev, *tail = cur;
        
        ListNode *third = NULL;
        while(n>0){
            third = cur->next;
            cur->next = prev;
            prev = cur;
            cur = third;
            --n;
        }
        
        if(con!=NULL)
            con->next = prev;
        else
            head = prev;
        
        tail->next = cur;
        return head;
    }
};
