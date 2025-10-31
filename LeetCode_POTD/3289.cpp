class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size();
        int xorr = 0;
        for(int i = 0; i<n-2; i++){
            xorr ^= i;
        }
        for(int i = 0; i<n; i++){
            xorr ^= nums[i];
        }

        int dbit = xorr & -xorr;
        int b1 = 0;
        int b2 = 0;
        for(int i = 0; i<n; i++){
            if(nums[i]&dbit){
                b1 ^= nums[i];
            }else{
                b2 ^= nums[i];
            }
        }

        for(int i = 0; i<n-2; i++){
            if(i & dbit){
                b1 ^= i;
            }else{
                b2 ^= i;
            }
        }

        return {b1,b2};
    }
};