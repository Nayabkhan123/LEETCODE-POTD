/*
    In this problem, a tree is an undirected graph that is connected and has no cycles.

    You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional 
    edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that 
    already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] 
    indicates that there is an edge between nodes ai and bi in the graph.

    Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are 
    multiple answers, return the answer that occurs last in the input.
*/

class Solution {
    int find(vector<int>& dsuf,int v){
        if(dsuf[v]==-1)
            return v;
        return dsuf[v] = find(dsuf,dsuf[v]);
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int> dsuf(n+1,-1);
        for(auto edge: edges){
            int parent_x = find(dsuf,edge[0]);
            int parent_y = find(dsuf,edge[1]);
            
            if(parent_x == parent_y)
                return edge;
            else
                dsuf[parent_x] = parent_y;
        }
        return {0,0};
    }
};