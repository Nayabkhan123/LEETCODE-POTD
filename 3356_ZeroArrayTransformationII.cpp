/*
    You are given an integer array nums of length n and a 2D array queries where 
    queries[i] = [li, ri, vali].

    Each queries[i] represents the following action on nums:

    Decrement the value at each index in the range [li, ri] in nums by at most vali.
    The amount by which each value is decremented can be chosen independently for each index.
    A Zero Array is an array with all its elements equal to 0.

    Return the minimum possible non-negative value of k, such that after processing 
    the first k queries in sequence, nums becomes a Zero Array. If no such k exists, return -1.
*/

class Solution {
    public:
        int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
            int n=nums.size();
            vector<int> diff(n+1,0);
            int sum=0;
            int pos=0;
            for(int i=0;i<n;++i){
                while(sum + diff[i] < nums[i]){
                    if(pos==queries.size())
                        return -1;
                    
                    int start = queries[pos][0];
                    int end = queries[pos][1];
                    int val = queries[pos][2];
                    pos++;
                    
                    if(end < i) continue;
    
                    diff[max(start,i)]+=val;
                    diff[end+1]-=val;
                }
                sum += diff[i];
            }
            return pos;
        }
    };