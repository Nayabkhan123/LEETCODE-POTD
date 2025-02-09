/*
    You are given a 0-indexed integer array nums. A pair of indices (i, j) is a bad pair 
    if i < j and j - i != nums[j] - nums[i].

    Return the total number of bad pairs in nums.
*/

class Solution {
    public:
        long long countBadPairs(vector<int>& nums) {
            unordered_map<int,int>mp;
            long long n=nums.size(),goodPairs=0,badPairs=0;
            long long totalPairs = (n*(n-1))/2;
            for(int i=0;i<n;i++){
                if(mp[i-nums[i]]){
                    goodPairs+=mp[i-nums[i]];
                }
                mp[i-nums[i]]++;
            }
        return totalPairs-goodPairs;
    }
};

// Brute Force Approach
class Solution {
    public:
        long long countBadPairs(vector<int>& nums) {
            int n=nums.size(),ans=0;
            for(int i=0;i<n-1;i++){
                for(int j=i+1;j<n;j++){
                    if((j-i)!=(nums[j]-nums[i])){
                        ans++;
                    }
                }
            }
        return ans;
    }
};