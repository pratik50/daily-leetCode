class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        
        //TC = O(nlog n) and SC = O(n)
        int n = start.size();
        vector<pair<int,int>> meetings;
        
        for(int i=0; i<n;i++){
            meetings.push_back({end[i],start[i]});
        }
        
        sort(meetings.begin(),meetings.end());
        
        int cnt = 1;
        int freeTime = meetings[0].first;
        
        for(int i = 1; i<n; i++){
            if(meetings[i].second > freeTime){
                freeTime = meetings[i].first;
                cnt++;
            }
        }
        
        return cnt;
        
    }
};