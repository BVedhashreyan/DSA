// q1) Isomorphic Strings
// https://leetcode.com/problems/isomorphic-strings/description/
class Solution {
    public:
        bool isIsomorphic(string s, string t) {
            if(s.length()!=t.length()) return false;
    
            vector<int>s_list(256,0);
            vector<int>t_list(256,0);
    
            for(int i = 0; i<s.length(); i++){
                if(s_list[s[i]] != t_list[t[i]]) return false;
    
                s_list[s[i]] = i+1;
                t_list[t[i]] = i+1;
            }
    
            return true;
    
        }
    };