class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
        
        // TC = O(n log n) and SC = O(1)
        int n = arr.size();

        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        
        int cnt = 0;
        int maxPlatform = 0;
        int j=0, i=0;
        
        while(i < n && j < n){
            
            if(arr[i] <= dep[j]){
                cnt++;
                i++;
            }else{
                cnt--;
                j++;
            }
            maxPlatform = max(cnt,maxPlatform);
        }
        
        return maxPlatform;
    }
};
