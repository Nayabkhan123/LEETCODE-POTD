/*
    You are given an integer n. There is an undirected graph with n vertices, numbered 
    from 0 to n - 1. You are given a 2D integer array edges where edges[i] = [ai, bi] 
    denotes that there exists an undirected edge connecting vertices ai and bi.

    Return the number of complete connected components of the graph.

    A connected component is a subgraph of a graph in which there exists a path between 
    any two vertices, and no vertex of the subgraph shares an edge with a vertex outside of the subgraph.

    A connected component is said to be complete if there exists an edge between every pair of its vertices.
*/

class Solution {
    public:
        void function(int currnode,int& nodes,int& edges,vector<vector<int>>&adj,vector<bool>&visited){
            nodes++;
            visited[currnode]=true;
            for(auto it : adj[currnode]){
                edges++;
                if(!visited[it]){
                    function(it,nodes,edges,adj,visited);
                }
            }
        }
        int countCompleteComponents(int n, vector<vector<int>>& edges) {
            vector<vector<int>>adj(n);
            for(auto it : edges){
                adj[it[0]].push_back(it[1]);
                adj[it[1]].push_back(it[0]);
            }
            vector<bool>visited(n,false);
            int ans=0;
            for(int i=0;i<n;i++){
                if(!visited[i]){
                    int nodes=0,edges=0;
                    function(i,nodes,edges,adj,visited);
                    if(edges==(nodes*(nodes-1))){
                        ans++;
                    }
                }
            }
            return ans;
        }
    };