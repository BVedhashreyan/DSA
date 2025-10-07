    class Solution {
    public:
        vector<int> avoidFlood(vector<int>& rains) {
            set<int>zeroes;
            map<int,int>mpp;
            int n = rains.size();
            vector<int>ans(n,1);

            for(int i = 0; i<n; i++){
                if(rains[i] == 0){
                    zeroes.insert(i);
                }else{
                    if(mpp.find(rains[i]) != mpp.end()){
                        auto it = zeroes.lower_bound(mpp[rains[i]]);
                        if(it == zeroes.end())return {};
                        ans[*it] = rains[i];
                        zeroes.erase(it);
                    }
                    ans[i] = -1;
                    mpp[rains[i]] = i;
                }
            }
            return ans;
        }
    };