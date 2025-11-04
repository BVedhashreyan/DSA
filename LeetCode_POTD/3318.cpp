class Solution {
public:
    int solve(vector<int>&arr, int x){
        int m = *max_element(arr.begin(), arr.end());
        vector<pair<int,int>>hash(m+1, {0,0});
        for(int i = 0; i<arr.size(); i++){
            hash[arr[i]].first += 1;
            hash[arr[i]].second += arr[i];
        }

        sort(hash.begin(), hash.end(), [](auto &a, auto &b){
            if (a.first == b.first)
                return a.second > b.second; 
            return a.first > b.first;
        });

        int sum = 0;
        for(int i =0; i<min(x,(int)hash.size()); i++){
            sum += hash[i].second;
        }
        return sum;
    }
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int>ans(nums.size()-k+1, 0);
        for(int i = 0; i<=nums.size()-k; i++){
            vector<int>arr(nums.begin()+i, nums.begin()+i+k);
            ans[i] = solve(arr, x);
        }
        return ans;
    }
};