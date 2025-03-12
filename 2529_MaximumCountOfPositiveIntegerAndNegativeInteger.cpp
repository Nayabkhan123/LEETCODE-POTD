/*
    Given an array nums sorted in non-decreasing order, return the maximum between 
    the number of positive integers and the number of negative integers.

    In other words, if the number of positive integers in nums is pos and the number 
    of negative integers is neg, then return the maximum of pos and neg.
    Note that 0 is neither positive nor negative.
*/

// O(log(n))

class Solution {
    public:
        int binary(vector<int>&nums,int start,int end,int target){
            while(start<=end){
                int mid = start + (end-start)/2;
                if(nums[mid]<=target){
                    start=mid+1;
                }
                else{
                    end=mid-1;
                }
            }
            return start;
        }
        int maximumCount(vector<int>& nums) {
            int n=nums.size();
            int negPos = binary(nums,0,n-1,-1);
            int posPos = binary(nums,negPos,n-1,0);
            int posCnt = n-posPos;
            return max(negPos,posCnt);
        }
    };

// O(n)
class Solution {
    public:
        int maximumCount(vector<int>& nums) {
            int n=nums.size(),negCnt=0,posCnt=0;
            for(int i=0;i<n;i++){
                if(nums[i]<0){
                    negCnt++;
                }
                else if(nums[i]>0){
                    posCnt++;
                }
            }
            return max(negCnt,posCnt);
        }
    };