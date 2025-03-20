// q1) Valid anagram
// https://leetcode.com/problems/valid-anagram/

class Solution {
    public:
        bool isAnagram(string s, string t) {
            if(s.length()!=t.length()) return false;
    
            vector<int>smap(26,0);
            vector<int>tmap(26,0);
    
            for(auto it:s){
                smap[it-'a']++;
            }
            for(auto it:t){
                tmap[it-'a']++;
            }
    
            if(tmap.size()!=smap.size()) return false;
    
            for(int i = 0; i<smap.size(); i++){
                if(smap[i]!=tmap[i]) return false;
            }
            
            return true;
        }
    };

// TC:O(N) [O(3N)]
// SC:O(N) [O(2N)]

class Solution {
    public:
        bool isAnagram(string s, string t) {
            if(s.length()!=t.length()) return false;
    
            vector<int>fmap(26,0);
    
            for(int i=0; i<s.length(); i++){
                fmap[s[i]-'a']++;
                fmap[t[i]-'a']--;
            }
    
            for(int i = 0; i<fmap.size(); i++){
                if(fmap[i]!=0) return false;
            }
            
            return true;
        }
    };

// TC:O(N) [O(2N)]
// SC:O(N)

