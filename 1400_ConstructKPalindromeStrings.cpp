/*
    Given a string s and an integer k, return true if you can use all the characters in s to construct k 
    palindrome strings or false otherwise.
*/

class Solution {
public:
    bool canConstruct(string s, int k) {
        vector<int>freq(26,0);
        int n=s.size();
        if(n<k) return false;
        if(n==k) return true;
        for(int i=0;i<n;i++){
            freq[s[i]-'a']++;
        }
        int oddcount = 0;
        for(int i=0;i<26;i++){
            if(freq[i]%2==1) oddcount++;
        }
        return (oddcount<=k);
    }
};