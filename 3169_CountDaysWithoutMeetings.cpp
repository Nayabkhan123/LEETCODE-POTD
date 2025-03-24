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
            int lastDay=meetings[0][1],cnt=meetings[0][0]-1;
    
            for(int i=0;i<meetings.size()-1;i++){
                int b = meetings[i+1][0];
                if(lastDay < b) cnt+=b-lastDay-1;
                lastDay=max(lastDay,meetings[i+1][1]);
            }
            return cnt+days-lastDay;;
        }
    };

// timeComplexity: O(N*Days) && spaceComplexity: O(Days)  
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

