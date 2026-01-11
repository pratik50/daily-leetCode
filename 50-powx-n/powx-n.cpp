class Solution {
public:

    double myPow(double x, long n) {
        
        if (n == 0) return 1.0;
    
        // Handle negative exponent
        if (n < 0) {
            return 1.0 / myPow(x, -n);
        }

        if(x == 0)  return 0.0;
        if(x == 1)  return 1.0;

        if(n % 2 == 0){
            return myPow(x * x, n / 2);
        }
        
        return x * myPow(x, n - 1);
        
    }
};