class Solution {
    
    
    //TC O(m^v) and SC O(v)
    
    bool possible(int node, vector<int> colour, int col, vector<vector<int>> &edges){
    
        
        for(int k=0; k<edges.size(); k++){
            
            
            int u = edges[k][0];
            int v = edges[k][1];
            
            // Agar edge node se connected hai
            if (u == node) {
                // neighbour ka same color hua to not possible
                if (colour[v] == col) return false;
            }
            else if (v == node) {
                if (colour[u] == col) return false;
            }
        }
        
        return true;
    }
    
    
    bool solve(int v, vector<int> colour, vector<vector<int>> &edges, int m, int i){
        
        if(i == v){
            return true;
        }
        
        for(int col = 1; col<=m; col++){
            
            if(possible(i, colour, col, edges)){
                
                colour[i] = col;
                
                if(solve(v, colour, edges, m, i+1))
                    return true;
                else
                    colour[i] = 0;
                
            }
        }
        
        return false;
    }
    
  public:
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        // code here
        
        
        vector<int> colour;
        colour.assign(v, 0);
        
        return solve(v,colour, edges, m, 0);
    }
};