/*
    Given an integer array nums, return true if you can partition the array into two subsets
    such that the sum of the elements in both subsets is equal or false otherwise.
*/

// using DP
class Solution {
    public:
        bool solve(int n,int halfSum,vector<int>&nums,vector<vector<int>>&dp){
            if(halfSum==0){
                return true;
            }
            if(n==0){
                return nums[0]==halfSum;
            }
            if(dp[n][halfSum]!=-1) return dp[n][halfSum];
            bool notTake = solve(n-1,halfSum,nums,dp);
            bool take = false;
            if(halfSum>=nums[n]){
                take = solve(n-1,halfSum-nums[n],nums,dp);
            }
            return dp[n][halfSum] = take || notTake;
        }
        bool canPartition(vector<int>& nums) {
            int totalSum=0,n=nums.size();
            for(auto it : nums){
                totalSum+=it;
            }
            if(totalSum%2!=0) return false;
            vector<vector<int>>dp(n,vector<int>(totalSum/2+1,-1));
            return solve(n-1,totalSum/2,nums,dp);
        }
    };

// Brute Force Approach
class Solution {
    public:
        bool solve(int n,int halfSum,vector<int>&nums){
            if(halfSum==0){
                return true;
            }
            if(n==0){
                return nums[0]==halfSum;
            }
            bool notTake = solve(n-1,halfSum,nums);
            bool take = false;
            if(halfSum>=nums[n]){
                take = solve(n-1,halfSum-nums[n],nums);
            }
            return take || notTake;
        }
        bool canPartition(vector<int>& nums) {
            int totalSum=0,n=nums.size();
            for(auto it : nums){
                totalSum+=it;
            }
            if(totalSum%2!=0) return false;
            return solve(n-1,totalSum/2,nums);
        }
    };