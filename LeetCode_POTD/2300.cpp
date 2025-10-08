class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int>ans;
        for(int i = 0; i<spells.size(); i++){
            int l = 0;
            int r = potions.size() - 1;
            while(l<=r){
                int m = l+(r-l)/2;
                long long prod = 1LL * spells[i] * potions[m];
                if(prod < success){
                    l = m+1;
                }else{
                    r = m-1;
                }
            }
            ans.push_back(potions.size() - l);
        }
        return ans;
    }
};  