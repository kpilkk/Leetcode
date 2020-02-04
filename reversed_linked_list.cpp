// question link : https://leetcode.com/problems/reverse-linked-list/
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
    ListNode* reverseList(ListNode* head) {
        // ListNode 
        if(!head || !head->next) return head; 
        ListNode *temp1 = NULL, *temp2 = NULL;
        while(head){
            temp1 = head->next;
            head->next = temp2;
            temp2 = head;
            head = temp1;
        }
        return temp2;
    }
};
