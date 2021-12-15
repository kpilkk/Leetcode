// https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/

struct Trie{
    Trie *next[2];
    Trie(){
        next[0] = nullptr;
        next[1] = nullptr;
    }
};

class TrieNode{
private:
    Trie *root;

public:
    TrieNode(){
        root = new Trie();
    }
    
    void insert(int num){
        Trie *curr = root;
        
        for(int i = 31; i >= 0; --i){
            int bit = (num >> i) & 1;
            if(curr->next[bit] == nullptr)
                curr->next[bit] = new Trie();
            curr = curr->next[bit];
        }
    }
    
    int max_xor(int num){
        Trie *curr = root;
        int ans = 0;
        for(int i = 31; i >= 0; --i){
            int bit = (num >> i) & 1;
            
            if(curr->next[!bit]){
                ans += (1 << i);
                curr = curr->next[!bit];
            }
            else
                curr = curr->next[bit];
        }
        return ans;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int max_ans = 0;
        int n = nums.size();
        
        TrieNode *t  = new TrieNode();
        
        for(int i = 0;  i < n; ++i){
            t->insert(nums[i]);
            max_ans = max(max_ans, t->max_xor(nums[i]));
        }
        return max_ans;
    }
};