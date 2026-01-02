/*
    You are given an integer array nums with the following properties:
    nums.length == 2 * n.
    nums contains n + 1 unique elements.
    Exactly one element of nums is repeated n times.
    Return the element that is repeated n times.

    Example 1:

    Input: nums = [1,2,3,3]
    Output: 3
    Example 2:

    Input: nums = [2,1,2,5,3,2]
    Output: 2
*/

// optimal approach
int repeatedNTimes(vector<int>& nums) {
    int n=nums.size();
    for(int i=0;i<n;i++){
        if(i+1<n && nums[i]==nums[i+1]) return nums[i];
        else if(i+2<n && nums[i]==nums[i+2]) return nums[i];
        else if(i+3<n && nums[i]==nums[i+3]) return nums[i];
    }
    return -1;
}

// using hashmap
int repeatedNTimes(vector<int>& nums) {
    int n=nums.size();
    unordered_map<int,int>mp;
    for(auto it:nums){
        mp[it]++;
        if(mp[it]>1) return it;
    }
    return 0;
}