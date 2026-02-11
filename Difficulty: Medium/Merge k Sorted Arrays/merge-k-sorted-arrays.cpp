class Data {

  public:
    int val, vpos, apos;
        
    Data(int val, int vpos, int apos){
        this->val = val;
        this->vpos = vpos;
        this->apos = apos;
    }
};

struct minCompar{
    
    bool operator()(Data &d1, Data &d2){
        return d1.val > d2.val;
    }
};
    
class Solution {
  public:
    vector<int> mergeArrays(vector<vector<int>> &mat) {
        // Code here
        
        vector<int> ans;
        priority_queue<Data, vector<Data>, minCompar> pq;
        
        for(int i=0; i<mat.size(); i++){
            Data d(mat[i][0], 0, i);
            pq.push(d);
        }
        
        while(!pq.empty()){
            
            auto top = pq.top();    
            pq.pop();
            
            ans.push_back(top.val);
            
            int vpos = top.vpos;
            int apos = top.apos;
            
            
            if(vpos+1 < mat[apos].size()){
                Data d(mat[apos][vpos+1], vpos+1, apos);
                pq.push(d);
            }
        }
        return ans;
    }
};








