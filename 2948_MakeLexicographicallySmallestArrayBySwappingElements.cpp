/*
    You are given a 0-indexed array of positive integers nums and a positive integer limit.

    In one operation, you can choose any two indices i and j and swap nums[i] and nums[j] if 
    |nums[i] - nums[j]| <= limit.

    Return the lexicographically smallest array that can be obtained by performing the operation any number of times.

    An array a is lexicographically smaller than an array b if in the first position where a and b differ, array 
    a has an element that is less than the corresponding element in b. For example, the array [2,10,3] is 
    lexicographically smaller than the array [10,2,3] because they differ at index 0 and 2 < 10.
*/

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int>sorted=nums;
        int n = nums.size();
        sort(sorted.begin(),sorted.end());
        unordered_map<int,int>groupednumber;
        unordered_map<int,vector<int>>groupvector;
        int groupnum=0;
        groupednumber[sorted[0]] = groupnum;
        groupvector[groupnum].push_back(sorted[0]);
        for(int i=1;i<n;i++){
            if(sorted[i]-sorted[i-1]>limit) groupnum++;
            groupednumber[sorted[i]] = groupnum;
            groupvector[groupnum].push_back(sorted[i]);
        }
        for(int i=0;i<n;i++){
            int grp = groupednumber[nums[i]];
            nums[i] = groupvector[grp].front();
            groupvector[grp].erase(groupvector[grp].begin());
        }
        return nums;
    }
};