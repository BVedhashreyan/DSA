class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        if(n == 1)return 0;
        
        int ans = 0;
        int l = 0;
        int r = l+1;
        int sum = neededTime[l];
        int maxi = neededTime[l];
        while(l<n-1){
            if(colors[l] == colors[r]){
                sum += neededTime[r];
                maxi = max(maxi, neededTime[r]);
                r++;
                if(r >= n){
                    ans += sum-maxi;
                    break;
                }
            }else{
                ans += sum-maxi;
                l = r;
                r = l+1;
                sum = neededTime[l];
                maxi = neededTime[l];
            }
        }

        return ans;

    }
};