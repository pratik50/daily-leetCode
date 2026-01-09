class Solution {
public:
    double myPow(double x, int n) {

        long binaryNm = n;
        double ans = 1;
        
        if(n < 0){
            x = 1/x;
            binaryNm = -binaryNm;
        }

        while(binaryNm > 0 ){

            if(binaryNm % 2 == 1){
                ans = ans*x;
            }

            x = x*x;
            binaryNm = binaryNm/2;
        }
        return ans;
            
    }
};