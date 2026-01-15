class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        
        int n = val.size();
        vector<pair<double,int>>    items;
        
        for(int i = 0; i<n; i++){
            items.push_back({ (double)val[i]/wt[i], i});
        }
        
        // sort by value/weight ratio (desc)
        sort(items.begin(), items.end(), greater<>());
        
        double totalValue = 0.0;
        
        for(const auto& it: items){
            int idx = it.second;
            
            if (capacity >= wt[idx]) {
                totalValue += val[idx];
                capacity -= wt[idx];
            } else {
                totalValue += it.first * capacity;
                break;
            }
        }
        
        return totalValue;
    }
};
