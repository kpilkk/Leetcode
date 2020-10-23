// https://leetcode.com/problems/merge-k-sorted-lists/

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())
            return nullptr;
        int n = lists.size();
        while(n > 1){
            for(int i = 0; i < n / 2; ++i)
                lists[i] = mergeTwoLists(lists[i], lists[n - 1 - i]);
            n = (n + 1) / 2;
        }
        return lists.front();
    }
private:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        
        ListNode dummy(0);
        ListNode* ans = &dummy;
        
        while(l1 && l2){
            if(l1 -> val < l2 -> val){
                ans -> next = l1;
                l1 = l1 -> next;
            }
            else{
                ans -> next = l2;
                l2 = l2 -> next;
            }
            ans = ans -> next;
        }
        ans -> next = l1 ? l1 : l2;
        return dummy.next;
    }
};
