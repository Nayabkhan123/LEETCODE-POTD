/*
    You are given a 0-indexed 2D integer matrix grid of size n * n with values in 
    the range [1, n2]. Each integer appears exactly once except a which appears 
    twice and b which is missing. The task is to find the repeating and missing numbers a and b.

    Return a 0-indexed integer array ans of size 2 where ans[0] equals to a and ans[1] equals to b.
*/

class Solution {
    public:
        vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
            int n=grid.size();
            int len=(n*n)+1;
            vector<int>v(len);
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    v[grid[i][j]]++;
                }
            }
            int a,b;
            for(int i=0;i<len;i++){
                if(v[i]==2){
                    a=i;
                }
                if(v[i]==0){
                    b=i;
                }
            }
            return {a,b};
        }
    };