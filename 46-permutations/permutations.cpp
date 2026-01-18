class Solution {
private:
    void solve(vector<int>& nums, vector<vector<int>>& ans, int idx){

        if(idx == nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int i = idx; i<nums.size(); i++){

            swap(nums[i], nums[idx]);
            solve(nums, ans, idx+1);

            //backtrack
            swap(nums[i], nums[idx]);
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> ans;

        solve(nums, ans, 0);
        return ans;
    }
};