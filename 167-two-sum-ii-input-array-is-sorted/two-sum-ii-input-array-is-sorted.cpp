class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        int start = 0; 
        int end = numbers.size()-1;

        //TC O(n) and SC O(1)
        while(start <= end){

            int midSum = numbers[start] + numbers[end];

            if(midSum == target){
                return {start+1, end+1};
            }
            else if(midSum < target){
                start++;
            }else{
                end--;
            }
        }

        return {-1};
    }
};