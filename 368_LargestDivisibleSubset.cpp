/*
    Given a set of distinct positive integers nums, return the largest subset answer 
    such that every pair (answer[i], answer[j]) of elements in this subset satisfies:

    answer[i] % answer[j] == 0, or
    answer[j] % answer[i] == 0
    If there are multiple solutions, return any of them.
*/

class Solution {
    public:
        vector<int> largestDivisibleSubset(vector<int>& nums) {
            int n=nums.size();
            vector<int>ans;
            sort(nums.begin(),nums.end());
            int lis=1;
            vector<int>dp(n+1,1);
            for(int i=1;i<n;i++){
                for(int j=0;j<i;j++){
                    if(nums[i]%nums[j]==0 && dp[j]+1>dp[i]){
                        dp[i]=dp[j]+1;
                        if(lis<dp[i]){
                            lis=dp[i];
                        }
                    }
                }
            }
            int prev=-1;
            for(int i=n-1;i>=0;i--){
                if(lis==dp[i] && (prev%nums[i]==0 || prev==-1)){
                    ans.push_back(nums[i]);
                    lis-=1;
                    prev=nums[i];
                }
            }
            return ans;
        }
    };