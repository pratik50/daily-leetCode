class Solution {
public:

    void getAllSubsets(vector<int>& arr, vector<int> ans, int i, vector<vector<int>> &allSubsets){

        if(i == arr.size()){
            allSubsets.push_back({ans});
            return;
        }

        //include
        ans.push_back(arr[i]);
        getAllSubsets(arr, ans, i+1, allSubsets);

        // Backtrack
        ans.pop_back();

        //exclude
        getAllSubsets(arr, ans, i+1, allSubsets);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        
        // TC O(2^n * n) and SC O(2^n * n)

        // vector of vector to store the multiple vector subset
        vector<vector<int>> allSubsets;

        // To store a single subset
        vector<int> ans;
        getAllSubsets(nums, ans, 0, allSubsets);
        return allSubsets;
    }
};