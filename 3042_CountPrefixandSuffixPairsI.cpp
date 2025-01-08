/*
    You are given a 0-indexed string array words.

    Let's define a boolean function isPrefixAndSuffix that takes two strings, str1 and str2:

    isPrefixAndSuffix(str1, str2) returns true if str1 is both a 
    prefix
    and a 
    suffix
    of str2, and false otherwise.
    For example, isPrefixAndSuffix("aba", "ababa") is true because "aba" is a prefix of "ababa" and also a suffix, 
    but isPrefixAndSuffix("abc", "abcd") is false.

    Return an integer denoting the number of index pairs (i, j) such that i < j, and isPrefixAndSuffix(words[i], 
    words[j]) is true.
*/

class Solution {
public:
    bool isPrefixAndSuffix(string str1,string str2){
        int n1=str1.size(),n2=str2.size();
        if(n1>n2) return false;
        if(str2.substr(0,n1)==str1&&str2.substr(n2-n1,n2)==str1) return true;
        return false;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int cnt=0,n=words.size();
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                cnt+=isPrefixAndSuffix(words[i],words[j]);
            }
        }
        return cnt;
    }
};