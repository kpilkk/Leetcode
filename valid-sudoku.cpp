// https://leetcode.com/problems/valid-sudoku/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row[9][9] = {0}, column[9][9] = {0}, box[9][9] = {0};
        for(int i = 0; i < 9; ++i)
            for(int j = 0; j < 9; ++j)
                if(board[i][j] != '.'){
                    int num = board[i][j] - '1', k = i / 3 * 3 + j / 3;
                    if(row[i][num] || column[j][num] || box[k][num])
                        return false;
                    row[i][num] = column[j][num] = box[k][num] = true;
                }
        return true;
    }
};
