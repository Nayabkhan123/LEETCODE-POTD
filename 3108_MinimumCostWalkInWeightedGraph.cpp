/*
    There is an undirected weighted graph with n vertices labeled from 0 to n - 1.

    You are given the integer n and an array edges, where edges[i] = [ui, vi, wi] indicates 
    that there is an edge between vertices ui and vi with a weight of wi.

    A walk on a graph is a sequence of vertices and edges. The walk starts and ends with 
    a vertex, and each edge connects the vertex that comes before it and the vertex that 
    comes after it. It's important to note that a walk may visit the same edge or vertex more than once.

    The cost of a walk starting at node u and ending at node v is defined as the bitwise 
    AND of the weights of the edges traversed during the walk. In other words, if the 
    sequence of edge weights encountered during the walk is w0, w1, w2, ..., wk, then 
    the cost is calculated as w0 & w1 & w2 & ... & wk, where & denotes the bitwise AND operator.

    You are also given a 2D array query, where query[i] = [si, ti]. For each query, you need
     to find the minimum cost of the walk starting at vertex si and ending at vertex ti. 
     If there exists no such walk, the answer is -1.

    Return the array answer, where answer[i] denotes the minimum cost of a walk for query i.
*/

class Solution {
    #define pii pair<int,int>

    int find(vector<int>& dsuf,int v){
        if(dsuf[v]==-1)
            return v;
        return dsuf[v] = find(dsuf,dsuf[v]);
    }
    void traverseComponent(int& bitwise_and,int curr,vector<bool>& visited,vector<vector<pii>>& adj){
        visited[curr] = true;
        for(auto& [nbr,wt]: adj[curr]){
            bitwise_and &= wt;
            if(!visited[nbr])
                traverseComponent(bitwise_and,nbr,visited,adj);
        }
    }
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<int> dsuf(n,-1);
        vector<vector<pii>> adj(n);
        for(auto& edge: edges){
            adj[edge[0]].push_back(make_pair(edge[1],edge[2]));
            adj[edge[1]].push_back(make_pair(edge[0],edge[2]));

            int px = find(dsuf,edge[0]);
            int py = find(dsuf,edge[1]);
            if(px != py)
                dsuf[px] = py;
        }
        unordered_map<int,int> parent_cost;
        vector<bool> visited(n,false);
        for(int i=0;i<n;++i){
            if(!visited[i]){
                int bitwise_and = adj[i].size()==0? 0: adj[i][0].second;
                traverseComponent(bitwise_and,i,visited,adj);
                int parent = find(dsuf,i);
                parent_cost[parent] = bitwise_and;
            }
        }
        vector<int> ans;
        for(auto& q: query){
            int px = find(dsuf,q[0]);
            int py = find(dsuf,q[1]);
            if(px==py) ans.push_back(parent_cost[px]);
            else ans.push_back(-1);
        }
        return ans;
    }
};