/*
You are given a 0-indexed integer array nums. A subarray of nums is called continuous if:

Let i, i + 1, ..., j be the indices in the subarray. Then, for each pair of indices i <= i1, i2 <= j, 0 <= |nums[i1] - nums[i2]| <= 2.
Return the total number of continuous subarrays.

A subarray is a contiguous non-empty sequence of elements within an array.
*/

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n=nums.size(),i=0,j=0,update=1,currmin=nums[0],currmax=nums[0];
        long long ans=0;
        while(j<n){
            currmin=min(currmin,nums[j]);
            currmax=max(currmax,nums[j]);
            if(currmax-currmin<=2){
                ans+=update;
                update++;
            }
            else{
                currmax=nums[j];
                currmin=nums[j];
                i=j;
                update=1;
                while(i>=0&&abs(nums[j]-nums[i]) <=2){
                    ans++;
                    update++;
                    currmin = min(currmin,nums[i]);
                    currmax = max(currmax,nums[i]);
                    i--;
                }
            }
            j++;
        }
        return ans;
    }
};