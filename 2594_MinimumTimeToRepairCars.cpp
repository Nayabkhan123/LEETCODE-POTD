/*
    You are given an integer array ranks representing the ranks of some mechanics. 
    ranksi is the rank of the ith mechanic. A mechanic with a rank r can repair n 
    cars in r * n2 minutes.

    You are also given an integer cars representing the total number of cars 
    waiting in the garage to be repaired.

    Return the minimum time taken to repair all the cars.

    Note: All the mechanics can repair the cars simultaneously.
*/

class Solution {
    public:
        bool isRepairPossible(long long time,vector<int>& ranks, int cars){
            long long cnt=0;
            for(auto it : ranks){
                cnt += (long long)sqrt((double)time/it);
                if(cnt>=cars) return true;
            }
            return false;
        }
        long long repairCars(vector<int>& ranks, int cars) {
            long long start = 0;
            long long end = 0;
            for(auto it : ranks){
                if(it>end){
                    end=it;
                }
                if(it<start){
                    start=it;
                }
            }
            end = end*cars*cars;
            long long ans=0;
            while(start<=end){
                long long mid = start + (end-start)/2;
                if(isRepairPossible(mid,ranks,cars)){
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