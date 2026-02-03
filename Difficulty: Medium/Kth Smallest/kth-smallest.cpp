class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        
        if(arr.size() == 0) return 0;
        
        priority_queue<int> pq;
        
        //Optimized approach
        for(int i=0; i<arr.size(); i++){
            pq.push(arr[i]);
            if(pq.size() > k){
                pq.pop();
            }
        }
        
        return pq.top();
    }
};