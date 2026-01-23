class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //Time: O(n) & Space: O(n)
        
        if(s.size() == 0)   return 0;
        int longest = 0;
        int cnt = 0;

        unordered_set<char> st;
        int l =0;
        int r =0;

        for(int r = 0; r<s.size(); r++){

            while(st.find(s[r]) != st.end()){
                st.erase(s[l]);
                cnt--;
                l++;
            }
            
            cnt++;
            st.insert(s[r]);
            longest = max(longest, cnt);
        }

        return longest;
    }
};