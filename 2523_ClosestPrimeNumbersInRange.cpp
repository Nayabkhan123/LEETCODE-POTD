/*
    Given two positive integers left and right, find the two integers num1 and num2 such that:
    left <= num1 < num2 <= right .
    Both num1 and num2 are prime numbers.
    num2 - num1 is the minimum amongst all other pairs satisfying the above conditions.
    Return the positive integer array ans = [num1, num2]. If there are multiple pairs 
    satisfying these conditions, return the one with the smallest num1 value. If no such 
    numbers exist, return [-1, -1].
*/

class Solution {
    public:
        vector<int> closestPrimes(int left, int right) {
            vector<bool>prime((right+1),true);
            prime[0]=false;
            prime[1]=false;
            for(int i=2;i*i<=right;i++){
                if(prime[i]){
                    for(int j=i*i;j<=right;j+=i){
                        prime[j]=false;
                    }
                }
            }
            vector<int>ans={-1,-1};
            int prevprime=-1,minDiff=INT_MAX;
            for(int i=left;i<=right;i++){
                if(prime[i]){
                    if(prevprime==-1){
                        prevprime=i;
                    }
                    else{
                        if(i-prevprime<minDiff){
                            ans={prevprime,i};
                            minDiff=i-prevprime;
                        }
                    }
                    prevprime=i;
                }
            }
            return ans;
        }
    };