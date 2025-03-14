/*
    You are given a 0-indexed integer array candies. Each element in the array denotes 
    a pile of candies of size candies[i]. You can divide each pile into any number of 
    sub piles, but you cannot merge two piles together.

    You are also given an integer k. You should allocate piles of candies to k children 
    such that each child gets the same number of candies. Each child can be allocated 
    candies from only one pile of candies and some piles of candies may go unused.

    Return the maximum number of candies each child can get.
*/

class Solution {
    bool canAssign(long long& mid,vector<int>& candies,long long& k){
        long long count=0;
        for(long long ele: candies){
            if(ele >= mid)
                count += ele/mid;
        }
        return count>=k;
    }
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long low = 1;
        long long high = *max_element(candies.begin(),candies.end());
        long long mid;

        long long max_candies=0;
        while(low<=high){
            mid = low+(high-low)/2;
            if(canAssign(mid,candies,k)){
                max_candies = mid;
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return max_candies;
    }
};