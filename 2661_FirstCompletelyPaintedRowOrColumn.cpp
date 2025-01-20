/*
    You are given a 0-indexed integer array arr, and an m x n integer matrix mat. arr and mat both contain all 
    the integers in the range [1, m * n].

    Go through each index i in arr starting from index 0 and paint the cell in mat containing the integer arr[i].

    Return the smallest index i at which either a row or a column will be completely painted in mat.
*/

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int,pair<int,int>>mp;
        int n=mat.size();
        int m=mat[0].size();
        vector<int>rows(n);
        vector<int>cols(m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mp[mat[i][j]] = {i,j};
            }
        }
        for(int i=0;i<n*m;i++){
            auto pair = mp[arr[i]];
            if(++rows[pair.first]==m || ++cols[pair.second]==n) return i; 
        }
        return -1;
    }
};