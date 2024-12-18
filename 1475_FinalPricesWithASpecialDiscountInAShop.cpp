/*
You are given an integer array prices where prices[i] is the price of the ith item in a shop.

There is a special discount for items in the shop. If you buy the ith item, then you will receive a 
discount equivalent to prices[j] where j is the minimum index such that j > i and prices[j] <= prices[i]. 
Otherwise, you will not receive any discount at all.

Return an integer array answer where answer[i] is the final price you will pay for the ith item of the shop, 
considering the special discount.

*/

// Monotonic stack
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int>s;
        int n = prices.size();
        for(int i=n-1;i>=0;i--){
            while(!s.empty()&&s.top()>prices[i]){
                s.pop();
            }
            int val=prices[i];
            if(!s.empty()){
                prices[i]-=s.top();
            }
            s.push(val);
        }
        return prices;
    }
};

//Brute Force Approach
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int>answer;
        for(int i=0;i<prices.size();i++){
            for(int j=i+1;j<prices.size();j++){
                if(prices[j]<=prices[i]){
                    answer.push_back(prices[i]-prices[j]);
                    break;
                }
            }
            if(answer.size()!=i+1) answer.push_back(prices[i]);
        }
        return answer;
    }
};

