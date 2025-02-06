/*
    Given an array nums of distinct positive integers, return the number of tuples (a, b, c, d) 
    such that a * b = c * d where a, b, c, and d are elements of nums, and a != b != c != d.
*/

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n=nums.size(),cnt=0;
        unordered_map<int,int>mp;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int temp = nums[i]*nums[j];
                if(mp[temp]){
                    cnt+=8*mp[temp];
                }
                mp[temp]++;
            }
        }
        return cnt;
    }
};