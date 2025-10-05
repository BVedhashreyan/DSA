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

// q2) Remove Outermost Parentheses
// https://leetcode.com/problems/remove-outermost-parentheses/description/
class Solution {
    public:
        string removeOuterParentheses(string s) {
            string result;
            int rem = 0;
            for(int i = 0;i<s.length(); i++){
                if(s[i]=='('){
                    if(rem > 0){
                        result += s[i];
                    }
                    rem++;
                }else{
                    rem--;
                    if(rem>0){
                        result+=s[i];
                    }
                }
            }
            return result;
        }
    };