// q1)Maximum Nesting Depth of the Parentheses
// https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/description/
class Solution {
    public:
        int maxDepth(string s) {
            int maxi = 0;
            int balance = 0;
            for(auto it:s){
                if(it=='('){
                    balance++;
                    maxi = max(maxi,balance);
                }else if(it == ')'){
                    balance--;
                }
            }
            return maxi;
        }
    };
// TC:O(N);
// SC:O(1);

// q2)Roman to integer
// https://leetcode.com/problems/roman-to-integer/description/

class Solution {
    public:
        int romanToInt(string s) {
            unordered_map<char,int>rome;
    
            rome.insert({'I',1});
            rome.insert({'V',5});
            rome.insert({'X',10});
            rome.insert({'L',50});
            rome.insert({'C',100});
            rome.insert({'D',500});
            rome.insert({'M',1000});
    
            int n = s.length();
            int ans = rome[s[n-1]];
    
            for(int i = n-2; i>=0; i--){
                if(rome[s[i]]>=rome[s[i+1]]){
                    ans+=rome[s[i]];
                }else{
                    ans-=rome[s[i]];
                }
            }
    
            return ans;
            
        }
    };

// TC:O(N);
// SC:O(1);