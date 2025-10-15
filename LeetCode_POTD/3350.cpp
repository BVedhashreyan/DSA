class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        if(n == 2)return 1;

        int prev = 0, curr = 1;
        int maxK = 0;
        for(int i = 1; i<n; i++){
            if(nums[i]>nums[i-1]){
                curr++;
            }else{
                prev = curr;
                curr = 1;
            }

            maxK = max(maxK, min(prev, curr));
            maxK = max(maxK, curr/2); 
        }

        return maxK;
    }
};