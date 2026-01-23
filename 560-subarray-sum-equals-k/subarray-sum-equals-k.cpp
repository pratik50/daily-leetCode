class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        unordered_map<int,int> mpp;
        int cnt = 0, prefSum = 0;

        mpp[0] = 1;

        for(int i=0; i<nums.size(); i++){
            prefSum += nums[i];
            int remove = prefSum - k;
            cnt += mpp[remove];
            mpp[prefSum]++;
        }   

        return cnt;
    }
};