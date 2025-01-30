/*
    You are given a positive integer n representing the number of nodes in an undirected graph. The nodes 
    are labeled from 1 to n.

    You are also given a 2D integer array edges, where edges[i] = [ai, bi] indicates that there is a 
    bidirectional edge between nodes ai and bi. Notice that the given graph may be disconnected.

    Divide the nodes of the graph into m groups (1-indexed) such that:

    Each node in the graph belongs to exactly one group.
    For every pair of nodes in the graph that are connected by an edge [ai, bi], if ai belongs to the 
    group with index x, and bi belongs to the group with index y, then |y - x| = 1.
    Return the maximum number of groups (i.e., maximum m) into which you can divide the nodes. Return -1 
    if it is impossible to group the nodes with the given conditions.
*/

class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        
        for (auto& edge : edges) {
            int u = edge[0] - 1;
            int v = edge[1] - 1;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<int> distances(n, 0);

        for (int i = 0; i < n; i++) {
            queue<int> q;
            vector<int> color(n, 0);
            color[i] = 1;
            int maxDepth = 1;
            int rootNode = i;
            
            q.push(i);

            while (!q.empty()) {
                int currNode = q.front();
                q.pop();
                rootNode = min(rootNode, currNode);

                for (int neighbor : graph[currNode]) {
                    if (color[neighbor] == 0) {
                        color[neighbor] = color[currNode] + 1;
                        maxDepth = max(maxDepth, color[neighbor]);
                        q.push(neighbor);
                    } 
                    else if (abs(color[neighbor] - color[currNode]) != 1) {
                        return -1;
                    }
                }
            }
            
            distances[rootNode] = max(distances[rootNode], maxDepth);
        }

        return accumulate(distances.begin(), distances.end(), 0);
    }
};