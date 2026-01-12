class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        //TC = O(log n) and SC = O(1)
        if(n == 1)  return true;
        if(n == 0)  return false;

        long long i=2;
        while(i<=n){
            if(i == n)
                return true;

            i *= 2; 
        }
        return false;
    }
};