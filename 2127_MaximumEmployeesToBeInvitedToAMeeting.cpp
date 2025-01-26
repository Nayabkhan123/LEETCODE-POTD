/*
    A company is organizing a meeting and has a list of n employees, waiting to be invited. They have 
    arranged for a large circular table, capable of seating any number of employees.

    The employees are numbered from 0 to n - 1. Each employee has a favorite person and they will attend 
    the meeting only if they can sit next to their favorite person at the table. The favorite person 
    of an employee is not themself.

    Given a 0-indexed integer array favorite, where favorite[i] denotes the favorite person of the ith 
    employee, return the maximum number of employees that can be invited to the meeting.
*/

class Solution {
public:
    int maximumInvitations(vector<int>& fav) {
        int n = fav.size(), maxCycle = 0, pairChains = 0;
        queue<int> q;
        vector<bool> vis(n);
        vector<int> inDegree(n), chainLen(n);

        for (int x : fav) inDegree[x]++;
        for (int i = 0; i < n; ++i) 
            if (!inDegree[i]) q.push(i);

        while (!q.empty()) {
            int u = q.front(); q.pop();
            vis[u] = true;
            int neighbor = fav[u];
            chainLen[neighbor] = max(chainLen[neighbor], chainLen[u] + 1);
            if (--inDegree[neighbor] == 0) q.push(neighbor);
        }

        for (int i = 0; i < n; ++i) {
            if (vis[i]) continue;

            int cycleLen = 0, u = i;
            while (!vis[u]) {
                vis[u] = true;
                u = fav[u];
                cycleLen++;
            }

            if (cycleLen == 2) 
                pairChains += 2 + chainLen[i] + chainLen[fav[i]];
            else 
                maxCycle = max(maxCycle, cycleLen);
        }

        return max(maxCycle, pairChains);
    }
};