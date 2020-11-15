// https://leetcode.com/problems/open-the-lock/

// BFS method
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> visited(deadends.begin(), deadends.end());
        queue<string> bfs;
        
        if(visited.find("0000") != visited.end())
            return -1;
        
        int depth = 0;

        bfs.emplace("0000");
        visited.emplace("0000");
        
        while(!bfs.empty()){
            int n = bfs.size();
            
            for(int i = 0; i < n; ++i){
                string last_string = bfs.front();
                bfs.pop();
            
                if(last_string == target)
                    return depth;
                
                for(int j = 0; j < 4; ++j){
                    char temp = last_string[j];
                    last_string[j] = (temp == '9') ? '0' : temp + 1;
                    if(visited.find(last_string) == visited.end()){
                        bfs.emplace(last_string);
                        visited.emplace(last_string);
                    }
                    
                    last_string[j] = (temp == '0') ? '9' : temp - 1;
                    if(visited.find(last_string) == visited.end()){
                        bfs.emplace(last_string);
                        visited.emplace(last_string);
                    }
                    
                    last_string[j] = temp;
                }
            }
            ++depth;
        }
        return -1;
    }
};
