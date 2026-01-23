class Solution {
public:

    void solve(int index, string map[], string digits, vector<string>& ans, string& temp){

        if(index == digits.size()){
            ans.push_back(temp);
            return;
        }

        int num = digits[index] - '0';
        string val = map[num];
        
        for(int i=0; i<val.size(); i++){
            temp.push_back(val[i]);
            solve(index+1, map, digits, ans, temp);

            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        
        vector<string> ans;
        if(digits.size() == 0) return ans;

        string temp;
        string map[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

        solve(0, map, digits, ans, temp);
        return ans;
    }
};