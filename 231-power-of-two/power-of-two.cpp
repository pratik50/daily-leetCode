class Solution {
public:
    bool isPowerOfTwo(long long n) {

        // TC = O(1) and SC = O(1)
        // Bit masking/Binary expo.
        if(n == 1) return true;
        if(n == 0) return false;
        return ((n&(n-1)) == 0) ? true : false;
    }
};