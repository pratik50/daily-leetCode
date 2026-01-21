class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }

    bool solve(vector<vector<char>>& board){

        for(int i=0; i<9; i++){                               // poora board scan krenge
            for(int j=0; j<9; j++){

                if(board[i][j] == '.'){                       // agar empty cell mila

                    for(char ch = '1'; ch<='9'; ch++){        // we'll try char from "1" to "9"
                        if(isValid(i,j,ch,board)){
                            board[i][j] = ch;                 // choosen

                            if(solve(board) == true)          // next empty cell solve karo
                                return true;                  // agar aage solution mil gaya
                            else 
                                board[i][j] = '.';
                        }
                    }
                    return false;                             // koi number fit nahi hua → galat path
                }
            }
        }
        
        // yaha pahuche measn:
        // koi empty cell nahi bacha → sudoku solved
        return true; // BASE CASE
    }

    bool isValid(int row, int col, char ch, vector<vector<char>>& board){

        for(int i=0; i<9; i++){

            if(board[i][col] == ch)   
                return false;

            if(board[row][i] == ch)   
                return false;

            // 3×3 sub-grid check
            // row start = 3*(row/3)
            // col start = 3*(col/3)
            if(board[3 * (row/3) + i/3][3 * (col/3) + i%3] == ch)     
                return false;
        }
        return true;
    }
};