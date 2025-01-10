/*
    You are given two string arrays words1 and words2.

    A string b is a subset of string a if every letter in b occurs in a including multiplicity.

    For example, "wrr" is a subset of "warrior" but is not a subset of "world".
    A string a from words1 is universal if for every string b in words2, b is a subset of a.

    Return an array of all the universal strings in words1. You may return the answer in any order.
*/

class Solution {
public:
    vector<int> countFreq(string s){
        vector<int>temp(26);
        for(auto ch : s){
            temp[ch-'a']++;
        }
        return temp;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int>freq(26,0);
        for(auto word : words2){
            vector<int>temp = countFreq(word);
            for(int i=0;i<26;i++){
                freq[i] = max(freq[i],temp[i]);
            }
        }
        vector<string>ans;
        for(auto word : words1){
            vector<int>temp = countFreq(word);
            bool flag = true;
            for(int i=0;i<26;i++){
                if(freq[i]>temp[i]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                ans.push_back(word);
            }
        }
        return ans;
    }
};