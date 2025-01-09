/*
    You are given an array of strings words and a string pref.

    Return the number of strings in words that contain pref as a prefix.

    A prefix of a string s is any leading contiguous substring of s.
*/

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n=words.size(),sz=pref.size(),cnt=0;
        for(auto st : words){
            if(st.size()>=sz && st.substr(0,sz)==pref) cnt++;
        }
        return cnt;
    }
};