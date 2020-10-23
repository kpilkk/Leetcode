// https://leetcode.com/problems/merge-k-sorted-lists/

// Divide and Conquer
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

// Priority Queue
// Example : [[1,4,5],[1,3,4],[2,6]]
class Solution {
    struct compareNode {
        bool operator()(ListNode* const & p1, ListNode* const & p2) const{
            return p1 -> val > p2 -> val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        // construct min_heap
        // priority_queue default constructs max_heap
        priority_queue<ListNode*, vector<ListNode*>, compareNode> queue;
        
        for(int i = 0; i < lists.size(); ++i){
            if(lists[i])
                queue.push(lists[i]);
        }
        
        // while(!queue.empty()){
        //     cout << queue.top() -> val << " ";  // 1 , 1 , 2
        //     queue.pop();
        // }
        
        while(!queue.empty()){
            tail -> next = queue.top();
            // cout << queue.top() -> val<< " "; // 1 , 1 , 2 , 3 , 4 , 4 , 5 , 6
            queue.pop();
            tail = tail -> next;
            
            if(tail -> next)
                queue.push(tail -> next);
        }
        
        return dummy.next;
    }
};
