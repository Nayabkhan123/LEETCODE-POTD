/*
    Given an integer array nums, return the number of subarrays of length 3 such that the sum 
    of the first and third numbers equals exactly half of the second number.
*/

class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int cnt=0;
        for(int i=0;i<nums.size()-2;i++){
            if(nums[i]+nums[i+2]==(double)nums[i+1]/2) cnt++;
        }
        return cnt;
    }
};