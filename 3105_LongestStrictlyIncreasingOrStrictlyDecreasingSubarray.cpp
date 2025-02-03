/*
    You are given an array of integers nums. Return the length of the longest subarray of nums which is either 
    strictly increasing or strictly decreasing.
*/

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size(),inc=1,dec=1,ans=1;
        for(int i=0;i<n-1;i++){
            if(nums[i]<nums[i+1]){
                inc++;
                dec=1;
            }
            else if(nums[i]>nums[i+1]){
                dec++;
                inc=1;
            }
            else{
                dec=1;
                inc=1;
            }
            ans=max(ans,max(inc,dec));
        }
        return ans;
    }
};