/*
    You are given two strings s1 and s2 of equal length. A string swap is an operation where you choose 
    two indices in a string (not necessarily different) and swap the characters at these indices.

    Return true if it is possible to make both strings equal by performing at most one string swap on 
    exactly one of the strings. Otherwise, return false.
*/

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1==s2) return true;
        int idx=-1,n=s1.size();
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i]){
                if(idx>=0) {
                    swap(s1[idx],s1[i]);
                    break;
                }
                idx = i;
            }
        }
        return s1==s2;
    }
};