class Solution {
public:

    void getPerm(vector<int>& nums,vector<int>& freq , vector<vector<int>>& ans, vector<int>& sPer){

        if(sPer.size() == nums.size()){
            ans.push_back(sPer);
            return;
        }

        for(int i=0; i<nums.size(); i++){
            if(freq[i] == 0){
                
                freq[i] = 1;
                sPer.push_back(nums[i]);
                
                getPerm(nums, freq, ans, sPer);
                
                sPer.pop_back();
                freq[i] = 0;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> sPer;
        vector<int> freq(nums.size(), 0);

        getPerm(nums, freq, ans, sPer);

        return ans;    
    }
};