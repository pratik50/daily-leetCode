class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end());

        int sum = 0;

        // Flip negative numbers
        for (int i = 0; i < nums.size() && k > 0; i++) {
            if (nums[i] < 0) {
                nums[i] = -nums[i];
                k--;
            }
        }

        // Calculate sum and find minimum absolute value
        int minAbs = INT_MAX;
        for (int num : nums) {
            sum += num;
            minAbs = min(minAbs, abs(num));
        }

        // If k is odd, flip smallest element
        if (k % 2 == 1) {
            sum -= 2 * minAbs;
        }

        return sum;
    }
};