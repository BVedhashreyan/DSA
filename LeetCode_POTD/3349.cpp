class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        if(2*k > n)return false;
        if(k == 1)return true;

        int count = 1;
        for(int i = k+1; i<n; i++){
            if(nums[i]>nums[i-1] && nums[i-k]>nums[i-k-1]){
                count++;
            }else count = 1;

            if(count == k)return true;
        }
        return false;
    }
};