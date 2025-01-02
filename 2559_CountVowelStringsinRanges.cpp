/*
    You are given a 0-indexed array of strings words and a 2D array of integers queries.

    Each query queries[i] = [li, ri] asks us to find the number of strings present in the range li to ri 
    (both inclusive) of words that start and end with a vowel.

    Return an array ans of size queries.length, where ans[i] is the answer to the ith query.

    Note that the vowel letters are 'a', 'e', 'i', 'o', and 'u'.
*/

class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        unordered_set<char>st={'a','e','i','o','u'};
        vector<int>ans,prefixsum(words.size());
        int cnt=0;
        for(int i=0;i<words.size();i++){
            string s=words[i];
            if(st.contains(s[0])&&st.contains(s[s.size()-1])){
                cnt++;
            }
            prefixsum[i]=cnt;
        }
        for(int i=0;i<queries.size();i++){
            int a=queries[i][0];
            int b=queries[i][1];
            if(a-1<0) ans.push_back(prefixsum[b]);
            else ans.push_back(prefixsum[b]-prefixsum[a-1]);
        }
        return ans;
    }
};

// Time Limit Exceeded 92 / 93 testcases passed
class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        unordered_map<int,bool>mp;
        vector<int>ans;
        for(int i=0;i<words.size();i++){
            string s=words[i];
            int len=s.size()-1;
            if((s[0]=='a'||s[0]=='e'||s[0]=='i'||s[0]=='o'||s[0]=='u')&&
                (s[len]=='a'||s[len]=='e'||s[len]=='i'||s[len]=='o'||s[len]=='u')){
                    mp[i]=true;
            }
            
        }
        for(int i=0;i<queries.size();i++){
            int cnt=0;
            for(int j=queries[i][0];j<=queries[i][1];j++){
                if(mp[j]) cnt++;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};