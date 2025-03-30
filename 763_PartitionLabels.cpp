/*
    You are given a string s. We want to partition the string into as many parts as possible 
    so that each letter appears in at most one part. For example, the string "ababcc" can be 
    partitioned into ["abab", "cc"], but partitions such as ["aba", "bcc"] or ["ab", "ab", "cc"] 
    are invalid.

    Note that the partition is done so that after concatenating all the parts in order, the 
    resultant string should be s.

    Return a list of integers representing the size of these parts.
*/

class Solution {
    public:
        vector<int> partitionLabels(string s) {
            unordered_map<int,int>mp;
            int n=s.size();
            for(int i=0;i<n;i++){
                mp[s[i]]=i;
            }
            vector<int>ans;
            int last=0,prev=-1;
            for(int i=0;i<n;i++){
                last=max(last,mp[s[i]]);
                if(last==i) {
                    ans.push_back(last-prev);
                    prev=last;
                }
            }
            return ans;
        }
    };