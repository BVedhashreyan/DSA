// 1:Rearrange Array Elements by Sign
// Approach: Even places for positive numbers and odd places for negative numbers
// https://leetcode.com/problems/rearrange-array-elements-by-sign/description/

class Solution {
    public:
        vector<int> rearrangeArray(vector<int>& nums) {
            int n = nums.size();
            vector<int>ans(n,0);
            int pos = 0, neg = 1;
            for(int i = 0; i<n; i++){
                if(nums[i]>0){
                    ans[pos] = nums[i];
                    pos+=2;
                }else{
                    ans[neg] = nums[i];
                    neg+=2;
                }
            }
            return ans;
        }
        
    };
// TC:O(N);
// SC:O(N);

// 2:Next Permutation
// https://leetcode.com/problems/next-permutation/description/
// Approach: Found the first decreasing element and swapped it with next larger element after it and then sorted(reversed already in descending order) the after the pivot index

class Solution {
    public:
        void nextPermutation(vector<int>& nums) {
            int ind = -1;
            int n = nums.size();
    
            for(int i = n-2; i>=0; i--){
                if(nums[i]<nums[i+1]){
                    ind = i;
                    break;
                }
            }
            if(ind == -1){
                reverse(nums.begin(),nums.end());
            }
            else{
                for(int i = n-1; i>=ind; i--){
                    if(nums[i]>nums[ind]){
                        swap(nums[i],nums[ind]);
                        break;
                    }
                }
                reverse(nums.begin()+ind+1,nums.end());
            }
        }
    };

// TC:O(N);
// SC:O(N);