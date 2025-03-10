// 1: Two Sum
// https://leetcode.com/problems/two-sum/
// Approach : Used Hash map to find if remaining part of particular element present in array

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            map<int,int>mpp;
            for(int i = 0; i<nums.size(); i++){
                int rem = target - nums[i];
                if(mpp.find(rem)!=mpp.end()){
                    return {mpp[rem],i};
                }
                mpp[nums[i]] = i;
            }
            return {-1,-1};
        }
    };
// TC:O(N) worst case (NlogN)
// SC:O(N)

// 2:Sort Colors
// https://leetcode.com/problems/sort-colors/
// Approach: Used DNF (3 pointer method)

class Solution {
    public:
    void sortColors(vector<int>& nums) {
            // Brute Force - Using any of the sorting algo
            // Better - Count number of zeroes , ones and two then overwrite manually
            // Optimal - 
            int n = nums.size();
            int low = 0, mid = 0, high = n-1;
            while(mid<=high){
                if(nums[mid] == 0){
                    swap(nums[mid],nums[low]);
                    low++;
                    mid++;
                }else if(nums[mid] == 2){
                    swap(nums[mid],nums[high]);
                    high--;
                }else{
                    mid++;
                }
            }    
        }
    };

// TC:O(N)
// SC:O(1)
