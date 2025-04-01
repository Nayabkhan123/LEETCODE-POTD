/*
    You are given a 0-indexed 2D integer array questions where 
    questions[i] = [pointsi, brainpoweri].

    The array describes the questions of an exam, where you have to process the questions 
    in order (i.e., starting from question 0) and make a decision whether to solve or skip 
    each question. Solving question i will earn you pointsi points but you will be unable 
    to solve each of the next brainpoweri questions. If you skip question i, you get to 
    make the decision on the next question.

    For example, given questions = [[3, 2], [4, 3], [4, 4], [2, 5]]:
    If question 0 is solved, you will earn 3 points but you will be unable to solve questions 1 and 2.
    If instead, question 0 is skipped and question 1 is solved, you will earn 4 points but 
    you will be unable to solve questions 2 and 3.
    Return the maximum points you can earn for the exam.
*/

class Solution {
public:
    long long solve(vector<vector<int>>& questions,int n,int i,vector<long long>&dp){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        long long sol = questions[i][0]+solve(questions,n,i+questions[i][1]+1,dp);
        long long skip = solve(questions,n,i+1,dp);
        return dp[i]=max(sol,skip);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        vector<long long>dp(n,-1);
        return solve(questions,n,0,dp);
    }
};

class Solution {
public:
    long long solve(vector<vector<int>>& questions,int n,int i){
        if(i>=n) return 0;
        long long sol = questions[i][0]+solve(questions,n,i+questions[i][1]+1);
        long long skip = solve(questions,n,i+1);
        return max(sol,skip);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        long long maxi=solve(questions,n,0);
        return maxi;
    }
};