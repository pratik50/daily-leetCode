class Solution {
  public:
    int findMin(int n) {
        // code here
        
        //TC O(1) ans SC O(1)
        int coins[] = {10, 5, 2, 1};
        int cnt = 0;
        
        for(int coin: coins){
            cnt += n/coin;
            n %= coin;
        }    
        
        return cnt;
    }
};