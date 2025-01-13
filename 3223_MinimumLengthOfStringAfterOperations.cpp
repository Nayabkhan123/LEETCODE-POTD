/*
    You are given a string s.
    You can perform the following process on s any number of times:

    Choose an index i in the string such that there is at least one character to the left of index i that is 
    equal to s[i], and at least one character to the right that is also equal to s[i].
    Delete the closest character to the left of index i that is equal to s[i].
    Delete the closest character to the right of index i that is equal to s[i].
    Return the minimum length of the final string s that you can achieve.
*/

class Solution {
public:
    int minimumLength(string s) {
        int len=0;
        unordered_map<char,int>mp;
        for(auto it:s) mp[it]++;
        for(auto it:mp){
            if(it.second%2==0) len+=2;
            else len+=1;
        }
        return len;
    }
};