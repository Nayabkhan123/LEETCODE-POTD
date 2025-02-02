/*
    Given an array nums, return true if the array was originally sorted in non-decreasing order, then 
    rotated some number of positions (including zero). Otherwise, return false.

    There may be duplicates in the original array.

    Note: An array A rotated by x positions results in an array B of the same length such that 
    A[i] == B[(i+x) % A.length], where % is the modulo operation.
*/

class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size(),cnt=0;
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]) cnt++;
        }
        if(nums[n-1]>nums[0]) cnt++;
        return cnt<=1;
    }
};