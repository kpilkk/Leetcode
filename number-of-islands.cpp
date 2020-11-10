// https://leetcode.com/problems/number-of-islands/

// Recursive DFS solution
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == '1'){
                    DFSMarking(grid, i, j, m, n);
                    ++count;
                }
            }
        }
        return count;
    }
    
    void DFSMarking(vector<vector<char>>& grid, int i, int j, int m, int n){
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0')
            return;
        grid[i][j] = '0';
        DFSMarking(grid, i - 1, j, m, n);
        DFSMarking(grid, i, j - 1, m, n);
        DFSMarking(grid, i + 1, j, m, n);
        DFSMarking(grid, i, j + 1, m, n);
    }
};

// Iterative BFS solution
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == '1'){
                    bfsFill(grid, i, j);
                    ++ans;
                }
            }
        }
        return ans;
    }
    
    void bfsFill(vector<vector<char>>& grid, int i, int j){
        grid[i][j] = '0';
        int m = grid.size();
        int n = grid[0].size();
        
        queue<pair<int, int>> bfs;
        bfs.emplace(make_pair(i , j));
        while(!bfs.empty()){
            pair<int, int> temp = bfs.front();
            bfs.pop();
            if(temp.first > 0 && grid[temp.first - 1][temp.second] == '1'){
                bfs.emplace(make_pair(temp.first - 1, temp.second));
                grid[temp.first - 1][temp.second] = '0';
            }
            if(temp.first < m - 1 && grid[temp.first + 1][temp.second] == '1'){
                bfs.emplace(make_pair(temp.first + 1, temp.second));
                grid[temp.first + 1][temp.second] = '0';
            } 
            if(temp.second > 0 && grid[temp.first][temp.second - 1] == '1'){
                bfs.emplace(make_pair(temp.first, temp.second - 1));
                grid[temp.first][temp.second - 1] = '0';
            } 
            if(temp.second < n - 1 && grid[temp.first][temp.second + 1] == '1'){
                bfs.emplace(make_pair(temp.first , temp.second + 1));
                grid[temp.first][temp.second + 1] = '0';
            } 
        }
    }
};
