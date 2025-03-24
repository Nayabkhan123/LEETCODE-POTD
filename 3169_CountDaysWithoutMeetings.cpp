/*
    You are given a positive integer days representing the total number of days an employee is 
    available for work (starting from day 1). You are also given a 2D array meetings of size n 
    where, meetings[i] = [start_i, end_i] represents the starting and ending days of meeting i (inclusive).

    Return the count of days when the employee is available for work but no meetings are scheduled.

    Note: The meetings may overlap.
*/

class Solution {
    public:
        int countDays(int days, vector<vector<int>>& meetings) {
            sort(meetings.begin(),meetings.end());
            int lastDay=meetings[0][1],cnt=0,n=meetings.size();
    
            for(int i=0;i<n-1;i++){
                int b = meetings[i+1][0];
                if(lastDay < b){
                    cnt+=b-lastDay-1;
                }
                if(lastDay<meetings[i+1][1]){
                    lastDay=meetings[i+1][1];
                }
            }
            if(meetings[0][0]!=1){
                cnt+=meetings[0][0]-1;
            }
            if(meetings[n-1][1]!=days){
                lastDay = lastDay>meetings[n-1][1]?lastDay:meetings[n-1][1];
                cnt+=days-lastDay;
            }
            return cnt;
        }
};

    // timeComplexity: O(N) && spaceComplexity: O(N)  (N -> Days)
class Solution {
    public:
        int countDays(int days, vector<vector<int>>& meetings) {
            vector<int>cnt(days+1,0);
            for(int i=0;i<meetings.size();i++){
                for(int j=meetings[i][0];j<=meetings[i][1];j++){
                    cnt[j]++;
                }
            }
            int ans=0;
            for(auto it : cnt){
                if(it==0){
                    ans++;
                }
            }
            return ans-1;
        }
    };

