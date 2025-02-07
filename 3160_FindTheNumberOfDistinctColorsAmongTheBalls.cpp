/*
    You are given an integer limit and a 2D array queries of size n x 2.

    There are limit + 1 balls with distinct labels in the range [0, limit]. Initially, all balls are uncolored. 
    For every query in queries that is of the form [x, y], you mark ball x with the color y. After each query, 
    you need to find the number of distinct colors among the balls.

    Return an array result of length n, where result[i] denotes the number of distinct colors after ith query.

    Note that when answering a query, lack of a color will not be considered as a color.
*/

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n=queries.size();
        unordered_map<int,int> color_freq;
        unordered_map<int,int> ball_color;
        vector<int> res(n);
        for(int i=0;i<n;++i){
            int ball = queries[i][0];
            int color = queries[i][1];
            if(ball_color.count(ball)){
                color_freq[ball_color[ball]]--;
                if(color_freq[ball_color[ball]]==0)
                    color_freq.erase(ball_color[ball]);
            }
            ball_color[ball]=color;
            color_freq[color]++;
            res[i] = color_freq.size();
        }
        return res;
    }
};