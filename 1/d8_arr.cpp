Q1: Move zeroes
// https://leetcode.com/problems/move-zeroes/
// Approach: Used 2 pointer 2 swap non zero and zero elements
class Solution {
    public:
        void moveZeroes(vector<int>& nums) {
            int i = 0;
            int j = 0;
            while(j<nums.size()){
                if(nums[j]!=0){
                    swap(nums[i],nums[j]);
                    i++;
                }
                j++;
            }
        }
    };

Q2: Rotate Array
// https://leetcode.com/problems/rotate-array/
// Approach: Reversed the array in chunks inorder to get the desired rotation
class Solution {
    public:
        void rotate(vector<int>& nums, int k) {
            int n = nums.size();
            k = k % n;
            
            reverse(nums.begin(), nums.end());
            reverse(nums.begin(), nums.begin() + k);
            reverse(nums.begin() + k, nums.end());
        }
    };