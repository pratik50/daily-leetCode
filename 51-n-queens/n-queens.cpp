class Solution {

private:
    
    // NOT AN OPTIMAL APPROACH

    // TC (n! × n) ans SC O(n^2)
    bool isSafe(int row, int col, vector<string>& board, int n){
        int dupCol = col;
        int dupRow = row;

        // upper-left diagonal
        while(col >= 0 && row >=0){

            if(board[row][col] == 'Q'){
                return false;
            }
            col--;
            row--;
        }

        col = dupCol;
        row = dupRow;

        // upper column
        while(row >= 0){

            if(board[row][col] == 'Q'){
                return false;
            }
            row--;
        }

        col = dupCol;
        row = dupRow;

        // upper-right diagonal
        while(row >= 0 && col < n){
            if(board[row][col] == 'Q'){
                return false;
            }
            row--;
            col++;
        }

        return true;
    }

    void solve(int row, int n, vector<string>& board, vector<vector<string>>& ans){
        if(row == n){
            ans.push_back(board);
            return;
        }

        for(int col = 0; col<n; col++){

            if(isSafe(row, col, board, n)){
                board[row][col] = 'Q';
                solve(row+1, n, board, ans);

                board[row][col] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');

        for(int i=0; i<n; i++){
            board[i] = s;
        }

        // alternative for this loop is // vector<string> board(n, string(n, '.'));

        solve(0, n, board, ans);
        return ans;
    }
};