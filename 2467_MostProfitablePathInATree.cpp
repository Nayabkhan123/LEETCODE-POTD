/*
    There is an undirected tree with n nodes labeled from 0 to n - 1, rooted at node 0. 
    You are given a 2D integer array edges of length n - 1 where edges[i] = [ai, bi] 
    indicates that there is an edge between nodes ai and bi in the tree.

    At every node i, there is a gate. You are also given an array of even integers amount, 
    where amount[i] represents:

    the price needed to open the gate at node i, if amount[i] is negative, or,
    the cash reward obtained on opening the gate at node i, otherwise.
    The game goes on as follows:

    Initially, Alice is at node 0 and Bob is at node bob.
    At every second, Alice and Bob each move to an adjacent node. Alice moves towards some 
    leaf node, while Bob moves towards node 0.
    For every node along their path, Alice and Bob either spend money to open the gate at 
    that node, or accept the reward. Note that:
    If the gate is already open, no price will be required, nor will there be any cash reward.
    If Alice and Bob reach the node simultaneously, they share the price/reward for opening 
    the gate there. In other words, if the price to open the gate is c, then both Alice and 
    Bob pay c / 2 each. Similarly, if the reward at the gate is c, both of them receive c / 2 each.
    If Alice reaches a leaf node, she stops moving. Similarly, if Bob reaches node 0, he 
    stops moving. Note that these events are independent of each other.
    Return the maximum net income Alice can have if she travels towards the optimal leaf node.
*/

class Solution {
    bool findBobPath(vector<vector<int>>& adj,int bob,int parent,vector<int>& curr_path,vector<int>& bob_path){
        if(bob==0){
            bob_path = curr_path;
            return true;
        }
        curr_path.push_back(bob);
        for(int nbr: adj[bob]){
            if(nbr!=parent and findBobPath(adj,nbr,bob,curr_path,bob_path))
                return true;
        }
        curr_path.pop_back();
        return false;
    }
    int findMaxIncomeForAlice(vector<vector<int>>& adj,int alice,int parent,vector<int>& amount){
        int max_income = INT_MIN;
        for(int nbr: adj[alice]){
            if(nbr!=parent){
                int income = findMaxIncomeForAlice(adj,nbr,alice,amount);
                if(income + amount[alice] > max_income)
                    max_income = income + amount[alice];
            }
        }
        return max_income==INT_MIN?amount[alice]:max_income;
    }
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob,vector<int>& amount) {
        int n=amount.size();
        vector<vector<int>> adj(n);
        for(auto edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> curr_path,bob_path;
        findBobPath(adj,bob,-1,curr_path,bob_path);

        int size = bob_path.size();
        int i;
        for(i=0;i<size/2;++i)
            amount[bob_path[i]]=0;
        
        if(size&1)  amount[bob_path[i]]=0;
        else        amount[bob_path[i]]/=2;

        return findMaxIncomeForAlice(adj,0,-1,amount);
    }
};