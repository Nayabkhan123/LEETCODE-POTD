/*
    Given a string s of zeros and ones, return the maximum score after splitting the string into two non-empty 
    substrings (i.e. left substring and right substring).

    The score after splitting a string is the number of zeros in the left substring plus the number of ones in the 
    right substring.
*/

class Solution {
public:
    int maxScore(string s) {
        int zero=0,one=0,maxi=-1;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1') one++;
        }
        for(int i=0;i<s.size()-1;i++){
            if(s[i]=='0') zero++;
            else one--;
            maxi=max(maxi,zero+one);
        }
        return maxi;
    }
};