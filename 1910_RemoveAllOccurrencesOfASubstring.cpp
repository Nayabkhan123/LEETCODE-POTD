/*
    Given two strings s and part, perform the following operation on s until all occurrences of the 
    substring part are removed:

    Find the leftmost occurrence of the substring part and remove it from s.
    Return s after removing all occurrences of part.

    A substring is a contiguous sequence of characters in a string.
*/

class Solution {
    public:
        string removeOccurrences(string s, string part) {
            int n=part.size();
            string ans="";
            for(int i=0;i<s.size();i++){
                ans.push_back(s[i]);
                if(ans.size() >= n && ans.substr(ans.size()-n)==part){
                    ans=ans.substr(0,ans.size()-n);
                }
            }
            return ans;
        }
    };