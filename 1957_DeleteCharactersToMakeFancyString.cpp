class Solution {
public:
    string makeFancyString(string s) {
        string ans="";
        ans+=s[0];
        if(s.length()>1) ans+=s[1];
        for(int i=2;i<s.length();i++){
            if(s[i]==s[i-1]&&s[i-1]==s[i-2]) continue;
            else  ans+=s[i];
        }
        return ans;
    }
};