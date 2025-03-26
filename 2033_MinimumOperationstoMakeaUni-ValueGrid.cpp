/*
    You are given a 2D integer grid of size m x n and an integer x. In one operation, 
    you can add x to or subtract x from any element in the grid.

    A uni-value grid is a grid where all the elements of it are equal.

    Return the minimum number of operations to make the grid uni-value. If it is not 
    possible, return -1.
*/

class Solution {
    public:
        int minOperations(vector<vector<int>>& grid, int x) {
            vector<int> array;
            int remainder = grid[0][0]%x;
    
            for(int i=0;i<grid.size();++i){
                for(int j=0;j<grid[0].size();++j){
                    if(grid[i][j]%x != remainder)
                        return -1;
                    array.push_back(grid[i][j]);
                }
            }
            sort(array.begin(),array.end());
            int n = array.size();
            int median = n/2;
            
            int steps = 0;
            for(int i=0;i<n;++i)
                steps += abs(array[i]-array[median])/x;
    
            return steps;
        }
    };