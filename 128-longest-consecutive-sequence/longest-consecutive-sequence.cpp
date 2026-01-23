class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if(nums.size() == 0) return 0;
        sort(nums.begin(), nums.end());

        int longest = 1;
        int cnt = 1;
        int curr = nums[0];

        for(int i = 1; i < nums.size(); i++){

            if(nums[i] == curr + 1){
                cnt++;
                curr = nums[i];
            }
            else if(nums[i] == curr){
                // ignore duplicate
                continue;
            }
            else{
                // sequence break
                cnt = 1;
                curr = nums[i];
            }

            longest = max(longest, cnt);
        }

        return longest;
    }
};