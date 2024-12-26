/*
    You are given an integer array nums and an integer target.

    You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums 
    and then concatenate all the integers.

    For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the 
    expression "+2-1".
    Return the number of different expressions that you can build, which evaluates to target.
*/

//using Recursion
void targetSum(int i,vector<int>&nums,int target,int sum,int& cnt){
    if(i==nums.size()){
        if(target==sum) cnt++;
        return;
    }
    targetSum(i+1,nums,target,sum+nums[i],cnt);
    targetSum(i+1,nums,target,sum-nums[i],cnt);
}
int findTargetSumWays(vector<int>& nums, int target) {
    int cnt=0;
    targetSum(0,nums,target,0,cnt);
    return cnt;
}