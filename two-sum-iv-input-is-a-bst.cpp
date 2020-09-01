// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

// Approach #1 Using HashSet
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        set<int> temp;
        
        return find(root, k, temp);
    }
    
private:
    bool find(TreeNode *root, int k, set<int>& temp){
        if(root == NULL)
            return false;
        if(temp.find(k-root->val)!=temp.end())
            return true;
        temp.emplace(root->val);
        return find(root->left, k, temp) || find(root->right, k, temp);
    }
};

// Approach #2 Using BFS and HashSet

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        set<int> temp;
        queue<TreeNode*> q;
        
        q.emplace(root);
        while(!q.empty()){
            if(q.front() != NULL){
                TreeNode *node = q.front();
                q.pop();
                if(temp.find(k - node->val) != temp.end())
                    return true;
                temp.emplace(node->val);
                q.emplace(node->right);
                q.emplace(node->left);
            }
            else{
                q.pop();
            }
        }
        return false;
    }
};

// Approach #3 Using BST

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> temp;
        inorder(root, temp);
        
        int l = 0, r = temp.size()-1;
        
        while(l<r){
            int sum = temp[l] + temp[r];
            if(sum==k)
                return true;
            else if(sum<k)
                l++;
            else
                r--;
        }
        return false;
    }
    
private:
    void inorder(TreeNode* root, vector<int>& temp){
        if(root == NULL)
            return;
        inorder(root->left, temp);
        temp.push_back(root->val);
        inorder(root->right, temp);
    }
};
