#include<bits/stdc++.h>
class Solution {
public:
    int maximumLength(string s) {
        unordered_map<string,int>mp;
        int n = s.length();
        for(int i=0;i<n;i++){
            string currs="";
            for(int j=i;j<n;j++){
                if(currs.length()==0 || s[j]==currs[currs.length()-1]){
                    currs+=s[j];
                    mp[currs]++;
                }else{
                    break;
                }
            }
        }
        int ans=-1;
        for(auto it : mp){
            string ss=it.first;
            int frequency = it.second;
            if(frequency>2){
                cout<<ss.length()<<" ";
                if(int(ss.size())>ans){
                    ans=ss.size();
                }
            }
        }
    return ans;
    }
};