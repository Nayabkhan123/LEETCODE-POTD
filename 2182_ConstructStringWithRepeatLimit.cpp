/*
You are given a string s and an integer repeatLimit. Construct a new string repeatLimitedString 
using the characters of s such that no letter appears more than repeatLimit times in a row. 
You do not have to use all characters from s.

Return the lexicographically largest repeatLimitedString possible.

A string a is lexicographically larger than a string b if in the first position where a and b differ, 
string a has a letter that appears later in the alphabet than the corresponding letter in b. 
If the first min(a.length, b.length) characters do not differ, then the longer string is the lexicographically
larger one.
*/

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        int freq[26]={0};
        for(auto c:s){
            freq[c-'a']++;
        }
        string ans="";
        int index=25;
        while(index>=0){
            if(freq[index]==0){
                index--;
                continue;
            }
            int n=min(freq[index],repeatLimit);
            for(int i=0;i<n;i++){
                ans+=('a'+index);
            }
            freq[index]-=n;
            if(freq[index]>0){
                int previndex=index-1;
                while(previndex>=0&&freq[previndex]==0){
                    previndex--;
                }
                if(previndex<0){
                    break;
                }
                ans+=('a'+previndex);
                freq[previndex]--;
            }
        }
        return ans;
    }
};