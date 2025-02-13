/*
    You are given a 0-indexed integer array nums, and an integer k.

    In one operation, you will:

    Take the two smallest integers x and y in nums.
    Remove x and y from nums.
    Add min(x, y) * 2 + max(x, y) anywhere in the array.
    Note that you can only apply the described operation if nums contains at least two elements.

    Return the minimum number of operations needed so that all elements of the array are greater than 
    or equal to k.
*/

class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            int cnt=0;
            priority_queue<long long,vector<long long>,greater<long long>>q;
            for(auto it:nums){
                q.push(it);
            }
            while(!q.empty()){
                long long x = q.top();
                if(x<k){
                    q.pop();
                    long long y = q.top();
                    q.pop();
                    long long num = min(x,y)*2 + max(x,y);
                    q.push(num);
                    cnt++;
                }
                else break;
            }
            return cnt;
        }
    };