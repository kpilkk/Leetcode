// https://leetcode.com/problems/sudoku-solver/

// recursion
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    
    bool solve(vector<vector<char>>& board){
        for(int i = 0; i < 9; ++i){
            for(int j = 0; j < 9; ++j){
                if(board[i][j] == '.'){
                    for(char c = '1'; c <= '9'; ++c){
                        if(isValid(board, i, j, c)){
                            board[i][j] = c;
                            
                            if(solve(board))
                                return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isValid(vector<vector<char>>& board, int row, int col, char c){
        for (int i = 0; i < 9; i++)
            if (board[i][col] == c) 
                return false;
        
        for (int i = 0; i < 9; i++)
            if (board[row][i] == c) 
                return false;
        
        for (int i = (row / 3) * 3; i < (row / 3 + 1) * 3; i++)
            for (int j = (col / 3) * 3; j < (col / 3 + 1) * 3; j++)
                if (board[i][j] == c) 
                    return false;
        
        return true;
    }
};
