class Solution {
  public:
    
        
    vector<vector<int>> dp;
    
    bool solve(int i, vector<int>& arr, int sum) {
        if (sum == 0)
            return true;
        
        if (i == arr.size() || sum < 0)
            return false;
        
        //check if already store
        if (dp[i][sum] != -1)
            return dp[i][sum];
            
        // include or exclude
        bool take = solve(i + 1, arr, sum - arr[i]);
        bool skip = solve(i + 1, arr, sum);
        
        //store & return
        return dp[i][sum] = take || skip;
    }
    
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        
        dp.assign(arr.size(), vector<int>(sum + 1, -1));
        
        return solve(0, arr, sum);

    }
};