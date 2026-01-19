class Solution {

private:
    void solve(string s, int index, vector<vector<string>>& ans, vector<string>& subS){

        if(index == s.length()){
            ans.push_back(subS);
            return;
        }

        for(int i = index; i<s.length(); i++){
            if(palindrome(s, index, i)){
                subS.push_back(s.substr(index, i - index + 1));
                solve(s, i+1, ans, subS);
                subS.pop_back();
            }            
        }
    }

    bool palindrome( string s, int start, int end){
        while(start <= end){
            if(s[start] != s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }

public:
    vector<vector<string>> partition(string s) {   
        vector<vector<string>> ans;
        vector<string> subS;

        solve(s, 0, ans, subS);
        return ans;
    }
};