class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        // TC = O(n) and SC O(n)
        int n = nums.size();
        int longest = 1;
        if(nums.size() == 0)    return 0;

        unordered_set<int> st;

        for(int i = 0; i<n; i++){
            st.insert(nums[i]);
        }

        for(auto it: st){
            int n = it;
            int cnt = 1;
            if(st.find(it - 1) == st.end()){
                
                int x = it+1;
                while(st.find(x) != st.end()){
                    cnt ++; 
                    x = x + 1;
                }
                longest = max(longest, cnt);
            }
        }

        return longest;
    }
};