class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        map<int,int> mpp;

        for(int i = 0; i<nums.size(); i++){
            int n = nums[i];
            int rem = target - n;

            if(mpp.find(rem) != mpp.end()){
                return {mpp[rem],i};
            }
            mpp[n] = i;
        }
        return {};
    }
};