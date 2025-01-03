/*
    You are given a 0-indexed integer array nums of length n.

    nums contains a valid split at index i if the following are true:

    The sum of the first i + 1 elements is greater than or equal to the sum of the last n - i - 1 elements.
    There is at least one element to the right of i. That is, 0 <= i < n - 1.
    Return the number of valid splits in nums.
*/

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long totalsum=0,sum=0;
        int cnt=0;
        for(auto it:nums) totalsum+=it;
        for(int i=0;i<nums.size()-1;i++){
            totalsum-=nums[i];
            sum+=nums[i];
            if(totalsum<=sum){
                cnt++;
            }
        }
        return cnt;
    }
};


int waysToSplitArray(vector<int>& nums) {
    long long totalSum=0,prefixSum=0;
    for(auto it:nums) totalSum+=it;
    int cnt=0;
    for(int i=0;i<nums.size()-1;i++){
        prefixSum+=nums[i];
        if(prefixSum>=totalSum-prefixSum) cnt++;
    }
    return cnt;
}