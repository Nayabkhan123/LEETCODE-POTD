/*
    You are given a 0-indexed integer array nums.

    Return the maximum value over all triplets of indices (i, j, k) such that i < j < k. 
    If all such triplets have a negative value, return 0.

    The value of a triplet of indices (i, j, k) is equal to (nums[i] - nums[j]) * nums[k].
*/


// O(n)
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();
        long long maxDiff=0,maxLeft=0,ans;
        for(int i=0;i<n;i++){
            ans=max(ans,(long long)maxDiff*nums[i]);
            maxLeft=max(maxLeft,(long long)nums[i]);
            maxDiff=max(maxDiff,(long long)maxLeft-nums[i]);
        }
        return ans;
    }
};

// O(n^2)
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;
        for(int j=0;j<n;j++){
            int max_i = 0;
            for(int i=0;i<j;i++){
                max_i=max(max_i,nums[i]);
            }
            int max_k = 0;
            for(int k=j+1;k<n;k++){
                max_k=max(max_k,nums[k]);
            }
            long long triplet = (long long) (max_i-nums[j])*max_k;
            ans=max(ans,triplet);
        }
        return ans;
    }
};

// BRUTE FORCE O(n^3)
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;
        for(int i=0;i<n-2;i++){
            for (int j=i+1;j<n-1;j++){
                for(int k=j+1;k<n;k++){
                    long long triplet=(long long)(nums[i]-nums[j])*nums[k];
                    ans=max(ans,triplet);
                }
            }
        }
        return ans;
    }
};