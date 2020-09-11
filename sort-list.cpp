// https://leetcode.com/problems/sort-list/
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
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head -> next == NULL)
            return head;
        
        ListNode *slow = head, *fast = head, *pre = NULL;
        
        while(fast && fast -> next){
            pre = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        
        pre -> next = NULL;
        return mergeSort(sortList(head), sortList(slow));
    }
    
    ListNode* mergeSort(ListNode* left, ListNode* right){
        ListNode* merge = new ListNode(0);
        ListNode* dummy = merge;
        
        while(left && right){
            if(left -> val < right -> val){
                merge -> next = left;
                left = left -> next;
            }
            else{
                merge -> next = right;
                right = right -> next;
            }
            merge = merge -> next;
        }
        
        if(left)
            merge -> next = left;
        
        if(right)
            merge -> next = right;
            
        return dummy -> next;
    }
};
