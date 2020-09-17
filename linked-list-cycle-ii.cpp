// https://leetcode.com/problems/linked-list-cycle-ii/
/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.

Note: Do not modify the linked list.

 

Example 1:

Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.
*/

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
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next==NULL) return NULL;
        ListNode *slow = head, *fast = head;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast)
                break;
        }
        
        fast = head;
        while(slow!=fast && slow!=NULL){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
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
    ListNode *detectCycle(ListNode *head) {
        if(!head) return NULL;
        bool cycle = false;
        ListNode *slow = head, *fast = head;
        while(fast && fast -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
            if(fast == slow){
                cycle = true;
                break;
            }
        }
        if(!cycle) return NULL;
        slow = head;
        while(slow != fast){
            slow = slow -> next;
            fast = fast -> next;
        }
        return slow;
    }
};
