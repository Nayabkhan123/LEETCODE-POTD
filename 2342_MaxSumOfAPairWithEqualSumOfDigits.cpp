/*
    You are given a 0-indexed array nums consisting of positive integers. You can choose two 
    indices i and j, such that i != j, and the sum of digits of the number nums[i] is equal to 
    that of nums[j].

    Return the maximum value of nums[i] + nums[j] that you can obtain over all possible 
    indices i and j that satisfy the conditions.

*/

class Solution {
    public:
        void digitSum(int num,unordered_map<int,vector<int>>&mp,int &ans){
            int rem=0,i=num;
            while(i){
                rem = rem + i%10;
                i=i/10;
            }
            mp[rem].push_back(num);
        }
        int maximumSum(vector<int>& nums) {
            int n=nums.size(),ans=-1;
            unordered_map<int,vector<int>>mp;
            for(int i=0;i<n;i++){
                digitSum(nums[i],mp,ans);
            }
            for(auto it : mp){
                int size = it.second.size();
                if(size>1){
                    sort(it.second.begin(),it.second.end());
                    ans=max(ans,it.second[size-1]+it.second[size-2]);
                }
            }
            return ans;
        }
    };