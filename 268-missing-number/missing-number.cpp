class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int ans = 0;
        int x1 =0, x2 =0;
        int n = nums.size();

        for(int i = 0; i < nums.size(); i++){
            x1 = x1^i;
            x2 = x2^nums[i];
        }

        x1 ^= n;

        ans = x1 ^ x2;
        return ans;
    }
};