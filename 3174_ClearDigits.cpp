/*
    You are given a string s.

    Your task is to remove all digits by doing this operation repeatedly:

    Delete the first digit and the closest non-digit character to its left.
    Return the resulting string after removing all digits.
*/

class Solution {
public:
    string clearDigits(string s) {
        string ans="";
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]<97 || s[i]>122){
                ans.pop_back();
            }
            else ans.push_back(s[i]);
        }
        return ans;
    }
};

class Solution {
public:
    string clearDigits(string s) {
        string ans="";
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]<97 || s[i]>122){
                s[i]='@';
                int j=i-1;
                while(j>=0){
                    if(s[j]>=97 && s[j]<=122){
                        s[j]='@';
                        break;
                    }
                    j--;
                }
            }
        }
        for(auto it : s){
            if(it!='@') ans+=it;
        }
        return ans;
    }
};