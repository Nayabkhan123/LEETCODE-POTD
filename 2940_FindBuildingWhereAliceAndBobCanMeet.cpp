/*
You are given a 0-indexed array heights of positive integers, where heights[i] represents the height of the ith building.

If a person is in building i, they can move to any other building j if and only if i < j and heights[i] < heights[j].

You are also given another array queries where queries[i] = [ai, bi]. On the ith query, Alice is in building ai 
while Bob is in building bi.

Return an array ans where ans[i] is the index of the leftmost building where Alice and Bob can meet on the ith query. 
If Alice and Bob cannot move to a common building on query i, set ans[i] to -1.
*/


vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
    int n = heights.size();
    int totalQueries = queries.size();
    vector<int> ans(totalQueries, -1);
    unordered_map<int, vector<pair<int,int>>> mp;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int q=0; q<totalQueries; q++) {
        int i = queries[q][0];
        int j = queries[q][1];
        if (i < j && heights[i] < heights[j])
            ans[q] = j;
        else if (i > j && heights[i] > heights[j])
            ans[q] = i;
        else if (i == j)
            ans[q] = i;
        else
            mp[max(i, j)].push_back({max(heights[i], heights[j]), q});
    }
    for (int i=0; i<n; i++) {
        while (!pq.empty() && pq.top().first < heights[i]) {
            ans[pq.top().second] = i;
            pq.pop();
        }
        for (auto &it : mp[i])
            pq.push(it);
    }
    return ans;
}

//Brute Force Approach (945 / 952 testcases passed) Gives TLE
class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        vector<int>ans(queries.size(),-1);
        for(int i=0;i<queries.size();i++){
            int a=queries[i][0];
            int b=queries[i][1];
            int maxind=max(a,b);
            for(int j=maxind;j<heights.size();j++){
                if(a==b){
                    ans[i]=j;
                    break;
                }
                else if(a<b){
                    if((heights[a]<heights[j]&&heights[b]<=heights[j])){
                        ans[i]=j;
                        break;
                    }
                }
                else{
                    if((heights[a]<=heights[j]&&heights[b]<heights[j])){
                        ans[i]=j;
                        break;
                    }
                } 
            }
        }
        return ans;
    }
};