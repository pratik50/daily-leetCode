class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        // code here
        
        sort(a.rbegin(), a.rend());
        sort(b.rbegin(), b.rend());
        
        priority_queue<pair<int,pair<int,int>>> pq;
        set<pair<int,int>> visited;
        vector<int> ans;
        
        pq.push({{a[0] + b[0]}, {0,0}});
        visited.insert({0,0});
        
        while(ans.size() < k){
            
            auto top = pq.top();
            
            int sum = top.first;
            int i = top.second.first;
            int j = top.second.second;
            
            pq.pop();
            ans.push_back(sum);
            
            if(i+1 < a.size() && visited.find({i+1,j}) == visited.end()){
                visited.insert({i+1,j});
                pq.push({{a[i+1]+b[j]}, {i+1,j}});
            }
            
            if(j+1 < b.size() && visited.find({i,j+1}) == visited.end()){
                visited.insert({i,j+1});
                pq.push({{a[i]+b[j+1]}, {i,j+1}});
            }
        }
        return ans;
    }
};