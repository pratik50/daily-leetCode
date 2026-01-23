class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        
        unordered_set<char> J(jewels.begin(),jewels.end());
        int cnt = 0;
        for(char ch: stones){
            if(J.count(ch))         //this returns bool
                cnt++;
        }
        return cnt;
    }
};