// Approach - sorted the strings and checked with the previous one's , if not present then append

class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        string prev = "";
        vector<string>ans;

        for(auto it:words){
            string curr = it;
            sort(curr.begin(), curr.end());
            if(curr != prev)ans.push_back(it);
            prev = curr;
        }

        return ans;
    }
};

// tc - o(n*mlogm)
// sc - o(n)