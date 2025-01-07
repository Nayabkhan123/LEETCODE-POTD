/*
    Given an array of string words, return all strings in words that is a substring of another word. You can 
    return the answer in any order.

    A substring is a contiguous sequence of characters within a string
*/

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string>ans;
        int n=words.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) continue;
                auto small = words[j].find(words[i]);
                if(small != string::npos){
                    ans.push_back(words[i]);
                    break;
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    bool isvalid(string small,string big){
        for(int i=0;i<big.size()-small.size()+1;i++){
            if(big.substr(i,small.size())==small) return true;
        }
        return false;
    }
    vector<string> stringMatching(vector<string>& words) {
        vector<string>ans;
        int n=words.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) continue;
                if(words[i].size()>words[j].size()) continue;
                if(isvalid(words[i],words[j])) {
                    ans.push_back(words[i]);
                    break;
                }
            }
        }
        return ans;
    }
};