class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev = 0;
        int ans = 0;
        for(auto s:bank){
            int curr = 0;
            for(int i = 0; i<s.size(); i++){
                if(s[i]=='1'){
                    curr++;
                }
            }
            if(curr != 0){
                ans += curr*prev;
                prev = curr;
            }
        }
        return ans;
    }
};