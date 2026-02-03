// User function Template for C++

class Solution {
  public:
  
    void heapifyAns(vector<int>& ans, int n, int i){
        
        int largest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;
        
        if(left < n && ans[left] > ans[largest])
            largest = left;
        
        if(right < n && ans[right] > ans[largest])
            largest = right;
            
        if(largest != i){
            swap(ans[largest], ans[i]);
            heapifyAns(ans, n, largest);
        }
        
    }
    
    
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        
        vector<int> ans;
        ans.insert(ans.end(), a.begin(), a.end());
        ans.insert(ans.end(), b.begin(), b.end());
        
        int ansSize = ans.size();
        for(int i = ansSize/2 - 1; i>=0; i--){
            heapifyAns(ans,ansSize,i);
        }
        
        return ans;
    }
};