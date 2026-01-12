class Solution {
public:
    int divide(int dividend, int divisor) {
        
        //TC = O(lon n) and SC - O(1)
        if (divisor == 0) return INT_MAX; 

        if(dividend == divisor){
            return 1;
        }

        bool negative = (dividend < 0) ^ (divisor < 0);
        
        long long a = llabs((long long)divisor);
        long long b = llabs((long long)dividend);
        long long ans = 0;

        while(a<=b){
            int cnt = 0;
            while((a<<(cnt+1)) <= b){
                cnt++;
            }

            ans += 1LL<<cnt;                     // 1<<cnt == 2^cnt
            b = b - (a<<cnt);                   // a<<cnt == a * 2^cnt 
        }

        if(ans > INT_MAX && !negative){
            return INT_MAX;
        }

        if(ans > INT_MAX && negative){
            return INT_MIN;
        }

        return (negative) ? -ans : ans;
    }
};