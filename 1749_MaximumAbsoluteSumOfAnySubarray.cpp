/*
    You are given an integer array nums. The absolute sum of a subarray 
    [numsl, numsl+1, ..., numsr-1, numsr] is abs(numsl + numsl+1 + ... + numsr-1 + numsr).

    Return the maximum absolute sum of any (possibly empty) subarray of nums.

    Note that abs(x) is defined as follows:

    If x is a negative integer, then abs(x) = -x.
    If x is a non-negative integer, then abs(x) = x.
*/

class Solution {
    public:
        int maxAbsoluteSum(vector<int>& nums) {
            int posmax=0,negmax = 0,poscurr = 0,negcurr=0;
            for(auto it:nums){
                poscurr+=it;
                negcurr+=it;
                posmax=max(posmax,poscurr);
                negmax=min(negmax,negcurr);
                if(poscurr<0){
                    poscurr=0;
                }
                if(negcurr>0){
                    negcurr=0;
                }
            }   
            return max(posmax,abs(negmax));
        }
    };