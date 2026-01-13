class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        
        // TC = O(g log g) + O(s log s) + O(min(child,cookie)) and SC = O(1)
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int child = 0, cookie = 0;

        while(child < g.size() && cookie < s.size()){
            if(s[cookie] >= g[child]){
                child++;
                cookie++;
            }else{
                cookie++;
            }
        }
        return child;
    }
};