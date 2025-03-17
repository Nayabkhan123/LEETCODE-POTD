/*
    You are given an integer array nums consisting of 2 * n integers.

    You need to divide nums into n pairs such that:

    Each element belongs to exactly one pair.
    The elements present in a pair are equal.
    Return true if nums can be divided into n pairs, otherwise return false.
*/

class Solution {
    public:
        bool divideArray(vector<int>& nums) {
            int m=nums.size()/2;
            unordered_map<int,int>mp;
            for(auto it : nums) mp[it]++;
            for(auto it : mp){
                if(it.second%2) return false;
            }
            return true;
        }
    };