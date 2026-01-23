class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        unordered_set<int> st;
        int n = nums.size();
        vector<int> ans;

        for(int i=0; i<n; i++){

            if(st.count(nums[i])){
                ans.push_back(nums[i]);
            }

            st.insert(nums[i]);
        }

        return ans;
    }
};