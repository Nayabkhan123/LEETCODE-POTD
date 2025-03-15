/*
    There are several consecutive houses along a street, each of which has some money inside. 
    There is also a robber, who wants to steal money from the homes, but he refuses to steal 
    from adjacent homes.

    The capability of the robber is the maximum amount of money he steals from one house of 
    all the houses he robbed.

    You are given an integer array nums representing how much money is stashed in each house. 
    More formally, the ith house from the left has nums[i] dollars.

    You are also given an integer k, representing the minimum number of houses the robber will 
    steal from. It is always possible to steal at least k houses.

    Return the minimum capability of the robber out of all the possible ways to steal at least k houses.
*/

class Solution {
    public:
        int robberyPossible(int capability,vector<int>& nums, int k){
            int cnt=0;
            for(int i=0;i<nums.size();i++){
                if(nums[i]<=capability){
                    cnt++;
                    i++;
                }
            }
            return cnt>=k;
        }
        int minCapability(vector<int>& nums, int k) {
            int start = INT_MAX;
            int end = INT_MIN;
            for(auto it : nums){
                if(it<start) start=it;
                if(it>end) end=it;
            }
            int ans=0;
            while(start<=end){
                int mid = start + (end-start)/2;
                if(robberyPossible(mid,nums,k)){
                    ans=mid;
                    end=mid-1;
                }
                else{
                    start=mid+1;
                }
            }
            return ans;
        }
    };