/*
    You are given a 0-indexed string blocks of length n, where blocks[i] is either 'W' 
    or 'B', representing the color of the ith block. The characters 'W' and 'B' denote 
    the colors white and black, respectively.

    You are also given an integer k, which is the desired number of consecutive black blocks.

    In one operation, you can recolor a white block such that it becomes a black block.

    Return the minimum number of operations needed such that there is at least one 
    occurrence of k consecutive black blocks.
*/

class Solution {
    public:
        int minimumRecolors(string blocks, int k) {
            int currcnt=0,ans=INT_MAX;
            int n=blocks.size();
            for(int i=0;i<=n-k;i++){
                for(int j=i;j<i+k;j++){
                    if(blocks[j]=='W') currcnt++;
                }
                ans = min(ans,currcnt);
                currcnt=0;
            }
            return ans;
        }
    };