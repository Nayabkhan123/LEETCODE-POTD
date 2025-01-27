/*
    There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are 
    given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course 
    ai first if you want to take course bi.

    For example, the pair [0, 1] indicates that you have to take course 0 before you can take course 1.
    Prerequisites can also be indirect. If course a is a prerequisite of course b, and course b is a 
    prerequisite of course c, then course a is a prerequisite of course c.

    You are also given an array queries where queries[j] = [uj, vj]. For the jth query, you should 
    answer whether course uj is a prerequisite of course vj or not.

    Return a boolean array answer, where answer[j] is the answer to the jth query.
*/

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses);

     
        for(const auto& p : prerequisites) {
            graph[p[0]].push_back(p[1]);
            indegree[p[1]]++;
        }

        queue<int> q;
        vector<unordered_set<int>> pre(numCourses);

        for(int u = 0; u < numCourses; ++u)
            if(!indegree[u])
                q.push(u);

        while(!q.empty()) {
            int u = q.front(); q.pop();

            for(int v : graph[u]) {
                pre[v].insert(u);
                pre[v].insert(pre[u].begin(), pre[u].end());

                indegree[v]--;
                if(!indegree[v])
                    q.push(v);
            }
        }        
        vector<bool>ans(queries.size());
        for(int i = 0; i < queries.size(); ++i) {
            int u = queries[i][0], v = queries[i][1];
            ans[i] = pre[v].find(u) != pre[v].end();
        }

        return ans;
    }
};