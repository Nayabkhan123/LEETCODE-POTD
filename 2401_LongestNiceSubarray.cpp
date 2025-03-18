/*
    You are given an array nums consisting of positive integers.

    We call a subarray of nums nice if the bitwise AND of every pair of elements that are 
    in different positions in the subarray is equal to 0.

    Return the length of the longest nice subarray.

    A subarray is a contiguous part of an array.

    Note that subarrays of length 1 are always considered nice.
*/

class Solution {
    public:
        int longestNiceSubarray(vector<int>& nums) {
            int n=nums.size();
            int left=0;
            int right=0;
    
            int max_window_size = 0;
            int xor_sum=0;
            int curr_sum=0;
            while(right<n){
                curr_sum += nums[right];
                xor_sum ^= nums[right];
                while(xor_sum!=curr_sum){
                    curr_sum -= nums[left];
                    xor_sum ^= nums[left];
                    left++;
                }
                max_window_size = max(max_window_size,right-left+1);
                right++;
            }
            return max_window_size;
        }
    };