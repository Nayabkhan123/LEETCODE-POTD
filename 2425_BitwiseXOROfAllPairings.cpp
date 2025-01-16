/*
    You are given two 0-indexed arrays, nums1 and nums2, consisting of non-negative integers. There exists 
    another array, nums3, which contains the bitwise XOR of all pairings of integers between nums1 and nums2 
    (every integer in nums1 is paired with every integer in nums2 exactly once).

    Return the bitwise XOR of all integers in nums3.
*/

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size(),ans=0;
        if(n1%2 == 0 && n2%2 == 0){
            return 0;
        }
        else if(n1%2 == 0 && n2%2 == 1){
            for(auto it:nums1){
                ans^=it;
            }
        }
        else if (n1%2 == 1 && n2%2 == 0){
            for(auto it:nums2){
                ans^=it;
            }
        }
        else{
            for(auto it:nums1){
                ans^=it;
            }
            for(auto it:nums2){
                ans^=it;
            }
        }
        return ans;
    }
};