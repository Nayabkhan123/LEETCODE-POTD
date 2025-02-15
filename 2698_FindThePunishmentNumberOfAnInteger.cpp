/*
    Given a positive integer n, return the punishment number of n.

    The punishment number of n is defined as the sum of the squares of all integers i such that:

    1 <= i <= n
    The decimal representation of i * i can be partitioned into contiguous substrings such that 
    the sum of the integer values of these substrings equals i.
*/

class Solution {
    public:
        bool check(int j,string i2,int i, int currsum){
            int n=i2.size();
            if(j==n){
                return currsum==i;
            }
            for(int idx = j;idx<n;idx++){
                int value = stoi(i2.substr(j,idx-j+1));
                if(check(idx+1,i2,i,currsum+value)){
                    return true;
                }
            }
            return false;
        }
        int punishmentNumber(int n) {
            int ans=0;
            for(int i=1;i<=n;i++){
                string i2 = to_string(i*i);
                if(check(0,i2,i,0)){
                    ans+=(i*i);
                }
            }
            return ans;
        }
    };