class Solution {
public:

    void getAllSubsets(vector<int>& arr, vector<int>& ans, int i, vector<vector<int>>& allSubsets){

        if(i == arr.size()){
            allSubsets.push_back(ans);
            return;
        }

        //include
        ans.push_back(arr[i]);
        getAllSubsets(arr, ans, i+1, allSubsets);

        // backtrack
        ans.pop_back();

        int idx = i+1;
        // skipping the next all duplicate
        while(idx < arr.size() && arr[idx] == arr[idx - 1]){
            idx++;
        }

        // exclude
        getAllSubsets(arr, ans, idx, allSubsets);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        //imp
        sort(nums.begin(), nums.end());

        vector<int> ans;
        vector<vector<int>> allSubsets;
        getAllSubsets(nums, ans, 0, allSubsets);

        return allSubsets;
    }
};