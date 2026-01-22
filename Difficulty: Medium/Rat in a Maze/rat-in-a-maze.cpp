class Solution {
    
    int n;
    vector<vector<int>> vis;   // visited array to avoid cycles
    vector<string> result;        

    bool isSafe(int r, int c, vector<vector<int>>& maze) {
        //proper boundary + visited + open cell check
        return (r >= 0 && c >= 0 && r < n && c < n &&
                maze[r][c] == 1 && vis[r][c] == 0);
    }
    

    void solve(int r, int c, vector<vector<int>>& maze, string path) {

        if (r == n - 1 && c == n - 1) {
            result.push_back(path);
            return;
        }

        vis[r][c] = 1;  // mark visited

        // Down
        if (isSafe(r + 1, c, maze))
            solve(r + 1, c, maze, path + 'D');

        // Right
        if (isSafe(r, c + 1, maze))
            solve(r, c + 1, maze, path + 'R');

        // Up
        if (isSafe(r - 1, c, maze))
            solve(r - 1, c, maze, path + 'U');
            
        // Left
        if (isSafe(r, c - 1, maze))
            solve(r, c - 1, maze, path + 'L');    

        vis[r][c] = 0;  // backtracking (unmark)
    }
    
    
  public:
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        
        n = maze.size();
        vis.assign(n, vector<int>(n, 0)); 

        if (maze[0][0] == 0) return {};     // start blocked case

        solve(0, 0, maze, "");  
        
        sort(result.begin(), result.end());
        return result;
    }
};