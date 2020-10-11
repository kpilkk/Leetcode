// https://leetcode.com/problems/longest-common-prefix/

// Horizontal Scanning
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(n == 0) return "";
        string ans = strs[0];
        for(int i = 1; i < n; ++i){
            while(strs[i].find(ans) != 0)
                ans = ans.substr(0, ans.length() - 1);
            if(ans.empty())
                return "";
        }
        return ans;
    }
};

// Vertical Scanning
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        for(int i = 0; i < strs[0].length(); ++i){
            char c = strs[0][i];
            for(int j = 1; j < strs.size(); ++j)
                if(i == strs[j].length() || strs[j][i] != c)
                    return strs[0].substr(0 , i);
        }
        return strs[0];
    }
};

// By sorting and comparing first and last string
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        sort(strs.begin(), strs.end());
        int n = strs.size() - 1;
        int m = min(strs[0].length(), strs[n].length());
        
        int i = 0, j = 0;
        while(i < m){
            if(strs[0][i] == strs[n][i])
                j++;
            else
                break;
            i++;
        }
        return strs[0].substr(0, j);
    }
};

// Divide and Conquer
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        return longestCommonPrefix(strs, 0, strs.size() - 1);
    }
private:
    string longestCommonPrefix(vector<string> strs, int l, int r){
        if(l == r)
            return strs[l];
        else{
            int mid = ( l + r ) / 2;
            string lcpLeft = longestCommonPrefix(strs, l, mid);
            string lcpRight = longestCommonPrefix(strs, mid + 1, r);
            return commonPrefix(lcpLeft, lcpRight);
        }
    }
    
    string commonPrefix(string left, string right){
        int mini = min(left.length(), right.length());
        for(int i = 0; i < mini; ++i)
            if(left[i] != right[i])
                return left.substr(0, i);
        return left.substr(0, mini);
    }
};

// Using Trie Data structure
class TrieNode{
public:
    unordered_map<char, TrieNode*> children;
    char val;
    bool isWord = false;
    
    TrieNode() {}
    
    TrieNode(char v){
        this -> val = v;
    }
};

class Trie{
private:
    TrieNode* root;
    
public:
    // Initialize your data structure here
    Trie() {
        root = new TrieNode();
    }
    
    // Get TrieNode
    TrieNode* getTrieNode(){
        return root;
    }
    
    // Insert a word into the tree
    void insert(string word){
        TrieNode* temp = root;
        
        for(auto ch : word){
            if(temp -> children.find(ch) == temp -> children.end())
                temp -> children[ch] = new TrieNode(ch);
            temp = temp -> children[ch];
        }
        
        temp -> isWord = true;
    }
    
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // insert all keys into trie
        Trie* t = new Trie();
        
        for(auto str : strs)
            t -> insert(str);
        
        // Traverse the trie and find longest common prefix
        string lcp;
        TrieNode* curr = t -> getTrieNode();
        
        // Do till we find a leaf node or node has more than 1 children
        while(curr && !curr -> isWord && (curr -> children.size() == 1)){
            auto it = curr -> children.begin();
            lcp += it -> first;
            curr = it -> second;
        }
        
        return lcp;
    }
};
