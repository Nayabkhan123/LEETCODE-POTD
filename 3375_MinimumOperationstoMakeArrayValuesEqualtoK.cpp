/*
    You are given an integer array nums and an integer k.

    An integer h is called valid if all values in the array that are strictly greater than h are identical.

    For example, if nums = [10, 8, 10, 8], a valid integer is h = 9 because all nums[i] > 9 are 
    equal to 10, but 5 is not a valid integer.

    You are allowed to perform the following operation on nums:

    Select an integer h that is valid for the current values in nums.
    For each index i where nums[i] > h, set nums[i] to h.
    Return the minimum number of operations required to make every element in nums equal to k. 
    If it is impossible to make all elements equal to k, return -1.
*/

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(auto it:nums){
            if(it<k) return -1;
            else if(it>k) mp[it]++;
        }
        return mp.size();
    }
};

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int cnt=0,n=nums.size();
        if(nums[0]<k) return -1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>k){
                cnt++;
                while(i+1<n && nums[i]==nums[i+1]) i++;
            }
        }
        return cnt;
    }
};