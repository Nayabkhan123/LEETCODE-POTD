/*
There is an undirected tree with n nodes labeled from 0 to n - 1. You are given the integer n and a 2D integer array 
edges of length n - 1, where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.

You are also given a 0-indexed integer array values of length n, where values[i] is the value associated with 
the ith node, and an integer k.

A valid split of the tree is obtained by removing any set of edges, possibly empty, from the tree such that the 
resulting components all have values that are divisible by k, where the value of a connected component is the 
sum of the values of its nodes.

Return the maximum number of components in any valid split.
*/

class Solution {
public:
    long long dfs(int node, int parent, const vector<vector<int>> &adj, const vector<int>& values, int& res, int k){
        long long preSum = values[node];
        for(int child:adj[node]){
            if(child==parent) continue;
            preSum+=dfs(child,node,adj,values,res,k);
        }
        if(preSum%k==0){
            ++res;
            return 0;
        }
        return preSum;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adj(n);
        for(auto &e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int res = 0;
        dfs(0,-1,adj,values,res,k);
        return res;
    }
};