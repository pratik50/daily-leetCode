// User function Template for C++

class Solution {
  public:
    vector<string> splitString(string S) {
        // code here
        string s1 = "", s2 = "", s3 = "";
        
        for(int i=0; i<S.size(); i++){
            if(isalpha(S[i])){
                s1 += S[i];
            }
            else if(isdigit(S[i])){
                s2 += S[i];
            } 
            else{
                s3 += S[i];
            }
        }
        return {s1, s2, s3};
    }
};
