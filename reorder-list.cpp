// https://leetcode.com/problems/reorder-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        if(head == NULL || head -> next == NULL)
            return;
        
        ListNode *slow = head, *fast = head -> next;
        
        // Find the middle element
        while(fast && fast -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        // cout << slow -> val;
        // reverse second half  
        // Similar to reverse linked list II
        fast = slow -> next;
        while(fast -> next){
            ListNode* temp = slow -> next;
            slow -> next = fast -> next;
            fast -> next = fast -> next -> next;
            slow -> next -> next = temp;
        }
        
        // slow = slow -> next;
        ListNode* temp = head;
        // slow is mid
        fast = slow -> next;
        while(temp != slow){
            slow -> next = fast -> next;
            fast -> next = temp -> next;
            temp -> next = fast;
            temp = fast -> next;
            fast = slow -> next;
        }
    }
};
