class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        
        int cnt = 0;
        for(char ch: stones){
            // npos --> no position, returns false.
            if(jewels.find(ch) != string::npos)   
                cnt++;
        }
        return cnt;
    }
};