/*
    You have planned some train traveling one year in advance. The days of the year in which you will travel are 
    given as an integer array days. Each day is an integer from 1 to 365.

    Train tickets are sold in three different ways:

    a 1-day pass is sold for costs[0] dollars,
    a 7-day pass is sold for costs[1] dollars, and
    a 30-day pass is sold for costs[2] dollars.
    The passes allow that many days of consecutive travel.

    For example, if we get a 7-day pass on day 2, then we can travel for 7 days: 2, 3, 4, 5, 6, 7, and 8.
    Return the minimum number of dollars you need to travel every day in the given list of days.
*/

// DP
class Solution {
public:
    set<int>s;
    int recursion(vector<int>&dp,vector<int>days,vector<int>&costs,int currday){
        if(currday>days[days.size()-1]){
            dp[currday]=0;
            return 0;
        }
        if(dp[currday]!=-1) return dp[currday]; 
        if(!s.contains(currday)){
            dp[currday]=recursion(dp,days,costs,currday+1);
            return dp[currday];
        }
        int oneday = costs[0]+recursion(dp,days,costs,currday+1);
        int sevenday = costs[1]+recursion(dp,days,costs,currday+7);
        int thirtyday = costs[2]+recursion(dp,days,costs,currday+30);
        return dp[currday]=min(oneday,min(sevenday,thirtyday));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int lastday = days[days.size()-1]+30;
        vector<int>dp(lastday+1,-1);
        for(auto it:days){
            s.insert(it);
        }
        return recursion(dp,days,costs,days[0]);
    }
};

// recursion (Time Limit Exceeded)
class Solution {
public:
    set<int>s;
    int recursion(vector<int>days,vector<int>&costs,int currday){
        if(currday>days[days.size()-1]) return 0;
        if(!s.contains(currday)){
            return 0+recursion(days,costs,currday+1);
        }
        int oneday = costs[0]+recursion(days,costs,currday+1);
        int sevenday = costs[1]+recursion(days,costs,currday+7);
        int thirtyday = costs[2]+recursion(days,costs,currday+30);
        return min(oneday,min(sevenday,thirtyday));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        for(auto it:days){
            s.insert(it);
        }
        return recursion(days,costs,days[0]);
    }
};