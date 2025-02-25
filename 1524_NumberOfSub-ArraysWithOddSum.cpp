/*
    Given an array of integers arr, return the number of subarrays with an odd sum.

    Since the answer can be very large, return it modulo 109 + 7.
*/

class Solution {
    public:
        int numOfSubarrays(vector<int>& arr) {
            int oddCnt=0,evenCnt=1,prefix=0,res=0,mod=1000000007;
            for(auto it:arr){
                prefix+=it;
                if(prefix&1){
                    res+=evenCnt;
                    oddCnt++;
                    
                }
                else{
                    res+=oddCnt;
                    evenCnt++;
                }
                res = res%mod;
            }
            return res;
        }
    };