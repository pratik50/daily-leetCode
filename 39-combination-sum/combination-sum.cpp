class Solution {

private: 
    void solve(vector<int>& cddt, int target, int i, vector<vector<int>>& ans, vector<int>& combi){

        if(i == cddt.size()){
            if(target == 0){
                ans.push_back(combi);
            }
            return;
        }


        if(cddt[i] <= target){
            combi.push_back(cddt[i]);
            solve(cddt, target - cddt[i], i, ans, combi);

            //backtrack
            combi.pop_back();
        }

        solve(cddt, target, i+1, ans, combi);
    }


public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> ans;
        vector<int> combi;

        solve(candidates, target, 0, ans, combi);

        return ans;
    }
};