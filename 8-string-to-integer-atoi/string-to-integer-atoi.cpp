class Solution {
public:
    int myAtoi(string s) {
        
        //TC - O(n) and SC - O(1)
        int n = s.length();
        int i = 0;

        //removes all spaces
        while(i<n && isspace(s[i])){
            i++;
        }

        //if string have only spaces
        if(i == n){
            return 0;
        }

        //check sign and next digit if.
        bool negative = false;
        if(s[i] == '-'){
            negative = true;
            i++;
        }
        else if(s[i] == '+'){
            i++;
        }
        else if(!isdigit(s[i])){
            return 0;
        }

        //removing all leading 0's
        while(i<n && s[i] == '0'){
            i++;
        }

        //if string is end.
        if(i==n){
            return 0;
        }

        //extracting the digits from string now
        int value = 0;
        while(i < n && isdigit(s[i])){

            int digit = s[i] - '0';

            //check overflow
            if(value > (INT_MAX - digit)/10) return INT_MAX;
            //check underflow
            if(value < (INT_MIN + digit)/10) return INT_MIN;

            if(negative){
                value = value*10 + (-digit);
            }else{
                value = value*10 + (digit);
            }

            i++;
        }
        return value;
    }
};