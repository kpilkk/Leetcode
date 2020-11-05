// https://leetcode.com/problems/maximum-depth-of-n-ary-tree/

// DFS recursive solution
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        if(!root)
            return 0;
        int depth = 1;
        for(auto child : root -> children)
            depth = max(depth , 1 + maxDepth(child));
        return depth;
    }
};

// BFS iterative solution
class Solution {
public:
    int maxDepth(Node* root) {
        if(!root)
            return 0;
        
        queue<Node*> bfs;
        bfs.push(root);
        int ans = 0;
        while(!bfs.empty()){
            int n = bfs.size();
            ++ans;
            for(int i = 0; i < n; ++i){
                Node* temp = bfs.front();
                bfs.pop();
                for(auto child : temp -> children){
                    if(child)
                        bfs.push(child);
                }
            }
        }
        return ans;
    }
};
