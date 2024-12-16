/*
You are given an integer array nums, an integer k, and an integer multiplier.

You need to perform k operations on nums. In each operation:

Find the minimum value x in nums. If there are multiple occurrences of the minimum value, 
select the one that appears first.
Replace the selected minimum value x with x * multiplier.
Return an integer array denoting the final state of nums after performing all k operations.

 
*/

class Solution {
public:
    int min(vector<int>&nums){
        int mini=INT_MAX,idx=-1;
        for(int i=0;i<nums.size();i++){
            if(mini>nums[i]){
                mini = nums[i];
                idx=i;
            }
        }
        return idx;
    }
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        while(k--){
            int idx = min(nums);
            nums[idx]=multiplier*nums[idx];
        }
        return nums;
    }
};