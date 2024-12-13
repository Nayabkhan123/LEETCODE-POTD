/* You are given an array nums consisting of positive integers.

Starting with score = 0, apply the following algorithm:

Choose the smallest integer of the array that is not marked. If there is a tie, choose the one with the smallest index.
Add the value of the chosen integer to score.
Mark the chosen element and its two adjacent elements if they exist.
Repeat until all the array elements are marked.
Return the score you get after applying the above algorithm. */

//optimized approach
long long findScore(vector<int>& nums) {
    int n=nums.size();
    long long score=0;
    vector<vector<int>> copy(n,vector<int>(2));
    for(int i=0;i<n;i++){
        copy[i][0]=nums[i];
        copy[i][1]=i;
    }
    sort(copy.begin(),copy.end());
    for(int i=0;i<n;i++){
        int index=copy[i][1];
        if(nums[index]<0) continue;
        score+=nums[index];
        nums[index] = -1;
        if((index-1)>=0) nums[index-1] = -1;
        if((index+1)<=n-1) nums[index+1] = -1;
    }
    return score;
}
// brute force approch (it gives TLE) 1036 / 1044 testcases passed
class Solution {
public:
    int minindex(vector<int>& nums){
        int idx=-1,min=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(min>nums[i]&&nums[i]!=-1){
                min=nums[i];
                idx=i;
            }
        }
        return idx;
    }
    long long findScore(vector<int>& nums) {
        long long score=0;
        int minind=0;
        while(1){
            minind=minindex(nums);
            if(minind==-1) return score;
            score+=nums[minind];
            nums[minind]=-1;
            if(minind-1>=0) nums[minind-1]=-1;
            if(minind+1<=nums.size()-1) nums[minind+1]=-1;
        }
        return score;
    }
};